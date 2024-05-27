cmake_minimum_required(VERSION 3.28)
project(ComputerGraphic)

set(CMAKE_CXX_STANDARD 20)

add_executable(ComputerGraphic
        main.cpp
        main.h

        src/GraphicScreen.h

        # Utility
        src/Utility/color.cpp
        src/Utility/color.h

        src/Utility/PriorityQueue.h

        # --- PixelScreen ---
        src/PixelScreen/Pixel.cpp
        src/PixelScreen/Pixel.h

        src/PixelScreen/Screen.cpp
        src/PixelScreen/Screen.h

        # --- Object ---
        src/Draw/GraphicObject.h

        src/Draw/GraphicObject/Object.cpp
        src/Draw/GraphicObject/Object.h

        src/Draw/GraphicObject/Line.cpp
        src/Draw/GraphicObject/Line.h

        src/Draw/GraphicObject/Circle.cpp
        src/Draw/GraphicObject/Circle.h

        # --- Testcase ---
        testcase/testcase.h
        testcase/Object/Line.cpp

)
