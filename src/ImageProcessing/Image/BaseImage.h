//
// Created by Hà Tường Nguyên on 6/3/24.
//

#ifndef COMPUTERGRAPHIC_BASEIMAGE_H
#define COMPUTERGRAPHIC_BASEIMAGE_H

#include <iostream>
#include <cstdint>
#include <string>
#include <filesystem>
#include <fstream>

namespace graphic {

    class Screen;

    class BaseImage {
    protected:
        std::string filename;
        std::string extension;

    public:
        BaseImage(std::string _extension, std::string _filename);

        virtual std::string operator<<(const Screen& screen) = 0;

        virtual std::string operator<<(const Screen* screen) = 0;

        virtual Screen& operator>>(Screen& screen) const = 0;

        virtual Screen& operator>>(Screen* screen) const = 0;

    protected:
        virtual std::string to_file(const Screen& screen) = 0;

        [[nodiscard]] virtual Screen& to_screen(Screen& screen) const = 0;
    };

}

#endif //COMPUTERGRAPHIC_BASEIMAGE_H
