#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

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

struct Studentas{
    string var;
    string pav;
    vector <int> nd;
    int egz;
    double galVid;
    double galMed;
    };

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

Studentas Stud_iv();

int main(){

    vector <Studentas> Grupe;
    cout<<"Kiek studentu grupeje? ";
    int m;
    cin>>m;

    for(auto z=0; z<m; z++){
        Grupe.push_back(Stud_iv());
    }
    cout<<"Pasirinkite galutinio balo skaiciavimo buda: "<<endl;
    cout<<"1 - Vidurkis"<<endl;
    cout<<"2 - Mediana"<<endl;
    cout<<"3 - abu"<<endl;
    int pasirinkimas;
    cin>>pasirinkimas;

    cout<<setw(10)<<left<<"Vardas"<<setw(15)<<left<<"Pavarde";

    if(pasirinkimas == 1) cout<<setw(16)<<left<<"Galutinis (Vid.)"<<endl;
    else if(pasirinkimas == 2) cout<<setw(16)<<left<<"Galutinis (Med.)"<<endl;
    else cout<<setw(18)<<left<<"Galutinis (Vid.)"<<setw(16)<<left<<"Galutinis (Med.)"<<endl;

    cout<<"-----------------------------------------------------------"<<endl;
    
    for(auto Past:Grupe){
        cout<<setw(10)<<left<<Past.var<<setw(15)<<left<<Past.pav;
        if(pasirinkimas == 1) cout<<setw(16)<<left<<fixed<<setprecision(2)<<Past.galVid<<endl;
        else if(pasirinkimas == 2) cout<<setw(16)<<left<<fixed<<setprecision(2)<<Past.galMed<<endl;
        else cout<<setw(18)<<left<<fixed<<setprecision(2)<<Past.galVid<<setw(16)<<left<<fixed<<setprecision(2)<<Past.galMed<<endl;
        }
    }

    Studentas Stud_iv(){
        int laik_nd, sum=0;

        Studentas Pirmas;
        cout<<"Ivesk studento duomenis"<<endl;
        cout<<"Vardas: "; cin>>Pirmas.var;
        cout<<"Pavarde: "; cin>>Pirmas.pav;
        cout<<"Iveskite studento ("<<Pirmas.var<<" "<<Pirmas.pav<<") namu darbu pazymius (Paspauskite enter 2 kartus, kad baigti): "<<endl;
        while(true){
            cout<<Pirmas.nd.size()+1<<": ";
            cin>>laik_nd;
            if(laik_nd == 0) break;
            if(laik_nd < 1 || laik_nd > 10){
                cout<<"Neteisinga ivestis, iveskite skaiciu nuo 1 iki 10 arba 0 pabaigai"<<endl;
                continue;
            }
            Pirmas.nd.push_back(laik_nd);
            sum+=laik_nd;
        }

        cout<<"Studento egzamino pazimys: ";
        while(!(cin>>Pirmas.egz) || Pirmas.egz < 1 || Pirmas.egz > 10){
            cout<<"Neteisinga ivestis, iveskite skaiciu nuo 1 iki 10"<<endl;
            cin.clear();
            cin.ignore(10000, '\n');
            cout<<"Studento egzamino pazimys: ";
        }

        if(!Pirmas.nd.empty()){
            double vid = double(sum)/double(Pirmas.nd.size());
            Pirmas.galVid=vid*0.4+0.6*Pirmas.egz;
            Pirmas.galMed=median(Pirmas.nd)*0.4+0.6*Pirmas.egz;
        }   else{
            Pirmas.galVid=0.6*Pirmas.egz;
            Pirmas.galMed=0.6*Pirmas.egz;
    }
            return Pirmas;
    }


