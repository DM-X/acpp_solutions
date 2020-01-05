#ifndef GUARD_string_pic_h
#define GUARD_string_pic_h

#include "pic_base.hpp" //must be included (here not in cpp)

class String_Pic: public Pic_base {
   friend class Picture;
   protected:
      static void pad(std::ostream& os, wd_sz beg, wd_sz end) {
         while (beg != end) {
            os << " ";
            ++beg;
         }
      }
   private:
      std::vector<std::string> data;
      String_Pic(const std::vector<std::string>& v): data(v) { }

      wd_sz width() const;
      ht_sz height() const {return data.size();}
      void display(std::ostream&, ht_sz, bool) const;
      void reframe(char, char, char) { }
};

#endif
