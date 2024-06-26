[Computer Graphic](https://github.com/nguyenpanda/ComputerGraphic)
======================
---

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

I have always been fascinated by how computer screens work,
computer graphics, and how images are displayed and stored on computers.
This curiosity inspired me to undertake this project.

Currently, my goal for this project is to render images such as circles, lines, and bijective functions,
and then output these images in PNG and BMP formats.
Additionally, the program should be able to read images in JPEG and BMP formats for processing within the code.

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
    * [Export text `.txt` file](#export-text-txt-file)
  * [Animation using `cursor` class](#animation-using-cursor-class)
  * [Import & Export image](#import--export-image)
    * [Bitmap (.bmp)](#bitmap-bmp)
      * [Export bitmap](#export-bitmap)
      * [Import bitmap](#import-bitmap)
      * [Example](#example)
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

<table style="width:100%;">
  <tr>
    <td>
      <img src="docs/image/readme/line.png" alt="Line result">
    </td>
    <td>
      <img src="docs/image/readme/circle.png" alt="Circle result">
    </td>
  </tr>
</table>

### Plotting

In this example, we will plot `f(x) = 0.01*x^3 - 3x` in range `[-16, 16]`.

#### Discrete plot

[//]: # (@formatter:off)
```C++
// Screen::discretePlot(int x_start, int x_end, int (* f)(int))
scr.discretePlot(-16, 16,[](int x) -> int {
    return (int) (std::pow(x, 3) / 100 - 3 * x);
});

std::cout << scr;
```
[//]: # (@formatter:on)

#### Continuous plot

[//]: # (@formatter:off)
```C++
// Screen::plot(int x_start, int x_end, int (* f)(int))
scr.plot(-16, 16,[](int x) -> int {
    return (int) (std::pow(x, 3) / 100 - 3 * x);
});

std::cout << scr;
```
[//]: # (@formatter:on)

<table style="width:100%;">
  <tr>
    <td>
      <img src="docs/image/readme/discreteplot.png" alt="Line result">
    </td>
    <td>
      <img src="docs/image/readme/plot.png" alt="Circle result">
    </td>
  </tr>
</table>

### Export text `.txt` file

[//]: # (@formatter:off)
```C++
graphic::Screen scr(w, 51);

scr.setUp()->setMapChar(graphic::mapchar::std_dot);

scr.plot(0, w - 1,[](int x) -> int {
    return (int) (25 * std::sin(0.2 * (x - 2)));
});

std::cout << scr;

std::ofstream file("write_ofstream0.txt");
file << scr;
file.close();
```
[//]: # (@formatter:on)

<table style="width:100%; text-align:center;">
  <tr>
    <td style="vertical-align:middle;">
      <figure>
        <img src="docs/image/readme/write_ofstream0_terminal.png" alt="Line result" style="max-width:100%; height:auto; min-height: 200px"/>
        <figcaption>Result in Terminal</figcaption>
      </figure>
    </td>
  </tr>
  <tr>
    <td style="vertical-align:middle;">
      <figure>
        <img src="docs/image/readme/write_ofstream0_file.png" alt="Circle result" style="max-width:100%; height:100%; min-height: 200px"/>
        <figcaption>Result in .txt file</figcaption>
      </figure>
    </td>
  </tr>
</table>

## Animation using `cursor` class

This is some example of animating using `curesor` class.
Get more information on usage
at [here](testcase/Screen/test_changeAt.cpp) & [here](test_application/digit_recognizer/Dataset.cpp)

```bash
./ComputerGraphic --tc changeAt
./ComputerGraphic --ta -mnist 199.csv
```

<div style="display: flex; justify-content: space-between;">
  <div style="flex-basis: 48%; text-align: center;">
    <p style="font-weight: bold; font-size: 1.2em; margin-bottom: 10px;">--tc changeAt</p>
    <img src="docs/image/readme/changAt_animation.gif" style="width: 100%; height: auto;" alt="changAt_animation"/>
  </div>
  <div style="flex-basis: 48%; text-align: center;">
    <p style="font-weight: bold; font-size: 1.2em; margin-bottom: 10px;">--ta -mnist 199.csv</p>
    <img src="docs/image/readme/mnist_animation.gif" style="width: 100%; height: auto;" alt="mnist_animation"/>
  </div>
</div>


Additionally, it can be used to simulate physical phenomenons.

```bash
./ComputerGraphic --ta -bouncing
./ComputerGraphic --ta -orbit
```

The left side simulates the motion of a rigid object under gravity with fluid resistance, 
while the right side simulates the motion of an object experiencing only gravitational force.

<div style="display: flex; justify-content: space-between;">
  <div style="flex-basis: 48%;">
    <p style="font-weight: bold; font-size: 1.2em; margin-bottom: 10px;">Bouncing ball</p>
    <img src="docs/image/readme/Collision_animation.gif" style="max-width: 100%; height: auto;" alt="collision"/>
  </div>
  <div style="flex-basis: 48%;">
    <p style="font-weight: bold; font-size: 1.2em; margin-bottom: 10px;">Meteorite's orbit</p>
    <img src="docs/image/readme/Orbit_animation.gif" style="max-width: 100%; height: auto;" alt="orbit"/>
  </div>
</div>


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

#### Example

```C++
graphic::Screen scr;

graphic::Bitmap("Steveeeeeee") >> scr;

int w, h;
scr.shape(w, h);

for (int j = 0; j < h; ++j) {
    for (int i = 0; i < w; ++i) {
        // Set the green component of all pixels to 100
        scr.pixel(i, j).set_g(100); // Similar to red & blue
    }
}

graphic::Bitmap("Emotional Damage_green=100") << scr;
```

<table style="width:100%;">
  <caption style="caption-side: top; text-align: center; font-weight: bold; font-size: 1.2em; margin-bottom: 10px;">
    Bitmap Images from graphic::Bitmap
  </caption>
  <tr>
    <td>
      <figure>
        <img src="docs/image/readme/EmotionalDamage_origin.bmp" alt="EmotionalDamage_origin"/>
        <figcaption>Original Image</figcaption>
      </figure>
    </td>
    <td>
      <figure>
        <img src="docs/image/readme/EmotionalDamage_red=0.bmp" alt="EmotionalDamage_red=0"/>
        <figcaption>Red Channel Removed</figcaption>
      </figure>
    </td>
  </tr>
  <tr>
    <td>
      <figure>
        <img src="docs/image/readme/EmotionalDamage_green=0.bmp" alt="EmotionalDamage_green=0"/>
        <figcaption>Green Channel Removed</figcaption>
      </figure>
    </td>
    <td>
      <figure>
        <img src="docs/image/readme/EmotionalDamage_blue=0.bmp" alt="EmotionalDamage_blue=0"/>
        <figcaption>Blue Channel Removed</figcaption>
      </figure>
    </td>
  </tr>
</table>

# Project implementation

---
Check [DOCS.md](docs/DOCS.md) for more information.

# License

---
**MIT** License (see `LICENSE.txt` file).

# References

---

Check [REFERENCES.md](docs/REFERENCES.md) for more information.