#if !defined(SCORED_MATCH_HEADER_INCLUDED)
#define SCORED_MATCH_HEADER_INCLUDED

// Noisy features matching

// ~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
// Headers


#include <vector>
#include <stdexcept>

namespace uniclop
{
namespace algorithms
{
namespace features
{

using namespace std;


// ~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
// Classes definition

template<typename F>
class ScoredMatch
{
public:

    typedef F feature_type;

    const F *feature_a, *feature_b;
    ///< warning: keeping pointers to a vector element is dangereous since
    ///< the vector memory area will change as its content grows
    ///< should only keep pointers to std::list

    float distance;
    ///< distance between features A and B (given a metric)

    ScoredMatch()
    {
        feature_a = NULL;
        feature_b = NULL;
        distance = -1;
        return;
    }

    ScoredMatch(const F *a, const F *b)
    {
        feature_a = a;
        feature_b = b;
        distance = a->distance(*b);
        return;
    }

    ScoredMatch(const ScoredMatch &m)
    {
        feature_a = m.feature_a;
        feature_b = m.feature_b;
        distance = m.distance;
        return;
    }

    ~ScoredMatch()
    { // nothing to do
        return;
    }


    bool operator<(const ScoredMatch &m) const
    {
        if ( distance < 0 || m.distance < 0)
            throw runtime_error("Comparing an uninitialized ScoredMatch::distance");

        return distance < m.distance;
    }

};


}
}
}

#endif // SCORED_MATCH_HEADER_INCLUDED
