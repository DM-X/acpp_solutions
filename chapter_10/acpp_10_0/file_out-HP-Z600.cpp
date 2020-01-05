/*Author: Daniel Maier
 * Date: /2019
 * Program description:
 * */
#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::ifstream;

int main(int argc, char** argv)
{
   int error_cnt=0;

   for (int i=1; i<=argc-1; ++i) {
      ifstream in (argv[i]);

      if (in) {
         cout << argv[i] << endl;
         string s;
         while (getline(in, s)) {
            cout << "  " << s << endl;
         }
      } else {
         cerr << "cannot open " << argv[i] << endl;
         ++error_cnt;
      }
   }
   cout << "reading errors: " << error_cnt << endl;

   return error_cnt;
}
