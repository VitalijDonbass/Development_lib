#pragma once

#include "Point2D.h"

namespace dl
{
    template <typename T>
    class Vector2D {
    public:
        T x;
        T y;

        Vector2D();
        Vector2D(T x, T y);
        Vector2D(Point2D<T> start, Point2D<T> end);
        Vector2D(const Vector2D<T>& other);
        Vector2D<T>& operator=(const Vector2D<T>& other);

        Vector2D<T> operator+(const Vector2D<T>& other) const;
        Vector2D<T> operator-(const Vector2D<T>& other) const;
        Vector2D<T> operator*(const T numb) const;
        Vector2D<T> operator/(const T numb) const;
        Vector2D<T>& operator*=(const T numb);
        Vector2D<T>& operator/=(const T numb);
        Vector2D<T>& operator+=(const Vector2D<T>& other);
        Vector2D<T>& operator-=(const Vector2D<T>& other);

        bool operator==(const Vector2D<T>& other) const;
        bool operator!=(const Vector2D<T>& other) const;
    };

    template <typename T>
    Vector2D<T>::Vector2D() 
        :x(), y() {}

    template <typename T>
    Vector2D<T>::Vector2D(T x, T y) 
        :x(x), y(y) {}

    template <typename T>
    Vector2D<T>::Vector2D(Point2D<T> start, Point2D<T> end) 
        :x(end.x - start.x), y(end.y - start.y) {}

    template <typename T>
    Vector2D<T>::Vector2D(const Vector2D<T>& other) : x(other.x), y(other.y) {}

    template <typename T>
    Vector2D<T>& Vector2D<T>::operator=(const Vector2D<T>& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    template <typename T>
    Vector2D<T> Vector2D<T>::operator+(const Vector2D<T>& other) const {
        return Vector2D<T>(x + other.x, y + other.y);
    }

    template <typename T>
    Vector2D<T> Vector2D<T>::operator-(const Vector2D<T>& other) const {
        return Vector2D<T>(x - other.x, y - other.y);
    }

    template<typename T>
    inline Vector2D<T> Vector2D<T>::operator*(const T numb) const
    {
        return Vector2D<T>(this->x * numb, this->y * numb);
    }

    template<typename T>
    inline Vector2D<T> Vector2D<T>::operator/(const T numb) const
    {
        return Vector2D<T>(this->x / numb, this->y / numb);
    }

    template<typename T>
    inline Vector2D<T>& Vector2D<T>::operator*=(const T numb)
    {
        this->x *= numb;
        this->y *= numb;
        return *this;
    }

    template<typename T>
    inline Vector2D<T>& Vector2D<T>::operator/=(const T numb)
    {
        this->x /= numb;
        this->y /= numb;
        return *this;
    }

    template<typename T>
    inline Vector2D<T>& Vector2D<T>::operator+=(const Vector2D<T>& other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    template<typename T>
    inline Vector2D<T>& Vector2D<T>::operator-=(const Vector2D<T>& other)
    {
        this->x -= other.x;
        this->y -= other.y;
        return *this;
    }

    template <typename T>
    bool Vector2D<T>::operator==(const Vector2D<T>& other) const {
        return x == other.x && y == other.y;
    }

    template <typename T>
    bool Vector2D<T>::operator!=(const Vector2D<T>& other) const {
        return !(*this == other);
    }

    typedef Vector2D<int> Vector2DInt;
    typedef Vector2D<float> Vector2DFloat;
}