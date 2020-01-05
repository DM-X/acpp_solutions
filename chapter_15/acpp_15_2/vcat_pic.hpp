#ifndef GUARD_vcat_pic_h
#define GUARD_vcat_pic_h

#include "ptr.hpp"
#include "pic_base.hpp"

class VCat_Pic: public Pic_base {
   friend Picture vcat(const Picture&, const Picture&);
   private:
      Ptr<Pic_base> top, bottom;
      VCat_Pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b):
         top(t), bottom(b) { }

      wd_sz width() const {
         return std::max(top->width(), bottom->width());
      }
      ht_sz height() const {
         return top->height() + bottom->height();
      }
      void display(std::ostream&, ht_sz, bool) const;
};

#endif
