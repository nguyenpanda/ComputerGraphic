//
// Created by Hà Tường Nguyên on 6/3/24.
//

#include "BaseImage.h"

namespace graphic {

    BaseImage::BaseImage(std::string _extension, std::string _filename) {
        extension = std::move(_extension);
        size_t found_idx = _filename.rfind(extension);
        if (found_idx == std::string::npos) {
            _filename.append(extension);
        }
        filename = std::move(_filename);
    }

}
