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
    std::string vardas_;
    std::string pavarde_;
    std::vector <int> nd_;
    int egzaminas_= 0;
    double galVid_ = 0.0;
    double galMed_= 0.0;


public:

    Studentas()= default;
    Studentas(const Studentas& other);
    Studentas& operator=(const Studentas& other);

    const std::string& vardas() const override {return vardas_;}
    const std::string& pavarde() const override {return pavarde_;}
    
    std::istream& read(std::istream& is) override;
    std::ostream& write(std::ostream& os) const override;

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

    void skaiciuotiGalutinis();

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
