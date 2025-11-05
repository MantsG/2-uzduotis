#pragma once
#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

struct Studentas{
    std::string var;
    std::string pav;
    std::vector <int> nd;
    int egz;
    double galVid;
    double galMed;
};

#define NAUDOTI_VECTOR
//#define NAUDOTI_LIST

#ifdef NAUDOTI_LIST
    using Konteineris = std::list<Studentas>;
#else
    using Konteineris = std::vector<Studentas>;
#endif
