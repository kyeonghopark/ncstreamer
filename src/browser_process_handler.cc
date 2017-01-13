/**
 * Copyright (C) 2017 NCSOFT Corporation
 */


#include "src/browser_process_handler.h"

#include <string>

#include "include/cef_browser.h"
#include "include/cef_command_line.h"
#include "include/wrapper/cef_helpers.h"

#include "src/client.h"
#include "src/manifest.h"


namespace ncstreamer {
BrowserProcessHandler::BrowserProcessHandler(HINSTANCE instance)
    : instance_{instance} {
}


BrowserProcessHandler::~BrowserProcessHandler() {
}


void BrowserProcessHandler::OnContextInitialized() {
  CEF_REQUIRE_UI_THREAD();

  CefWindowInfo window_info;
  window_info.style = WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS |
                      WS_VISIBLE;
  window_info.x = CW_USEDEFAULT;
  window_info.y = CW_USEDEFAULT;
  window_info.width = static_cast<int>(kWindowMinimumSize.first);
  window_info.height = static_cast<int>(kWindowMinimumSize.second);

  CefRefPtr<Client> client{new Client{instance_}};

  std::string uri{
      CefCommandLine::GetGlobalCommandLine()->GetSwitchValue("url")};

  CefBrowserSettings browser_settings;

  CefBrowserHost::CreateBrowser(
      window_info, client, uri, browser_settings, NULL);
}
}  // namespace ncstreamer
