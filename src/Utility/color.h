//
// Created by Hà Tường Nguyên on 5/25/24.
//

#ifndef COMPUTERGRAPHIC_COLOR_H
#define COMPUTERGRAPHIC_COLOR_H

#include <string>

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
        static std::string get(uint8_t SGR, int color) {
            // SGR: Select Graphic Rendition
            return "\033[" + std::to_string(SGR) + ";" + std::to_string(color) + "m";
        }

        static std::string foreground(int color) {
            return "\033[1;" + std::to_string(color) + "m";
        }
    };

    class eightBit {
    public:
        static std::string foreground(uint8_t color) {
            return "\033[38;5;" + std::to_string(color) + "m";
        }

        static std::string background(uint8_t color) {
            return "\033[48;5;" + std::to_string(color) + "m";
        }
    };

    class two4Bit {
    public:
        static std::string foreground(uint8_t r, uint8_t g, uint8_t b) {
            return "\033[38;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b) + "m";
        }

        static std::string background(uint8_t r, uint8_t g, uint8_t b) {
            return "\033[48;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b) + "m";
        }
    };
};

#endif //COMPUTERGRAPHIC_COLOR_H
