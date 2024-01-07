#include<iostream>
#include<random>
#include<chrono>
using namespace std;


template <int n>
struct factorial {
  static const int value =
    n * factorial<n - 1>::value;
};

const int b = 42;

void test()
{
    static const int a = std::random_device{}();
    constexpr const int& ra = a; // OK：a 是泛左值常量表达式
    //constexpr int ia = a; // 错误：a 不是纯右值常量表达式
    constexpr const int& rb = b; // 错误：b 不是泛左值常量表达式
    constexpr int ib = b; // OK：b 是纯右值常量表达式
}
template <>
struct factorial<0> {
  static const int value = 1;
};


template<typename T>
void f(T ans){cout<<typeid(1).name()<<endl;}
template<size_t w, size_t h>
void f(double (&s)[w][h]){cout<<s[0]<<endl;} 
/*int main(){
    cout<<factorial<5>().value<<endl;
 
    double v[10][20];
    f(v);
}*/


//#include <iostream>

struct foo
{
    template <typename T> void operator()(T const&) {
        std::cout << "general\n";
    }
};

template <>
void foo::operator()<int>(int const&) {
    std::cout << "int spec\n";
}
struct Widget{};
void process(const Widget& lvalArg);        //处理左值
void process(Widget&& rvalArg);             //处理右值

template<typename T>                        //用以转发param到process的模板
void logAndProcess(T&& param)
{
    auto now =                              //获取现在时间
        std::chrono::system_clock::now();
    
    //makeLogEntry("Calling 'process'", now);
    process(std::forward<T>(param));
}

int main()
{
    ratio_multiply<std::ratio<1, 1000>, std::micro>::type;
    foo fo;
    fo(1.2);
    fo(1);
    fo(1); // <-- ERROR: doesn't work!
    //std::cout<<__cplusplus<<std::endl;
    //std::cout<<factorial::value<<std::endl;
}