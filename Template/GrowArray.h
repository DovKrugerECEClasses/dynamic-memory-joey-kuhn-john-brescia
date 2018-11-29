/*
    HW - Template GrowArray
    Authors: Joseph Kuhn & John Brescia
    We pledge our honor that we have abided by the Stevens Honor System.
*/

#pragma once

#include <iostream>

template<typename T>
class GrowArray {
private:
    int used, capacity;
    T* data;
    void checkGrow() {
        if (used < capacity)
            return; // don't grow unless you have to
        T* old = data;
        data = new T [capacity * 2];
        for (int i = 0; i < used; i++)
            data[i] = old[i];
        used++;
    }
public:
    GrowArray() : used(0), capacity(0), data(nullptr) {}
    GrowArray(int initialCapacity)
            : used(0), capacity(initialCapacity), data(new T[capacity]) {
}
    ~GrowArray() {
        delete [] data;
    }

    GrowArray(const GrowArray& orig) : used(orig.used), capacity(orig.capacity), data(new T[capacity]) {
        memcpy(data, orig.data, orig.capacity);
    }

    GrowArray& operator = (const GrowArray& orig) {
        if (this != &orig)
        {
            delete [] data;
            used = orig.used;
            capacity = orig.capacity;
            data = new T[capacity];
            for (int i = 0; i < used; ++i)
            {
                data[i] = orig.data[i];
            }
        }
        return *this;
    }

void addEnd(const T& v) {
    checkGrow();
    data[used - 1] = v;
}

T removeEnd() {
    used--;
    return data[used];
}

T operator [](int i) const {
    return data[i];
}

T& operator [](int i) {
    return data[i];
}

friend std::ostream& operator <<(std::ostream& s, const GrowArray<T>& list) {
    for (int i = 0; i < list.used; i++)
        s << list[i] << ' ';
    return s;
}
};