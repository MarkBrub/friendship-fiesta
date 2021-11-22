#include "matchSet.hpp"

pair<Element*, Element*>& StableMatchSet::getPair(string name) {
    for(auto& match : matches) {
        if(match.first->getName() == name || match.second->getName() == name) return match;
    }
}

int StableMatchSet::getPartnersRank(string name) {
    for(auto& match : matches) {
        if(match.first->getName() == name || match.second->getName() == name) {
            if(match.first->getName() == name) {
                return match.first->getRank(match.second->getName());
            } else {
                return match.second->getRank(match.first->getName());
            }
        }
    }
    return -1;
}

void StableMatchSet::determineMatches(SetOfElements& men, SetOfElements& women) {
    int expectedMatches = men.getElements().size();

    while(matches.size() != expectedMatches) {
        Element* m = men.getFirstUnmatched();
        Element* w = women.getElement(m->getBestUnproposed());

        if(!w->isPaired()) {
            addMatch(m, w);
        } else {
            m->propose(w->getName());
            if(w->getRank(m->getName()) > getPartnersRank(w->getName())) {
                getPair(w->getName()).first->makeSingle();
                getPair(w->getName()).first = m;
            }
        }
    }

    cout << "Stable matches:" << endl;
    for(auto& m : matches) {
        cout << "(" << m.first->getName() << ", " << m.second->getName() << ")" << endl;
    }
    cout << endl;
}

void StableMatchSet::addMatch(Element* a, Element* b) {
    matches.emplace_back(a, b);
    a->setPaired();
    b->setPaired();
    a->propose(b->getName());
}

bool StableMatchSet::matchesAreStable(SetOfElements& men, SetOfElements& women) {
    for(auto& match : matches) {
        for(auto& m : men.getElements()) {
            if(match.first->getRank(m.getName()) > getPartnersRank(match.first->getName())) {
                if(m.getRank(match.first->getName()) > getPartnersRank(m.getName())) return false;
            }
        }
        for(auto& w : women.getElements()) {
            if(match.second->getRank(w.getName()) > getPartnersRank(match.second->getName())) {
                if(w.getRank(match.second->getName()) > getPartnersRank(w.getName())) return false;
            }
        }
    }
    return true;
}