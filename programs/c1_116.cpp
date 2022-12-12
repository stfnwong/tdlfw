/*
 * Stuff from Chapter 1, Section 1.1.6
 * Nominating methods of metafunctions in this book
 */

#include <iostream>
#include <type_traits>


template <int a, int b> struct AddStruct
{
    constexpr static int value = a + b;
};

template <int a, int b> constexpr int AddExpr = a + b;

constexpr int x1 = AddStruct<2, 3>::value;
constexpr int x2 = AddExpr<2, 3>;


int main(void)
{
    std::cout << "Nominating methods of metafunctions" << std::endl;
    std::cout << "x1: " << x1 << std::endl;
    std::cout << "x2: " << x2 << std::endl;

    return 0;
}
