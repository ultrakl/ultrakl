#ifndef _COMPLEX_
#define _COMPLEX_
#include<iostream>
// inline complex& doapls (complex* ths,const complex& x);
class complex{
public: 
    complex(double r=0,double i=0):re(r), im(i){std::cout<<"default_ctor"<<'\n';}
    complex(std::initializer_list<double>){std::cout<<"list_initial_ctor"<<'\n';}
    complex(const complex& x) {std::cout<<"copy_ctor"<<'\n';}
    complex& operator += (const complex& r);
    virtual void draw() {};
    virtual ~complex(){};
private:
    double re,im;
    friend complex& doapls(complex* ths,const complex& x);
};

inline complex& doapls (complex *ths,const complex& x)
{
    ths->re+=x.re;
    ths->im+=x.im;
    return *ths;
}

inline complex& complex::operator+=(const complex& r)
{
    return doapls(this,r);
}

class derived : public complex{
    using complex::operator+=;
    virtual void draw() const{
        
    }
};
#endif