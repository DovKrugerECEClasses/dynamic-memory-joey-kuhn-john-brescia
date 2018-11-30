/*
    HW - Bitmap
    Authors: Joseph Kuhn & John Brescia
    We pledge our honor that we have abided by the Stevens Honor System.
*/

#include <iostream>
#include <cmath>
#include "Color.h"
using namespace std;

class Bitmap {
private:
    int rows, cols;
    char* pixels;
public:
    char operator () (int col, int row) const {
        return pixels[row * cols + col];
    }

    char& operator () (int col, int row) {
        return pixels[row * cols + col];
    }

    Bitmap(int col, int row) : cols(col), rows(row), pixels(new char[rows * cols]) {
        for (int i = 0; i < row * col; i++)
        {
            pixels[i] = ' ';
        }
    }

    void line(int xstart, int ystart, int xend, int yend, Color& color) {
        char colour = color.whatColor();
        double slope = ((double)yend - (double)ystart) / ((double)xend - (double)xstart);
        if (slope == 1 || slope == -1)
        {
            for (int i = ystart; i <= yend; i++)
            {
                for (int j = xstart; j <= xend; j++)
                {
                    if (i == j) {
                        pixels[i * cols + j] = colour;
                    }
                }
            }
        }
        else {
            double error = 2 * ((double)yend - (double)ystart);
            double slopeError = error - ((double)xend - (double)xstart);
            int y = ystart;
            for (int i = xstart; i <= xend; i++)
            {
                pixels[y * cols + i] = colour;
                slopeError += error;
                if (slopeError >= 0)
                {
                    y++;
                    slopeError -= 2 * ((double)xend - (double)xstart);
                }
            }
        }
    }

    void horizLine(int xstart, int xend, int y, Color& color) {
        char colour = color.whatColor();
        for (int i = xstart; i <= xend; i++)
        {
            pixels[y * cols + i] = colour;
        }
    }

    void vertLine(int x, int ystart, int yend, Color& color) {
        char colour = color.whatColor();
        for (int j = ystart; j <= yend; j++)
        {
            pixels[j * cols + x] = colour;
        }

    }

    void fillRect(int x, int y, int width, int height, Color& color) {
        for (int i = y; i <= y + height - 1; i++)
        {
            horizLine(x, x + width - 1, i, color);
        }
    }

    void drawRect(int x, int y, int width, int height, Color& color) {
        horizLine(x, x + width - 1, y, color);
        horizLine(x, x + width - 1, y + height - 1, color);
        vertLine(x, y, y + height - 1, color);
        vertLine(x + width - 1, y, y + height - 1, color);
    }

    friend ostream& operator << (ostream& s, const Bitmap& b)
    {
        for (int i = 0; i < b.rows; i++)
        {
            for (int j = 0; j < b.cols; j++)
            {
                s << b.pixels[i * b.cols + j];
            }
            s << '\n';
        }
        return s;
    }
};

int main() {
    Bitmap b(30, 20); // 30 pixels across, 20 pixels high, each pixel RGBA
    // top left pixel = (0,0)
    Color RED(255,0,0); // all red, no green, no blue (fully opaque)
    Color GREEN(0,255,0);
    Color BLUE(0,0,255);
    Color WHITE(255,255,255);
    Color BLACK(0, 0, 0);

    b.line(0, 0, 19, 19, RED);
    b.line(0, 5, 29, 10, BLUE);
    b.horizLine(0, 20, 19, GREEN); // from x=0 to x=20 at y=19
    b.vertLine(5, 0, 19, GREEN); // from y = 0 to y=19 at x = 5
    b.fillRect(10, 10, 4, 3, BLACK); // x = 10, y =10 w=4, h=3
    b.drawRect(10, 10, 4, 3, WHITE); // x = 10, y =10 w=4, h=3
    cout << b;

/*R
 R
  R
   R
    R
BBB
   BBBBB
        BBBBBB
     */
}