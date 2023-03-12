#pragma once

namespace dl
{
    template <typename T>
    class Point2D {
    public:
        T x;
        T y;

        Point2D();
        Point2D(T x, T y);
        Point2D(const Point2D<T>& other);
        Point2D<T>& operator=(const Point2D<T>& other);
        bool operator==(const Point2D<T>& other) const;
        bool operator!=(const Point2D<T>& other) const;
    };

    template <typename T>
    Point2D<T>::Point2D() 
        :x(), y() {}

    template <typename T>
    Point2D<T>::Point2D(T x, T y) 
        :x(x), y(y) {}

    template <typename T>
    Point2D<T>::Point2D(const Point2D<T>& other) 
        :x(other.x), y(other.y) {}

    template <typename T>
    Point2D<T>& Point2D<T>::operator=(const Point2D<T>& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    template <typename T>
    bool Point2D<T>::operator==(const Point2D<T>& other) const {
        return x == other.x && y == other.y;
    }

    template <typename T>
    bool Point2D<T>::operator!=(const Point2D<T>& other) const {
        return !(*this == other);
    }

    typedef Point2D<int> Point2DInt;
    typedef Point2D<float> Point2DFloat;
}