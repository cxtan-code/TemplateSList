#include <iostream>
using namespace std;
template <typename T>
void Swap(T& a,T &b ) {
    T t = a;
    a = b;
    b = t;
}
int main()
{
    long ia = 10; long ib = 20;
    Swap(ia,ib); //Swap<int>(ia,ib);
    cout<<ia<<ib<<endl;
    double da = 10, db = 20;
    Swap(da,db); //Swap<double>(da,db);
    cout<<da<<db<<endl;
    return 0;
}
