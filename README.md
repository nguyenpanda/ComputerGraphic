[Computer Graphic](https://github.com/nguyenpanda/ComputerGraphic)
======================
---
I have always been fascinated by how computer screens work,
computer graphics, and how images are displayed and stored on computers.
This curiosity inspired me to undertake this project.

Currently, my goal for this project is to render images such as circles, lines, and bijective functions,
and then output these images in PNG and BMP formats.
Additionally, the program should be able to read images in PNG and BMP formats for processing within the code.

# Table of contents

---

<!-- TOC -->
* [Computer Graphic](#computer-graphic)
* [Table of contents](#table-of-contents)
* [How to install?](#how-to-install)
* [How to use?](#how-to-use)
  * [Creating `graphic::Screen` object](#creating-graphicscreen-object)
  * [Drawing object on `graphic::Screen` object](#drawing-object-on-graphicscreen-object)
    * [Line](#line)
    * [Circle](#circle)
    * [Plotting](#plotting)
      * [Discrete plot](#discrete-plot)
      * [Continuous plot](#continuous-plot)
  * [`testcase.h` header file](#testcaseh-header-file)
* [Requirements](#requirements)
* [Project implementation](#project-implementation)
* [License](#license)
* [References](#references)
<!-- TOC -->

# How to install?

---
```bash
git clone "https://github.com/nguyenpanda/ComputerGraphic.git"
cd /path/to/where/you/place/ComputerGraphic
mkdir build cd build
```

Please ensure your computer meets all the requirements listed in the [Requirements](#requirements) section
```bash
cmake ..
make
./ComputerGraphic
```

All the output files created by `int main()` function locate in `build` directory.

# How to use?

---

## Creating `graphic::Screen` object

Initially, we must create `graphic::Screen` object.

```C++
// graphic::Screen(int width, int height)
graphic::Screen scr(w, h);
int width, height;
scr.shape(width, height); // Getting the `scr` shape
```

## Drawing object on `graphic::Screen` object

### Line

```C++
// graphic::Line(int x0, int y0, int x1, int y1)
scr << graphic::Line(27, 17, 11, 27);   // Directly draw
// scr::drawline(int x0, int y0, int x1, int y1)
scr.drawline(1, 1, 11, 5);              // Recommence using this way
std::cout << scr;                       // Print the screen onto console/terminal
scr.reset();                            // Reset all Pixel
```

### Circle

```C++
// graphic::Circle(int x, int y, int r)
scr << graphic::Circle(25, 25, 15);
// graphic::drawcircle(int x, int y, int r)
scr.drawcircle(25, 17, 5);
scr.drawcircle(17, 25, 5);
scr.drawcircle(25, 33, 5);
scr.drawcircle(33, 25, 5);
scr.drawcircle(3, 3, 1);
scr.drawcircle(8, 8, 0);
std::cout << scr;
```

### Plotting

In this example, we will plot `f(x) = 0.01*x^3 - 3x` in range `[-16, 16]`.

#### Discrete plot

```C++
// Screen::discretePlot(int x_start, int x_end, int (* f)(int))
scr.discretePlot(-16, 16,[](int x) -> int {
return (int) (std::pow(x, 3) / 100 - 3 * x);
});

std::cout << scr;
```

#### Continuous plot

```C++
// Screen::plot(int x_start, int x_end, int (* f)(int))
scr.plot(-16, 16,[](int x) -> int {
return (int) (std::pow(x, 3) / 100 - 3 * x);
});

std::cout << scr;
```

## `testcase.h` header file

```C++
#include "testcase/testcase.h"

int main() {
    testcase::change_at0();
    testcase::change_at1();
    testcase::change_at2(100, 100);

    testcase::draw0();
    testcase::draw1(33, 42, -16, 33);
    testcase::draw2();

    testcase::plot0();
    testcase::plot1(72, 90, -33, 33);
}

```

# Requirements

---

| **Tool**      | **Version** |
|---------------|-------------|
| **C++**       | `>=20`      |
| **CMakeFile** | `>=3.28`    |

# Project implementation

---
  Check [DOCS.md](docs/DOCS.md) for more information.


# License

---
**MIT** License (see `LICENSE.txt` file).

# References

---

- [Solving circular dependency]                            [1]
- [Bitmap file format]                                     [2]
- [Display color on the console using ANSI escape code]    [3] 
- [Grayscale conversion algorithms]                        [4], _First formula in Method 2_ `src/PixelScreen/Pixel.cpp`
- [Bresenham's line algorithm]                             [5] `src/Draw/GraphicObject/Line.cpp`
- [Midpoint circle algorithm]                              [6] `src/Draw/GraphicObject/Circle.cpp`
- [Accessing base class protected member]                  [7] `src/Utility/PriorityQueue.h`

[1]: https://cplusplus.com/articles/Gw6AC542/ "Solving circular dependency"
[2]: https://en.wikipedia.org/wiki/BMP_file_format "Bitmap file format"
[3]: https://en.wikipedia.org/wiki/ANSI_escape_code "ANSI escape code"
[4]: https://tannerhelland.com/2011/10/01/grayscale-image-algorithm-vb6.html "Method 2"
[5]: https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm "Line algorithm"
[6]: https://en.wikipedia.org/wiki/Midpoint_circle_algorithm "Midpoint circle algorithm"
[7]: https://stackoverflow.com/questions/69012795/accessing-a-base-class-member-with-accessing-priority-queue-container "Accessing protected attribute"
