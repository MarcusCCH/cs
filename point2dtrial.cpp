#include <iostream>
using namespace std;
struct point2d {
    float x, y;
    point2d() {}
    point2d(float x, float y): x(x), y(y) {}
    point2d& operator+=(const point2d &t) {
        x += t.x;
        y += t.y;
        return *this;
    }
    point2d& operator-=(const point2d &t) {
        x -= t.x;
        y -= t.y;
        return *this;
    }
    point2d& operator*=(float t) {
        x *= t;
        y *= t;
        return *this;
    }
    point2d& operator/=(float t) {
        x /= t;
        y /= t;
        return *this;
    }
    point2d operator+(const point2d &t) const {
        return point2d(*this) += t;
    }
    point2d operator-(const point2d &t) const {
        return point2d(*this) -= t;
    }
    point2d operator*(float t) const {
        return point2d(*this) *= t;
    }
    point2d operator/(float t) const {
        return point2d(*this) /= t;
    }
};

int main(){
    point2d a,b;
    a.x = 1,a.y = 2; 
    b.x = 3,b.y = 4;
    a *= 4;
    cout<<a.x<<endl;
    return 0;

}


