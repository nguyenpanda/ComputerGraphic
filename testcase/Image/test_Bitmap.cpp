//
// Created by Hà Tường Nguyên on 6/4/24.
//

#include "test_Bitmap.h"

namespace testcase {

    double distance(int x0, int y0, int x1, int y1) {
        return std::hypot(x0 - x1, y0 - y1);
    }

    void all_bitmap() {
        bitmap0();
        bitmap1();
        bitmap2();
    }

    void bitmap0() {
        int w = 101;
        int h = 101;
        graphic::Screen scr(w, h);

        for (int i = 0; i < 10; i++) {
            scr.drawcircle(w / 2, h / 2, w / 2 - 1 - 4 * i);
        }

        std::cout << color::GREEN << (graphic::Bitmap("bitmap0.bmp") << scr) << color::RESET << std::endl;
    }

    void bitmap1() {
        int w = 401;
        int h = 101;
        graphic::Screen scr(w, h);

        scr.plot(-200, 200, [](int x) {
            return (int) (50 * std::sin(0.2 * x));
        });

        std::cout << color::GREEN << (graphic::Bitmap("bitmap1") << scr) << color::RESET << std::endl;
    }

    void bitmap2() {
        int w = 123;
        int h = 123;
        graphic::Screen scr(w, h);

        for (int j = 0; j < h; j++) {
            for (int i = 0; i < w; i++) {
                scr.pixel(i, j) = graphic::Pixel(2 * i, j, i + j);
            }
        }
        std::cout << color::YELLOW << scr.export_image("bitmap2_0.bmp") << color::RESET << std::endl;

        for (int j = 0; j < h; j++) {
            for (int i = 0; i < w; i++) {
                scr.pixel(i, j) = graphic::Pixel(i + j, 2 * j, i);
            }
        }
        std::cout << color::YELLOW << scr.export_image("bitmap2_1") << color::RESET << std::endl;

        int firstX = w / 3, secondX = 2 * firstX;
        int cenX = w / 2, cenY = h / 2;
        for (int j = 0; j < h; j++) {
            for (int i = 0; i < w; i++) {
                scr.pixel(i, j) = graphic::Pixel((int) (2.5 * distance(i, j, firstX, cenY)),
                                                 (int) (2.5 * distance(i, j, cenX, cenY)),
                                                 (int) (2.5 * distance(i, j, secondX, cenY))
                );
            }
        }
        std::cout << color::YELLOW << (graphic::Bitmap("bitmap2_2") << scr) << color::RESET << std::endl;

    }

}