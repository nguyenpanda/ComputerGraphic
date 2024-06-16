//
// Created by Hà Tường Nguyên on 6/17/24.
//

#include "Orbit.h"

namespace Physic {

    #define pull1 100000
    #define pull2 600000

    Particle_orbit::Particle_orbit(int w, int h) {
        width = w;
        height = h;
        x = w / 2;
        y = h / 2;
        v_x =  80.00001100365;
        v_y = -80.00001100365;
        cal_acc();
    }

    void Particle_orbit::updateState(double _dt) {
        cal_acc();

        v_x = v_x + a_x * _dt;
        v_y = v_y + a_y * _dt;

        x = x + v_x * _dt;
        y = y + v_y * _dt;
    }

    int Particle_orbit::get_x() const {
        return (int) (v_x < 0 ? floor(x) : ceil(x));
    }

    int Particle_orbit::get_y() const {
        return (int) (v_y < 0 ? floor(y) : ceil(y));
    }

    void Particle_orbit::cal_acc() {
        a_x = planet_1(x, y);
        a_y = planet_1(x, y);
        if (x > width / 3) a_x = -a_x;
        if (y > height / 3) a_y = -a_y;

        if (x > 2 * width / 3) a_x -= planet_2(x, y);
        else a_x += planet_2(x, y);

        if (y > 2 * height / 3) a_y -= planet_2(x, y);
        else a_y += planet_2(x, y);
    }

    double Particle_orbit::planet_1(double x, double y) const {
        if (x == width / 3 or y == height / 3) return std::numeric_limits<double>::max();
        return pull1 / (std::pow(width / 3 - x, 2) + std::pow(1.0 * height / 3 - y, 2));
    }

    double Particle_orbit::planet_2(double x, double y) const {
        if (x == 2 * width / 3 or y == 2 * height / 3) return std::numeric_limits<double>::max();
        return pull2 / (std::pow(2 * width / 3 - x, 2) + std::pow(2.0 * height / 3 - y, 2));
    }

    Box_orbit::Box_orbit(int w, int h, int fps) {
        width = w;
        height = h;
        dt = 1.0 / fps;
        scr = new graphic::Screen(w, h);
        p = new Particle_orbit(w, h);
        history = new std::queue<std::pair<int, int> >();

        scr->changeAt(0, 255, 200, w / 3, h / 3);
        scr->changeAt(0, 255, 200, 2 * w / 3, 2 * h / 3);
    }

    Box_orbit::~Box_orbit() {
        delete scr;
        delete p;
        delete history;
    }

    void Box_orbit::update_frame() const {
        int x_now = p->get_x();
        int y_now = p->get_y();
        auto point = std::pair<int, int>(x_now, y_now);

        scr->changeAt(255, 255, 255, x_now, y_now);
        history->push(point);

        p->updateState(dt);
        scr->changeAt(255, 0, 50, p->get_x(), p->get_y());

        std::cout << cursor::preline(width);
        std::cout << scr;

        if (history->size() == 50) {
            auto temp = history->front();
            scr->changeAt(0, 0, 0, temp.first, temp.second);
            history->pop();
        }
    }

    void orbit() {
        std::cout << "Orbit" << std::endl;
        int w = 105;
        int h = 105;
        int fps = 120;
        Box_orbit box(w, h, fps);

        std::cout << cursor::eraseDis(3);

        try {
            while (true) {
                box.update_frame();
                std::this_thread::sleep_for(std::chrono::microseconds(10));
            }
        } catch (std::out_of_range& e) {
            cursor::nextline(h);
            std::cout << color::RED << "SIMULATION END" << color::RESET << std::endl;
        }
    }

}
