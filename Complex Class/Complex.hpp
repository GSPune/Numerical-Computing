class Complex
{
    public:
        double r,i;
        Complex();//Normal Constructor
        //Use of a parameterised constructor to initialize data members instead of a 'set' function
        Complex(double,double);
        void print();
        void add(Complex,Complex);
        void sub(Complex,Complex);
        void mul(Complex,Complex);
        void div(Complex,Complex);
        void conjugate();
        double norm();
};
