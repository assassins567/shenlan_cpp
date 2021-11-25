1. 指针常量
    const int* ptr 指针指向的是常量，不能改变
    int* const ptr 指针本身是常量，不能变化
    const int* const ptr 指针本身和指向的数据都是常量

    int* --> const int* 是合法的， 反之不合法。

    void fun(const int& param) 完全不可取， 但是可以绑定字面值

    e.g. fun(3)

    constexpr 明确告诉编译器是常量