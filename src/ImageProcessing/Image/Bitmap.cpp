//
// Created by Hà Tường Nguyên on 6/3/24.
//

#include "Bitmap.h"

namespace graphic {

    Bitmap::Bitmap(std::string _filename) : BaseImage(".bmp", std::move(_filename)) {}

    std::string Bitmap::operator<<(const Screen& screen) {
        return to_file(screen);
    }

    std::string Bitmap::operator<<(const Screen* screen) {
        return to_file(*screen);
    }

    std::string Bitmap::operator<<(const Screen*& screen) {
        return to_file(*screen);
    }

    Screen& Bitmap::operator>>(Screen& screen) const {
        return to_screen(screen);
    }

    Screen& Bitmap::operator>>(Screen* screen) const {
        return to_screen(*screen);
    }
    
    std::string Bitmap::to_file(const Screen& screen) {
        int w, h;
        screen.shape(w, h);

        int padding = (4 - (3 * w) % 4) % 4;
        int data_size = 3 * w * h + padding * w;
        int total_size = data_size + 54;

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

        fillHeaderVal(total_size, 5, header);
        fillHeaderVal(w, 21, header);
        fillHeaderVal(h, 25, header);
        fillHeaderVal(data_size, 37, header);

        std::ofstream file(filename, std::ios::binary | std::ios::out);
        file.write((char*) header, 54);

        for (int j = h - 1; j > -1; j--) {
            for (int i = 0; i < w; i++) {
                Pixel temp = screen.point(i, j);
                int r = temp.R(), g = temp.G(), b = temp.B();
                file.write((char*) &b, 1);
                file.write((char*) &g, 1);
                file.write((char*) &r, 1);
                if (i == w - 1) {
                    for (int k = 0; k < padding; k++) {
                        file.write((char*) &r, 1);
                    }
                }
            }
        }

        file.close();
        return (std::filesystem::current_path() / filename).string();
    }

    Screen& Bitmap::to_screen(Screen& screen) const {
        std::ifstream file(filename);

        if (!file) {
            throw std::invalid_argument(
                    "Error opening file: " + (std::filesystem::current_path() / filename).string()
            );
        }

        char header_data[54];
        file.read(header_data, 54);

        int width = *((int*) &header_data[18]), height = *((int*) &header_data[22]);
        const int padding = (4 - (3 * width) % 4) % 4;

        screen.resize(width, height);

        char r, g, b, temp;
        for (int j = height - 1; j > -1; --j) {
            for (int i = 0; i < width; ++i) {
                file.read(&b, 1);
                file.read(&g, 1);
                file.read(&r, 1);
                if (i == width - 1) file.read(&temp, padding);
                screen.pixel(i, j).set(r, g, b);
            }
        }

        file.close();
        return screen;
    }

    void Bitmap::fillHeaderVal(int val, int placeHigh, unsigned char* header) {
        header[placeHigh] = ((val & 0xFF000000) >> (6 * 4));
        header[placeHigh - 1] = ((val & 0x00FF0000) >> (4 * 4));
        header[placeHigh - 2] = ((val & 0x0000FF00) >> (2 * 4));
        header[placeHigh - 3] = (val & 0x000000FF);
    }

}
