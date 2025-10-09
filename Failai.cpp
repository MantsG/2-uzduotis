#include "Failai.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using std::string;
using std::ofstream;
using std::cout;
using std::endl;
using std::vector;
using std::ifstream;

void GeneruotiFaila(const string& failoVardas, int kiek){
    ofstream out(failoVardas);
    if(!out){
        cout<<"Nepavyko sukurti failo"<<failoVardas<<"\n";
        return;
    }

    out<<"Vardas Pavarde";
    for(int i=1; i<=10; i++) out<<" ND"<<i;
    out<<" Egz"<<endl;

    for(int i=1; i<=kiek; i++){
        out<<"Vardas"<<i<<" Pavarde"<<i;
        for(int j=0; j<10; j++){
            out<<" "<<(rand() % 10 + 1);
        }
        out<<" "<<(rand() % 10 + 1)<<endl;
    }
    cout<<"Sugeneruotas failas: "<<failoVardas<<" ("<<kiek<<" irasai)\n";
}

vector<Studentas> SkaitytiFaila(const string &failoVardas){
    vector<Studentas> grupe;
    ifstream in(failoVardas);
    if(!in){
        cout<<"Nepavyko atidaryti failo"<<endl;
        return grupe;
        }
    string vard, pavarde;
    string header;
    std::getline(in, header);

    while(in >> vard >> pavarde){
        Studentas s;
        s.var = vard;
        s.pav = pavarde;
        s.nd.clear();

        int paz;
        vector<int> laik;
        string restOfLine;
        getline(in, restOfLine);
        std::istringstream iss(restOfLine);
        while(iss>>paz){
            laik.push_back(paz);
        }

        if(!laik.empty()){
            s.egz = laik.back();
            laik.pop_back();
            s.nd = laik;

            double vid = 0;
            for(int x: s.nd) vid += x;
            if(!s.nd.empty()) vid /= s.nd.size();
            s.galVid = vid*0.4 + 0.6*s.egz;
            s.galMed = median(s.nd)*0.4 + 0.6*s.egz;
        }
        grupe.push_back(s);
    }
    return grupe;
}
