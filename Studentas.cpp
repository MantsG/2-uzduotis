#include "Studentas.h"
#include <iomanip>

double Studentas::galBalas(double (*skaiciaviams)(std::vector<int>&)) const{
    if (nd_.empty()) return 0.6 * egzaminas_;
    std::vector<int> kopija = nd_;
    return skaiciavimas(kopija) * 0.4 + 0.6 * egzaminas_;
}

std::istream& Studentas::readStudent(std::istream& is){
    is>>vardas_>>pavarde_;
    nd_.clear();
    int paz;
    for(int i=0; i<10; i++){
        if(!(is>>paz)) break;
        nd_.push_back(paz);
    }
    is>>egzaminas_;
    skaiciuotiGalutinis();
    return is;
}
