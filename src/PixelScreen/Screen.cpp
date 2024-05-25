//
// Created by Hà Tường Nguyên on 5/21/24.
//

#include "Screen.h"

char mapChar(int pixel, const std::string& charSet) {
    int index = static_cast<int>(pixel * charSet.size() / 255);
    if (index < 0) return ' ';
    if (index >= charSet.size()) return '@';
    return charSet[index];
}

void mapCharColor(int pixel, const std::string& charSet, std::ostream& _cout) {
    int index = static_cast<int>(pixel * charSet.size() / 255);
    if (index < 0) {
        _cout << ' ';
    } else if (index >= charSet.size()) {
        _cout << "\033[1;94m@\033[0m";
    } else {
        _cout << charSet[index];
    }
    _cout << ' ';
}

namespace graphic {

    Screen::Screen(int width, int height) : width(width), height(height) {
        if (width < 1) throw std::invalid_argument("Screen's width must >= 1, got " + std::to_string(width));
        if (height < 1) throw std::invalid_argument("Screen's height must >= 1, got " + std::to_string(height));

        setting = new ScreenSetUp();
        pixels = new Pixel* [height];
        for (int i = 0; i < height; ++i) {
            pixels[i] = new Pixel[width];
            for (int j = 0; j < width; ++j) {
                pixels[i][j] = Pixel();
            }
        }
    }

    Screen::~Screen() {
        for (int i = 0; i < height; ++i) {
            delete[] pixels[i];
        }
        delete[] pixels;
        delete setting;
    }

    int Screen::getWidth() const {
        return width;
    }

    int Screen::getHeight() const {
        return height;
    }

    ScreenSetUp* Screen::setUp() const {
        return setting;
    }

    void Screen::shape(int& _width, int& _height) const {
        _width = width;
        _height = height;
    }

    Screen& Screen::operator=(const Screen& other) {
        if (this == &other) return *this;
        this->_copy(other);
        return *this;
    }

    void Screen::copy(const Screen& other) {
        if (this != &other) this->_copy(other);
    }

    Pixel Screen::point(int x, int y) const {
        checkRange(x, y);
        return pixels[y][x];
    }

    Pixel& Screen::pixel(int x, int y) {
        checkRange(x, y);
        return pixels[y][x];
    }

    void Screen::resetX(int x) {
        checkRange(x, 1);

        Pixel* temp;
        for (int y = 0; y < height; ++y) {
            temp = &pixels[y][x];
            temp->r = temp->g = temp->b = 0;
        }
    }

    void Screen::resetY(int y) {
        checkRange(1, y);

        Pixel* temp;
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

    void Screen::changeAt(const Pixel& pixel, int x, int y) {
        checkRange(x, y);

        Pixel* temp = &pixels[y][x];
        temp->r = pixel.r;
        temp->g = pixel.g;
        temp->b = pixel.b;
    }

    void Screen::changeAt(int r, int g, int b, int x, int y) {
        checkRange(x, y);

        Pixel* temp = &pixels[y][x];
        temp->r = r;
        temp->g = g;
        temp->b = b;
    }

    void Screen::changeAt(const int (& RGB_X_Y)[5]) {
        int x = RGB_X_Y[3];
        int y = RGB_X_Y[4];
        checkRange(x, y);

        Pixel* temp = &pixels[y][x];
        temp->r = RGB_X_Y[0];
        temp->g = RGB_X_Y[1];
        temp->b = RGB_X_Y[2];
    }

// File output
    std::string Screen::to_text(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file: " + filename);
        }

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                file << mapChar(pixels[y][x].gray(), setting->getMapChar()) << ' ';
            }
            file << '\n';
        }

        file.close();
        return std::filesystem::current_path() / filename;
    }

// Draw
    void Screen::plot(int xStart, int xEnd, int (* f)(int)) {
        int N = xEnd - xStart + 1;
        std::vector<int> x(N), y(N);

        std::iota(x.begin(), x.end(), 0);
        std::transform(x.begin(), x.end(), y.begin(), [this, xStart, f](int xi) {
            return std::round((this->height - 1) - f(xi + xStart));
        });

        int shift = *std::min_element(y.begin(), y.end());
        std::transform(y.begin(), y.end(), y.begin(), [shift](int& new_y) {
            return new_y - shift;
        });

        for (int i = 1; i < x.size(); ++i) {
            *this << Line(x[i - 1], y[i - 1], x[i], y[i]);
        }
    }

    void Screen::discretePlot(int xStart, int xEnd, int (* f)(int)) {
        int N = xEnd - xStart + 1;
        std::vector<int> x(N), y(N);

        std::iota(x.begin(), x.end(), 0);
        std::transform(x.begin(), x.end(), y.begin(), [this, xStart, f](int xi) {
            return std::round((this->height - 1) - f(xi + xStart));
        });

        int shift = *std::min_element(y.begin(), y.end());
        std::transform(y.begin(), y.end(), y.begin(), [shift](int& new_y) {
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
        } catch (std::invalid_argument& e) {
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

// Private
    Pixel** Screen::_copy(const Screen& other) {
        if (this == &other) return pixels;

        width = other.width;
        height = other.height;

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                pixels[i][j] = other.pixels[i][j];
            }
        }

        return pixels;
    }

    void Screen::checkRange(int x, int y) const {
        if (x < 0 or x >= width) throw std::out_of_range("x out of range, got " + std::to_string(x));
        if (y < 0 or y >= height) throw std::out_of_range("y out of range, got " + std::to_string(y));
    }

// Friend
    std::ostream& operator<<(std::ostream& _cout, const Screen& srn) {
        for (int y = 0; y < srn.height; ++y) {
            for (int x = 0; x < srn.width; ++x) {
//                _cout << mapChar(srn.pixels[y][x].gray(), srn.setting->getMapChar()) << ' ';
                mapCharColor(srn.pixels[y][x].gray(), srn.setting->getMapChar(), _cout);
            }
            _cout << '\n';
        }
        return _cout;
    }

} // graphic