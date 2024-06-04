cmake_minimum_required(VERSION 3.28)
project(ComputerGraphic)

set(CMAKE_CXX_STANDARD 20)

add_executable(ComputerGraphic
        main.cpp
        main.h
        custom_test.h

        src/GraphicScreen.h

        # --- Utility ---
        src/Utility.h

        src/Utility/cursor.cpp
        src/Utility/cursor.h

        src/Utility/color.cpp
        src/Utility/color.h

        src/Utility/performance.cpp
        src/Utility/performance.h

        src/Utility/PriorityQueue.h

        # --- PixelScreen ---
        src/PixelScreen/Pixel.cpp
        src/PixelScreen/Pixel.h

        src/PixelScreen/ScreenSetting.cpp
        src/PixelScreen/ScreenSetting.h

        src/PixelScreen/Screen.cpp
        src/PixelScreen/Screen.h

        ##### Screen::ImageProcessing
        src/ImageProcessing/Image.h

        src/ImageProcessing/Image/BaseImage.cpp
        src/ImageProcessing/Image/BaseImage.h

        src/ImageProcessing/Image/Bitmap.cpp
        src/ImageProcessing/Image/Bitmap.h

        # --- Object ---
        src/Draw/GraphicObject.h

        src/Draw/GraphicObject/Object.cpp
        src/Draw/GraphicObject/Object.h

        src/Draw/GraphicObject/Line.cpp
        src/Draw/GraphicObject/Line.h

        src/Draw/GraphicObject/Circle.cpp
        src/Draw/GraphicObject/Circle.h

        src/Draw/GraphicObject/Rectangle.cpp
        src/Draw/GraphicObject/Rectangle.h

        # --- Test_application
        testcase/testcase.cpp
        test_application/test_application.h

        test_application/digit_recognizer/Dataset.cpp
        test_application/digit_recognizer/Dataset.h

        # --- Testcase ---
        testcase/testcase.h

        ##### testcase::Image
        testcase/Image/test_Bitmap.cpp
        testcase/Image/test_Bitmap.h

        ##### testcase::Object
        testcase/Object/test_Circle.cpp
        testcase/Object/test_Circle.h

        testcase/Object/test_Line.cpp
        testcase/Object/test_Line.h

        testcase/Object/test_Rectangle.cpp
        testcase/Object/test_Rectangle.h

        ##### testcase::Screen
        testcase/Screen/test_changeAt.h
        testcase/Screen/test_changeAt.cpp

        testcase/Screen/test_draw.cpp
        testcase/Screen/test_draw.h

        testcase/Screen/test_operator.cpp
        testcase/Screen/test_operator.h

        testcase/Screen/test_plot.cpp
        testcase/Screen/test_plot.h
        # --- End ---
)
