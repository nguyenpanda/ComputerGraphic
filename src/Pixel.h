//
// Created by Hà Tường Nguyên on 5/22/24.
//

#ifndef COMPUTERGRAPHIC_PIXEL_H
#define COMPUTERGRAPHIC_PIXEL_H

#include <cstdint>
#include <ostream>

namespace graphic {

    class Screen;

    class Pixel {
        friend Screen;
        friend std::ostream& operator<<(std::ostream& _cout, const Pixel& pixel);

    private:
        uint8_t r;
        uint8_t g;
        uint8_t b;

    public:
        [[maybe_unused]] Pixel();

        ~Pixel() = default;

        [[maybe_unused]] explicit Pixel(uint8_t _r, uint8_t _g, uint8_t _b);

        Pixel& operator=(const Pixel& other);

        [[nodiscard]] [[maybe_unused]] uint8_t R() const;

        [[nodiscard]] [[maybe_unused]] uint8_t G() const;

        [[nodiscard]] [[maybe_unused]] uint8_t B() const;

        [[maybe_unused]] int gray() const;

        [[maybe_unused]] static Pixel red();

        [[maybe_unused]] static Pixel green();

        [[maybe_unused]] static Pixel yellow();

        [[maybe_unused]] static Pixel blue();

        [[maybe_unused]] static Pixel magenta();

        [[maybe_unused]] static Pixel cyan();

        [[maybe_unused]] static Pixel white();
    };

}

#endif //COMPUTERGRAPHIC_PIXEL_H
