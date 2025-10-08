#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cctype>

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

struct Studentas{
    string var;
    string pav;
    vector <int> nd;
    int egz;
    double galVid;
    double galMed;
    };

bool naturalCompare(const string& a, const string& b){
    size_t i=0, j=0;
    while(i < a.size() && j < b.size()){
        if(std::isdigit(static_cast<unsigned char>(a[i])) && std:isdigit(static_cast<unsigned char>(b[j]))){
            size_t i2 = i;
            while(i2 < a.size() && std::isdigit(static_cast<unsigned char>(a[i2]))) ++i2;
            size_t j2 = j;
            while(j2 < b.size() && std::isdigit(static_cast<unsigned char>(b[j2]))) ++j2;

            int numA = 0;
            for(size_t k=i; k<i2; ++k) numA = numA*10 + (a[k]-'0');
            int numB = 0;
            for(size_t k=j; k<i2; ++k) numA = numA*10 + (b[k]-'0');
            
            if(numA != numB) return numA <numB;
            i = i2;
            j = j2;
        } else{
            if(a[i] != b[j]) return a[i] < b[j];
            i++; j++;
        }
    }   
     return a.size() < b.size();       
}

double median(vector<int> &v){
    if(v.empty()) return 0.0;
    vector<int> laik=v;
    sort(laik.begin(), laik.end());
    int n = laik.size();
    if(n % 2 ==1)
        return laik[n/2];
    else
        return (laik[n/2-1] + laik[n/2]) / 2.0;
    }

Studentas Stud_iv(bool atsitiktinis);

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
            s.GalMed = median(s.nd)*0.4 + 0.6*s.egz;
        }
        grupe.push_back(s);
    }
    return grupe;
}


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
    
    ofstream out("rezultatai.txt");
    
    cout<<setw(15)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde";
    out<<setw(15)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde";

    if(pasirinkimas == 1){
        cout<<setw(16)<<left<<"Galutinis (Vid.)"<<endl;
        out<<setw(16)<<left<<"Galutinis (Vid.)"<<endl;
    } else if(pasirinkimas == 2){
        cout<<setw(16)<<left<<"Galutinis (Med.)"<<endl;
        out<<setw(16)<<left<<"Galutinis (Med.)"<<endl;
    } else{
        cout<<setw(18)<<left<<"Galutinis (Vid.)"<<setw(16)<<left<<"Galutinis (Med.)"<<endl;
        out<<setw(18)<<left<<"Galutinis (Vid.)"<<setw(16)<<left<<"Galutinis (Med.)"<<endl;
    }

    cout<<"--------------------------------------------------------------------"<<endl;
    out<<"--------------------------------------------------------------------"<<endl;
    for(const auto &Past:Grupe){
        cout<<setw(15)<<left<<Past.var<<setw(20)<<left<<Past.pav;
        out<<setw(15)<<left<<Past.var<<setw(20)<<left<<Past.pav;
        
    if(pasirinkimas == 1){
        cout<<setw(16)<<left<<"Galutinis (Vid.)"<<endl;
        out<<setw(16)<<left<<"Galutinis (Vid.)"<<endl;
    } else if(pasirinkimas == 2){
        cout<<setw(16)<<left<<"Galutinis (Med.)"<<endl;
        out<<setw(16)<<left<<"Galutinis (Med.)"<<endl;
    } else{
        cout<<setw(18)<<left<<"Galutinis (Vid.)"<<setw(16)<<left<<"Galutinis (Med.)"<<endl;
        out<<setw(18)<<left<<"Galutinis (Vid.)"<<setw(16)<<left<<"Galutinis (Med.)"<<endl;
    }
}

    cout<<"---------------------------------------------------------------------"<<endl;
    out<<"---------------------------------------------------------------------"<<endl;
    cout<<"Rezultatai issaugoti faile rezultatai.txt"<<endl;
}

    Studentas Stud_iv(bool atsitiktinis){
        int laik_nd, sum=0;
        
        Studentas Pirmas;
        cout<<"Ivesk studento duomenis"<<endl;
        cout<<"Vardas: "; cin>>Pirmas.var;
        cout<<"Pavarde: "; cin>>Pirmas.pav;
           
    if (atsitiktinis){
        int nd_kiekis = rand()%10 + 1;
        for(int i=0; i<nd_kiekis; i++){
            laik_nd = rand()%10 + 1;
            Pirmas.nd.push_back(laik_nd);
            sum+=laik_nd;
    }
    Pirmas.egz = rand()%10 + 1;
    cout<<"Sugeneruoti "<<nd_kiekis<<" namu darbu pazymiai ir egzaminas"<<endl;
}
    else{
        string ndStr;
        cin.ignore();
        
        cout<<"Iveskite studento("<<Pirmas.var<<" "<<Pirmas.pav<<") namu darbu pazymius (Paspauskite enter 2 kartus, kad baigti): "<<endl;
        
        int enter= 0;
        
        while (true){
            cout<<Pirmas.nd.size()+1<<": ";
            std::getline(cin, ndStr);
                    
            if(ndStr.empty()){
                enter++;
                if(enter == 2) break;
                continue;
            }
            enter = 0;
            
            if(all_of(ndStr.begin(), ndStr.end(), ::isdigit)){
                laik_nd = stoi(ndStr);
                if(laik_nd >= 1 && laik_nd <= 10){
                    Pirmas.nd.push_back(laik_nd);
                    sum += laik_nd;
                    continue;
                }
            }
            cout<<"Neteisinga ivestis, iveskite skaiciu nuo 1 iki 10"<<endl;
        }
        string egzStr;

        while(true){
            cout<<"Studento egzamino pazimys: ";
            cin>>egzStr;
            if(!egzStr.empty() && all_of(egzStr.begin(), egzStr.end(), ::isdigit)){
                Pirmas.egz = stoi(egzStr);
                if(Pimras.egz >= 1 && Pirmas.egz <= 10) break;
            }
            cout<<"Neteisinga ivestis, iveskite skaiciu nuo 1 iki 10"<<endl;
        }
    }

    
    if(!Pirmas.nd.empty()){
        double vid = double(sum)/double(Pirmas.nd.size());
        Pirmas.galVid=vid*0.4+0.6*Pirmas.egz;
        Pirmas.galMed=median(Pirmas.nd)*0.4+0.6*Pirmas.egz;
    } else{
        Pirmas.galVid=0.6*Pirmas.egz;
        Pirmas.galMed=0.6*Pirmas.egz;
    }
    return Pirmas;
}
