#include <iostream>
#include "Circle.hpp"
using namespace std;

int main()
{
    float radius,height;
    cout<<"请输入半径，高："<<endl;
    cin>>radius>>height;

    Cylinder cy(height,radius);
    cout<<"圆的周长："<<cy.getCircle()->getPeri()<<";"
        <<"圆的面积："<<cy.getCircle()->getArea()<<";"
        <<"圆柱的表面积："<<cy.getSurfaceArea()<<";"
        <<"圆柱的体积："<<cy.getVolume()<<".";
    return 0;
}