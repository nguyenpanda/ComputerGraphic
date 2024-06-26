//
// Created by Hà Tường Nguyên on 5/25/24.
//

#ifndef COMPUTERGRAPHIC_TESTCASE_H
#define COMPUTERGRAPHIC_TESTCASE_H

// testcase::Image
#include "Image/test_Bitmap.h"

// testcase::Object
#include "Object/test_Circle.h"
#include "Object/test_Line.h"
#include "Object/test_Rectangle.h"

// testcase::Screen
#include "Screen/test_changeAt.h"
#include "Screen/test_draw.h"
#include "Screen/test_operator.h"
#include "Screen/test_plot.h"

// GraphicScreen
#include "../src/GraphicScreen.h"

#include <cmath>
#include <cstdint>

namespace testcase {

    void all();

}

#endif //COMPUTERGRAPHIC_TESTCASE_H
