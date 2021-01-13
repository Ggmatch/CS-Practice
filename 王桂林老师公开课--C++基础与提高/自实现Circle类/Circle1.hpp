#pragma once
#include "Point.hpp"

class Circle1
{
private:
    double m_radius;
    Point* m_point;

public:
    Circle1(double x=0, double y=0, double radius = 0);
    ~Circle1();
    friend bool isCross(const Circle1& c1, const Circle1& c2);
};

Circle1::Circle1(double x, double y, double radius) : m_radius(radius), m_point(new Point(x,y))
{
}

Circle1::~Circle1()
{
    if(m_point)
        delete m_point;
}

bool isCross(const Circle1& c1, const Circle1& c2)
{
    if(dist(*c1.m_point,*c2.m_point)<c1.m_radius+c2.m_radius)
        return true;
    else
        return false;
}