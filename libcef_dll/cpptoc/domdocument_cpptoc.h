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
// $hash=fffbd23b71b8c0d8cc38a6968cb5833ac26d4499$
//

#ifndef CEF_LIBCEF_DLL_CPPTOC_DOMDOCUMENT_CPPTOC_H_
#define CEF_LIBCEF_DLL_CPPTOC_DOMDOCUMENT_CPPTOC_H_
#pragma once

#if !defined(BUILDING_CEF_SHARED)
#error This file can be included DLL-side only
#endif

#include "include/capi/cef_dom_capi.h"
#include "include/cef_dom.h"
#include "libcef_dll/cpptoc/cpptoc_ref_counted.h"

// Wrap a C++ class with a C structure.
// This class may be instantiated and accessed DLL-side only.
class CefDOMDocumentCppToC : public CefCppToCRefCounted<CefDOMDocumentCppToC,
                                                        CefDOMDocument,
                                                        cef_domdocument_t> {
 public:
  CefDOMDocumentCppToC();
  virtual ~CefDOMDocumentCppToC();
};

#endif  // CEF_LIBCEF_DLL_CPPTOC_DOMDOCUMENT_CPPTOC_H_
