# `Computer Graphic` documents

# Table of contents

<!-- TOC -->
* [`Computer Graphic` documents](#computer-graphic-documents)
* [Table of contents](#table-of-contents)
* [Source code dependency graph](#source-code-dependency-graph)
* [Console display](#console-display)
  * [Color](#color)
  * [Cursor control](#cursor-control)
* [Implementation](#implementation)
  * [Pixel](#pixel)
  * [Screen](#screen)
<!-- TOC -->

# Source code dependency graph

---
Can be downloaded
and viewed
at [here](https://lucid.app/lucidchart/68a72af9-e53f-4598-a9ff-7f21c41abe66/edit?viewport_loc=-1733%2C-1227%2C5751%2C3140%2C0_0&invitationId=inv_2e2b332c-cd16-4ccb-b0bc-db0f3d715938)
<img alt="Dependency graph" src="image/dependency graph/240601.png" title="Dependency graph"/>

# Console display

## Color
We use [ANSI escape code color](https://en.wikipedia.org/wiki/ANSI_escape_code#SGR_(Select_Graphic_Rendition)_parameters) in other
to display 3-bits, 4-bits, 8-bits and 24-bits of color on the console/terminal window.
In the future, we may use 8-bits.
The table below is the 3-bits and 4-bits of color `ANSI escape code`.

Real implement destination: [color.h](../src/Utility/color.h)

Some example for 4-bits color:

| Color         | ANSI Color   | Color          | ANSI Color   |
|---------------|--------------|----------------|--------------|
| Bright Black  | `\033[1;90m` | Bright Blue    | `\033[1;94m` |
| Bright Red    | `\033[1;91m` | Bright Magenta | `\033[1;95m` |
| Bright Green  | `\033[1;92m` | Bright Cyan    | `\033[1;96m` |
| Bright Yellow | `\033[1;93m` | Bright White   | `\033[1;97m` |

## Cursor control
The cursor is manually controlled
by using [ANSI escape code](https://en.wikipedia.org/wiki/ANSI_escape_code#Fe_Escape_sequences).

[//]: # (Real implement destination: [color.h]&#40;../src/Utility/color.h&#41;)

# Implementation

## Pixel

`Pixel` has three `uint8_t` attributes, `r`, `g`, and `b`, which stand for `RED`, `GREEN`, and `BLUE`, respectively.  
```C++
class Pixel {
    uint8_t r, g, b;
};
```

 Real implement destination: [Pixel.h](../src/PixelScreen/Pixel.h), [Pixel.cpp](../src/PixelScreen/Pixel.cpp)

## Screen
