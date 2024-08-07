class Complex
{
    private:
        double real_;
        double imag_;
    public:
        Complex();
        Complex(double real,double imag=0);
        Complex(Complex &a);

        Complex add(Complex b);
        Complex sub(Complex b);
        void print();

        Complex operator +(complex a,complex b);
        Complex operator -(complex a,complex b);
        Complex operator *(complex a,complex b);
}