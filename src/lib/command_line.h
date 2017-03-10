/**
 * Copyright (C) 2017 NCSOFT Corporation
 */


#ifndef SRC_LIB_COMMAND_LINE_H_
#define SRC_LIB_COMMAND_LINE_H_


#include <string>


namespace ncstreamer {
class CommandLine {
 public:
  explicit CommandLine(const std::wstring &cmd_line);
  virtual ~CommandLine();

  bool is_renderer() const { return is_renderer_; }
  bool needs_to_find_sources() const { return needs_to_find_sources_; }

 private:
  bool is_renderer_;
  bool needs_to_find_sources_;
};
}  // namespace ncstreamer


#endif  // SRC_LIB_COMMAND_LINE_H_
