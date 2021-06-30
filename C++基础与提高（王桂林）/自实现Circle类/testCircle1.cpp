#include <iostream>
#include "Circle1.hpp"
using namespace std;

int main()
{
    double x1,y1,radius1,x2,y2,radius2;
    cout<<"请输入第一个圆的圆心坐标(x,y)和半径：";
    cin>>x1>>y1>>radius1;
    cout<<"请输入第二个圆的圆心坐标(x,y)和半径：";
    cin>>x2>>y2>>radius2;
    Circle1 c1(x1,y1,radius1);
    Circle1 c2(x2,y2,radius2);
    if(isCross(c1,c2))
        cout<<"相交"<<endl;
    else
        cout<<"不相交"<<endl;
    
    return 0;
}