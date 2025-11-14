#pragma once
#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Utils.h"

//#define NAUDOTI_VECTOR
#define NAUDOTI_LIST

#ifdef NAUDOTI_LIST
    using Konteineris = std::list<Studentas>;
#else
    using Konteineris = std::vector<Studentas>;
#endif

class Studentas{
private:
    std::string var;
    std::string pav;
    std::vector <int> nd;
    int egzaminas_;
    double galVid_;
    double galMed_;
};
