/*
    HW - STL
    Authors: Joseph Kuhn & John Brescia
    We pledge our honor that we have abided by the Stevens Honor System.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
const double PI = 3.14159265358979;
/*
   Cube
   Cylinder
   Sphere (optional)
https://en.wikipedia.org/wiki/STL_(file_format)

 */

class Cube {
private:
    double dimension, xval, yval, zval;

public:
    Cube(double d) : dimension(d), xval(0), yval(0), zval(0) {
    }

    void translate(double x, double y, double z) {
        xval += x;
        yval += y;
        zval += z;
    }

    double volume(){
        return dimension * dimension * dimension;
    }

    void write(const string& name){
        ofstream myf (name);
        if (myf.fail())
        {
            cerr << "Error opening file" << endl;
            exit(1);
        }
        else
        {
            myf << "solid cube" << endl;
            //FACES TOUCHING ORIGIN
            // FACE 1 (FRONT) checked
            myf << "facet normal 0 -1 -0\n outer loop\n vertex " << xval+0 << " " << yval+0
                << " " << zval+0 << "\n vertex " << xval+dimension << " " << yval+0 << " " << zval+dimension << "\n vertex "
                << xval+dimension << " " << yval+0 << " " << zval+0 << "\n endloop\n endfacet\n";

            myf << "facet normal 0 -1 0\n outer loop\n vertex " << xval+0 << " " << yval+0
                << " " << zval+0 << "\n vertex " << xval+dimension << " " << yval+0 << " " << zval+dimension << "\n vertex "
                << xval+0 << " " << yval+0 << " " << zval+dimension << "\n endloop\n endfacet\n";
            //FACE 2 (LEFT) checked
            myf << "facet normal -1 -0 0\n outer loop\n vertex " << xval+0 << " " << yval+0
                << " " << zval+0 << "\n vertex " << xval+0 << " " << yval+dimension << " " << zval+dimension << "\n vertex "
                << xval+0 << " " << yval+0 << " " << zval+dimension << "\n endloop\n endfacet\n";

            myf << "facet normal -1 0 0\n outer loop\n vertex " << xval+0 << " " << yval+0
                << " " << zval+0 << "\n vertex " << xval+0 << " " << yval+dimension << " " << zval+0 << "\n vertex "
                << xval+0 << " " << yval+dimension << " " << zval+dimension << "\n endloop\n endfacet\n";
            //FACE 3 (BOTTOM) checked
            myf << "facet normal 0 0 -1\n outer loop\n vertex " << xval+0 << " " << yval+0
                << " " << zval+0 << "\n vertex " << xval+dimension << " " << yval+0 << " " << zval+0 << "\n vertex "
                << xval+dimension << " " << yval+dimension << " " << zval+0 << "\n endloop\n endfacet\n";

            myf << "facet normal -0 0 -1\n outer loop\n vertex " << xval+0 << " " << yval+0
                << " " << zval+0 << "\n vertex " << xval+0 << " " << yval+dimension << " " << zval+0 << "\n vertex "
                << xval+dimension << " " << yval+dimension << " " << zval+0 << "\n endloop\n endfacet\n";
            //END FACES TOUCHING ORIGIN

            //FACE 4 (RIGHT) Checked
            myf << "facet normal 1 -0 0\n outer loop\n vertex " << xval+dimension << " " << yval+dimension
                << " " << zval+0 << "\n vertex " << xval+dimension << " " << yval+0 << " " << zval+0 << "\n vertex "
                << xval+dimension << " " << yval+0 << " " << zval+dimension << "\n endloop\n endfacet\n";

            myf << "facet normal 1 0 0\n outer loop\n vertex " << xval+dimension << " " << yval+dimension
                << " " << zval+0 << "\n vertex " << xval+dimension << " " << yval+dimension << " " << zval+dimension << "\n vertex "
                << xval+dimension << " " << yval+0 << " " << zval+dimension << "\n endloop\n endfacet\n";

            //FACE 5 (BACK) checked

            myf << "facet normal 0 1 0\n outer loop\n vertex " << xval+dimension << " " << yval+dimension
                << " " << zval+0 << "\n vertex " << xval+0 << " " << yval+dimension << " " << zval+0 << "\n vertex "
                << xval+0 << " " << yval+dimension << " " << zval+dimension << "\n endloop\n endfacet\n";

            myf << "facet normal 0 1 -0\n outer loop\n vertex " << xval+dimension << " " << yval+dimension
                << " " << zval+0 << "\n vertex " << xval+dimension << " " << yval+dimension << " " << zval+dimension << "\n vertex "
                << xval+0 << " " << yval+dimension << " " << zval+dimension << "\n endloop\n endfacet\n";

            //FACE 6 (TOP) checked
            myf << "facet normal 0 0 1\n outer loop\n vertex " << xval+dimension << " " << yval+0
                << " " << zval+dimension << "\n vertex " << xval+0 << " " << yval+0 << " " << zval+dimension << "\n vertex "
                << xval+0 << " " << yval+dimension << " " << zval+dimension << "\n endloop\n endfacet\n";

            myf << "facet normal 0 -0 1\n outer loop\n vertex " << xval+dimension << " " << yval+0
                << " " << zval+dimension << "\n vertex " << xval+dimension << " " << yval+dimension << " " << zval+dimension << "\n vertex "
                << xval+0 << " " << yval+dimension << " " << zval+dimension << "\n endloop\n endfacet\n";

        }
    }
};
#if 0
class Cylinder { //CENTERED AT ORIGIN
private:
    double radius, height;
public:
    Cylinder(double radius, double height) : radius(radius), height(height) {

    }

    void write(const string &name) {
        double BaseVertices[8][3] = {

                0, radius, 0,
                radius * cos(PI / 4), radius * sin(PI / 4), 0,
                radius, 0, 0,
                radius * cos(PI / 4), -radius * sin(PI / 4), 0,
                0, -radius, 0,
                -radius * cos(PI / 4), -radius * sin(PI / 4), 0
                                                              - radius, 0, 0,
                -radius * cos(PI / 4), radius * sin(PI / 4), 0,


        };
        double TopVertices[8][3];
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 3; y++) {
                if (y == 2) {
                    TopVertices[x][y] = BaseVertices[x][y] + height;
                } else {
                    TopVertices[x][y] = BaseVertices[x][y];
                }

            }
        }
        ofstream myf(name);
        if (myf.fail()) {
            cerr << "Error opening file" << endl;
            exit(1);
        } else {

            myf << "solid cylinder" << endl;
            for (int x = 0; x < 8; x++) {
                for (int y = 0; y < 3; y++) {
                    myf << "facet normal 0 0 1\n outer loop\n";

                    myf << "vertex" << TopVertices[x][y] << " ";


                }
            }
            myf << "\n endloop\n endfacet\n";

//Facets First from bottom
for (int x = 0; x < 8; x++) {
if(x == 1) myf << "facet normal 0.3826834 0.923879 0\n outer loop\n ";
if(x == 2) myf << "facet normal 0.923879 0.3826834 0\n outer loop\n ";
if(x == 3) myf << "facet normal 0.923879 -0.3826834 0\n outer loop\n ";
if(x == 4) myf << "facet normal 0.3826834 -0.923879 0\n outer loop\n ";
if(x == 5) myf << "facet normal -0.3826834 -0.923879 0\n outer loop\n ";
if(x == 6)myf << "facet normal -0.923879 -0.3826834 0\n outer loop\n ";
if(x == 7)myf << "facet normal -0.923879 0.3826834 0\n outer loop\n ";
if(x == 8)myf << "facet normal -0.3826834 0.923879 0\n outer loop\n ";
for (int y = 0; y < 3; y++){

myf << "vertex" << BaseVertices << " "






}

}



"vertex " << xval+0 << " " << yval+0
<< " " << zval+0 << "\n vertex " << xval+dimension << " " << yval+0 << " " << zval+0 << "\n vertex "
<< xval+dimension << " " << yval+dimension << " " << zval+0 << "\n endloop\n endfacet\n";
}








}





};

class Design {
private:

public:

    Design() {

    }

    void add(Cube c)
    {

    }
};

#endif

int main() {
    //Design d;
    double s = 10;
    Cube c(s);
    //c.translate(x,y,z);
    // rotate??
    cout << c.volume() << '\n';
    c.write("out.stl"); // how to get all my shapes into the same file
    //d.add(c);
    double r = 10, height  = 20;
    //  Cylinder cyl(r, height);
    //   cyl.write("out.stl");
    //  d.add(c);
    //  d.write("test.stl");
}