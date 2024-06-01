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
        uint8_t r, g, b;

    public:
        [[maybe_unused]] Pixel();

        [[maybe_unused]] Pixel(int color);

        [[maybe_unused]] explicit Pixel(int _r, int _g, int _b);

        ~Pixel() = default;

        Pixel& operator=(const Pixel& other);

        [[nodiscard]] [[maybe_unused]] uint8_t R() const;

        [[nodiscard]] [[maybe_unused]] uint8_t G() const;

        [[nodiscard]] [[maybe_unused]] uint8_t B() const;

        [[nodiscard]] [[maybe_unused]] int gray() const;

        [[maybe_unused]] static Pixel red();

        [[maybe_unused]] static Pixel green();

        [[maybe_unused]] static Pixel yellow();

        [[maybe_unused]] static Pixel blue();

        [[maybe_unused]] static Pixel magenta();

        [[maybe_unused]] static Pixel cyan();

        [[maybe_unused]] static Pixel white();

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
