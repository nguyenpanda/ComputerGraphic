//
// Created by Hà Tường Nguyên on 5/25/24.
//

#ifndef COMPUTERGRAPHIC_COLOR_H
#define COMPUTERGRAPHIC_COLOR_H

#include <string>
#include <cstdint>

class color {
public:
    // @formatter:off
    const static std::string
            RED                 ,
            GREEN               ,
            YELLOW              ,
            BLUE                ,
            MAGENTA             ,
            CYAN                ,
            GREEN_BACKGROUND    ,
            RED_BACKGROUND      ,
            CYAN_BACKGROUND     ,
            YELLOW_BACKGROUND   ,
            MAGENTA_BACKGROUND  ,
            BLUE_BACKGROUND     ,
            RESET               ;
    // @formatter:on

    class fourBit {
    public:
        static std::string get(uint8_t SGR, int color);

        static std::string foreground(int color);
    };

    class eightBit {
    public:
        static std::string foreground(uint8_t color);

        static std::string background(uint8_t color);
    };

    class two4Bit {
    public:
        static std::string foreground(uint8_t r, uint8_t g, uint8_t b);

        static std::string background(uint8_t r, uint8_t g, uint8_t b);
    };
};

void ANSI_bright_color_4bits_info();

void ANSI_color_4bits_info();

#endif //COMPUTERGRAPHIC_COLOR_H
