/*
 * THAT TEMPLATE BOOK
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


// ========
// Note on the form of metafunction used in the book
// ========
template <int a, int b> struct BaseFunction_ {
    constexpr static int value = a + b;   // basically a compile-time addition
};

template <int a, int b> constexpr int Function = a + b;
constexpr int x1 = BaseFunction_<2, 3>::value;    // dependent result (ie: depends on the presence of BaseFunction_
constexpr int x2 = Function<2, 3>;

// ========
// Templates as the input of metafunctions and container templates
// ========

template <template <typename> class T1, typename T2> 
struct meta_fun_struct {
    using type = typename T1<T2>::type;
};

template <template <typename> class T1, typename T2> 
using meta_fun = typename meta_fun_struct<T1, T2>::type;

meta_fun<std::remove_reference, int&> h = 3;


void ex_just_an_int(void)
{
    //FUN<int> that_fun;
    //FUN<long>::type h = 3;

    FUN<just_an_int>::type h = 4;
    //FUN<just_an_int::type>::type h = 4;
    std::cout << " FUN<int>::type h = " << h << std::endl;
    //std::cout << "integral : " << std::is_integral<h>::value << std::endl;
    std::cout << "integral : " << std::is_integral<FUN<int>::type>::value << std::endl;
    //std::cout << "floating : " << std::is_floating_point<FUN<int>::type> << std::endl;

    is_it_integral(h);
}

void ex_remove_reference_const(void)
{
    //std::cout << "integral : " << std::is_integral<h> << std::endl;
    //std::cout << "integral : " << std::is_integral<FUN<int>::type> << std::endl;
    //std::cout << "floating : " << std::is_floating_point(h) << std::endl;
    //const int& thing;

    RemoveReferenceConst<const int&> i = 3;
    std::cout << "RemoveReferenceConst i: " << i << std::endl;
    is_it_integral(i);
}




int main(int argc, char *argv[])
{
    ex_just_an_int();
    ex_remove_reference_const();

    return 0;
}
