//
// Created by Hà Tường Nguyên on 6/3/24.
//

#ifndef COMPUTERGRAPHIC_BITMAP_H
#define COMPUTERGRAPHIC_BITMAP_H

#include "BaseImage.h"

namespace graphic {

    class Bitmap : public BaseImage {
    private:
        unsigned char header[54] = {
            //@formatter:off
            0x42, 0x4D,             // "BM"
            0, 0, 0, 0,             // __VARIABLE: image size with header
            0x00, 0x00, 0x00, 0x00, // reversed
            0x36, 0x00, 0x00, 0x00, // offset of pixel (position that data is start)
            0x28, 0x00, 0x00, 0x00, // DIB header size
            0, 0, 0, 0,             // __VARIABLE: image width
            0, 0, 0, 0,             // __VARIABLE: image height
            0x01, 0x00,             // color planes
            0x18, 0x00,             // bits per pixel
            0x00, 0x00, 0x00, 0x00, // no compression
            0, 0, 0, 0,             // __VARIABLE: image size excluding header
            0xC4, 0x0E, 0x00, 0x00, // width print resolution ppm
            0xC4, 0x0E, 0x00, 0x00, // height print resolution
            0x00, 0x00, 0x00, 0x00, // number of colors in the palette
            0x00, 0x00, 0x00, 0x00  // important color
            //@formatter:on
        };

    public:
        explicit Bitmap(std::string _filename);

        std::string operator<<(const Screen& screen) override;

        std::string operator<<(const Screen* screen) override;

        std::string operator<<(const Screen*& screen) override;

    private:
        [[nodiscard]] std::string to_file(const Screen& screen) override;

        void fillHeaderVal(int val, int placeHigh);
    };

}

#include "../../PixelScreen/Screen.h"

#endif //COMPUTERGRAPHIC_BITMAP_H
