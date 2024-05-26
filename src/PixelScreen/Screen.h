//
// Created by Hà Tường Nguyên on 5/21/24.
//

#ifndef COMPUTERGRAPHIC_SCREEN_H
#define COMPUTERGRAPHIC_SCREEN_H

#include <iostream>
#include <sstream>
#include <cstdint>
#include <fstream>
#include <numeric>
#include <vector>
#include "Pixel.h"
#include "../Utility/PriorityQueue.h"
#include "../Draw/GraphicObject.h"

namespace graphic {

    namespace mapchar {
        const std::string std_whitespace = " .,:;+*?%S#@";
        const std::string std_dot = ".,:;+*?%S#@";
        const std::string invert_whitespace = "@#S%?*+;:,. ";
        const std::string invert_dot = "@#S%?*+;:,.";
    }

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

        [[maybe_unused]] void reset();

        void changeAt(const Pixel& pixel, int x, int y);

        void changeAt(int r, int g, int b, int x, int y);

        void changeAt(const int (& arr)[5]);

        // File
        std::string to_text(const std::string& filename) const; // NOLINT(*-use-nodiscard)

        // Draw
        template<size_t N, size_t M>
        void draw(int (& x)[N], int (& y)[M], size_t startIdx, size_t size) {
            if (N < size) throw std::invalid_argument("Array's size of X < size");
            if (M < size) throw std::invalid_argument("Array's size of Y < size");

            for (int i = startIdx; i < size; ++i) {
                changeAt(255, 255, 255, x[i], y[i]);
            }
        }

        void plot(int xStart, int xEnd, int (* f)(int));

        void discretePlot(int xStart, int xEnd, int (* f)(int));

        // Circle
        void drawcircle(int x, int y, int r, bool hasCenter = false);

        // Line
        void drawline(float slope, float intercept);

        void drawline(float slope, float intercept, int xRange, int x_max);

        void drawline(int x0, int y0, int x1, int y1);

    private:
        Pixel** _copy(const Screen& other);

        void checkRange(int x, int y) const;
    };

} // graphic

#endif //COMPUTERGRAPHIC_SCREEN_H
