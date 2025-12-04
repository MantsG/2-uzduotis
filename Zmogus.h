#pragma once
#include "Zmogus.h"
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>
#include <algorithm>
#include "Utils.h"

//#define NAUDOTI_VECTOR
#define NAUDOTI_LIST

#ifdef NAUDOTI_LIST
    using Konteineris = std::list<class Studentas>;
#else
    using Konteineris = std::vector<class Studentas>;
#endif

class Studentas : public Zmogus{
private:
    std::vector <int> nd_;
    int egzaminas_ = 0;
    double galVid_ = 0.0;
    double galMed_ = 0.0;


public:
    
    Studentas() = default;
    Studentas(std::istream& is){read(is);}
    Studentas(const Studentas& other) = default;
    Studentas& operator=(const Studentas& other) = default;
    
    ~Studentas() = default;

    const std::vector<int>& nd() const {return nd_;}
    int egzaminas() const {return egzaminas_;}
    double galVid() const {return galVid_;}
    double galMed() const {return galMed_;}

    void setEgzaminas(int e) {egzaminas_ = e;}
    void setNd(const std::vector<int>& n) {nd_ = n;}
    void addNd(int paz) {nd_.push_back(paz);}

    void skaiciuotiGalutinis();

    double galBalas(double (*skaiciavimas)(std::vector<int>&) = median) const;

    std::ostream& write(std::ostream& os) const override;
    std::istream& read(std::istream& is) override;

    friend std::ostream& operator<<(std::ostream& os, const Studentas& s){
        return s.write(os);
    }
    friend std::istream& operator>>(std::istream& is, Studentas& s){
        return s.read(is);
    }
};

bool compare(const Studentas& a, const Studentas& b);
bool comparePagalPavarde(const Studentas& a, const Studentas& b);
bool comparePagalEgza(const Studentas& a, const Studentas& b);
