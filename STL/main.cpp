/*
    HW - STL
    Authors: Joseph Kuhn & John Brescia
    We pledge our honor that we have abided by the Stevens Honor System.
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*
	Cube
	Cylinder
	Sphere (optional)
https://en.wikipedia.org/wiki/STL_(file_format)

 */

class Cube {
private:
    double dimension;

public:
    Cube(double d) : dimension(d){
    }

    void translate(double x, double y, double z) {
        dimension += x;
        dimension += y;
        dimension += z;
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
            myf << "Solid cube" << endl;
            myf << "facet normal";
        }
    }
};

class Cylinder {
private:
    double radius, height;
public:
    Cylinder(double radius, double height) : radius(radius), height(height){
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



int main() {
    Design d;
    double s = 10;
    Cube c(s);
    c.translate(x,y,z);
    // rotate??
    cout << c.volume() << '\n';
    c.write("out.stl"); // how to get all my shapes into the same file
    d.add(c);
    double r = 10, height  = 20;
    Cylinder cyl(r, height);
    d.add(c);
    d.write("test.stl");
}