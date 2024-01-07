class base{
public:
    base() : a1(2){};
    // base(int a): a1(a){}
private:
    int a1;
};
class derived:public base{
public:
    /*inherited constructors 指的是
    如果 using 声明指代了正在定义的类的某个直接基类的构造函数（例如 using Base::Base;），
    那么在初始化派生类时，该基类的所有构造函数（忽略成员访问）均对重载决议可见。
    虽然标准规定忽略对基类的成员访问，但是继承构造函数必须在派生类中可访问，这样在初始化派生类时，首先调用基类的构造函数，派生类中的各成员
    使用默认成员初始化器(如果有的话)进行默认初始化*/
    using base::base;
    /*如果子类定义了相同签名的构造函数(若未定义，则在继承构造函数的影响下同签名构造函数默认是删除的)，则基类的同签名继承构造函数被隐藏*/
    derived(int a1):a2(a1){}
    // derived(): a2(5){}
    int a2;
};
#include <iostream>
template<typename T>
class test{
private:
    static const short b = 3; 
    T arr[b];
public:
    // T operator[] (std::size_t idx) const {std::cout<<"no"; return arr[idx];}
    T& operator[] (std::size_t idx) {std::cout<<"called"; return arr[idx];}
};

test<int> makeTest() {
    return test<int>();
}

template<typename Container, typename Index>
decltype(auto)
authAndAccess(Container&& c, Index i) {
    return std::forward<decltype(c[i])>(c[i]);
}

int main() {
    int c = authAndAccess(makeTest(), 2);
    int a, b;
    a=b=3;
    std::cout<<b<<std::endl;
    return 0;
}