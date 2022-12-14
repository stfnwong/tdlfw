/*
 * Stuff from Chapter 1, Section 1.3
 * WRITING OF SEQUENCES, BRANCHES, AND LOOPS
 * 
 */

#include <iostream>
#include <type_traits>


// Section 1.3.1
// Codes executed in sequence order 
template <typename T> struct RemoveReferenceConst_ {
    private:
        using inter_type = typename std::remove_reference<T>::type;
    public:
        using type = typename std::remove_const<inter_type>::type;
};

template <typename T> using RemoveReferenceConst = typename RemoveReferenceConst_<T>::type;


// Section 1.3.2
// Code executed in branches
//template <bool B, typename T, typename F> struct Conditional {

// Section 1.3.1
// Code executed in loops - we can't really do loops so we do recursion instead
// This set of metafunctions finds the number of 1s in the binary representation of 45
template <size_t Input>
constexpr size_t OnesCount = (Input % 2) + OnesCount<(Input / 2)>;
template <> constexpr size_t OnesCount<0> = 0;

// We can also process elements in an array recursively 



int main(void)
{
    RemoveReferenceConst<const int&> rr_h = 3;
    std::cout << "[RemoveReferenceConst<const int&> h = 3]: " << rr_h << std::endl;
    constexpr size_t oc_45 = OnesCount<45>;
    std::cout << "OnesCount<45>: " << oc_45 << std::endl;

    return 0;
}
