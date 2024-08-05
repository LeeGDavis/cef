# Copyright (c) 2024 The Chromium Embedded Framework Authors. All rights
# reserved. Use of this source code is governed by a BSD-style license that
# can be found in the LICENSE file.

load("@bazel_tools//tools/cpp:windows_cc_configure.bzl", "find_vc_path", "setup_vc_env_vars")

def _get_arch(rctx):
    if rctx.os.arch == "amd64":
        return "x64"

def _is_windows(rctx):
    return rctx.os.name.find("windows") != -1

# Tools in the form <Target>: [<Tool>, <Other files needed for that target>]
TOOLS = {
    "mt": {
        "tool": "mt.exe",
        "deps": [],
    },
    "rc": {
        "tool": "rc.exe",
        "deps": ["rcdll.dll"],
    },
}

def _setup_tools(rctx, sdk_bin_path, sdk_metadata_path):
    contents = ""

    rctx.symlink(sdk_metadata_path, "VerUnionMetadata")
    contents += """
exports_files(["VerUnionMetadata"])
"""

    for toolname, toolcfg in TOOLS.items():
        toolexec = toolcfg["tool"]
        deps = toolcfg["deps"]
        direct_deps = [toolexec] + deps
        shared_deps = toolcfg.get("shared_deps", [])

        # Symlink any tools into the right places
        for dep in direct_deps:
            rctx.symlink(
                "{}/{}".format(sdk_bin_path, dep),
                dep,
            )

        # Setting up a filegroup for those dependents
        contents += """
filegroup(
  name = "{}_deps",
  srcs = {},
)
""".format(toolname, direct_deps + shared_deps)

        # Now create a wrapper for this tool that simply calls it
        rctx.template(
            "{}_wrapper.py".format(toolname),
            Label("//bazel/win:wrapper.py.tpl"),
            substitutions = {
                "${binary}": toolexec,
            },
            executable = True,
        )

        # And add that newly created wrapper to the BUILD.bazel file
        contents += """
py_binary(
    name = "{0}_pybin",
    srcs = ["{0}_wrapper.py"],
    main = "{0}_wrapper.py",
    data = [
        "@rules_python//python/runfiles",
        ":{0}_deps"
    ],
    python_version = "PY3",
)
""".format(toolname)

    return contents

def _setup_vc_debug_runtime(rctx, sdk_bin_path):
    ucrtbased_dll = "ucrtbased.dll"
    rctx.symlink("{}/ucrt/{}".format(sdk_bin_path, ucrtbased_dll), ucrtbased_dll)

    contents = """
filegroup(
    name = "vc_debug_runtime",
    srcs = ["{}"],
)
""".format(ucrtbased_dll)

    return contents

def _windows_sdk_impl(rctx):
    # We only support Windows
    if not _is_windows(rctx):
        fail("This rule only supports Windows")

    # Figure out where the SDK is, which is based on a registry key.
    vc_path = find_vc_path(rctx)
    env = setup_vc_env_vars(rctx, vc_path, envvars = ["WINDOWSSDKVERBINPATH", "WindowsSdkDir", "WindowsSDKVersion"])
    sdk_bin_path = "{}{}".format(env["WINDOWSSDKVERBINPATH"], _get_arch(rctx))
    sdk_metadata_path = "{}UnionMetadata/{}".format(env["WindowsSdkDir"], env["WindowsSDKVersion"])

    # Start with some pre-amble
    contents = """# Autogenerated by //bazel/win:sdk.bzl
load("@rules_python//python:defs.bzl", "py_binary")

package(default_visibility = ["//visibility:public"])
"""

    # Handle setting up tools from our list
    contents += _setup_tools(rctx, sdk_bin_path, sdk_metadata_path)

    contents += _setup_vc_debug_runtime(rctx, sdk_bin_path)

    rctx.file("BUILD.bazel", contents)

setup_sdk = repository_rule(
    attrs = {},
    local = True,
    configure = True,
    implementation = _windows_sdk_impl,
)