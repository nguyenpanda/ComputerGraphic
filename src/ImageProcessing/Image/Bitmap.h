//
// Created by Hà Tường Nguyên on 6/3/24.
//

#ifndef COMPUTERGRAPHIC_BITMAP_H
#define COMPUTERGRAPHIC_BITMAP_H

#include "BaseImage.h"

namespace graphic {

    /**
     * @class graphic::Bitmap
     * @brief Specializes BaseImage for bitmap (.bmp) image handling.
     *
     * Extends BaseImage to provide specific functionalities required for handling bitmap images,
     * including reading from and writing to bitmap files.
     */
    class Bitmap : public BaseImage {
    public:

        /**
         * @brief Constructs a Bitmap object.
         * Initializes a bitmap image with a filename, setting the file extension to .bmp.
         * @param _filename The filename for the bitmap image.
         */
        explicit Bitmap(std::string _filename);

        /**
         * @brief Export image data from a Screen object and returns the exported file path.
         * @param screen The Screen object from which image content will be exported into a file.
         * @return A string indicating the path of the exported file.
         */
        std::string operator<<(const Screen& screen) override;

        /**
         * @brief Export image data from a Screen object  using a pointer a pointer and returns the exported file path.
         * @param screen The Screen object from which image content will be exported into a file.
         * @return A string indicating the path of the exported file.
         */
        std::string operator<<(const Screen* screen) override;
        /**
         * @brief Imports image content from a file into a Screen object.
         * @param screen A reference to the Screen object to modify with image data.
         * @return A reference to the modified Screen object.
         */
        Screen& operator>>(Screen& screen) const override;
        /**
         * @brief Imports image content from a file into a Screen object using a pointer.
         * @param screen A pointer to the Screen object to modify with image data.
         * @return A reference to the modified Screen object if the pointer is not null.
         */
        Screen& operator>>(Screen* screen) const override;

    private:

        /**
         * @brief Saves the current state of the screen to a bitmap file.
         * Handles the creation of a BMP file header, calculates padding, and writes pixel data.
         * @param screen The Screen object containing the graphical data to be saved.
         * @return A string containing the path to the saved bitmap file.
         */
        [[nodiscard]] std::string to_file(const Screen& screen) override;

        /**
         * @brief Loads image data from a bitmap file and displays it on the screen.
         * Reads bitmap header and pixel data from a file, then updates the Screen object with this data.
         * @param screen A reference to the Screen where the bitmap image will be displayed.
         * @return A reference to the modified Screen object.
         */
        [[nodiscard]] Screen& to_screen(Screen& screen) const override;

        /**
         * @brief Fills in values in the bitmap file header.
         * @param val The value to be inserted into the header.
         * @param placeHigh The high byte position in the header where the value will be placed.
         * @param header The header array to be modified.
         */
        static void fillHeaderVal(int val, int placeHigh, unsigned char* header);
    };

}

#include "../../PixelScreen/Screen.h"

#endif //COMPUTERGRAPHIC_BITMAP_H
