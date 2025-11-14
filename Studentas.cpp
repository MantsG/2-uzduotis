#include "Studentas.h"
#include <iomanip>

double Studentas::galBalas(double (*skaiciaviams)(std::vector<int>&)) const{
    if (nd_.empty()) return 0.6 * egzaminas_;
    std::vector<int> kopija = nd_;
    return skaiciavimas(kopija) * 0.4 + 0.6 * egzaminas_;
}
