#include <iostream>
#include "complex.h"
using namespace std;
int main()
{
    complex a(2,2);
    complex b(2,1);
    complex c = complex(1,2);
    complex d = {1,2};
    a+=b;
    cout<<"success"<<endl;
    int au=3;
    complex* p = new complex();
    cout<<sizeof(*p)<<endl;
    int *i = &au;
    cout<<sizeof(i)<<endl; 
    delete p;
    return 0;
}
