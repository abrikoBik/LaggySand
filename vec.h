#pragma once
#include<math.h>

class Vector2D {
public:

    float x,y;

    Vector2D() : x(0), y(0) {}
    Vector2D(float value) : x(value), y(value) {}
    Vector2D(float x, float y) : x(x), y(y) {}

    float length() { return sqrt(x * x + y * y); }

    Vector2D operator+(const Vector2D& v2) const {
        return Vector2D(x + v2.x, y + v2.y);
    }

    friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2) {
        v1.x += v2.x;
        v1.y += v2.y;
        return v1;
    }

    Vector2D operator*(float scalar) {
        return Vector2D(x * scalar, y * scalar);
    }

    Vector2D& operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vector2D operator-(const Vector2D& v2) const {
        return Vector2D(x - v2.x, y - v2.y);
    }
    friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2) {
        v1.x -= v2.x;
        v1.y -= v2.y;
        return v1;
    }

    Vector2D operator/(float scalar) {
        return Vector2D(x / scalar, y / scalar);
    }
    Vector2D& operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    friend bool operator!=(Vector2D& v1, const Vector2D& v2) {
        return (v1.x != v2.x) && (v1.y != v2.y);
    }
    friend bool operator==(Vector2D& v1, const Vector2D& v2) {
        return (v1.x == v2.x) && (v1.y == v2.y);
    }

    void normalize() {
        float l = length();
        if (l > 0) {
            (*this) *= 1 / l;
        }
    }
};