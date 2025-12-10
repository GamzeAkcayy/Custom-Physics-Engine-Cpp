#ifndef VEC2_H
#define VEC2_H

#include <cmath>

struct Vec2 {
    float x, y;

    // Constructor (Kurucu)
    Vec2() : x(0.0f), y(0.0f) {}
    Vec2(float x, float y) : x(x), y(y) {}

    // Operatör Aşırı Yükleme (Vektör Toplama: v1 + v2)
    Vec2 operator+(const Vec2& other) const {
        return Vec2(x + other.x, y + other.y);
    }

    // Skaler Çarpım (Hız * Zaman)
    Vec2 operator*(float scalar) const {
        return Vec2(x * scalar, y * scalar);
    }

    // Vektörün Büyüklüğü (Hızın şiddeti)
    float Magnitude() const {
        return std::sqrt(x * x + y * y);
    }
};

#endif