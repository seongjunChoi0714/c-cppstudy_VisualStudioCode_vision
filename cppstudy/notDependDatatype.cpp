#include <iostream>
#define square(X) ((X)*(X))

template <typename T>
inline T Square(T x)
{
    return x*x;
}
// inline int Square(int x)
// {
//     return x*x;
// }
int main(void)
{
    std::cout<<Square(5)<<std::endl;
    std::cout<<Square(12.5)<<std::endl;
    return 0;
}