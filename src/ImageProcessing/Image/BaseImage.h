//
// Created by Hà Tường Nguyên on 6/3/24.
//

#ifndef COMPUTERGRAPHIC_BASEIMAGE_H
#define COMPUTERGRAPHIC_BASEIMAGE_H

#include <iostream>
#include <cstdint>
#include <string>
#include <filesystem>
#include <fstream>

namespace graphic {

    class Screen;

    /**
     * @class BaseImage
     * @brief Represents a generic base image class for handling image operations.
     *
     * This abstract class provides a base structure for image manipulation and conversion,
     * supporting operations to and from screen displays, as well as file interactions.
     */
    class BaseImage {
    protected:
        std::string filename;  ///< Filename of the image
        std::string extension; ///< File extension of the image.

    public:
        /**
         * @brief Constructs a BaseImage object with specified file properties.
         * @param _extension File extension of the image.
         * @param _filename Filename of the image.
         */
        BaseImage(std::string _extension, std::string _filename);

        /**
         * @brief Outputs image content to the given Screen object and returns the path to the exported image.
         *
         * This operator should be implemented to take the current state of the image and
         * rendering an image, returning the path to the exported file
         *
         *
         * @param screen A reference to the Screen object.
         * @return The path to the exported file.
         */
        virtual std::string operator<<(const Screen& screen) = 0;

        /**
         * @brief Outputs image content to the given Screen object and returns the path to the exported image.
         *
         * This operator should be implemented to take the current state of the image and
         * rendering an image, returning the path to the exported file.
         *
         * @param screen A pointer to the Screen object.
         * @return The path to the exported file.
         */
        virtual std::string operator<<(const Screen* screen) = 0;

        /**
         * @brief Imports image content into a given Screen object.
         *
         * This operator takes the current state of the image and integrates it onto the provided Screen object.
         * The operation modifies the Screen to reflect the image content, making adjustments based on the image's properties.
         *
         * @param screen A reference to the Screen object to input from.
         * @return A reference to the modified Screen object.
         */
        virtual Screen& operator>>(Screen& screen) const = 0;

        /**
         * @brief Imports image content into a given Screen object pointed to by a pointer.
         *
         * Similar to the reference version, this operator modifies the Screen object to which the pointer points,
         * based on the current state of the image. r
         *
         * @param screen A pointer to the Screen object to input from.
         * @return A reference to the modified Screen object if the pointer is not null. If the pointer is null, behavior should be clearly defined (e.g., throw an exception).
         */
        virtual Screen& operator>>(Screen* screen) const = 0;

    protected:

        /**
         * @brief Converts the image content based on a Screen object into a file.
         *
         * This pure virtual function should be implemented to handle converting the current graphical content
         * displayed on the Screen into a corresponding image file format, specified by the extension attribute of the class.
         *
         * @param screen The Screen object containing the graphical data to be converted.
         * @return A string indicating the filepath where the image file was saved.
         */
        virtual std::string to_file(const Screen& screen) = 0;
        
        /**
         * @brief Renders the image content from a file onto a Screen object.
         *
         * This pure virtual function should be implemented to read the image data from a file and render it onto
         * the provided Screen object. The function must handle file reading, error checking, and pixel manipulation to update
         * the Screen's state accurately based on the image's content.
         *
         * @param screen A reference to the Screen where the image will be rendered.
         * @return A reference to the modified Screen object.
         */
        [[nodiscard]] virtual Screen& to_screen(Screen& screen) const = 0;
    };

}

#endif //COMPUTERGRAPHIC_BASEIMAGE_H
