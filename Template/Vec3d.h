//
// Created by Joey Kuhn on 11/29/18.
//

#pragma once
#include <iostream>
using namespace std;

template<typename T>

class Vec3d {
private:
    T x, y, z;
public:
    Vec3d(T x, T y, T z) : x(x), y(y), z(z){}

    friend Vec3d operator +(const Vec3d& a, const Vec3d& b) {
        return Vec3d(a.x + b.x, a.y + b.y, a.z + b.z);
    }
    friend ostream& operator <<(ostream& s, const Vec3d& a) {
        return s << "<" << a.x << ", " << a.y << ", " << a.z << ">" << " ";
    }

};