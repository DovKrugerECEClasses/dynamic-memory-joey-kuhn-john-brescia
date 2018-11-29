//
// Created by Joey Kuhn on 11/15/18.
//
#include <stdint.h>
#pragma once

class Color {
private:
    uint32_t r,g,b,a;
public:
    Color(uint8_t r, uint8_t g, uint8_t b): r(r), g(g), b(b), a(1) {}
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a):  r(r), g(g), b(b), a(a) {}
    //TODO:	Color(uint8_t r, uint8_t g, uint8_t b, uint8_t alpha) {}
    char whatColor()
    {
        if (this->r == 255 && this->g == 0 && this->b == 0)
        {
            return 'R';
        }
        else if (this->r == 0 && this->g == 255 && this->b == 0)
        {
            return 'G';
        }
        else if (this->r == 0 && this->g == 0 && this->b == 255)
        {
            return 'B';
        }
        else if (this->r == 255 && this->g == 255 && this->b == 255)
        {
            return 'W';
        }
        else if (this->r == 0 && this->g == 0 && this->b == 0)
        {
            return 'b';
        }
    }
};
