#include "Studentas.h"
#include <iomanip>

Studentas::Studentas(const Studentas& other){
    vardas_ = other.vardas_;
    pavarde_ = other.pavarde_;
    nd_ = other.nd_;
    egzaminas_ = other.egzaminas_;
    galVid_ = other.galVid_;
    galMed_ = other.galMed_;
}

Studentas& Studentas::operator=(const Studentas& other){
    if(this != &other){
        vardas_ = other.vardas_;
        pavarde_ = other.pavarde_;
        nd_ = other.nd_;
        egzaminas_ = other.egzaminas_;
        galVid_ = other.galVid_;
        galMed_ = other.galMed_;
    }
    return *this;
}

double Studentas::galBalas(double (*skaiciavimas)(std::vector<int>&)) const{
    if (nd_.empty()) return 0.6 * egzaminas_;
    std::vector<int> kopija = nd_;
    return skaiciavimas(kopija) * 0.4 + 0.6 * egzaminas_;
}

std::istream& Studentas::readStudent(std::istream& is){
     std::string v, p;
    if(!(is >> v >> p)) return is;
    vardas_ = v;
    pavarde_ = p;
    
    int ndCount;
    if(!(is >> ndCount)){
        is.setstate(std::ios::failbit);
        return is;
    }
    if(ndCount < 0) ndCount = 0;
    nd_.clear();
     for(int i=0; i<ndCount; ++i){
        int paz;
        if(!(is >> paz)){
            is.setstate(std::ios::failbit);
            return is;
        }
        skaiciuotiGalutinis();
        return is;
    }

    std::ostream& operator<<(std::ostream& os, const Studentas& s){
    os<<std::left<<std::setw(15)<<s.vardas_
      <<std::left<<std::setw(20)<<s.pavarde_
      <<std::fixed<<std::setprecision(2)
      <<std::left<<std::setw(16)<<s.galVid_
      <<std::left<<std::setw(16)<<s.galMed_;
      return os;
        
}

void Studentas::skaiciuotiGalutinis(){
    if(nd_.empty()){
        galVid_=galMed_=0.6*egzaminas_;
        return;
    }
    double vid = 0.0;
    for(int paz: nd_) vid+=paz;
    vid /= static_cast<double>(nd_.size());
    galVid_ = vid*0.4+0.6*egzaminas_;
    galMed_ = median(const_cast<std::vector<int>&>(nd_))*0.4+0.6*egzaminas_;
}

double Studentas::galBalas(double(*skaiciavimas)(std::vector<int>&)) const{
    if (nd_.empty()) return 0.6 * egzaminas_;
    std::vector<int> kopija = nd_;
    return skaiciavimas(kopija) * 0.4 + 0.6 * egzaminas_;
}

bool compare(const Studentas& a, const Studentas& b){
    return a.vardas() < b.vardas();
}

bool comparePagalPavarde(const Studentas& a, const Studentas& b){
    return a.pavarde() < b.pavarde();
}

bool comparePagalEgza(const Studentas& a, const Studentas& b){
    return a.egzaminas() < b.egzaminas();
}
