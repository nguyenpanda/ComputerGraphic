//
// Created by Hà Tường Nguyên on 5/22/24.
//

#include "../Pixel.h"

namespace graphic {

    Pixel::Pixel() {
        r = g = b = 0;
    }

    Pixel::Pixel(uint8_t _r, uint8_t _g, uint8_t _b) : r(_r), g(_g), b(_b) {}

    Pixel& Pixel::operator=(const Pixel& other) {
        if (this == &other) return *this;

        r = other.r;
        g = other.g;
        b = other.b;

        return *this;
    }

    uint8_t Pixel::R() const {
        return r;
    }

    uint8_t Pixel::G() const {
        return g;
    }

    uint8_t Pixel::B() const {
        return b;
    }

    int Pixel::gray() const {
        return (int) (0.3 * r + 0.59 * g + 0.11 * b);
    }

    Pixel Pixel::red() {
        return Pixel(255, 0, 0);
    }

    Pixel Pixel::green() {
        return Pixel(0, 255, 0);
    }

    Pixel Pixel::yellow() {
        return Pixel(255, 255, 0);
    }

    Pixel Pixel::blue() {
        return Pixel(0, 0, 255);
    }

    Pixel Pixel::magenta() {
        return Pixel(255, 0, 255);
    }

    Pixel Pixel::cyan() {
        return Pixel(0, 255, 255);
    }

    Pixel Pixel::white() {
        return Pixel(255, 255, 255);
    }

    std::ostream& operator<<(std::ostream& _cout, const Pixel& pixel) {
        _cout << '(' << pixel.r << ", " << pixel.g << ", " << pixel.b << ')';
        return _cout;
    }
}