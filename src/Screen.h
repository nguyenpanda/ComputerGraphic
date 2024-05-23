//
// Created by Hà Tường Nguyên on 5/21/24.
//

#ifndef COMPUTERGRAPHIC_SCREEN_H
#define COMPUTERGRAPHIC_SCREEN_H

#include <iostream>
#include <sstream>
#include <cstdint>
#include <fstream>
#include "Pixel.h"
#include "Draw/GraphicObject.h"

namespace graphic {

    class ScreenSetUp {
        friend Screen;
    private:
        std::string mapChar;

    public:
        explicit ScreenSetUp(std::string _mapChar = ".,:;+*?%S#@") {
            this->mapChar = std::move(_mapChar);
        }

        void setMapChar(std::string _mapChar) {
            this->mapChar = std::move(_mapChar);
        }

        [[nodiscard]] std::string getMapChar() const {
            return this->mapChar;
        }
    };

    class Screen {
        friend std::ostream& operator<<(std::ostream& _cout, const Screen& srn);
        friend ScreenSetUp;

    private:
        int width, height;
        Pixel** pixels;
        ScreenSetUp* setting;

    public:
        Screen(int width, int height);

        ~Screen();

        [[nodiscard]] int getWidth() const;

        [[nodiscard]] int getHeight() const;

        void shape(int& _width, int& _height) const;

        [[nodiscard]] ScreenSetUp* setUp() const;

        Screen& operator=(const Screen& other);

        void copy(const Screen& other);

        [[nodiscard]] Pixel point(int x, int y) const;

        Pixel& pixel(int x, int y);

        void resetX(int x);

        void resetY(int y);

        void reset();

        void changeAt(const Pixel& pixel, int x, int y);

        void changeAt(int r, int g, int b, int x, int y);

        void changeAt(const int (&arr)[5]);

        // File
        std::string to_text(const std::string& filename) const;

        // Line
        void drawline(float slope, float intercept);

        void drawline(float slope, float intercept, int x_min, int x_max);

        void drawline(int x0, int y0, int x1, int y1);

    private:
        Pixel** _copy(const Screen& other);

        void checkRange(int x, int y) const;
    };

} // graphic

#endif //COMPUTERGRAPHIC_SCREEN_H
