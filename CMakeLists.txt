cmake_minimum_required(VERSION 3.28)
project(ComputerGraphic)

set(CMAKE_CXX_STANDARD 20)

add_executable(ComputerGraphic
        main.cpp
        main.h

        src/GraphicScreen.h

        src/PixelScreen/Pixel.cpp
        src/Pixel.h

        src/PixelScreen/Screen.cpp
        src/Screen.h

        src/Draw/GraphicObject.h
        src/Draw/Object.h

        src/Draw/GraphicObject/Line.cpp
        src/Draw/Line.h

        src/Draw/GraphicObject/Circle.cpp
        src/Draw/Circle.h
        src/Draw/GraphicObject/Object.cpp
)
