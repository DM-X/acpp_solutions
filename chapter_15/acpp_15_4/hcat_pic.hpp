#ifndef GUARD_hcat_pic_h
#define GUARD_hcat_pic_h

#include "ptr.hpp"
#include "pic_base.hpp"

class HCat_Pic: public Pic_base {
   friend Picture hcat(const Picture&, const Picture&);
   friend Picture reframe(const Picture&, const char, const char, const char);
   private:
      Ptr<Pic_base> left, right;
      HCat_Pic(const Ptr<Pic_base>& l, const Ptr<Pic_base>& r):
         left(l), right(r) { }

      wd_sz width() const { 
         return left->width() + right->width();
      }
      ht_sz height() const {
         return std::max(left->height(), right->height());
      }
      void display(std::ostream&, ht_sz, bool) const;
      virtual void reframe(char, char, char);
};

#endif
