#include <iostream>
#include "Matrix.hpp"
using namespace std;

int main()
{
    Matrix m;
    cout << "m="
         << "\n"
         << m << endl;

    int **data = new int *[3];
    for (int i = 0; i < 3; i++)
        data[i] = new int[3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            data[i][j] = i * j;
    Matrix m1(data);
    cout << "m1="
         << "\n"
         << m1 << endl;
    int **p = m + m1;
    Matrix m2(p);
    cout << "m2="
         << "\n"
         << m2 << endl;
    int **p1 = m1 * m2;
    Matrix m3(p1);
    cout << "m3="
         << "\n"
         << m3 << endl;
    m3 *= m1;
    cout << "m3="
         << "\n"
         << m3 << endl;

    return 0;
}