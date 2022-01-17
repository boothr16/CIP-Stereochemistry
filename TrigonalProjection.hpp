#ifndef TRIGONALPROJECTION_HPP
#define TRIGONALPROJECTION_HPP

#include <string>
#include "Tetrahedral.hpp"

// TrigonalProjection API
class TrigonalProjection {
    private:
        AtomNode *top, *left, *right, *min;
    public:
        TrigonalProjection(Tetrahedral& tetrahedral);
        std::string GET_STEREOCHEMISTRY(Tetrahedral& tetrahedral) const;
};

#endif