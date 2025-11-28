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
    using Konteineris = std::list<class Studentas>;
#else
    using Konteineris = std::vector<class Studentas>;
#endif

class Studentas{
private:
    std::string vardas_;
    std::string pavarde_;
    std::vector <int> nd_;
    int egzaminas_;
    double galVid_;
    double galMed_;


public:
    Studentas() : egzaminas_(0), galVid_(0), galMed_(0) {}
    Studentas(std::istream& is) {readStudent(is);}
    
    ~Studentas();
    Studentas(const Studentas& other);
    Studentas& operator=(const Studentas& other);

    inline std::string vardas() const {return vardas_;}
    inline std::string pavarde() const {return pavarde_;}
    inline double galVid() const {return galVid_;}
    inline double galMed() const {return galMed_;}
    inline int egzaminas() const {return egzaminas_;}
    inline const std::vector<int>& nd() const {return nd_;}

    inline void setVardas(const std::string& v) {vardas_ = v;}
    inline void setPavarde(const std::string& p) {pavarde_ = p;}
    inline void setEgzaminas(int e) {egzaminas_ = e;}
    inline void setNd(const std::vector<int>& n) {nd_ = n;}
    inline void addNd(int paz) {nd_.push_back(paz);}

    void pridetiNd(int pazymys) { nd_.push_back(pazymys); }

    double galBalas(double (*skaiciavimas)(std::vector<int>&) = median) const;
    std::istream& readStudent(std::istream& is);
    void skaiciuotiGalutinis();

    friend std::ostream& operator<<(std::ostream& os, const Studentas& s);
};

bool compare(const Studentas& a, const Studentas& b);
bool comparePagalPavarde(const Studentas& a, const Studentas& b);
bool comparePagalEgza(const Studentas&a, const Studentas& b);
