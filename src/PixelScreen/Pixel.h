//
// Created by Hà Tường Nguyên on 5/22/24.
//

#ifndef COMPUTERGRAPHIC_PIXEL_H
#define COMPUTERGRAPHIC_PIXEL_H

#include "../Utility/color.h"
#include <cstdint>
#include <ostream>

namespace graphic {

    class Screen;

    class Pixel {

        friend Screen;

        friend std::ostream& operator<<(std::ostream& _cout, const Pixel& pixel);

    private:
        uint8_t r, g, b, a;

    public:
        [[maybe_unused]] Pixel();

        [[maybe_unused]] explicit Pixel(int color);

        [[maybe_unused]] explicit Pixel(int _r, int _g, int _b);

        [[maybe_unused]] explicit Pixel(int _r, int _g, int _b, int _a);

        ~Pixel() = default;

        Pixel& operator=(const Pixel& other);

        void set(int _r, int _g, int _b);

        void set(int _r, int _g, int _b, int _a);

        void set(int gray_value);

        void set_r(int _r);

        void set_g(int _g);

        void set_b(int _b);

        void set_alpha(int _a);

        void to_gray();

        [[nodiscard]] [[maybe_unused]] uint8_t R() const;

        [[nodiscard]] [[maybe_unused]] uint8_t G() const;

        [[nodiscard]] [[maybe_unused]] uint8_t B() const;

        [[nodiscard]] [[maybe_unused]] uint8_t A() const;

        [[nodiscard]] [[maybe_unused]] int gray() const;

        [[maybe_unused]] static Pixel red(int _a = 255);

        [[maybe_unused]] static Pixel green(int _a = 255);

        [[maybe_unused]] static Pixel yellow(int _a = 255);

        [[maybe_unused]] static Pixel blue(int _a = 255);

        [[maybe_unused]] static Pixel magenta(int _a = 255);

        [[maybe_unused]] static Pixel cyan(int _a = 255);

        [[maybe_unused]] static Pixel white(int _a = 255);

        struct Compare {
            struct Less {
                bool operator()(Pixel& lhs, Pixel& rhs) { return lhs.gray() < rhs.gray(); }
            };

            struct Greater {
                bool operator()(Pixel& lhs, Pixel& rhs) { return lhs.gray() > rhs.gray(); }
            };
        };

    };

}

#endif //COMPUTERGRAPHIC_PIXEL_H
