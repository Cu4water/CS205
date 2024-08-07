#include"complex.hpp"
Complex::Complex(double real,double imag=0)
{
    real_=real;
    imag_=imag;
}
Complex::Complex(Complex &a)
{
    real_=a.real_;
    imag_=a.imag_;
    //used++;
}

Complex Complex::add(Complex b)
{
    this->real_+=b.real_;
    this->imag_+=b.imag_;
    return *this;
}
Complex Complex::sub(Complex b)
{
    this->real_-=b.real_;
    this->imag_-=b.imag_;
    return *this;
}
void Complex::print()
{
    if(imag_==0)
    {
        std::cout<<real_<<std::endl;
        return ;
    }
    char c='+';
    if(imag_<0) c='-';
    std::cout<<real_<<' '<<c<<' '<<imag_<<'i'<<std::endl;
    return;
}

Complex operator+(Complex a,Complex b)
{
    return Complex(a.real_+b.real_, a.imag_+b.imag_);
}
Complex operator-(Complex a,Complex b)
{
    return Complex(a.real_-b.real_, a.imag_-b.imag_);
}
Complex operator*(Complex a,Complex b)
{
    return Complex(a.real_*b.real_-a.imag_*b.imag_, a.real_*b.imag_+a.imag_*b.real_);
}