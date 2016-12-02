/**
 * @file empty_class_size.cpp
 * @brief 测试空类的大小
 * @copyright public domain
 */

/**
 + 编译器会为空类（不包含任何成员）分配1的空间，避免不同的变量地址相同
 + 空类的子类会优化多分配的空间
 + 带虚析构函数的空类不是严格意义的空类，它包含虚函数表指针
 */

#include<iostream>

class Empty { };

class SubEmpty : public Empty
{
protected:
    int mInt; 
};

class VEmpty
{
public:
    virtual ~VEmpty() = 0;
};


int main() 
{
    std::cout << "Empty class: " << sizeof(Empty) << std::endl;
    std::cout << "SubEmpty: " << sizeof(SubEmpty) << std::endl;
    std::cout << "VEmpty: " << sizeof(VEmpty) << std::endl;
    std::cout << "Void*: " << sizeof(void*) << std::endl;
    return 0;
}

