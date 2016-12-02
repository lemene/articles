/**
 * @file constructor_destructor_sequence.cpp
 * @brief 测试构造析构函数的调用次序
 * @copyright public domain
 */

/**
## 说明
+ 构造函数的调用顺序是先基类再派生类。析构函数的顺序相反——先派生类再基类。
+ delete时根据指针类型调用析构函数
  - 类型有非virtual析构函数，在调用该类的析构函数
  + 类型有virtual析构函数，则从虚函数表找析构函数。
  - 类型为void*，则不会调用析构函数。
*/

#include <iostream>

class Base {
public:
    Base() { std::cout << "Base()" << std::endl; }
    ~Base() { std::cout << "~Base()" << std::endl; }
};

class VBase {
public:
    VBase() { std::cout << "VBase()" << std::endl; }
    virtual ~VBase() { std::cout << "~VBase()" << std::endl; }
};

class Derived : public Base {
public:
    Derived() { std::cout << "Derived()" << std::endl; }
    ~Derived() { std::cout << "~Derived()" << std::endl; }
};

class VDerived: public VBase {
public:
    Derived() { std::cout << "VDerived()" << std::endl; }
    ~VDerived() { std::cout << "~VDerived()" << std::endl; }
};

void test_0() {
    std::cout <<"派生类不声明virtual，按基类指针删除派生类" << std::endl;
    VBase* p = new VDerived;
    delete p;
}

void test_1() {
    std::cout <<"不声明virtual，按派生类指针删除派生类" << std::endl;
    Derived* p = new Derived;
    delete p;
}

void test_2() {
    std::cout <<"不声明virtual，按基类指针删除派生类" << std::endl;
    Base* p = new Derived;
    delete p;
}

void test_3() {
    std::cout <<"不声明virtual，按void*删除派生类" << std::endl;
    void* p = new Derived;
    delete p;
}

int main() {
    test_0();
    test_1();
    test_2();
    test_3();

    return 0;
}

