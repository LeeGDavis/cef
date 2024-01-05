// Copyright (c) 2024 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//
// $hash=6271032d1ece3a64e53b1b3013214d358c8b1d6d$
//

#ifndef CEF_LIBCEF_DLL_CPPTOC_MENU_MODEL_CPPTOC_H_
#define CEF_LIBCEF_DLL_CPPTOC_MENU_MODEL_CPPTOC_H_
#pragma once

#if !defined(BUILDING_CEF_SHARED)
#error This file can be included DLL-side only
#endif

#include "include/capi/cef_menu_model_capi.h"
#include "include/cef_menu_model.h"
#include "libcef_dll/cpptoc/cpptoc_ref_counted.h"

// Wrap a C++ class with a C structure.
// This class may be instantiated and accessed DLL-side only.
class CefMenuModelCppToC : public CefCppToCRefCounted<CefMenuModelCppToC,
                                                      CefMenuModel,
                                                      cef_menu_model_t> {
 public:
  CefMenuModelCppToC();
  virtual ~CefMenuModelCppToC();
};

#endif  // CEF_LIBCEF_DLL_CPPTOC_MENU_MODEL_CPPTOC_H_
