# include <iostream>
using namespace std;
// using std::cout;

namespace BestCom
{
    void notSimple(void);
    void Simple(void);
}
namespace ProgCom
{
    void Simple(void);
}

int main(void)
{
    BestCom::notSimple();
    BestCom::Simple();
    ProgCom::Simple();
    return 0;
}
void BestCom::notSimple(void)
{
    cout<<"notSimple"<<endl;
    Simple();
    ProgCom::Simple();
}
void BestCom::Simple(void)
{
    cout<<"BestSimple"<<endl;
}
void ProgCom::Simple(void)
{
    cout<<"ProgSimple"<<endl;
}