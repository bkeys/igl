/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <android/log.h>
#include <shell/shared/imageLoader/ImageLoader.h>
#include <string>

class AAssetManager;

namespace igl::shell {

class ImageLoaderAndroid final : public ImageLoader {
 public:
  ImageLoaderAndroid() = default;
  ~ImageLoaderAndroid() override = default;
  ImageData loadImageData(std::string imageName) noexcept override;
  void setAssetManager(AAssetManager* mgr) {
    assetManager_ = mgr;
  }
  AAssetManager* getAssetManager() const noexcept {
    return assetManager_;
  }

 private:
  AAssetManager* assetManager_;
};

} // namespace igl::shell