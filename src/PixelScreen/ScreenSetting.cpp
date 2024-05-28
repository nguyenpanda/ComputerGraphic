//
// Created by Hà Tường Nguyên on 5/28/24.
//

#include "ScreenSetting.h"

namespace graphic {

    void MapFunc::mapChar(std::ostream& os, int pixel, const std::string& charSet) {
        int index = static_cast<int>(pixel * charSet.size() / 255);
        if (index < 0) os << ' ';
        else if (index >= charSet.size()) os << '@';
        else os << charSet[index];
        os << ' ';
    }

    void MapFunc::mapCharColor(std::ostream& os, int pixel, const std::string& charSet) {
        int index = static_cast<int>(pixel * charSet.size() / 255);
        if (index < 0) os << ' ';
        else if (index >= charSet.size()) os << "\033[1;94m@\033[0m";
        else os << charSet[index];
        os << ' ';
    }

}

namespace graphic {

    ScreenSetting::ScreenSetting(std::string _mapChar, MapCharFunc _func) {
        map_char = std::move(_mapChar);
        map_func = _func;
    }

    void ScreenSetting::setMapChar(std::string _mapChar) {
        map_char = std::move(_mapChar);
    }

    std::string ScreenSetting::getMapChar() const {
        return map_char;
    }

    void ScreenSetting::setMapFunc(MapCharFunc _func) {
        map_func = _func;
    }

    MapCharFunc ScreenSetting::getMapFunc() const {
        return map_func;
    }

}
