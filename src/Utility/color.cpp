//
// Created by Hà Tường Nguyên on 5/27/24.
//

#include "color.h"

// @formatter:off
const std::string color::RED                 = "\033[1;91m";
const std::string color::GREEN               = "\033[1;92m";
const std::string color::YELLOW              = "\033[1;93m";
const std::string color::BLUE                = "\033[1;94m";
const std::string color::MAGENTA             = "\033[1;95m";
const std::string color::CYAN                = "\033[1;96m";
const std::string color::GREEN_BACKGROUND    = "\033[42;97m";
const std::string color::RED_BACKGROUND      = "\033[41;97m";
const std::string color::CYAN_BACKGROUND     = "\033[46;97m";
const std::string color::YELLOW_BACKGROUND   = "\033[43;97m";
const std::string color::MAGENTA_BACKGROUND  = "\033[45;97m";
const std::string color::BLUE_BACKGROUND     = "\033[44;97m";
const std::string color::RESET               = "\033[0m";
// @formatter:on

// color::fourBit
std::string color::fourBit::get(uint8_t SGR, int color) {
    // SGR: Select Graphic Rendition
    return "\033[" + std::to_string(SGR) + ";" + std::to_string(color) + "m";
}

std::string color::fourBit::foreground(int color) {
    return "\033[1;" + std::to_string(color) + "m";
}

// color::eightBit
std::string color::eightBit::foreground(uint8_t color) {
    return "\033[38;5;" + std::to_string(color) + "m";
}

std::string color::eightBit::background(uint8_t color) {
    return "\033[48;5;" + std::to_string(color) + "m";
}

// color::two4Bit
std::string color::two4Bit::foreground(uint8_t r, uint8_t g, uint8_t b) {
    return "\033[38;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b) + "m";
}

std::string color::two4Bit::background(uint8_t r, uint8_t g, uint8_t b) {
    return "\033[48;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b) + "m";
}

//
void ANSI_bright_color_4bits_info() {
    printf("--- \\033[1;<x>m ---");
    int i, j, n;
    for (i = 0; i < 11; i++) {
        for (j = 0; j < 10; j++) {
            n = 10 * i + j;
            if (n > 108) break;
            printf("\033[1;%dm %3d\033[0m", n, n);
        }
        printf("\n");
    }
}

void ANSI_color_4bits_info() {
    printf("--- \\033[<x>m ---");
    int i, j, n;
    for (i = 0; i < 11; i++) {
        for (j = 0; j < 10; j++) {
            n = 10 * i + j;
            if (n > 108) break;
            printf("\033[%dm %3d\033[0m", n, n);
        }
        printf("\n");
    }
}