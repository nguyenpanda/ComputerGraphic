//
// Created by Hà Tường Nguyên on 5/31/24.
//

#ifndef COMPUTERGRAPHIC_CURSOR_H
#define COMPUTERGRAPHIC_CURSOR_H

#include <string>
#include <cstdint>

class cursor {
public:
    //@formatter:off
    static std::string up(int n);
    static std::string down(int n);
    static std::string forward(int n);
    static std::string back(int n);
    static std::string nextline(int n);
    static std::string preline(int n);
    static std::string horizonAbs(int n);
    static std::string position(int r, int c);
    static std::string eraseDis(int n);
    static std::string eraseLine(int n);
    static std::string scrollUp(int n);
    static std::string scrollDown(int n);
    //@formatter:on
};

#endif //COMPUTERGRAPHIC_CURSOR_H
