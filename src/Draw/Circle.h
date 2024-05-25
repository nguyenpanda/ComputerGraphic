//
// Created by Hà Tường Nguyên on 5/24/24.
//

#ifndef COMPUTERGRAPHIC_CIRCLE_H
#define COMPUTERGRAPHIC_CIRCLE_H

#include "Object.h"

namespace graphic {

    class Circle : public Object {
    private:
        int x, y, r;
    };

}

#include "../Screen.h"

#endif //COMPUTERGRAPHIC_CIRCLE_H
