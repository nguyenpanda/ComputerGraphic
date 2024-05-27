# `Computer Graphic` documents

# Table of contents

<!-- TOC -->
* [`Computer Graphic` documents](#computer-graphic-documents)
* [Table of contents](#table-of-contents)
* [Source code dependency graph](#source-code-dependency-graph)
* [Implementation](#implementation)
  * [Color](#color)
  * [Pixel](#pixel)
  * [Screen](#screen)
<!-- TOC -->

# Source code dependency graph

---
Can be downloaded
and viewed
at [here](https://lucid.app/lucidchart/68a72af9-e53f-4598-a9ff-7f21c41abe66/edit?viewport_loc=-1733%2C-1227%2C5751%2C3140%2C0_0&invitationId=inv_2e2b332c-cd16-4ccb-b0bc-db0f3d715938)
<img alt="Dependency graph" src="image/dependency graph/1.png" title="Dependency graph"/>

# Implementation

## Color
We use [ANSI escape code](https://en.wikipedia.org/wiki/ANSI_escape_code) in other
to display 3-bits and 4-bits of color on the console/terminal window.
In the future, we may use 8-bits.
The table below is the 3-bits and 4-bits of color `ANSI escape code`.


| Color         | ANSI Color   | Color          | ANSI Color   |
|---------------|--------------|----------------|--------------|
| Bright Black  | `\033[1;90m` | Bright Blue    | `\033[1;94m` |
| Bright Red    | `\033[1;91m` | Bright Magenta | `\033[1;95m` |
| Bright Green  | `\033[1;92m` | Bright Cyan    | `\033[1;96m` |
| Bright Yellow | `\033[1;93m` | Bright White   | `\033[1;97m` |


## Pixel

`Pixel` has three `uint8_t` attributes, `r`, `g`, and `b`, which stand for `RED`, `GREEN`, and `BLUE`, respectively.  
```C++
class Pixel {
    uint8_t r, g, b;
};
```

## Screen
