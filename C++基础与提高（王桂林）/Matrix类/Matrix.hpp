#pragma once
#include <iostream>
using namespace std;

class Matrix
{
private:
    int data[3][3];

public:
    Matrix(/* args */);
    Matrix(int** p);
    int **operator+(const Matrix &another);
    void operator+=(const Matrix &another);
    int **operator*(const Matrix &another);
    void operator*=(const Matrix &another);
    friend ostream &operator<<(ostream &os, const Matrix &m);
    ~Matrix();
};

Matrix::Matrix(/* args */)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            data[i][j] = 0;
}

Matrix::Matrix(int** p)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            data[i][j] = p[i][j];
}

int **Matrix::operator+(const Matrix &another)
{
    int **tmp = new int *[3];
    for (int i = 0; i < 3; i++)
        tmp[i] = new int[3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tmp[i][j] = data[i][j] + another.data[i][j];

    return tmp;
}

void Matrix::operator+=(const Matrix &another)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            data[i][j] += another.data[i][j];
}
int **Matrix::operator*(const Matrix &another)
{
    int **tmp = new int *[3];
    for (int i = 0; i < 3; i++)
        tmp[i] = new int[3]{0};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                tmp[i][j] += data[i][k] * another.data[k][j];
    return tmp;
}
void Matrix::operator*=(const Matrix &another)
{
    int tmp[3][3]={{0},{0},{0}};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                tmp[i][j] += data[i][k] * another.data[k][j];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            data[i][j] = tmp[i][j];
}

ostream &operator<<(ostream &os, const Matrix &m)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 2)
                os << m.data[i][j] << endl;
            else
                os << m.data[i][j] << " ";
        }
    }
    return os;
}

Matrix::~Matrix()
{
}
