/*
 * Stuff from Chapter 1, Section 1.1.2 
 * TYPE METAFUNCTIONS
 */

#include <iostream>


template <typename T> struct Function { 
    using type = T;
};

template <> struct Function<int> { 
    using type = unsigned int;
};

template <> struct Function<long> { 
    using type = unsigned long;
};



int main(void)
{
    Function<int>::type h = 3;
    std::cout << "[Function<int>::type h = 3] : " << h << std::endl;
    return 0;
}
