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

    cout << "Hello, give the length of the rectangle ";
    int length_re;
    cin >> length_re;
    cout << "Hello, give the height of the rectangle ";
    int height_re;
    cin >> height_re;

    for (int i=0; i!=height_re; ++i) {
       if (i==0 || i==height_re-1) {
          for (int j=0; j!=length_re; ++j) {
             cout << "* ";
          }
          cout << std::endl;
       } else {
          cout << "* ";
          for (int j=0; j!=length_re-2; ++j) {
             cout << "  ";
          }
          cout << "*" << std::endl;
       }
    }

    cout << "Hello, give the length of the triangle ";
    int height_tri;
    cin >> height_tri;

    for (int i=0; i!=height_tri; ++i) {
       if (i==0) {
          for (int j=0; j!=height_tri-1; ++j) {
             cout << " ";
          }
          cout << "*" << std::endl;
       } else {
          if (i==height_tri-1) {
             for (int j=0; j!=height_tri; ++j) {
                cout << "* ";
             }
             cout << std::endl;
          } else {
             for (int j=0; j!=2*height_tri; ++j) {
                if (j==height_tri-1-i || j==height_tri-2+i)  cout << "* ";
                else cout << " ";
             }
             cout << std::endl;
          }
       }
    }
    return 0;
}
