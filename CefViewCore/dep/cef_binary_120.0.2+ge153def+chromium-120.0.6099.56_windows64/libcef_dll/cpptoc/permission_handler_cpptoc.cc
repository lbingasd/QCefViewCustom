// Copyright (c) 2023 The Chromium Embedded Framework Authors. All rights
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
// $hash=0386addd1e401049523c8b13439412a802fb4211$
//

#include "libcef_dll/cpptoc/permission_handler_cpptoc.h"
#include "libcef_dll/ctocpp/browser_ctocpp.h"
#include "libcef_dll/ctocpp/frame_ctocpp.h"
#include "libcef_dll/ctocpp/media_access_callback_ctocpp.h"
#include "libcef_dll/ctocpp/permission_prompt_callback_ctocpp.h"
#include "libcef_dll/shutdown_checker.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

int CEF_CALLBACK permission_handler_on_request_media_access_permission(
    struct _cef_permission_handler_t* self,
    cef_browser_t* browser,
    cef_frame_t* frame,
    const cef_string_t* requesting_origin,
    uint32_t requested_permissions,
    cef_media_access_callback_t* callback) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return 0;
  }
  // Verify param: frame; type: refptr_diff
  DCHECK(frame);
  if (!frame) {
    return 0;
  }
  // Verify param: requesting_origin; type: string_byref_const
  DCHECK(requesting_origin);
  if (!requesting_origin) {
    return 0;
  }
  // Verify param: callback; type: refptr_diff
  DCHECK(callback);
  if (!callback) {
    return 0;
  }

  // Execute
  bool _retval =
      CefPermissionHandlerCppToC::Get(self)->OnRequestMediaAccessPermission(
          CefBrowserCToCpp::Wrap(browser), CefFrameCToCpp::Wrap(frame),
          CefString(requesting_origin), requested_permissions,
          CefMediaAccessCallbackCToCpp::Wrap(callback));

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK permission_handler_on_show_permission_prompt(
    struct _cef_permission_handler_t* self,
    cef_browser_t* browser,
    uint64_t prompt_id,
    const cef_string_t* requesting_origin,
    uint32_t requested_permissions,
    cef_permission_prompt_callback_t* callback) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return 0;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return 0;
  }
  // Verify param: requesting_origin; type: string_byref_const
  DCHECK(requesting_origin);
  if (!requesting_origin) {
    return 0;
  }
  // Verify param: callback; type: refptr_diff
  DCHECK(callback);
  if (!callback) {
    return 0;
  }

  // Execute
  bool _retval = CefPermissionHandlerCppToC::Get(self)->OnShowPermissionPrompt(
      CefBrowserCToCpp::Wrap(browser), prompt_id, CefString(requesting_origin),
      requested_permissions, CefPermissionPromptCallbackCToCpp::Wrap(callback));

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK permission_handler_on_dismiss_permission_prompt(
    struct _cef_permission_handler_t* self,
    cef_browser_t* browser,
    uint64_t prompt_id,
    cef_permission_request_result_t result) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self) {
    return;
  }
  // Verify param: browser; type: refptr_diff
  DCHECK(browser);
  if (!browser) {
    return;
  }

  // Execute
  CefPermissionHandlerCppToC::Get(self)->OnDismissPermissionPrompt(
      CefBrowserCToCpp::Wrap(browser), prompt_id, result);
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

CefPermissionHandlerCppToC::CefPermissionHandlerCppToC() {
  GetStruct()->on_request_media_access_permission =
      permission_handler_on_request_media_access_permission;
  GetStruct()->on_show_permission_prompt =
      permission_handler_on_show_permission_prompt;
  GetStruct()->on_dismiss_permission_prompt =
      permission_handler_on_dismiss_permission_prompt;
}

// DESTRUCTOR - Do not edit by hand.

CefPermissionHandlerCppToC::~CefPermissionHandlerCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
CefRefPtr<CefPermissionHandler> CefCppToCRefCounted<
    CefPermissionHandlerCppToC,
    CefPermissionHandler,
    cef_permission_handler_t>::UnwrapDerived(CefWrapperType type,
                                             cef_permission_handler_t* s) {
  DCHECK(false) << "Unexpected class type: " << type;
  return nullptr;
}

template <>
CefWrapperType CefCppToCRefCounted<CefPermissionHandlerCppToC,
                                   CefPermissionHandler,
                                   cef_permission_handler_t>::kWrapperType =
    WT_PERMISSION_HANDLER;