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
    * [Bitmap](#bitmap)
<!-- TOC -->
[//]: # (@formatter:on)

# References

---

## ANSI Escape code & Color display

---

[//]: # (@formatter:off)
- [Display 24-bit color using ANSI escape code] [ANSI_1] `src/Utility/color.h`
- [Moving cursor using ANSI escape code]        [ANSI_2] `src/Utility/cursor.h`
- [Grayscale conversion algorithms]             [ANSI_3], _First formula in Method 2_ `src/PixelScreen/Pixel.cpp`

[ANSI_1]: https://en.wikipedia.org/wiki/ANSI_escape_code#24-bit "ANSI escape code 24-bit color"
[ANSI_2]: https://en.wikipedia.org/wiki/ANSI_escape_code#CSI_(Control_Sequence_Introducer)_sequences "ANSI escape code moving cursor"
[ANSI_3]: https://tannerhelland.com/2011/10/01/grayscale-image-algorithm-vb6.html "Method 2"
[//]: # (@formatter:on)

## C++ and Programming skills

---

[//]: # (@formatter:off)
- [Solving circular dependency in C++]    [C++_1]
- [Accessing base class protected member] [C++_2] `src/Utility/PriorityQueue.h`

[C++_1]: https://cplusplus.com/articles/Gw6AC542/ "Solving circular dependency"
[C++_2]: https://stackoverflow.com/questions/69012795/accessing-a-base-class-member-with-accessing-priority-queue-container "Accessing protected attribute"
[//]: # (@formatter:on)

## Drawing specific object

---

[//]: # (@formatter:off)
- [Bresenham's line algorithm] [Object_1] `src/Draw/GraphicObject/Line.cpp`
- [Midpoint circle algorithm]  [Object_2] `src/Draw/GraphicObject/Circle.cpp`

[Object_1]: https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm "Line algorithm"
[Object_2]: https://en.wikipedia.org/wiki/Midpoint_circle_algorithm "Midpoint circle algorithm"
[//]: # (@formatter:on)

## Image

---

Destination: `src/ImageProcessing/Image.h`

### Bitmap

Destination: `src/ImageProcessing/Image/Bitmap.h`

[//]: # (@formatter:off)
- [Bitmap file format - Wiki]                 [bitmap_1]
- [Hexadecimal format of a 3x3 pixel bitmap file](document/BMP_Structure_3x3.pdf) - [RestingKiwi](https://github.com/RestingWiki) (project co-author)
- [How to Make Pictures in C (bitmap images)] [bitmap_2] - Electromechanical Productions
- [BMP-in-C]                                  [bitmap_3] - Electromechanical Productions
- [How Bitmap File Format Works (.bmp)]       [bitmap_4] - Nir Lichtman

[bitmap_1]: https://en.wikipedia.org/wiki/BMP_file_format "Bitmap file format"
[bitmap_2]: https://www.youtube.com/watch?v=CmQoJEOeUT8 "Make Pictures in C"
[bitmap_3]: https://github.com/EmergentComplexity/BMP-in-C "Make Pictures in C github code"
[bitmap_4]: https://www.youtube.com/watch?v=kpHFFFu9qeU "How Bitmap File Format Works (.bmp)"
[//]: # (@formatter:on)