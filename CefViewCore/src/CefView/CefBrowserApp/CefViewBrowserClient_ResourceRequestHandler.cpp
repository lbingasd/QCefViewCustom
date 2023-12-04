#include <CefViewBrowserClient.h>

#pragma region std_headers
#include <sstream>
#include <string>
#include <algorithm>
#pragma endregion std_headers

#pragma region cef_headers
#include <include/cef_app.h>
#pragma endregion cef_headers

#include <Common/CefViewCoreLog.h>

CefRefPtr<CefResourceRequestHandler>
CefViewBrowserClient::GetResourceRequestHandler(CefRefPtr<CefBrowser> browser,
                                                CefRefPtr<CefFrame> frame,
                                                CefRefPtr<CefRequest> request,
                                                bool is_navigation,
                                                bool is_download,
                                                const CefString& request_initiator,
                                                bool& disable_default_handling)
{
  
  //logD("GetResourceRequestHandler: %s", request->GetURL().c_str());
  return this;
}

CefResourceRequestHandler::ReturnValue
CefViewBrowserClient::OnBeforeResourceLoad(CefRefPtr<CefBrowser> browser,
                                           CefRefPtr<CefFrame> frame,
                                           CefRefPtr<CefRequest> request,
#if CEF_VERSION_MAJOR > 91
                                           CefRefPtr<CefCallback> callback
#else
                                           CefRefPtr<CefRequestCallback> callback
#endif
)
{
  auto url = request->GetURL().ToString();
  //logD("OnBeforeResourceLoad: %s", url.c_str());
  auto delegate = client_delegate_.lock();
  if (delegate) {
    delegate->OnBeforeResourceLoad(browser, frame, request);
  }
  return resource_manager_->OnBeforeResourceLoad(browser, frame, request, callback);
}

CefRefPtr<CefResourceHandler>
CefViewBrowserClient::GetResourceHandler(CefRefPtr<CefBrowser> browser,
                                         CefRefPtr<CefFrame> frame,
                                         CefRefPtr<CefRequest> request)
{
  return resource_manager_->GetResourceHandler(browser, frame, request);
}

void
CefViewBrowserClient::OnProtocolExecution(CefRefPtr<CefBrowser> browser,
                                          CefRefPtr<CefFrame> frame,
                                          CefRefPtr<CefRequest> request,
                                          bool& allow_os_execution)
{}
