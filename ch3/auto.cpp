#include<iostream>
#include<type_traits>

int main(int argc, char* argv[])
{
    int x = 3;
    int* y = &x;
    std::cout << std::is_same_v<decltype(*y), int&> << std::endl;

    decltype(auto) m = 3.5 + 15l;
    std::cout << std::is_same_v<decltype(m), double> << std::endl;
}