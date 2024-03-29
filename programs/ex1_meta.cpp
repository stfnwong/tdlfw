/*
 * Chapter 1, problem 7.
 *
 * Use short-circuit logic of branches to implement a metafuction. Given an integer sequence determine if an element 
 * equals 1. If there is such an element, return true, else return false
 */

#include <cstdint>
#include <iostream>


/*
 * Template to check if a value is even or odd 
 */
template <std::size_t N> constexpr bool is_odd = ((N % 2) == 1);

template <std::size_t N> struct AllOdd
{
    constexpr static bool is_cur_odd = is_odd<N>;
    constexpr static bool is_pre_odd = AllOdd<N-1>::value;
    constexpr static bool value = is_cur_odd && is_pre_odd; 
};

template <> struct AllOdd<0> 
{
    constexpr static bool value = is_odd<0>;
};

// alternative to using the short-circuit AND above is to create an
// auxilliary metafunction.
template <bool cur, typename t_next> constexpr static bool AndValue = false;

template <typename t_next> constexpr static bool AndValue<true, t_next> = t_next::value;


int main(int argc, char *argv[])
{
    // Stuff for problem 7 in Chapter 1
    std::cout << "AllOdd<5>::value : " << AllOdd<5>::value << std::endl;
    std::cout << "AllOdd<5>::is_cur_odd : " << AllOdd<5>::is_cur_odd << std::endl;
    std::cout << "AllOdd<5>::is_pre_odd : " << AllOdd<5>::is_pre_odd << std::endl;

    std::cout << "AllOdd<4>::value : " << AllOdd<4>::value << std::endl;
    std::cout << "AllOdd<4>::is_cur_odd : " << AllOdd<4>::is_cur_odd << std::endl;
    std::cout << "AllOdd<4>::is_pre_odd : " << AllOdd<4>::is_pre_odd << std::endl;

    return 0;
}
