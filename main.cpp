#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include "Studentas.h"
#include "Utils.h"
#include "Failai.h"
#include "Ivedimas.h"
#include <chrono>
#include <vector>
#include <list>

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
using namespace std::chrono;

using Konteineris = std::vector<Studentas>;

int main(){

    string failoVardas;
    
    srand(time(0));

    cout<<"Pasirinkite faila generuoti (0 - negeneruoti failo):\n";
    cout<<"1 - 1000 studentu failas\n";
    cout<<"2 - 10000 studentu failas\n";
    cout<<"3 - 100000 studentu failas\n";
    cout<<"4 - 1000000 studentu failas\n";
    cout<<"5 - 10000000 studentu failas\n";

    int GenPasirinkimas;
    string GenPasirinkimasStr;
    while(true){
        cin>>GenPasirinkimasStr;
        if(!GenPasirinkimasStr.empty() && all_of(GenPasirinkimasStr.begin(), GenPasirinkimasStr.end(), ::isdigit)){
            GenPasirinkimas = stoi(GenPasirinkimasStr);
            if(GenPasirinkimas >= 0 && GenPasirinkimas <= 5) break;
        }
    cout<<"Neteisinga ivestis, iveskite skaiciu nuo 0 iki 5\n";
    }

    if(GenPasirinkimas != 0){
        auto startGen = high_resolution_clock::now();
        switch(GenPasirinkimas){
            case 1: GeneruotiFaila("Studentai1000.txt", 1000); break;
            case 2: GeneruotiFaila("Studentai10000.txt", 10000); break;
            case 3: GeneruotiFaila("Studentai100000.txt", 100000); break;
            case 4: GeneruotiFaila("Studentai1000000.txt", 1000000); break;
            case 5: GeneruotiFaila("Studentai10000000.txt", 10000000); break;
        }
        auto endGen = high_resolution_clock::now();
        auto trukmeGen = duration_cast<milliseconds>(endGen - startGen).count();

        if(trukmeGen > 1000)
            cout<<"Failo generavimas uztruko: "<<fixed<<setprecision(2)<<trukmeGen/1000.0<<" s\n";
        else
            cout<<"Failo generavimas uztruko: "<<trukmeGen<<" ms\n";
    }else {
        cout<<"Failo generavimas nepasirinktas.\n";
    }
    
    Konteineris Grupe;

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
        if(failoVardas.empty()){
            cout<<"Iveskite failo pavadinimas nuskaitymui: ";
            cin>>failoVardas;
        }
        auto start_skaitymas = high_resolution_clock::now();

        Grupe = SkaitytiFaila(failoVardas);

        auto endSkaitymas = high_resolution_clock::now();
        auto trukmeSkaitymo = duration_cast<milliseconds>(endSkaitymas - startSkaitymas).count();
        if(trukmeSkaitymas > 1000)
            cout<<"Failo nuskaitymas uztruko: "<<trukmeSkaitymas/1000.0<<" s\n";
        else
            cout<<"failo nuskaitymas uztruko: "<<trukmeSkaitymas<<" ms\n";
        if(Grupe.empty()){
            cout<<"Programa uždaroma, nes nepavyko nuskaityti failo"<<endl;
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

        cin>>pasirinkimasStr;

        if(!pasirinkimasStr.empty() && all_of(pasirinkimasStr.begin(), pasirinkimasStr.end(), ::isdigit)){
            pasirinkimas = stoi(pasirinkimasStr);
            if(pasirinkimas >= 1 && pasirinkimas <= 3) break;
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

    auto startSkirstymas = high_resolution_clock::now();

    Konteineris vargsiukai;
    Konteineris kietiakai;

    for(const auto &s: Grupe){
        double galutinis = (pasirinkimas == 1? s.galVid : (pasirinkimas == 2 ? s.galMed : s.galVid));
        if(galutinis < 5.0) vargsiukai.push_back(s);
        else kietiakai.push_back(s);
    }

    if(pasirinkimas == 1){
        sort(vargsiukai.begin(), vargsiukai.end(), [](const Studentas &a, const Studentas &b){
            return a.galVid < b.galVid;
        });
        sort(kietiakai.begin(), kietiakai.end(), [](const Studentas &a, const Studentas &b){
            return a.galVid < b.galVid;
        });
    } else if (pasirinkimas == 2) {
        sort(vargsiukai.begin(), vargsiukai.end(), [](const Studentas &a, const Studentas &b){
            return a.galMed < b.galMed;
        });
        sort(kietiakai.begin(), kietiakai.end(), [](const Studentas &a, const Studentas &b){
            return a.galMed < b.galMed;
        });
    } else{
        sort(vargsiukai.begin(), vargsiukai.end(), [](const Studentas &a, const Studentas &b){
             return a.galVid < b.galVid;
        });
        sort(kietiakai.begin(), kietiakai.end(), [](const Studentas &a, const Studentas &b){
             return a.galVid < b.galVid;
        });
    }
    
    auto endSkirstymas = high_resolution_clock::now();
    auto trukmeSkirstymas = duration_cast<milliseconds>(endSkirstymas - startSkirstymas).count();
    if (trukmeSkirstymas > 1000)
        cout<<"Failo rusiavimas ir isvedimas uztruko: "<<trukmeSkirstymas/1000.0<<" s\n";
    else
        cout<<"Failu rusiavimas ir isvedimas uztruko: "<<trukmeSkirstymas<<" ms\n";

    
    auto startIsvedimas = high_resolution_clock::now();
    
    ofstream outV("vargsiukai.txt");
    ofstream outK("kietiakai.txt");

       auto spausdinti = [&](ofstream &out, const Konteineris& grupe){
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


    auto endIsvedimas = high_resolution_clock::now();
    auto trukmeIsvedimas = duration_cast<milliseconds>(endIsvedimas - startIsvedimas).count();
    if(trukmeIsvedimas >1000)
        cout<<"Failo isvedimas uztruko: "<<trukmeSkirstymas/1000.0<<" s\n";
    else
        cout<<"Failu isvedimas uztruko: "<<trukmeSkirstymas<<" ms\n";


}
