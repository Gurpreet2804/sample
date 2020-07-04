#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

using namespace std;

class Point
{
    Point(const float x, const float y)
        : x{x},
          y{y}
    {
    }
    float x, y;

public:
    friend std::ostream &operator<<(std::ostream &os, const Point &obj)
    {
        return os
               << "x: " << obj.x
               << " y: " << obj.y;
    }

    static Point NewCartesian(float x, float y)
    {
        return {x, y};
    }

    static Point NewPolar(float r, float theta)
    {
        return {r * cos(theta), r * sin(theta)};
    }
};

int main()
{
    auto p = Point::NewPolar(5, M_PI_4);
    std::cout << p << std::endl;

    getchar();
    return 0;
}