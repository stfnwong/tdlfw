/*
 * Stuff from Chapter 1, Section 1.1.3
 * TYPE METAFUNCTIONS
 */

#include <iostream>


// A template is in fact a metafunction. The below code snippet defines a metafunction
// that receives the parameter T as input. The output is Fun<T>.
template <typename T> struct Fun {};

// The input of a function can be empty, and as such its possible to write a parameterless
// metafunction.
struct ParameterlessMetafunction {
    using type = int;
};

constexpr int parameterless_metafunction(void)
{
    return 10;
}


int main(void)
{
    std::cout << "parameterless_metafunction(): " << parameterless_metafunction() << std::endl;
    return 0;
}
