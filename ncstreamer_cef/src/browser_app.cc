/**
 * Copyright (C) 2017 NCSOFT Corporation
 */


#include "ncstreamer_cef/src/browser_app.h"


namespace ncstreamer {
BrowserApp::BrowserApp(
    HINSTANCE instance,
    bool shows_sources_all,
    const std::vector<std::string> &sources,
    const std::wstring &locale,
    const std::wstring &ui_uri)
    : browser_process_handler_{new BrowserProcessHandler{
          instance,
          shows_sources_all,
          sources,
          locale,
          ui_uri}} {
}


BrowserApp::~BrowserApp() {
}


CefRefPtr<CefBrowserProcessHandler> BrowserApp::GetBrowserProcessHandler() {
  return browser_process_handler_;
}
}  // namespace ncstreamer
