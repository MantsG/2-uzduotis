#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include "Studentas.h"
#include "Utils.h"
#include "Failai.h"
#include "Ivedimas.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::setw;
using std::left;
using std::right;
using std::fixed;
using std::setprecision;
using std::sort;
using std::ifstream;
using std::ofstream;




int main(){
    
    srand(time(0));
    
    cout<<"Ar generuoti 5 studentu failus (1k, 10k, 100k, 1m, 10m)? 1 - taip, 2 - ne: ";
    string genStr;
    cin>>genStr;
    if(!genStr.empty() && all_of(genStr.begin(), genStr.end(), ::isdigit) && stoi(genStr) == 1){
        cout<<"Pradedam generuoti failus...\n";
        GeneruotiFaila("Studentai1000.txt", 1000);
        GeneruotiFaila("Studentai10000.txt", 10000);
        GeneruotiFaila("Studentai100000.txt", 100000);
        GeneruotiFaila("Studentai1000000.txt", 1000000);
        GeneruotiFaila("Studentai10000000.txt", 10000000);
        cout<<"Generavimas baigtas.\n";
    }
    vector <Studentas> Grupe;

    
    cout<<"Pasirinkite duomenu isvedimo buda: "<<endl;
    cout<<"1 - Ivesti ranka"<<endl;
    cout<<"2 - Generuoti atsitiktinai"<<endl;
    cout<<"3 - Nuskaityti is failo"<<endl;

    int ivBudas;
    string ivBudasStr;

    while(true){
        cin>>ivBudasStr;
        if(!ivBudasStr.empty() && all_of(ivBudasStr.begin(), ivBudasStr.end(), ::isdigit)){
            ivBudas = stoi(ivBudasStr);
            if(ivBudas >= 1 && ivBudas <= 3) break;
        }
        cout<<"Neteisinga ivestis, iveskite skaiciu 1, 2 arba 3"<<endl;
    }

    if(ivBudas == 3){
        Grupe = SkaitytiFaila("studentai10000.txt");
        
        if(Grupe.empty()){
            cout<<"Programa uždaroma, nes nepavyko nuskaityti failo"<endl;
            return 0;
        }
    }        
    else{
        int m;
        string mStr;
        
        while(true){
            cout<<"Kiek studentu grupeje? "<<endl;
            cin>>mStr;

            if(!mStr.empty() && all_of(mStr.begin(), mStr.end(), ::isdigit)){
                m = stoi(mStr);
                if(m >=1){
                    break;
                }
            }
            cout<<"Neteisinga ivestis, turi buti skaicius lygus arba didesnis uz 1"<<endl;
        }
        
        bool atsitiktinis = (ivBudas == 2);
        for(auto z=0; z<m; z++){
            Grupe.push_back(Stud_iv(atsitiktinis));
        }
    }
    
    int pasirinkimas;
    string pasirinkimasStr;

    while(true){
        cout<<"Pasirinkite galutinio balo skaiciavimo buda: "<<endl;
        cout<<"1 - Vidurkis"<<endl;
        cout<<"2 - Mediana"<<endl;
        cout<<"3 - Abu"<<endl;

        cin>>pasirinkimas Str;

        if(!pasirinkimasStr.empty() && all_of(pasirinkimasStr.begin(), pasirinkimasStr.end(), ::isdigit)){
            pasirinkimas = stoi(pasirinkimasStr);
            if(pasirinkimas >= 1 && pasirinkimasStr <= 3) break;
        }
        cout<<"Neteisinga ivestis, iveskite skaiciu 1, 2 arba 3"<<endl;
    }

    int rusiavimas;
    string rusiavimasStr;
    while(true){
        cout<<"Pasirinkite rusiavimo buda: "<<endl;
        cout<<"1 - pagal varda"<<endl;
        cout<<"2 - pagal pavarde"<<endl;
        cin>>rusiavimasStr;
        if(!rusiavimasStr.empty() && all_of(rusiavimasStr.begin(), rusiavimasStr.end(), ::isdigit)){
            rusiavimas = stoi(rusiavimasStr);
            if(rusiavimas == 1 || rusiavimas == 2) break;
        }
        cout<<"Neteisingas ivestis, iveskite skaiciu 1 arba 2"<<endl;
    }
    
    if(rusiavimas == 1){
        sort(Grupe.begin(), Grupe.end(), [](const Studentas &a, const Studentas &b){
            return naturalCompare(a.var, b.var);
        }};
    }else{ 
        sort(Grupe.begin(), Grupe.end(), [](const Studentas &a, const Studentas &b){
        return naturalCompare (a.pav, b.pav);
    });
}
    
    vector<Studentas> vargsiukai;
    vector<Studentas> kietiakai;

    for(const auto &s: Grupe){
        double galutinis = (pasirinkimas == 1? s.galVid : (pasirinkimas == 2 ? s.galMed : s.galVid));
        if(galutinis < 5.0) vargsiukai.push_back(s);
        else kietiakai.push_back(s);
    }

    if(rusiavimas == 1){
        sort(vargsiukai.begin(), vargsiukai.end(), [](const Studentas &a, const Studentas &b){
            return naturalCompare(a.var, b.var);
        });
        sort(kietiakai.begin(), kietiakai.end(), [](const Studentas &a, const Studentas &b){
            return naturalCompare(a.var, b.var);
        });
    } else{
        sort(vargsiukai.begin(), vargsiukai.end(), [](const Studentas &a, const Studentas &b){
             return naturalCompare(a.pav, b.pav);
        });
        sort(kietiakai.begin(), kietiakai.end(), [](const Studentas &a, const Studentas &b){
             return naturalCompare(a.pav, b.pav);
        });
    }

    ofstream outV("vargsiukai.txt");
    ofstream outK("kietiakai.txt");

    auto spausdinti = [&](ofstream &out, const vector<Studentas>& grupe){
        out<<setw(15)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde";
        if(pasirinkimas == 1) out<<setw(16)<<left<<"Galutinis (Vid.)"<<endl;
        else if(pasirinkimas == 2) out<<setw(16)<<left<<"Galutinis (Med.)"<<endl;
        else out<<setw(18)<<left<<"Galutinis (Vid.)"<<setw(16)<<left<<"Galutinis (Med.)"<<endl;
        out<<"---------------------------------------------------------------------"<<endl;

        for(const auto &s: grupe){
            out<<setw(15)<<left<<s.var<<setw(20)<<left<<s.pav;
            if(pasirinkimas == 1) out<<setw(16)<<left<<fixed<<setprecision(2)<<s.galVid<<endl;
            else if(pasirinkimas == 2) out<<setw(16)<<left<<fixed<<setprecision(2)<<s.galMed<<endl;
            else out<<setw(18)<<left<<fixed<<setprecision(2)<<s.galVid<<setw(16)<<left<<fixed<<setprecision(2)<<s.galMed<<endl;
    }
};

spausdinti(outV, vargsiukai);
spausdinti(outK, kietiakai);


}
