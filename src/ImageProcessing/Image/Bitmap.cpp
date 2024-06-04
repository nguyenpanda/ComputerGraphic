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
        screen = to_screen();
        return screen;
    }

    std::string Bitmap::to_file(const Screen& screen) {
        int w, h;
        screen.shape(w, h);

        int padding = (4 - (3 * w) % 4) % 4;
        int data_size = 3 * w * h + padding * w;
        int total_size = data_size + 54;

        fillHeaderVal(total_size, 5);
        fillHeaderVal(w, 21);
        fillHeaderVal(h, 25);
        fillHeaderVal(data_size, 37);

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

    Screen& Bitmap::to_screen() const {
        std::ifstream file(filename);

        if (!file) {
            throw std::invalid_argument(
                    "Error opening file: " + (std::filesystem::current_path() / filename).string()
            );
        }

        char header_data[54];
        file.read(header_data, 54);

        int w = 0, h = 0, count = 0;

        for (int i = 18; i <= 21; ++i) {
            std::cout << (int) header_data[i] << ' ';
            w += header_data[i] * (int) std::pow(16, count);
        } std::cout << std::endl;

        count = 0;

        for (int i = 22; i <= 25; ++i) {
            std::cout << (int) header_data[i] << ' ';
            h += header_data[i] * (int) std::pow(16, count);
        } std::cout << std::endl;

        char temp;
        char r, g, b;
        int padding = (4 - (3 * w) % 4) % 4;

        graphic::Screen scr(w, h);
        for (int j = 0; j < h; ++j) {
            for (int i = 0; i < w; ++i) {
                file.read(&b, 1);
                file.read(&g, 1);
                file.read(&r, 1);
                if (i == w - 1) file.read(&temp, padding);
                scr.pixel(i, j) = graphic::Pixel(r, g, b);
            }
        }

        file.close();
        return scr;
    }

    void Bitmap::fillHeaderVal(int val, int placeHigh) {
        header[placeHigh] = ((val & 0xFF000000) >> (6 * 4));
        header[placeHigh - 1] = ((val & 0x00FF0000) >> (4 * 4));
        header[placeHigh - 2] = ((val & 0x0000FF00) >> (2 * 4));
        header[placeHigh - 3] = (val & 0x000000FF);
    }

}
