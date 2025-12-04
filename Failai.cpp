#include "Failai.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Studentas.h"

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

    out<<"# Vardas Pavarde NDCount ND1 ND2 ... Egz"<<endl;

    for(int i=1; i<=kiek; i++){
        int nd_kiekis = rand()%10 + 1;
        out<<"Vardas"<<i<<" Pavarde"<<i<<" "<<nd_kiekis;
        for(int j=0; j<nd_kiekis; j++){
            out<<" "<<(rand() % 10 + 1);
        }
        out<<" "<<(rand() % 10 + 1)<<endl;
    }
    cout<<"Sugeneruotas failas: "<<failoVardas<<" ("<<kiek<<" irasai)\n";
}

Konteineris SkaitytiFaila(const string &failoVardas){
    Konteineris grupe;
    ifstream in(failoVardas);
    if(!in){
        cout<<"Nepavyko atidaryti failo "<<failoVardas<<endl;
        return grupe;
        }
    
   string line;
    while(std::getline(in, line)){
        if(line.empty()) continue;
        if(line[0] == '#') continue;
        std::istringstream iss(line);
        Studentas s;
        if(!(iss >> s)){
            cout<<"Demesio: nepavyko nuskaityti eilutes: "<<line<<endl;
            continue;
        }
        grupe.push_back(s);
    }
    return grupe;
}
