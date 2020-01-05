#include "ptr.hpp"

template<class T>
Ptr<T>& Ptr<T>::operator=(const Ptr& rhs)
{
   //std::cout << "assignment" << std::endl;
   ++*rhs.refptr;
   //std::cout << "refptr= " << *rhs.refptr << std::endl;
   // free the left-hand side, destroying pointers if appropriate
   if (--*refptr == 0) {
      delete refptr;
      delete p;
   }
   // copy in values from the right-hand side
   refptr = rhs.refptr;
   p = rhs.p;
   return *this;
}

template<class T>
Ptr<T>::~Ptr()
{
   if (--*refptr == 0) {
      delete refptr;
      delete p;
   }
}
