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

template<class T>
void Ptr<T>::make_unique() 
{
   if (*refptr != 1) {
      --*refptr;
      refptr = new size_t(1);
      p = p ? clone(p) : 0;
   }
}

template<class T>
T* clone(const T* tp)
{
   return tp->clone();
}

template<>
inline Vec<char>* clone(const Vec<char>* vp)
{
   return new Vec<char>(*vp);
}
