#include <iostream>
#include <vector>
#include <memory>
#include <chrono>
#include <algorithm>
#include <set>
#include <type_traits>
#include "complex.h"
#include <functional>
#include <thread>
#include <future>
#include <mutex>
// #include <bits/stdc++.h>
using namespace std;
// using namespace std::literals;
void g()
{
    const int n = 0;
 
    constexpr int j = *&n; 
 
    [=]
    {
        constexpr int i = n;  
        //constexpr int j = *&n;
    };
}
constexpr int incr(int& n)
{
    return ++n;
}
int&& martix(int&& n){
    cout<<&n<<endl; 
    return std::move(n);
}
template<typename T,
         typename = typename std::enable_if_t<is_integral_v<T>>>
void own(const T& a){}

struct B {int x;};
struct D : B { B b; };
B nv{7};
D d;
B& br1 = d;
B& br2 = d.b;
//D& br3 = static_cast<D&>(br1);
//D& br4 = static_cast<D&>(br2);

template<typename T>
using vec = vector<T, allocator<T>>;
template<class T>
using a = typename table<T>::type;
constexpr                                   //pow是绝不抛异常的
int pow(int base, int exp) noexcept         //constexpr函数
{
    if(!exp)return 1;
    else return base * pow(base, exp-1);                                          //实现在下面
}
constexpr auto numConds = 5;                //（上面例子中）条件的个数
  //结果有3^numConds个元素010200
int nums[] = {1,2,3,4,5,6};
static int i1 = 4;
int&& i2 = 42;

template<typename T>
decltype(auto) move(T&& param)          //C++14，仍然在std命名空间
{
    using ReturnType = remove_reference_t<T>&&;
    const int a;
    return static_cast<ReturnType>(param);
    
}
struct A
{
    explicit A(int i = 0) {}
};
//一个时间点的类型定义（语法见条款9）
using Time = std::chrono::steady_clock::time_point;

//“enum class”见条款10
enum class Sound { Beep, Siren, Whistle };

//时间段的类型定义
using Duration = std::chrono::steady_clock::duration;
void setAlarm(Time t, Sound s, Duration d)
{
    return;
}
//A a[2](A(1)); // OK：以 A(1) 初始化 a[0] 并以 A() 初始化 a[1]
//A b[2]{A(1)}; // 错误：从 {} 隐式复制初始化 b[1] 选择了 explicit 构造函数
A c = {A(2)};
int S(0);
//typedef vector<T> vec;
int main()
{
    
    complex a(2,2);
    complex b(2,1);
    complex c = complex(1,2);
    complex e = complex();
    complex d = {1,2}; 
    complex f = {};
    a+=complex(1,2);
    a+=b;
    cout<<"success"<<endl;
    int au=3;
    complex* p = new complex();
    cout<<sizeof(*p)<<endl;
    int *i = &au;
    complex *j = new complex[au]{(1,0),(2,3),(1)};
    cout<<j[0].real()<<'\n';
    // sizeof(j[0].imag());
    /* chrono::duration<int, ratio<100, 1>> setter(3);
    cout<<sizeof(i)<<endl; 
    delete p;
    auto teaser = [](complex a, complex b)->complex{return a.real()+b.real();};
    teaser(a, b);
    static_assert(sizeof(complex), "complex");
    std::vector<complex, allocator<complex>>();
    vec<int> T;
    T.push_back(au);
    T.emplace_back(au);
    ++++au;
    comparsion(1,2,3,4,5,6,7,8,9,10,11);
    table<int>::type T1;
    T1.push_back(1);
    shared_ptr<int> pInt (new int(100));
    //return 0;
    //__attribute__((__constructor__));
    int t1, t2, t3;
    constexpr int t4 = 1 ;
    std::tie(t1, t2, t3) = make_tuple(1, 2, 3);
    array<int, 5> results;
    results.fill(1);
    et<&i1>();
    remove_const_t<int> i1;
    //remove_reference<int>::type i2;
    cout<<&i2<<endl;
    static_cast<D&>(br1); // OK: lvalue denoting the original d object
    static_cast<D&>(br2); // UB: the b subobject is not a base class subobject
    static_cast<complex&>(a);
    double (complex::*cp)()const = &complex::imag;
    //cout<<cp<<endl;
    complex a1[3]{complex(1), complex(2)}; 
    int an = 10;
    //const double* p1 = &an;  // 编译错误：类型不兼容
    int* p2 = &an;
    // double*& p3 = p1;  // 编译错误：类型不兼容
    int*& p4 = p2;
    double p5 = 1.0;
    // const int* p6 = &p5;
    struct A { };
    struct B : A { operator int&(); } b1;
    A& ra = b1;                      // ra refers to A subobject in b
    const A& rca = b1;               // rca refers to A subobject in b
    //int& ir = B();                  // ir refers to the result of B​::​operator int&
    //cout<<ir<<endl;
    g();
    int x, y, z[30];
    constexpr auto e2 = &z[20] - &z[3];
    const int h =2;
    constexpr int h1 = h;
    //constexpr const int& e3 = 42;
    //constexpr int x = 5;
    //constexpr int& y = x; // y是一个类型为constexpr int&的变量    
    double t = 10;
    auto cmp = [t]()constexpr mutable noexcept->int{t+=2;return 0;};
    pow(2, 100);
    // int y2 = martix(1);
    // cout<<y2<<endl;
    multiset<std::string>mset;
    mset.insert("x");
    mset.emplace("x");
    mset.emplace("x");
    testReturn();
    //std::in_place_type_t _1;
    using placeholders::_1;
    auto _2 = std::bind([](const std::string&){}, _1); 
    // std::placeholders
    auto setSoundB =                            //“B”代表“bind”
    std::bind(setAlarm,
              chrono::steady_clock::now() + 1h,     //不正确！见下
              _1,
              30s);
    1h;
    // std::atomic_thread_fence(); */
    return 0;
}
