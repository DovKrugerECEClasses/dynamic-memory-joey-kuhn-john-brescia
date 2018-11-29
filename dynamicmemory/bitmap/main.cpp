/*
    HW - Bitmap
    Authors: Joseph Kuhn & John Brescia
    We pledge our honor that we have abided by the Stevens Honor System.
*/

#include <iostream>
#include "Color.h"
using namespace std;

class Bitmap {
private:
    int length, height;
    //char Bit[20][30];
    char* pixels;
public:
    char operator () (int colum, int row) const {
        return pixels[row * length + colum];
    }

    char& operator () (int colum, int row) {
        return pixels[row * length + colum];
    }

    Bitmap(int length, int height) : length(length), height(height), pixels(new char[length * height]) {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < length; x++) {
                pixels[(x, y)] = 'x';
            }
        }
    }
    /*Bitmap(int length, int height) : length(length), height(height) {
        //char Bit[height][length];
        for (int x = 0; x < height; x++)
        {
            for (int y = 0; y < length; y++)
            {
                Bit[x][y] = ' ';
            }
        }

    }*/

    /*void line(int xstart, int ystart, int xend, int yend, Color color) {
        for (int i = xstart; i <= xend; i++)
        {
        }
    }*/

    void horizLine(int xstart, int xend, int y, Color color) {
        char col = color.whatColor();
        for (int i = xstart; i <= xend; i++)
        {
            pixels[(i, y)] = col;
        }
    }

    void vertLine(int x, int ystart, int yend, Color color) {
        char col = color.whatColor();
        for (int j = ystart; j <= yend; j++)
        {
            pixels[(x, j)] = col;
        }

    }

    void fillRect(int x, int y, int width, int height, Color color) {
        char col = color.whatColor();
        for (int i = y; i <= y + height - 1; i++)
        {
            horizLine(x, x + width - 1, i, color);
        }
    }

    void drawRect(int x, int y, int width, int height, Color color) {
        char col = color.whatColor();
        horizLine(x, x + width - 1, y, color);
        horizLine(x, x + width - 1, y + height - 1, color);
        vertLine(x, y, y + height - 1, color);
        vertLine(x + width - 1, y, y + height - 1, color);
    }

    void ellipse(int x, int y, int width, int height, Color color) {
        char col = color.whatColor();

    }

    friend ostream& operator << (ostream& s, Bitmap b)
    {
        for (int i = 0; i < b.height; i++)
        {
            for (int j = 0; j < b.length; j++)
            {
                s << b.pixels[(j, i)];
            }
            cout << '\n';
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

    //b.line(0, 0, 19, 19, RED);
    //b.line(0, 5, 29, 10, BLUE); //Bresenham algorithm
    //https://en.wikipedia.org/wiki/Bresenham's_line_algorithm

    // https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm
    //TODO: b.line(0,100, 100,50, BLUE); //Wu algorithm
    b.horizLine(0, 20, 19, GREEN); // from x=0 to x=20 at y=19
    //b.vertLine(5, 0, 19, GREEN); // from y = 0 to y=19 at x = 5
    b.fillRect(10, 10, 4, 3, BLACK); // x = 10, y =10 w=4, h=3
    b.drawRect(10, 10, 4, 3, WHITE); // x = 10, y =10 w=4, h=3
    //b.ellipse(15,0, 8, 5, RED);    // ellipse centered at (15,0) w= 8, h=5
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