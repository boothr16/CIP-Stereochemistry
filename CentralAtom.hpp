#ifndef CENTRALATOM_HPP
#define CENTRALATOM_HPP

#include <string>

class CentralAtom {
    private:
        std::string flat1;
        std::string flat2;
        std::string dashed;
        std::string wedged;
    public:
        CentralAtom();
        void setFlat1(const std::string& symbol);
        void setFlat2(const std::string& symbol);
        void setDashed(const std::string& symbol);
        void setWedged(const std::string& symbol);
};

CentralAtom::CentralAtom() 
    : flat1("")
    , flat2("")
    , dashed("")
    , wedged("") {}


#endif