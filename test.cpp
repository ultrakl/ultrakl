#include <iostream>
#include "complex.h"
using namespace std;
int main()
{
    complex a(2,2);
    complex b(2,1);
    complex c = complex(1,2);
    a+=b;
    cout<<"NB"<<endl;
}