#include <iostream>
#include <locale>

//using namespace std;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    //setlocale("Rus,all");
    cout << "Hello \t World \n !" << endl;
    cout << "Int \t "<<sizeof(int)<<"\t"
         << int(0b10000000000000000000000000000000)<<"\t"
         << int(0b01111111111111111111111111111111)<<endl;
    cout << double(5)/2<<"\t"
<<5/double(2)<<"\t"
<<double(5/2)<<endl;
    return 0;
}
