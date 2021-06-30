#include <iostream>
#include "Point.hpp"
using namespace std;

int main()
{
    int x1,x2,y1,y2;
    cout<<"请输入第一个点的坐标(x,y)：";
    cin>>x1>>y1;
    cout<<"请输入第二个点的坐标(x,y)：";
    cin>>x2>>y2;
    Point p1(x1,y1),p2(x2,y2);
    cout<<"两点之间的距离："<<dist(p1,p2);

    return 0;
}