/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "stb_image.h"
#include <stdint.h>
#include <cstring>
#include <filesystem>
#include <shell/shared/imageLoader/win/ImageLoaderWin.h>

namespace igl::shell {

ImageLoaderWin::ImageLoaderWin() {
// @fb-only
  // @fb-only
  // @fb-only
    // @fb-only
  // @fb-only
    // @fb-only
  // @fb-only
// @fb-only
}

ImageLoaderWin::ImageLoaderWin(const std::string& homePath) {
  setHomePath(homePath);
}

ImageData ImageLoaderWin::loadImageData(std::string imageName) noexcept {
  // Path from home directory
  std::string fullName = homePath() + imageName;

  if (!std::filesystem::exists(fullName)) {
    fullName = homePath() + "shell/resources/images/" + imageName;
  }

  if (!std::filesystem::exists(fullName)) {
    using namespace std::filesystem;
    path dir = current_path();
    // find `shell/resources/images/` somewhere above our current directory
    const path subdir("shell/resources/images/");
    while (dir != current_path().root_path() && !exists(dir / subdir)) {
      dir = dir.parent_path();
    }
    fullName = (dir / subdir / imageName).string();
  }

  if (!std::filesystem::exists(fullName)) {
    using namespace std::filesystem;
    path dir = current_path();
    const path subdir("images/");
    fullName = (dir / subdir / imageName).string();
  }

  // Load image from file in RGBA format
  auto ret = ImageData();
  int width, height;
  unsigned char* data = stbi_load(fullName.c_str(), &width, &height, 0, 4);
  if (!data) {
    IGL_ASSERT_MSG(data, "Could not find image file: %s", fullName.c_str());
    return ret;
  }

  // Copy results into return value
  ret.width = width;
  ret.height = height;
  ret.bitsPerComponent = 8;
  ret.bytesPerRow = (ret.bitsPerComponent * 4 / 8) * ret.width;
  ret.buffer.resize(ret.bytesPerRow * ret.height);
  memcpy(ret.buffer.data(), data, ret.bytesPerRow * ret.height);

  stbi_image_free(data);

  return ret;
}

} // namespace igl::shell
