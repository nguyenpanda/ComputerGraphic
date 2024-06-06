//
// Created by Hà Tường Nguyên on 6/3/24.
//

#ifndef COMPUTERGRAPHIC_BITMAP_H
#define COMPUTERGRAPHIC_BITMAP_H

#include "BaseImage.h"

namespace graphic {

    class Bitmap : public BaseImage {
    public:
        explicit Bitmap(std::string _filename);

        std::string operator<<(const Screen& screen) override;

        std::string operator<<(const Screen* screen) override;

        Screen& operator>>(Screen& screen) const override;

        Screen& operator>>(Screen* screen) const override;

    private:
        [[nodiscard]] std::string to_file(const Screen& screen) override;

        [[nodiscard]] Screen& to_screen(Screen& screen) const override;

        static void fillHeaderVal(int val, int placeHigh, unsigned char* header);
    };

}

#include "../../PixelScreen/Screen.h"

#endif //COMPUTERGRAPHIC_BITMAP_H
