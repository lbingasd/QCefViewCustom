#include "CCefClientDelegate.h"

#include <QApplication>
#include <QDebug>
#include <QJsonDocument>

#include "QCefViewPrivate.h"


void
CCefClientDelegate::OnBeforeResourceLoad(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefRefPtr<CefRequest> request)
{
  auto url = request->GetURL().ToString();
  CefRequest::HeaderMap headers;
  request->GetHeaderMap(headers);
  CefRequest::HeaderMap::iterator itor = headers.begin();
  QVariantMap vmap;
  while (itor != headers.end()) {
    vmap.insert(QString::fromStdString(itor->first.ToString()), QString::fromStdString(itor->second.ToString()));
    ++itor;
  }

  const QJsonDocument doc = QJsonDocument::fromVariant(vmap);
  QString headers_json = doc.toJson();

  emit pCefViewPrivate_->q_ptr->beforeResourceLoad(browser->GetIdentifier(),
      frame->GetIdentifier(),
      QString::fromStdString(url),
      headers_json);
}
