#pragma once
#include <memory>

class Circle
{
private:
    float m_radius;

public:
    static constexpr float PI=3.14;
    Circle(float radius = 0);
    ~Circle();
    float getArea();
    float getPeri();
};

Circle::Circle(float radius) : m_radius(radius)
{
}

Circle::~Circle()
{
}

float Circle::getArea()
{
    return PI * m_radius * m_radius;
}

float Circle::getPeri()
{
    return 2*PI*m_radius;
}

class Cylinder
{
private:
    float m_height;
    Circle* m_circle;

public:
    Cylinder(float height, float radius);
    ~Cylinder();
    float getSurfaceArea();
    float getVolume();
    Circle* getCircle();
};

Cylinder::Cylinder(float height = 0, float radius = 0) : m_height(height),m_circle(new Circle(radius))
{
}

Cylinder::~Cylinder()
{
    if(m_circle)
        delete m_circle;
}

float Cylinder::getSurfaceArea()
{
    return m_circle->getArea()+m_circle->getPeri()*m_height;
}

float Cylinder::getVolume()
{
    return m_circle->getArea()*m_height;
}

Circle* Cylinder::getCircle()
{
    return m_circle;
}
