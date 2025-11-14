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


public:
    Studentas() : egzaminas_(0), galVid_(0), galMed_(0) {}
    Studentas(std::istream& is) {readStudent(is);}
    
    inline string vardas() const {return vardas_;}
    inline string pavarde() const {return pavarde_;}
    inline double galVid() const {return galVid_;}
    inline double galMed() const {return galMed_;}
    inline int egzaminas() const {return egzaminas_;}
    inline const vector<int>& nd() const {return nd_;}

    inline void setVardas(const string& v) {vardas_ = v;}
    inline void setPavarde(const string& p) {pavarde_ = p;}
    inline void setEgzaminas(int e) {egzaminas_ = e;}
    inline void setNd(const vector<int>& n) {nd_ = n;}
    inline void addNd(int paz) {nd_.push_back(paz);}

    double galBalas(double (*skaiciavimas)(vector<int>&) = median) const;
    std::istream& readStudent(std::istream& is);
    void skaiciuotiGalutinis();

    friend std::ostream& operator<<(std::ostream& os, const Studentas& s);
};

bool compare(const Studentas& a, const Studentas& b);
bool comparePagalPavarde(const Studentas& a, const Studentas& b);
bool comparePagalEgza(const Studentas&a, const Studentas& b);
