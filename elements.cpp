#include "elements.hpp"

void Element::propose(string name) {
    for(int x = 0; x < preferences.size(); x++) {
        if(preferences[x] == name) {
            proposed[x] = true;
            break;
        }
    }
}

int Element::getRank(string name) {
    return preferences.end() - find(preferences.begin(), preferences.end(), name);
}

string Element::getBestUnproposed() {
    for(int x = 0; x < preferences.size(); x++) {
        if(proposed[x] == false) return preferences[x];
    }
    return "Error: Proposed to all";
}

SetOfElements::SetOfElements(string filePath) {
    ifstream file(filePath);
    string line;

    getline(file, line);
    while(std::getline(file, line)) {
        replace(line.begin(), line.end(), ':', ' ');
        replace(line.begin(), line.end(), ',', ' ');
        stringstream ss (line);
        string person;

        ss >> person;
        Element e(person);
        while(ss >> person) {
            e.addPreference(person);
        }
        addElement(e);
    }
}

Element* SetOfElements::getElement(string name) {
    for(auto& e : set) {
        if(e.getName() == name) return &e;
    }
    return nullptr;
}

Element* SetOfElements::getFirstUnmatched() {
    for(auto& e : set) {
        if(!e.isPaired()) return &e;
    }
    return nullptr;
}

void SetOfElements::print() {
    for(auto& s : set) {
        cout << s.getName() << ": ";
        for(auto& p : s.getPreferences()) {
            cout << p << ",";
        }
        cout << endl;
    }
    cout << endl;
}