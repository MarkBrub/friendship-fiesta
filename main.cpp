#include <iostream>
#include <vector>
#include <string>
#include "elements.hpp"
#include "matchSet.hpp"

using namespace std;

int main() {
    SetOfElements men("SetA.txt");
    SetOfElements women("SetB.txt");
    StableMatchSet marriages;

    cout << "Set A contains: " << endl;
    men.print();
    cout << "Set B contains: " << endl;
    women.print();

    marriages.determineMatches(men, women);

    cout << "Result of verification function: ";
    if(marriages.matchesAreStable(men, women)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}