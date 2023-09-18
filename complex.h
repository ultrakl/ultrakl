#ifndef _COMPLEX_
#define _COMPLEX_
#include<iostream>
#include<vector>
// inline complex& doapls (complex* ths,const complex& x);

using T = int[3];
using namespace std;
class complex{
public: 
    complex(double r=0,double i=0):re(r), im(i){std::cout<<"default_ctor"<<'\n';}
    //complex(std::initializer_list<double> il){std::cout<<"list_initial_ctor"<<'\n';}
    complex(const complex& x) {std::cout<<"copy_ctor"<<'\n';}
    complex(complex&& x){std::cout<<"move_ctor"<<'\n';}
    //complex(complex&& x) = delete;
    double real()const{return re;}
    double imag()const{return im;}
    complex& operator += (const complex& r);
    virtual void draw() {};
    virtual ~complex(){cout<<"destroy"<<std::endl;};
    operator int() const {return im;}
private:
    double re,im;
    friend complex& __doapls(complex* ths,const complex& x);
};
inline complex testReturn() {
    complex x;
    return x;
} 
inline complex& __doapls (complex *ths,const complex& x)
{
    ths->re+=x.re;
    ths->im+=x.im;
    return *ths;
}

inline complex& complex::operator+=(const complex& r)
{
    return __doapls(this,r);
}

inline ostream& operator<< (ostream &out, const complex& x){
    return out << x.imag() << ", " << x.real();
}
class derived : public complex{
    using complex::operator+=;
    virtual void draw() override {
        
    }
};
template<typename T1, typename T2>
auto add (const T1& x, const T2& y) -> decltype(x+y){x+y;} 
template<class T>
class string{
    
};
void comparsion();
template<typename T, typename... Type>
void comparsion(const T& val, const Type& ...args){
    cout<<val<<endl;
    comparsion(args...);
}
void comparsion(){
    /*...*/
}
template<class T>
inline T g(T) { /* ... */ }
template<>
int g<>(int) { /* ... */ }

int n = static_cast<int>(complex());
template<class T>
struct table {
    typedef vector<T, allocator<T>> type;
    
};
// template<double r>
//template<string name> error: string is ambiguous

template<int const * x>
int et(){cout<<*x<<endl;}

#endif