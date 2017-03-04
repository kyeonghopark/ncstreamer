/**
 * Copyright (C) 2017 NCSOFT Corporation
 */


#ifndef SRC_RENDER_PROCESS_HANDLER_H_
#define SRC_RENDER_PROCESS_HANDLER_H_


#include "include/cef_render_process_handler.h"

#include "src/render_process/render_load_handler.h"


namespace ncstreamer {
class RenderProcessHandler : public CefRenderProcessHandler {
 public:
  RenderProcessHandler();
  virtual ~RenderProcessHandler();

  // override CefRenderProcessHandler
  CefRefPtr<CefLoadHandler> GetLoadHandler() override;

 private:
  CefRefPtr<RenderLoadHandler> load_handler_;

  IMPLEMENT_REFCOUNTING(RenderProcessHandler);
};
}  // namespace ncstreamer


#endif  // SRC_RENDER_PROCESS_HANDLER_H_
