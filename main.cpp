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

#define NAUDOTI_VECTOR
//#define NAUDOTI_LIST

#ifdef NAUDOTI_VECTOR
using Konteineris = std::vector<Studentas>;
#else
using Konteineris = std::list<Studentas>;
#endif

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
            case 1: GeneruotiFaila("Studentai1000.txt", 1000); failoVardas = "Studentai1000.txt"; break;
            case 2: GeneruotiFaila("Studentai10000.txt", 10000); failoVardas = "Studentai10000.txt"; break;
            case 3: GeneruotiFaila("Studentai100000.txt", 100000); failoVardas = "Studentai100000.txt"; break;
            case 4: GeneruotiFaila("Studentai1000000.txt", 1000000); failoVardas = "Studentai1000000.txt"; break;
            case 5: GeneruotiFaila("Studentai10000000.txt", 10000000); failoVardas = "Studentai10000000.txt"; break;
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
        auto startSkaitymas = high_resolution_clock::now();

        Grupe = SkaitytiFaila(failoVardas);

        auto endSkaitymas = high_resolution_clock::now();
        auto trukmeSkaitymas = duration_cast<milliseconds>(endSkaitymas - startSkaitymas).count();
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

            if(!atsitiktinis){
                cout<<"Studento objektas saugomas adresu: " << &Grupe.back() <<endl;
            }
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

    auto startSkirstymas = high_resolution_clock::now();

    Konteineris vargsiukai;
    Konteineris kietiakai;

    auto strat1_start = high_resolution_clock::now();
    for(const auto &s: Grupe){
        double galutinis = (pasirinkimas == 1? s.galVid : (pasirinkimas == 2 ? s.galMed : s.galVid));
        if(galutinis < 5.0) vargsiukai.push_back(s);
        else kietiakai.push_back(s);
    }

#ifdef NAUDOTI_VECTOR
vargsiukai.shrink_to_fit();
kietiakai.shrink_to_fit();
#endif // NAUDOTI_VECTOR
    auto strat1_end = high_resolution_clock::now();
    auto trukmeStrat1 = duration_cast<milliseconds>(strat1_end - strat1_start).count();
    if(trukmeStrat1 > 1000)
            cout<<"1 strategijos rusiavimas uztruko: "<<trukmeStrat1/1000.0<<" s\n";
        else
            cout<<"1 strategijos rusiavimas uztruko: "<<trukmeStrat1<<" ms\n";

    auto strat2_start = high_resolution_clock::now();
    Konteineris vargsiukai2;
#ifdef NAUDOTI_VECTOR
   auto midle = std::partition(Grupe.begin(), Grupe.end(), [&](const Studentas &s){
       double galutinis = (pasirinkimas == 1 ? s.galVid : (pasirinkimas == 2 ? s.galMed : s.galVid));
       return galutinis < 5.0;
   });
    vargsiukai2.insert(vargsiukai2.end(), Grupe.begin(), midle);
    Grupe.erase(Grupe.begin(), midle);
    vargsiukai2.shrink_to_fit();
    Grupe.shrink_to_fit();
#else
    for(auto it = Grupe.begin(); it != Grupe.end(); ){
        double galutinis = (pasirinkimas == 1? it->galVid : (pasirinkimas == 2? it->galMed : it->galVid));
        if(galutinis < 5.0){
            auto toMove = it++;
            vargsiukai2.splice(vargsiukai2.end(), Grupe, toMove);
        }else ++it;
    }

#endif // NAUDOTI_VECTOR
    auto strat2_end = high_resolution_clock::now();
    auto trukmeStrat2 = duration_cast<milliseconds>(strat2_end - strat2_start).count();
    if(trukmeStrat2 > 1000)
        cout<<"2 strategijos rusiavimas uztruko: "<<trukmeStrat2/1000.0<<" s\n";
    else
        cout<<"2 strategijos rusiavimas uztruko: "<<trukmeStrat2<<" ms\n";

    auto strat3_start = high_resolution_clock::now();
    Konteineris vargsiukai3;
    Konteineris kietiakai3;
#ifdef NAUDOTI_VECTOR
        auto middle = std::stable_partition(Grupe.begin(), Grupe.end(), [&](const Studentas &s){
            double galutinis = (pasirinkimas == 1? s.galVid : (pasirinkimas == 2 ? s.galMed : s.galVid));
            return galutinis < 5.0;
        });
        vargsiukai3.insert(vargsiukai3.end(), Grupe.begin(), middle);
        kietiakai3.insert(kietiakai3.end(), middle, Grupe.end());

        vargsiukai3.shrink_to_fit();
        kietiakai3.shrink_to_fit();
#else
    for(auto it = Grupe.begin(); it != Grupe.end(); ){
        double galutinis = (pasirinkimas == 1? it->galVid : (Pasirinkimas == 2 ? it->galMed : it->galVid));
        if(galutinis < 5.0){
            auto toMove = it++;
            vargsiukai3.splice(vargsiukai3.end(), Grupe, toMove);
        }else ++it;
    }
    kietiakai 3 = Grupe;
#endif // NAUDOTI_VECTOR
    auto strat3_end = high_resolution_clock::now();
    auto trukmeStrat3 = duration_cast<milliseconds>(strat3_end - strat3_start).count();
    if(trukmeStrat3 > 1000)
        cout<<"3 strategijos rusiavimas uztruko: "<<trukmeStrat3/1000.0<<" s\n";
    else
        cout<<"3 strategijos rusiavimas uztruko: "<<trukmeStrat3<<" ms\n";
#ifdef NAUDOTI_LIST
    if (pasirinkimas == 1){
        vargsiukai.sort([](const Studentas &a, const Studentas &b){
            return a.galVid < b.galVid;
        });
        kietiakai.sort([](const Studentas &a, const Studentas &b){
            return a.galVid < b.galVid;
        });
    } else if (pasirinkimas == 2) {
        vargsiukai.sort([](const Studentas &a, const Studentas &b){
            return a.galMed < b.galMed;
        });
        kietiakai.sort([](const Studentas &a, const Studentas &b){
            return a.galMed < b.galMed;
        });
    } else {
        vargsiukai.sort([](const Studentas &a, const Studentas &b){
            return a.galVid < b.galVid;
        });
        kietiakai.sort([](const Studentas &a, const Studentas &b){
            return a.galVid < b.galVid;
        });
    }
#else
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
#endif
    
    auto endSkirstymas = high_resolution_clock::now();
    auto trukmeSkirstymas = duration_cast<milliseconds>(endSkirstymas - startSkirstymas).count();
    if (trukmeSkirstymas > 1000)
        cout<<"Failo rusiavimas ir skirstymas uztruko: "<<trukmeSkirstymas/1000.0<<" s\n";
    else
        cout<<"Failo rusiavimas ir skirstymas uztruko: "<<trukmeSkirstymas<<" ms\n";

    
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

    outV.close();
    outK.close();
    
    auto endIsvedimas = high_resolution_clock::now();
    auto trukmeIsvedimas = duration_cast<milliseconds>(endIsvedimas - startIsvedimas).count();
    if(trukmeIsvedimas >1000)
        cout<<"Failo isvedimas uztruko: "<<trukmeIsvedimas/1000.0<<" s\n";
    else
        cout<<"Failu isvedimas uztruko: "<<trukmeIsvedimas<<" ms\n";

}
