#pragma once

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Element {
    string name;
    vector<string> preferences;
    vector<Element*> proposals;
    vector<bool> proposed;
    bool paired = false;

public:
    Element(string name) : name(name) {}

    string getName() {return name;}
    bool isPaired() {return paired;}
    void setPaired() {paired = true;}
    void makeSingle() {paired = false;}
    void propose(string name);
    void addPreference(string pref) {
        preferences.push_back(pref);
        proposed.push_back(false);
    }
    int getRank(string name);
    vector<string> getPreferences() {return preferences;}
    string getBestUnproposed();
};

class SetOfElements {
    vector<Element> set;

public:
    SetOfElements(string filePath);

    void addElement(Element e) {set.push_back(e);}
    Element* getElement(string name);
    Element* getFirstUnmatched();
    vector<Element>& getElements() {return set;}
    void print();
};