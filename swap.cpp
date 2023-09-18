#include <iostream>

namespace MyNamespace {
      // 在与自定义类型相同的命名空间中声明 swap 的自定义重载
    template<typename T>
    void swap(T& a, T& b) {
        std::cout << "Custom swap called." << std::endl;
        T temp = a;
          a    = b;
          b    = temp;
    }

class MyType {
public           : 
MyType(int value): value(value) {}

    int getValue() const {
        return value;
    }

private: 
    int value;
};
}

#include <iostream>

class Base {
public: 
      // Virtual function
    virtual void print() {
        std::cout << "Base::print()" << std::endl;
    }

      // Member function template
    template <typename T>
    void setValue(T value) {
        this->value = value;
    }

protected: 
    int value;
};

class Derived : public Base {
public: 
      // This will not work as an override of Base::print()
      // because member function templates cannot be virtual
      //template <typename T>
    void print() {
        std::cout << "Derived::print()" << std::endl;
    }
};
template <typename T>
class MyClass {
public          : 
MyClass(T value): data(value) {
        std::cout << "Constructor called: " << data << std::endl;
    }

      // Template copy constructor
      // This will not work as a copy constructor
    template <typename U>
    MyClass(const MyClass<U>& other) : data(other.getData()) {
        std::cout << "Template copy constructor called: " << data << std::endl;
    }

      // Destructor
      // This cannot be a template
    ~MyClass() {
        std::cout << "Destructor called: " << data << std::endl;
    }

    T getData() const {
        return data;
    }

private: 
    T data;
};

using namespace MyNamespace;
  // using namespace std;
  /* int main() {
    MyType a(5);
    MyType b(10);

    std::cout << "Before swap: a = " << a.getValue() << ", b = " << b.getValue() << std::endl;

      // 调用自定义命名空间中的 swap，而不是 std::swap
    swap(a, b);

    std::cout << "After swap: a = " << a.getValue() << ", b = " << b.getValue() << std::endl;

    return 0;
} */

#include <iostream>
#include <vector>
#include <memory>

struct Data {
  int value;
};

int main() {

    /* std::vector<std::shared_ptr<Data>> vec;

    // 创建一个Data对象,shared_ptr给闭包对象
  auto data        = std::make_shared<Data>();
       data->value = 10;

  vec.push_back(data);

  std::cout << data->value << std::endl;  // 打印20,外部data也被修改

    // 带初始化器捕获data
  auto print = [ptr = std::move(data)]() mutable {
    
      // ptr实际上是一个auto变量,作为闭包对象成员
    std::cout << ptr->value << std::endl; 

      // 修改ptr指向的对象
    ptr->value = 20;
  };

  print();  // 打印10

  std::cout << vec.back()->value << std::endl;  // 打印20,外部data也被修改

    // data已经被移动给闭包对象,vec中的shared_ptr失效
  vec.clear();

  print();  // 打印20,ptr内部对象并没有被清理
  
  return 0; */

  Derived obj;
  obj.Base::print();
  obj.print();
  MyClass<int>obj1(MyClass<int>(10));
}
