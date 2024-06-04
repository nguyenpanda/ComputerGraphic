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
        bitmap3();
    }

    void bitmap0() {
        std::cout << color::YELLOW << "testcase::bitmap 0" << color::RESET << std::endl;
        int w = 101;
        int h = 101;
        graphic::Screen scr(w, h);

        std::cout << "------------------" << std::endl;

        for (int i = 0; i < 10; i++) {
            scr.drawcircle(w / 2, h / 2, w / 2 - 1 - 4 * i);
        }

        std::cout << color::GREEN << (graphic::Bitmap("bitmap0.bmp") << scr) << color::RESET << std::endl;
    }

    void bitmap1() {
        std::cout << color::YELLOW << "testcase::bitmap 1" << color::RESET << std::endl;
        int w = 401;
        int h = 101;
        graphic::Screen scr(w, h);
        std::cout << "------------------" << std::endl;

        scr.plot(-200, 200, [](int x) {
            return (int) (50 * std::sin(0.2 * x));
        });

        std::cout << color::GREEN << (graphic::Bitmap("bitmap1") << scr) << color::RESET << std::endl;
    }

    void bitmap2() {
        std::cout << color::YELLOW << "testcase::bitmap 2" << color::RESET << std::endl;
        int w = 123;
        int h = 123;
        graphic::Screen scr(w, h);
        std::cout << "------------------" << std::endl;

        for (int j = 0; j < h; j++) {
            for (int i = 0; i < w; i++) {
                scr.pixel(i, j) = graphic::Pixel(2 * i, j, i + j);
            }
        }
        std::cout << color::GREEN << scr.export_image("bitmap2_0.bmp") << color::RESET << std::endl;

        for (int j = 0; j < h; j++) {
            for (int i = 0; i < w; i++) {
                scr.pixel(i, j) = graphic::Pixel(i + j, 2 * j, i);
            }
        }
        std::cout << color::GREEN << scr.export_image("bitmap2_1") << color::RESET << std::endl;

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
        std::cout << color::GREEN << (graphic::Bitmap("bitmap2_2.text") << scr) << color::RESET << std::endl;
    }

    void bitmap3() {
        std::cout << color::YELLOW << "testcase::bitmap 3" << color::RESET << std::endl;
        int w = 3001, h = 3001;
        int cenX = w / 2, cenY = h / 2;
        int edge = 701;

        int point1_x = cenX, point1_y = cenY - (int) (std::sqrt(3) * edge / 3);
        int point2_x = cenX - edge / 2, point2_y = cenY + (int) (std::sqrt(3) * edge / 6);
        int point3_x = cenX + edge / 2, point3_y = cenY + (int) (std::sqrt(3) * edge / 6);

        graphic::Screen scr(w, h);
        std::cout << "------------------" << std::endl;

        for (int j = 0; j < h; j++) {
            for (int i = 0; i < w; i++) {
                scr.changeAt((int) (0.15 * distance(i, j, point1_x, point1_y)),
                             (int) (0.15 * distance(i, j, point2_x, point2_y)),
                             (int) (0.15 * distance(i, j, point3_x, point3_y)),
                             i, j);
            }
        }

        std::cout << color::GREEN << (graphic::Bitmap("bitmap3_0") << scr) << color::RESET << std::endl;
    }

}