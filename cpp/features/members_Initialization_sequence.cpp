/**
 * @file members_initialization_sequence.cpp
 * @brief 测试类成员的初始化顺序
 * @copyright public domain
 */

/**
C++类成员初始化顺序取决于其声明顺序，而非初始化列表的顺序。
**/

#include <iostream>

class Test {
public:
    Test() : mBb(sIndex++), mAa(sIndex++) { }

public:
    void Dump() {
        std::cout<< "a: " << mAa << ", b: " << mBb << std::endl;
    } 

protected:
    int mAa;
    int mBb;

    static int sIndex;
};

int Test::sIndex = 1;

int main() {
    Test t;
    t.Dump();
    return 0;
}

