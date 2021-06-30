#include <iostream>
using namespace std;

class Complex
{
private:
    double real;
    double image;
public:
    Complex(double real,double image);
    Complex(double real);  //类型转化构造函数
    // explicit Complex(const double& real);
    Complex(const Complex& another);
    operator double();
    ~Complex();
    friend ostream& operator<<(ostream& os,const Complex& c);
    Complex operator+(const Complex& another);
};

Complex::Complex(double real,double image) : real(real),image(image)
{
}

Complex::Complex(double real)
{
    this->real = real;
    this->image = 0;
}

Complex::Complex(const Complex& another)
{
    this->real=another.real;
    this->image = another.image;
}

Complex::operator double()
{
    return this->real;
}

Complex::~Complex()
{

}

ostream& operator<<(ostream& os,const Complex& c)
{
    os<<"real+image*i: "<<c.real<<"+"<<c.image<<"*i"<<endl;
    return os;
}

Complex Complex::operator+(const Complex& another)
{
    Complex c(0,0);
    c.real = this->real+another.real;
    c.image = this->image+another.image;
    return c;
}

int main()
{
    Complex c(1,2);
    Complex c2 = c + static_cast<Complex>(2);
    cout<<"c:"<<c<<";c2:"<<c2<<endl;

    Complex c1(1,2);

    double a = 2 + c;
    cout<<"a: "<<a<<endl;
    return 0;
}