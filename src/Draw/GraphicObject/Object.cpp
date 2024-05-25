//
// Created by Hà Tường Nguyên on 5/25/24.
//

#include "Object.h"

namespace graphic {
    Screen& Object::operator>>(Screen& screen) const {
        return displayOn(screen);
    }

    Screen& Object::operator>>(Screen* screen) const {
        return displayOn(*screen);
    }

    Screen& Object::operator>>(Screen*& screen) const {
        return displayOn(*screen);
    }
}
