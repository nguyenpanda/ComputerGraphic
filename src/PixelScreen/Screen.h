//
// Created by Hà Tường Nguyên on 5/21/24.
//

#ifndef COMPUTERGRAPHIC_SCREEN_H
#define COMPUTERGRAPHIC_SCREEN_H

#include "Pixel.h"
#include "ScreenSetting.h"

#include "../Draw/GraphicObject.h"
#include "../ImageProcessing/Image.h"
#include "../Utility/PriorityQueue.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <typeinfo>
#include <cstdint>
#include <numeric>
#include <vector>
#include <algorithm>
#include <filesystem>

namespace graphic {

    class Screen {
        friend std::ostream& operator<<(std::ostream& os, const Screen& srn);

        friend std::ostream& operator<<(std::ostream& os, const Screen* srn);

        friend ScreenSetting;

    private:
        int width, height;
        Pixel** pixels = nullptr;
        ScreenSetting* setting = nullptr;

    public:
        explicit Screen(int width = 1, int height = 1);

        Screen(const Screen& other);

        ~Screen();

        [[nodiscard]] int getWidth() const;

        [[nodiscard]] int getHeight() const;

        void shape(int& _width, int& _height) const;

        [[nodiscard]] ScreenSetting* setUp() const;

        Screen& operator=(const Screen& other);

        void copy(const Screen& other);

        void copy_image(const Screen& other);

        void copy_setting(const Screen& other);

        void resize(int w, int h);

        [[nodiscard]] Pixel point(int x, int y) const;

        Pixel& pixel(int x, int y);

        void resetX(int x);

        void resetY(int y);

        [[maybe_unused]] void reset();

        void changeAt(const Pixel& pixel, int x, int y);

        void changeAt(int color, int x, int y);

        void changeAt(int r, int g, int b, int x, int y);

        void changeAt(const int (& arr)[5]);

        void fill(const std::vector<int>& vec);

        // File
        std::string to_text(const std::string& filename) const; // NOLINT(*-use-nodiscard)

        // Draw
        template<size_t N, size_t M>
        void draw(int (& x)[N], int (& y)[M], size_t startIdx, size_t size) {
            if (N < size) throw std::invalid_argument("Array's size of X < size");
            if (M < size) throw std::invalid_argument("Array's size of Y < size");

            for (size_t i = startIdx; i < size; ++i) {
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

        // Rectangle
        void drawrectangle(int x, int y, int w, int h);

        // Image
        std::string export_image(const std::string& filename) const;

    private:
        void checkRange(int x, int y) const;

        void createPixels(int w, int h);

        void deletePixels();
    };

} // graphic

#endif //COMPUTERGRAPHIC_SCREEN_H
