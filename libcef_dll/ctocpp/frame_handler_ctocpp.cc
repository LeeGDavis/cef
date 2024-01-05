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
// $hash=0074492ed580ccc06962a05b6c72bdabae182a51$
//

#include "libcef_dll/ctocpp/frame_handler_ctocpp.h"
#include "libcef_dll/cpptoc/browser_cpptoc.h"
#include "libcef_dll/cpptoc/frame_cpptoc.h"
#include "libcef_dll/shutdown_checker.h"

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
void CefFrameHandlerCToCpp::OnFrameCreated(CefRefPtr<CefBrowser> browser,
                                           CefRefPtr<CefFrame> frame) {
  shutdown_checker::AssertNotShutdown();

  cef_frame_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_frame_created)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get()) {
    return;
  }
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get()) {
    return;
  }

  // Execute
  _struct->on_frame_created(_struct, CefBrowserCppToC::Wrap(browser),
                            CefFrameCppToC::Wrap(frame));
}

NO_SANITIZE("cfi-icall")
void CefFrameHandlerCToCpp::OnFrameAttached(CefRefPtr<CefBrowser> browser,
                                            CefRefPtr<CefFrame> frame,
                                            bool reattached) {
  shutdown_checker::AssertNotShutdown();

  cef_frame_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_frame_attached)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get()) {
    return;
  }
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get()) {
    return;
  }

  // Execute
  _struct->on_frame_attached(_struct, CefBrowserCppToC::Wrap(browser),
                             CefFrameCppToC::Wrap(frame), reattached);
}

NO_SANITIZE("cfi-icall")
void CefFrameHandlerCToCpp::OnFrameDetached(CefRefPtr<CefBrowser> browser,
                                            CefRefPtr<CefFrame> frame) {
  shutdown_checker::AssertNotShutdown();

  cef_frame_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_frame_detached)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get()) {
    return;
  }
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get()) {
    return;
  }

  // Execute
  _struct->on_frame_detached(_struct, CefBrowserCppToC::Wrap(browser),
                             CefFrameCppToC::Wrap(frame));
}

NO_SANITIZE("cfi-icall")
void CefFrameHandlerCToCpp::OnMainFrameChanged(CefRefPtr<CefBrowser> browser,
                                               CefRefPtr<CefFrame> old_frame,
                                               CefRefPtr<CefFrame> new_frame) {
  shutdown_checker::AssertNotShutdown();

  cef_frame_handler_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, on_main_frame_changed)) {
    return;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get()) {
    return;
  }
  // Unverified params: old_frame, new_frame

  // Execute
  _struct->on_main_frame_changed(_struct, CefBrowserCppToC::Wrap(browser),
                                 CefFrameCppToC::Wrap(old_frame),
                                 CefFrameCppToC::Wrap(new_frame));
}

// CONSTRUCTOR - Do not edit by hand.

CefFrameHandlerCToCpp::CefFrameHandlerCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

CefFrameHandlerCToCpp::~CefFrameHandlerCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
cef_frame_handler_t*
CefCToCppRefCounted<CefFrameHandlerCToCpp,
                    CefFrameHandler,
                    cef_frame_handler_t>::UnwrapDerived(CefWrapperType type,
                                                        CefFrameHandler* c) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
CefWrapperType CefCToCppRefCounted<CefFrameHandlerCToCpp,
                                   CefFrameHandler,
                                   cef_frame_handler_t>::kWrapperType =
    WT_FRAME_HANDLER;
