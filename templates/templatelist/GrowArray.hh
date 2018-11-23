#pragma once

#include <iostream>
#include <utility>

template<class T>
class GrowArray {

    int used; // Slots actually being used
    int capacity; // The total capacity of the list
    T *data;

    void checkGrow() {
        if (used == 0) {
            capacity++;
            data = new T[capacity * sizeof(T)];
        }

        if (used <= capacity) {
            used++;
            return; // don't grow unless you have to
        }

        T *old = data;
        capacity *= 2;

        data = new T[capacity * sizeof(T)];
        for (int i = 0; i < used; i++)
            data[i] = old[i];
        // memcpy(data, old, capacity);
        used++;
        delete[] old;
    }

public:
    GrowArray() : used(0), capacity(0), data(nullptr) {}

    GrowArray(int initialCapacity) : used(0), capacity(initialCapacity), data(new T[capacity * sizeof(T)] ) {
    }

    ~GrowArray() { delete[] data; }

    GrowArray(const GrowArray& orig) : capacity(orig.capacity), used(orig.used), data(new T[capacity * sizeof(T)]) {
        for (int i = 0; i < used; i++)
            data[i] = orig.data[i];
    }

    GrowArray& operator =(const GrowArray& orig) {
        GrowArray temp = orig;		// same as GrowArray temp(orig);
        used = temp.used;
        capacity = temp.capacity;
        data = temp.data;
        temp.data = nullptr;
        return *this;
    }

    void addEnd(const T &v) {
        checkGrow();
        data[used - 1] = v;
    }

    T removeEnd() {
        used--;
        return data[used];
    }

    T operator[](int i) const {
        return data[i];
    }

    T &operator[](int i) {
        return data[i];
    }

    friend std::ostream &operator<<(std::ostream &s, const GrowArray<T> &list) {
        for (auto i = 0; i < list.used; i++)
            s << list[i] << ' ';
        return s;
    }

};