#ifndef _COMPLEX_
#define _COMPLEX_

// inline complex& doapls (complex* ths,const complex& x);
class complex{
public: 
    complex(double r=0,double i=0):re(r),im(i){};
    complex& operator += (const complex& r);
private:
    double re,im;
    friend complex& doapls(complex* ths,const complex&x);
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

#endif