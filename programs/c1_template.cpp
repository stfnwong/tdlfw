/*
 * THAT TEMPLATE
 */

#include <iostream>
#include <type_traits>


struct just_an_int
{
    using type = int;
};


template <typename T> struct FUN
{
    using type = T;
};


template <typename T> struct ANY_FUCKING_THING
{
    int ur_mum;
    using type = T;
};


template <>
struct FUN<int> 
{
    using type = float;
    //using type = unsigned int;
};

template <>
struct FUN<long> 
{
    using type = unsigned long;
};

template <>
struct FUN<just_an_int> 
{
    using type = short;
};

// let the compiler choose correct type 
template <typename T> void is_it_integral(T x)
{
    std::cout << std::is_integral<T>::value << std::endl;
}


template <typename T>
struct RemoveReferenceConst_ {
    private:
        using inter_type = typename std::remove_reference<T>::type;
    public:
        using type = typename std::remove_const<inter_type>::type;
};


template <typename T> using RemoveReferenceConst = typename RemoveReferenceConst_<T>::type;



int main(void)
{
    //FUN<int> that_fun;
    //FUN<long>::type h = 3;

    FUN<just_an_int>::type h = 4;
    //FUN<just_an_int::type>::type h = 4;
    std::cout << " FUN<int>::type h = " << h << std::endl;

    is_it_integral(h);

    //std::cout << "integral : " << std::is_integral<h> << std::endl;
    //std::cout << "integral : " << std::is_integral<FUN<int>::type> << std::endl;
    //std::cout << "floating : " << std::is_floating_point(h) << std::endl;
    //const int& thing;

    RemoveReferenceConst<const int&> i = 3;
    std::cout << "RemoveReferenceConst i " << i << std::endl;
    is_it_integral(i);


    return 0;
}
