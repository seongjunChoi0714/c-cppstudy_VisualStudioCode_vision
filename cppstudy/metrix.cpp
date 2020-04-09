#include <iostream>

int main(void)
{
    // int goalNumber;
    // std::cout<<"calculate the number : ";
    // std::cin>>goalNumber;

    for (int i=1; i<10; i++)
    {
        std::cout<<std::endl;
        for (int j=1; j<10; j++)
        {
            std::cout<<i*j<<' ';
        }
    }
    return 0;
}