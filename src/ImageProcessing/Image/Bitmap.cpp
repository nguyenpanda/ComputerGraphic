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

    void Bitmap::fillHeaderVal(int val, int placeHigh) {
        header[placeHigh] = ((val & 0xFF000000) >> (6 * 4));
        header[placeHigh - 1] = ((val & 0x00FF0000) >> (4 * 4));
        header[placeHigh - 2] = ((val & 0x0000FF00) >> (2 * 4));
        header[placeHigh - 3] = (val & 0x000000FF);
    }

}
