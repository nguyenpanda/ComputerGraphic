//
// Created by Hà Tường Nguyên on 5/31/24.
//

#include "cursor.h"

std::string cursor::up(int n) {
    return "\033[" + std::to_string(n) + "A";
}

std::string cursor::down(int n) {
    return "\033[" + std::to_string(n) + "B";
}

std::string cursor::forward(int n) {
    return "\033[" + std::to_string(n) + "C";
}

std::string cursor::back(int n) {
    return "\033[" + std::to_string(n) + "D";
}

std::string cursor::nextline(int n) {
    return "\033[" + std::to_string(n) + "E";
}

std::string cursor::preline(int n) {
    return "\033[" + std::to_string(n) + "F";
}

std::string cursor::horizonAbs(int n) {
    return "\033[" + std::to_string(n) + "G";
}

std::string cursor::position(int r, int c) {
    return "\033[" + std::to_string(r) + ";" + std::to_string(c) + "H";
}

std::string cursor::eraseDis(int n) {
    return "\033[" + std::to_string(n) + "J";
}

std::string cursor::eraseLine(int n) {
    return "\033[" + std::to_string(n) + "K";
}

std::string cursor::scrollUp(int n) {
    return "\033[" + std::to_string(n) + "S";
}

std::string cursor::scrollDown(int n) {
    return "\033[" + std::to_string(n) + "T";
}
