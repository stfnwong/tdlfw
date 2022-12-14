/*
 * Stuff from Chapter 1, Section 1.2.1
 * TEMPLATES AS THE INPUT OF METAFUNCTIONS
 * 
 * This file also contains source for sections 1.2.2 and 1.2.3
 */

#include <iostream>


// 1.2.1 template as the input of a metafunction
template <template <typename> class T1, typename T2> 
struct meta_fun_struct {
    using type = typename T1<T2>::type;
};

template <template <typename> class T1, typename T2> 
using meta_fun = typename meta_fun_struct<T1, T2>::type;


// 1.2.2 template as the output of a metafunction
template <bool add_or_remove_ref> struct OutFun_;

// Here we define a metafunction where
//
// - When the input is true the output of OutFun_<true>::type is the function template 
// add_lvalue_reference, which can add an lvalue reference to the type.
// - When the input is false the output of OutFun_<false>::tpye is the function template
// remove_reference which can remove references from the type.
template <> struct OutFun_<true> {
    template <typename T> 
        using type = std::add_lvalue_reference<T>;
};

template <> struct OutFun_<false> {
    template <typename T> 
        using type = std::remove_reference<T>;
};

template <typename T>
using Res_ = OutFun_<false>::template type <T>;




int main(void)
{
    meta_fun<std::remove_reference, int&> h_inp = 3;
    std::cout << "Input metafunction [meta_fun<std::remove_reference, int&> h = 3]: " << h_inp << std::endl;

    Res_<int&>::type h_out = 3;
    std::cout << "Output metafunction [Res_<int&>::type h = 3" << h_out << std::endl;
    return 0;
}
