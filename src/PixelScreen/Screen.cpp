//
// Created by Hà Tường Nguyên on 5/21/24.
//

#include "Screen.h"

namespace graphic {

    Screen::Screen(int width, int height) : width(width), height(height) {
        if (width < 1) throw std::invalid_argument("Screen's width must >= 1, got " + std::to_string(width));
        if (height < 1) throw std::invalid_argument("Screen's height must >= 1, got " + std::to_string(height));

        setting = new ScreenSetting();
        createPixels(width, height);
    }

    Screen::Screen(const Screen &other) {
        copy_image(other);
        copy_setting(other);
    }

    Screen::~Screen() {
        deletePixels();
        delete setting;
    }

    int Screen::getWidth() const {
        return width;
    }

    int Screen::getHeight() const {
        return height;
    }

    ScreenSetting *Screen::setUp() const {
        return setting;
    }

    void Screen::shape(int &_width, int &_height) const {
        _width = width;
        _height = height;
    }

    Screen &Screen::operator=(const Screen &other) {
        if (this == &other) return *this;
        copy(other);
        return *this;
    }

    void Screen::copy(const Screen &other) {
        if (this == &other) return;
        copy_image(other);
        copy_setting(other);
    }

    void Screen::copy_setting(const Screen &other) {
        if (this == &other) return;
        setting = new ScreenSetting(other.setting->map_char,
                                    other.setting->map_func,
                                    other.setting->color_func,
                                    other.setting->ind_func
                );
//        setting = other.setting;
    }

    Pixel Screen::point(int x, int y) const {
        checkRange(x, y);
        return pixels[y][x];
    }

    Pixel &Screen::pixel(int x, int y) {
        checkRange(x, y);
        return pixels[y][x];
    }

    void Screen::resetX(int x) {
        checkRange(x, 1);

        Pixel *temp;
        for (int y = 0; y < height; ++y) {
            temp = &pixels[y][x];
            temp->r = temp->g = temp->b = 0;
        }
    }

    void Screen::resetY(int y) {
        checkRange(1, y);

        Pixel *temp;
        for (int x = 0; x < width; ++x) {
            temp = &pixels[y][x];
            temp->r = temp->g = temp->b = 0;
        }
    }

    void Screen::reset() {
        for (int y = 0; y < height; ++y) {
            resetY(y);
        }
    }

    void Screen::changeAt(const Pixel &pixel, int x, int y) {
        checkRange(x, y);

        Pixel *temp = &pixels[y][x];
        temp->r = pixel.r;
        temp->g = pixel.g;
        temp->b = pixel.b;
    }

    void Screen::changeAt(int color, int x, int y) {
        checkRange(x, y);
        pixels[y][x] = Pixel(color);
    }

    void Screen::changeAt(int r, int g, int b, int x, int y) {
        checkRange(x, y);
        pixels[y][x] = Pixel(r, g, b);
    }

    void Screen::changeAt(const int (&RGB_X_Y)[5]) {
        int x = RGB_X_Y[3];
        int y = RGB_X_Y[4];
        checkRange(x, y);

        pixels[y][x] = Pixel(RGB_X_Y[0], RGB_X_Y[1], RGB_X_Y[2]);
    }

    void Screen::fill(const std::vector<int> &vec) {
        if (vec.size() < width * height)
            throw std::range_error(
                    "Vector's size too small to fill the graphic::Screen object, got " + std::to_string(vec.size())
            );

        for (int j = 0; j < height; ++j) {
            for (int i = 0; i < width; ++i) {
                int value = vec[width * j + i];
                changeAt(value, value, value, i, j);
            }
        }
    }

// File output
    std::string Screen::to_text(const std::string &filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file: " + filename);
        }

        //@formatter:off
        std::string map_char = setting->getMapChar();
        colorfunc color_func = setting->getColorFunc();
        indexfunc index_func = setting->getIndexFunc();
        mapfunc map_func     = MapFunc::std_map;
        //@formatter:on

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                map_func(file, pixels[y][x], map_char, index_func, color_func);
            }
            file << '\n';
        }

        file.close();
        return (std::filesystem::current_path() / filename).string();
    }

// Draw
    void Screen::plot(int xStart, int xEnd, int (*f)(int)) {
        int N = xEnd - xStart + 1;
        std::vector<int> x(N), y(N);

        std::iota(x.begin(), x.end(), 0);
        std::transform(x.begin(), x.end(), y.begin(), [this, xStart, f](int xi) {
            return std::round((this->height - 1) - f(xi + xStart));
        });

        int shift = *std::min_element(y.begin(), y.end());
        std::transform(y.begin(), y.end(), y.begin(), [shift](int &new_y) {
            return new_y - shift;
        });

        for (int i = 1; i < x.size(); ++i) {
            *this << Line(x[i - 1], y[i - 1], x[i], y[i]);
        }
    }

    void Screen::discretePlot(int xStart, int xEnd, int (*f)(int)) {
        int N = xEnd - xStart + 1;
        std::vector<int> x(N), y(N);

        std::iota(x.begin(), x.end(), 0);
        std::transform(x.begin(), x.end(), y.begin(), [this, xStart, f](int xi) {
            return std::round((this->height - 1) - f(xi + xStart));
        });

        int shift = *std::min_element(y.begin(), y.end());
        std::transform(y.begin(), y.end(), y.begin(), [shift](int &new_y) {
            return new_y - shift;
        });

        for (int i = 0; i < N; ++i) {
            changeAt(255, 255, 255, x[i], y[i]); // Example usage of changeAt
        }
    }

// Circle
    void Screen::drawcircle(int x, int y, int r, bool hasCenter) {
        checkRange(x, y);

        if (hasCenter) changeAt(255, 255, 255, x, y);
        try {
            this << Circle(x, y, r);
        } catch (std::invalid_argument &e) {
            std::cerr << e.what() << std::endl;
        }
    }

// Line
    void Screen::drawline(float slope, float intercept) {
        drawline(slope, intercept, 0, width - 1);
    }

    void Screen::drawline(float slope, float intercept, int x_min, int x_max) {
        checkRange(x_min, 1);
        checkRange(x_max, 1);
        int n = x_max - x_min + 1;
        int rangeX[n];
        std::iota(rangeX, rangeX + n, x_min);
        for (auto i: rangeX) {
            std::cout << rangeX[i] << ' ';
        }
        std::cout << std::endl;
    }

    void Screen::drawline(int x0, int y0, int x1, int y1) {
        checkRange(x0, y0);
        checkRange(x1, y1);
        this << Line(x0, y0, x1, y1);
    }

// Rectangle
    void Screen::drawrectangle(int x, int y, int w, int h) {
        checkRange(x, y);
        checkRange(x + w, y + h);
        this << Rectangle(x, y, w, h);
    }

// Private
    void Screen::checkRange(int x, int y) const {
        if (x < 0 or x >= width) throw std::out_of_range("x out of range, got " + std::to_string(x));
        if (y < 0 or y >= height) throw std::out_of_range("y out of range, got " + std::to_string(y));
    }

// Friend
    std::ostream &operator<<(std::ostream &os, const Screen &srn) {
        mapfunc map_func;
        if (dynamic_cast<std::ofstream *>(&os) or dynamic_cast<std::fstream *>(&os)) {
            map_func = MapFunc::std_map;
        } else {
            map_func = srn.setting->getMapFunc();
        }

        std::string map_char = srn.setting->getMapChar();
        colorfunc color_func = srn.setting->getColorFunc();
        indexfunc index_func = srn.setting->getIndexFunc();

        for (int y = 0; y < srn.height; ++y) {
            for (int x = 0; x < srn.width; ++x) {
                map_func(os, srn.pixels[y][x], map_char, index_func, color_func);
            }
            os << color::RESET << '\n';
        }
        return os;
    }

} // graphic