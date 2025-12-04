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
    is>>vardas_>>pavarde_;
    nd_.clear();
    int paz;
    for(int i=0; i<10; i++){
        if(!(is>>paz)){
            return is;
        }
        nd_.push_back(paz);
    }
    if(!(is>>egzaminas_)){
        return is;
    }
    skaiciuotiGalutinis();
    return is;
}

void Studentas::skaiciuotiGalutinis(){
    if(nd_.empty()){
        galVid_=galMed_=0.6*egzaminas_;
        return;
    }
    double vid=0;
    for(int paz: nd_) vid+=paz;
    vid/=nd_.size();
    galVid_=vid*0.4+0.6*egzaminas_;
    galMed_=median(nd_)*0.4+0.6*egzaminas_;
}

std::ostream& operator<<(std::ostream& os, const Studentas& s){
    os<<std::left<<std::setw(15)<<s.vardas_
      <<std::left<<std::setw(20)<<s.pavarde_
      <<std::fixed<<std::setprecision(2)
      <<std::left<<std::setw(16)<<s.galVid_
      <<std::left<<std::setw(16)<<s.galMed_;
      return os;
}

std::istream& operator>>(std::istream& is, Studentas& s){
    return s.readStudent(is);
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







