# Table of contents

---

[//]: # (@formatter:off)
<!-- TOC -->
* [Table of contents](#table-of-contents)
* [References](#references)
  * [ANSI Escape code & Color display](#ansi-escape-code--color-display)
  * [C++ and Programming skills](#c-and-programming-skills)
  * [Drawing specific object](#drawing-specific-object)
  * [Image](#image)
    * [Bitmap (.BMP)](#bitmap-bmp)
    * [Portable Network Graphics (.PNG)](#portable-network-graphics-png)
    * [Joint Photographic Experts Group (.JPG/.JPEG)](#joint-photographic-experts-group-jpgjpeg)
<!-- TOC -->
[//]: # (@formatter:on)

# References

---

## ANSI Escape code & Color display

---
https://en.wikipedia.org/wiki/RGBA_color_model

[//]: # (@formatter:off)
- [Display 24-bit color using ANSI escape code] [ANSI_1] - Wikipedia `src/Utility/color.h`
- [RGBA 32-bit color]                           [ANSI_2] - Wikipedia                    
- [Moving cursor using ANSI escape code]        [ANSI_3] - Wikipedia `src/Utility/cursor.h`
- [Grayscale conversion algorithms]             [ANSI_4] - Tanner Helland, _First formula in Method 2_ `src/PixelScreen/Pixel.cpp`

[ANSI_1]: https://en.wikipedia.org/wiki/ANSI_escape_code#24-bit "ANSI escape code 24-bit color"
[ANSI_2]: https://en.wikipedia.org/wiki/RGBA_color_model "RGBA color"
[ANSI_3]: https://en.wikipedia.org/wiki/ANSI_escape_code#CSI_(Control_Sequence_Introducer)_sequences "ANSI escape code moving cursor"
[ANSI_4]: https://tannerhelland.com/2011/10/01/grayscale-image-algorithm-vb6.html "Method 2"
[//]: # (@formatter:on)

## C++ and Programming skills

---

[//]: # (@formatter:off)
- [Solving circular dependency in C++]    [C++_1] - Cplusplus
- [Accessing base class protected member] [C++_2] - Stackoverflow `src/Utility/PriorityQueue.h`

[C++_1]: https://cplusplus.com/articles/Gw6AC542/ "Solving circular dependency"
[C++_2]: https://stackoverflow.com/questions/69012795/accessing-a-base-class-member-with-accessing-priority-queue-container "Accessing protected attribute"
[//]: # (@formatter:on)

## Drawing specific object

---

[//]: # (@formatter:off)
- [Bresenham's line algorithm] [Object_1] - Wikipedia `src/Draw/GraphicObject/Line.cpp`
- [Midpoint circle algorithm]  [Object_2] - Wikipedia `src/Draw/GraphicObject/Circle.cpp`
- [Computer Graphics from Scratch: A Programmer's Introduction to 3D Rendering] [Object_3] - 2021 - Gabriel Gambetta

[Object_1]: https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm "Line algorithm"
[Object_2]: https://en.wikipedia.org/wiki/Midpoint_circle_algorithm "Midpoint circle algorithm"
[Object_3]: https://www.google.com.vn/books/edition/Computer_Graphics_from_Scratch/t0UqEAAAQBAJ?hl=en&gbpv=0 "Computer Graphics from Scratch - Gabriel Gambetta"
[//]: # (@formatter:on)

## Image

---

Destination: `src/ImageProcessing/Image.h`

### Bitmap (.BMP)

Destination: `src/ImageProcessing/Image/Bitmap.h`

[//]: # (@formatter:off)
- [Bitmap file format]                        [bitmap_1] - Wikipedia
- [Hexadecimal format of a 3x3 pixel bitmap file](document/BMP_Structure_3x3.pdf) - [RestingKiwi](https://github.com/RestingWiki) (project co-author)
- [How to Make Pictures in C (bitmap images)] [bitmap_2] - Electromechanical Productions
- [BMP-in-C]                                  [bitmap_3] - Electromechanical Productions
- [How Bitmap File Format Works (.bmp)]       [bitmap_4] - Nir Lichtman
- [Bitmap example images]                     [bitmap_5] - University of South Carolina

[bitmap_1]: https://en.wikipedia.org/wiki/BMP_file_format "Bitmap file format"
[bitmap_2]: https://www.youtube.com/watch?v=CmQoJEOeUT8 "Make Pictures in C"
[bitmap_3]: https://github.com/EmergentComplexity/BMP-in-C "Make Pictures in C github code"
[bitmap_4]: https://www.youtube.com/watch?v=kpHFFFu9qeU "How Bitmap File Format Works (.bmp)"
[bitmap_5]: https://people.math.sc.edu/Burkardt/data/bmp/bmp.html "Bitmap example images"
[//]: # (@formatter:on)

### Portable Network Graphics (.PNG)

Destination: `src/ImageProcessing/Image/Png.h`

[//]: # (@formatter:off)
- [Portable Network Graphics (.PNG)]                [png_1] - Wikipedia
- [The world's smallest PNG]                        [png_2] - Evan Hahn
- [PNG (Portable Network Graphics) Specification]   [png_3] - Libpng

[png_1]: https://en.wikipedia.org/wiki/PNG "Png Wiki"
[png_2]: https://evanhahn.com/worlds-smallest-png/ "The world's smallest PNG"
[png_3]: http://www.libpng.org/pub/png/spec/1.2/PNG-Contents.html "PNG (Portable Network Graphics) Specification"
[//]: # (@formatter:on)

### Joint Photographic Experts Group (.JPG/.JPEG)

Destination: `src/ImageProcessing/Image/Jpg.h`

[//]: # (@formatter:off)
- [JPEG]                                                [jpg_1] - Wikipedia
- [PNG & JPG, which is better for machine learning]     [jpg_2] - Stackoverflow

[jpg_1]: https://en.wikipedia.org/wiki/JPEG "JPEG Wiki"
[jpg_2]: https://stats.stackexchange.com/questions/440144/which-image-format-is-better-for-machine-learning-png-jpg-or-other "PNG JPG format, which is better for ML"
[//]: # (@formatter:on)
