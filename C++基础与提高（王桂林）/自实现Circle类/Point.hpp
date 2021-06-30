#pragma once
#include <cmath>

class Point
{
private:
    double x;
    double y;
public:
    Point(double x=0,double y=0);
    ~Point();
    friend double dist(const Point& p1, const Point& p2);
};

Point::Point(double x,double y):x(x),y(y)
{
}

Point::~Point()
{
}

double dist(const Point& p1, const Point& p2)
{
    return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}


