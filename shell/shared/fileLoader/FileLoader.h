/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once
#include <stdint.h>
#include <string>
#include <vector>

namespace igl::shell {

class FileLoader {
 public:
  FileLoader() = default;
  virtual ~FileLoader() = default;
  virtual std::vector<uint8_t> loadBinaryData(const std::string& /* filename */) {
    return std::vector<uint8_t>();
  }
  virtual bool fileExists(const std::string& /* filename */) const {
    return false;
  }
  virtual std::string basePath() const {
    return ".";
  }
};

} // namespace igl::shell
