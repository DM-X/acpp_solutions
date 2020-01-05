#include <iostream>

using std::cout;
using std::cin;

int main()
{
    cout << "Hello, give the length of the square ";
    int length_sq;
    cin >> length_sq;

    for (int i=0; i!=length_sq; ++i) {
       if (i==0 || i==length_sq-1) {
          for (int j=0; j!=length_sq; ++j) {
             cout << "* ";
          }
          cout << std::endl;
       } else {
          cout << "* ";
          for (int j=0; j!=length_sq-2; ++j) {
             cout << "  ";
          }
          cout << "*" << std::endl;
       }
    }
    return 0;
}
