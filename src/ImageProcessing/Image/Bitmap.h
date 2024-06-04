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
            0, 0, 0, 0,             // __VARIABLE [2, 5]: image size with header
            0x00, 0x00, 0x00, 0x00, // reversed
            0x36, 0x00, 0x00, 0x00, // offset of pixel (position that data is start)
            0x28, 0x00, 0x00, 0x00, // DIB header size
            0, 0, 0, 0,             // __VARIABLE [18, 21]: image width
            0, 0, 0, 0,             // __VARIABLE [22, 25]: image height
            0x01, 0x00,             // color planes
            0x18, 0x00,             // bits per pixel
            0x00, 0x00, 0x00, 0x00, // no compression
            0, 0, 0, 0,             // __VARIABLE [34, 37]: image size excluding header
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

        Screen& operator>>(Screen& screen) const override;

    private:
        [[nodiscard]] std::string to_file(const Screen& screen) override;

        [[nodiscard]] Screen& to_screen() const override;

        void fillHeaderVal(int val, int placeHigh);
    };

}

#include "../../PixelScreen/Screen.h"

#endif //COMPUTERGRAPHIC_BITMAP_H
