//
// Created by Hà Tường Nguyên on 5/28/24.
//

#include "ScreenSetting.h"

namespace graphic {

    void MapFunc::std_map(std::ostream& os, const Pixel& pixel, const std::string& charSet,
                          indexfunc _ifunc, colorfunc _cfunc) {
        int index = static_cast<int>(pixel.gray() * (charSet.size() - 1) / 255);
        os << charSet[index] << ' ';
    }

    void MapFunc::blue_if_out(std::ostream& os, const Pixel& pixel, const std::string& charSet,
                              indexfunc _ifunc, colorfunc _cfunc) {
        int index = (int) std::floor(pixel.gray() * charSet.size() / 255);
        if (index < 0) os << ' ';
        else if (index >= charSet.size()) os << "\033[1;94m@\033[0m";
        else os << charSet[index];
        os << ' ';
    }

    void MapFunc::two4_bit(std::ostream& os, const Pixel& pixel, const std::string& charSet,
                           indexfunc _ifunc, colorfunc _cfunc) {
        os << _cfunc(pixel.R(), pixel.G(), pixel.B());
        int index = static_cast<int>(pixel.gray() * (charSet.size() - 1) / 255);
        os << charSet[index] << ' ';
    }

    void MapFunc::gray_scale(std::ostream& os, const Pixel& pixel, const std::string& charSet,
                             indexfunc _ifunc, colorfunc _cfunc) {
        os << _cfunc(pixel.R(), pixel.G(), pixel.B());
        int index = _ifunc(pixel.gray(), charSet);
        os << charSet[index] << ' ';
    }

    void MapFunc::no_char(std::ostream& os, const graphic::Pixel& pixel, const std::string& charSet,
                          graphic::indexfunc _ifunc, graphic::colorfunc _cfunc) {
        os << _cfunc(pixel.R(), pixel.G(), pixel.B());
        os << ' ';
    }

}

namespace graphic {

    int IndexFunc::linear(int pixel, const std::string& charSet) {
        return static_cast<int>(pixel * (charSet.size() - 1) / 255);
    }

}

namespace graphic {

    ScreenSetting::ScreenSetting(std::string _mapChar, mapfunc _func, colorfunc _cfunc, indexfunc _ifunc) {
        map_char = std::move(_mapChar);
        map_func = _func;
        color_func = _cfunc;
        ind_func = _ifunc;
    }

    void ScreenSetting::setMapChar(std::string _mapChar) {
        map_char = std::move(_mapChar);
    }

    std::string ScreenSetting::getMapChar() const {
        return map_char;
    }

    void ScreenSetting::setMapFunc(mapfunc _func) {
        map_func = _func;
    }

    mapfunc ScreenSetting::getMapFunc() const {
        return map_func;
    }

    void ScreenSetting::setColorFunc(colorfunc _cfunc) {
        color_func = _cfunc;
    }

    colorfunc ScreenSetting::getColorFunc() const {
        return color_func;
    }

    void ScreenSetting::setIndexFunc(indexfunc _ifunc) {
        ind_func = _ifunc;
    }

    indexfunc ScreenSetting::getIndexFunc() const {
        return ind_func;
    }
}
