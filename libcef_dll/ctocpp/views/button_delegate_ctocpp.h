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
// $hash=53e751a5b54ab964ee2aef1a8232a9647f47db00$
//

#ifndef CEF_LIBCEF_DLL_CTOCPP_VIEWS_BUTTON_DELEGATE_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_VIEWS_BUTTON_DELEGATE_CTOCPP_H_
#pragma once

#if !defined(BUILDING_CEF_SHARED)
#error This file can be included DLL-side only
#endif

#include "include/capi/views/cef_button_capi.h"
#include "include/capi/views/cef_button_delegate_capi.h"
#include "include/views/cef_button.h"
#include "include/views/cef_button_delegate.h"
#include "libcef_dll/ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed DLL-side only.
class CefButtonDelegateCToCpp
    : public CefCToCppRefCounted<CefButtonDelegateCToCpp,
                                 CefButtonDelegate,
                                 cef_button_delegate_t> {
 public:
  CefButtonDelegateCToCpp();
  virtual ~CefButtonDelegateCToCpp();

  // CefButtonDelegate methods.
  void OnButtonPressed(CefRefPtr<CefButton> button) override;
  void OnButtonStateChanged(CefRefPtr<CefButton> button) override;

  // CefViewDelegate methods.
  CefSize GetPreferredSize(CefRefPtr<CefView> view) override;
  CefSize GetMinimumSize(CefRefPtr<CefView> view) override;
  CefSize GetMaximumSize(CefRefPtr<CefView> view) override;
  int GetHeightForWidth(CefRefPtr<CefView> view, int width) override;
  void OnParentViewChanged(CefRefPtr<CefView> view,
                           bool added,
                           CefRefPtr<CefView> parent) override;
  void OnChildViewChanged(CefRefPtr<CefView> view,
                          bool added,
                          CefRefPtr<CefView> child) override;
  void OnWindowChanged(CefRefPtr<CefView> view, bool added) override;
  void OnLayoutChanged(CefRefPtr<CefView> view,
                       const CefRect& new_bounds) override;
  void OnFocus(CefRefPtr<CefView> view) override;
  void OnBlur(CefRefPtr<CefView> view) override;
};

#endif  // CEF_LIBCEF_DLL_CTOCPP_VIEWS_BUTTON_DELEGATE_CTOCPP_H_
