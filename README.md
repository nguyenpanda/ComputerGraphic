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

[//]: # (@formatter:off)
<!-- TOC -->
* [Computer Graphic](#computer-graphic)
* [Table of contents](#table-of-contents)
* [Requirements](#requirements)
* [How to install?](#how-to-install)
    * [Default build system](#default-build-system)
    * [Windows GNU Make (MinGW Makefiles)](#windows-gnu-make-mingw-makefiles)
    * [Test run](#test-run)
* [How to use?](#how-to-use)
  * [Creating `graphic::Screen` object](#creating-graphicscreen-object)
  * [Drawing object on `graphic::Screen` object](#drawing-object-on-graphicscreen-object)
    * [Line](#line)
    * [Circle](#circle)
    * [Plotting](#plotting)
      * [Discrete plot](#discrete-plot)
      * [Continuous plot](#continuous-plot)
  * [Import & Export image](#import--export-image)
    * [Bitmap (.bmp)](#bitmap-bmp)
      * [Export bitmap](#export-bitmap)
      * [Import bitmap](#import-bitmap)
* [Project implementation](#project-implementation)
* [License](#license)
* [References](#references)
<!-- TOC -->
[//]: # (@formatter:on)

# Requirements

---

| **Tool**      | **Version** |
|---------------|-------------|
| **C++**       | `>=20`      |
| **CMakeFile** | `>=3.28`    |

# How to install?

---

```bash
git clone "https://github.com/nguyenpanda/ComputerGraphic.git"
cd /path/to/where/you/place/ComputerGraphic
mkdir build cd build
```

Please ensure your computer meets all the requirements listed in the [Requirements](#requirements) section

### Default build system

```bash
cmake ..
make
./ComputerGraphic
```

### Windows GNU Make (MinGW Makefiles)

First, check if you have installed **GNU Make** on your Windows system:

``` bash
make --version
```

You should see output similar to the following:

```
GNU Make 4.4.1
Built for Windows32
Copyright (C) 1988-2023 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
If the above command outputs the version information for **GNU Make**, you can proceed with the following commands:
```

If the above command outputs the version information for GNU Make, you can proceed with the following commands:

``` bash
cmake -G "MinGW Makefiles" ..
make
./ComputerGraphic.exe
```

All the output files created by `int main()` function locate in `build` directory.

### Test run

```bash
./ComputerGraphic --h
./ComputerGraphic --tc all
./ComputerGraphic --ta -mnist ../mnist/199.csv
```

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

## Import & Export image

### Bitmap (.bmp)

#### Export bitmap

```C++
graphic::Bitmap("filename") << scr;
graphic::Bitmap("filename.bmp") << scr;
```

#### Import bitmap

```C++
graphic::Bitmap("filename") >> scr;
graphic::Bitmap("filename.bmp") >> scr;
```

# Project implementation

---
Check [DOCS.md](docs/DOCS.md) for more information.

# License

---
**MIT** License (see `LICENSE.txt` file).

# References

---

Check [REFERENCES.md](docs/REFERENCES.md) for more information.