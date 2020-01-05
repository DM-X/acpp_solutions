#include "picture.hpp"


using std::vector;
using std::string;
using std::endl;

Picture frame(const Picture& pic, const char topbot_char, const char side_char,
              const char corner_char)
{
   return new Frame_Pic(pic.p, topbot_char, side_char, corner_char);
}

Picture hcat(const Picture& l, const Picture& r)
{
   return new HCat_Pic(l.p, r.p); //HCat_Pic* => Pic_base* => Picture
}

Picture vcat(const Picture& t, const Picture& b)
{
   return new VCat_Pic(t.p, b.p); //VCat_Pic* => Pic_base* => Picture
}

Picture::Picture(const vector<string>& v): p(new String_Pic(v)) { }

std::ostream& operator<<(std::ostream& os, const Picture& pic)
{
   const Pic_base::ht_sz ht = pic.p->height();
   for (Pic_base::ht_sz i = 0; i != ht; ++i) {
      pic.p->display(os, i, false);
      os << endl;
   }
   return os;
}
