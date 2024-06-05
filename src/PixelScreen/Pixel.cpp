//
// Created by Hà Tường Nguyên on 5/22/24.
//

#include "Pixel.h"

namespace graphic {

    Pixel::Pixel() {
        r = g = b = 0;
        a = 255;
    }

    Pixel::Pixel(int color) {
        if (color > 255) color = 255;
        r = color, g = color, b = color;
        a = 255;
    }

    Pixel::Pixel(int _r, int _g, int _b) {
        r = (_r > 255) ? 255 : _r;
        g = (_g > 255) ? 255 : _g;
        b = (_b > 255) ? 255 : _b;
        a = 255;
    }

    Pixel::Pixel(int _r, int _g, int _b, int _a) {
        r = (_r > 255) ? 255 : _r;
        g = (_g > 255) ? 255 : _g;
        b = (_b > 255) ? 255 : _b;
        a = (_a > 255) ? 255 : _a;
    }

    Pixel& Pixel::operator=(const Pixel& other) {
        if (this == &other) return *this;
        r = other.r;
        g = other.g;
        b = other.b;
        a = other.a;
        return *this;
    }

    void Pixel::set(int _r, int _g, int _b) {
        r = _r, g = _g, b = _b;
    }

    void Pixel::set(int _r, int _g, int _b, int _a) {
        r = (_r > 255) ? 255 : _r;
        g = (_g > 255) ? 255 : _g;
        b = (_b > 255) ? 255 : _b;
        a = (_a > 255) ? 255 : _a;
    }

    void Pixel::set_alpha(int _a) {
        a = _a;
    }

    void Pixel::set(int gray_value) {
        r = g = b = gray_value;
    }

    void Pixel::to_gray() {
        set(this->gray());
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

    uint8_t Pixel::A() const {
        return a;
    }

    int Pixel::gray() const {
        return (int) (0.3 * r + 0.59 * g + 0.11 * b);
    }

    Pixel Pixel::red(int _a) {
        return Pixel(255, 0, 0, _a);
    }

    Pixel Pixel::green(int _a) {
        return Pixel(0, 255, 0, _a);
    }

    Pixel Pixel::yellow(int _a) {
        return Pixel(255, 255, 0, _a);
    }

    Pixel Pixel::blue(int _a) {
        return Pixel(0, 0, 255, _a);
    }

    Pixel Pixel::magenta(int _a) {
        return Pixel(255, 0, 255, _a);
    }

    Pixel Pixel::cyan(int _a) {
        return Pixel(0, 255, 255, _a);
    }

    Pixel Pixel::white(int _a) {
        return Pixel(255, 255, 255, _a);
    }

    std::ostream& operator<<(std::ostream& _cout, const Pixel& pixel) {
        _cout << '(' << (int) pixel.r << ", " << (int) pixel.g << ", " << (int) pixel.b << ')';
        return _cout;
    }

}