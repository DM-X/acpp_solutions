#include <iostream>
#include "audit.hpp"

using std::cout;
using std::endl;

double Audit::grade() const
{
   return 0.0;
}

std::istream& Audit::read(std::istream& in)
{
   read_common(in);
   if (in.rdstate() == 4) in.clear(); //4=end of line; 6=end of file
   return in;
}

Audit::Audit()
{
   //cout << "Audit:Audit()" << endl;
}

Audit::Audit(std::istream& in)
{
   read(in);
}
