#include<iostream>
#include<type_traits>

int main()
{
    

    constexpr int y2 = 3;

    int x =3;
    
    constexpr const int* ptr = nullptr;
    std::cout << std::is_same<decltype(ptr),  const int* > << std::endl;

}

