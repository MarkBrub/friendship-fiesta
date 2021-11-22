#pragma once

#include <vector>
#include "elements.hpp"

using namespace std;

class StableMatchSet {
    vector<pair<Element*, Element*>> matches;

public:
    StableMatchSet() = default;

    pair<Element*, Element*>& getPair(string name);
    int getPairs() {return matches.size();}
    int getPartnersRank(string name);
    void determineMatches(SetOfElements& men, SetOfElements& women);
    void addMatch(Element* a, Element* b);
    bool matchesAreStable(SetOfElements& men, SetOfElements& women);
};