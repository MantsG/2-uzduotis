#pragma once
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

class Zmogus{
protected:
    std::string vardas_;
    std:: string pavarde_;

public:
    Zmogus() = default;
    Zmogus(const std::string& vardas, const std::string& pavarde)
        : vardas_(vardas), pavarde_(pavarde) {}

    virtual ~Zmogus() = default;

    virtual void spausdintiInfo(std::ostream& os) const = 0;
    virtual void skaitytiInfo(std::istream& is) = 0;

    inline std::string vardas() const { return vardas_; }
    inline std::string pavarde() const { return pavarde_; }

    inline void setVardas(const std::string& v) { vardas_ = v; }
    inline void setPavarde(const std::string& p) { pavarde_ = p; }

    virtual Zmogus& operator=(const Zmogus& other){
        if (this != &other){
            vardas_ = other.vardas_;
            pavarde_ = other.pavarde_;
        }
        return *this;
    }
};

class Studentas : public Zmogus{
private:
    std::vector<int> nd_;
    int egzaminas_;
    double galVid_;
    double galMed_;


public:
    Studentas() : egzaminas_(0), galVid_(0), galMed_(0) {}
    Studentas(const std::string& vardas, const std::string& pavarde)
        : Zmogus(vardas, pavarde), egzaminas_(0), galVid_(0), galMed_(0) {}
    Studentas(std::istream& is) { readStudent(is); }

    Studentas(const Studentas& other);

    Studentas& operator=(const Studentas& other);

    ~Studentas() override;

    void spausdintiInfo(std::ostream& os) const override;
    void skaitytiInfo(std::istream& is) override;

    inline double galVid() const { return galVid_; }
    inline double galMed() const { return galMed_; }
    inline int egzaminas() const { return egzaminas_; }
    inline const std::vector<int>& nd() const { return nd_; }

    inline void setEgzaminas(int e) { egzaminas_ = e; }
    inline void setNd(const std::vector<int>& n) { nd_ = n; }
    inline void addNd(int paz) { nd_.push_back(paz); }

    void pridetiNd(int pazymys) { nd_.push_back(pazymys); }

    double galBalas(double (*skaiciavimas)(std::vector<int>&) = median) const;
    std::istream& readStudent(std::istream& is);
    void skaiciuotiGalutinis();

    friend std::ostream& operator<<(std::ostream& os, const Studentas& s);
    friend std::istream& operator>>(std::istream& is, Studentas& s);
};

bool compare(const Studentas& a, const Studentas& b);
bool comparePagalPavarde(const Studentas& a, const Studentas& b);
bool comparePagalEgza(const Studentas& a, const Studentas& b);
