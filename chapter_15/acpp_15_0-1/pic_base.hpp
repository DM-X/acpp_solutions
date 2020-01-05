#ifndef GUARD_pic_base_h
#define GUARD_pic_base_h

#include <iostream>
#include <vector>
#include <string>
//#include "string_pic.hpp" //this include causes a compiler error:
                            //in string_pic.hpp the pic_base class is used but
                            //not defined because the 
                            //1) include "pic_base.hpp" is not executed (guard)
                            //2) the definition of Pic_base class is not yet done

class Picture; //forward declaration

class Pic_base {
   typedef std::vector<std::string>::size_type ht_sz;
   typedef std::string::size_type wd_sz;
   friend std::ostream& operator<<(std::ostream&, const Picture&);
   friend class Frame_Pic;
   friend class HCat_Pic;
   friend class VCat_Pic;
   friend class String_Pic;
   protected:
      static void pad(std::ostream& os, wd_sz beg, wd_sz end) {
         while (beg != end) {
            os << " ";
            ++beg;
         }
      }
   private:
      virtual wd_sz width() const = 0;
      virtual ht_sz height() const = 0;
      virtual void display(std::ostream&, ht_sz, bool) const = 0;
};

#endif
