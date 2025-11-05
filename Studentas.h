#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

#include <string>
#include <vector>

struct Studentas{
    std::string var;
    std::string pav;
    std::vector <int> nd;
    int egz;
    double galVid;
    double galMed;
};

#define NAUDOTI_LIST// uzkomentuoti, kad naudoti vector

#ifdef NAUDOTI_LIST
    using Konteineris = std::list<Studentas>;
#else
    using Konteineris = std::vector<Studentas>;
#endif
