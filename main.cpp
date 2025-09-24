#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

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

struct Studentas{
    string var;
    string pav;
    vector <int> nd;
    int egz;
    double gal;
    };

Studentas Stud_iv();

int main(){

    vector <Studentas> Grupe;
    cout<<"Kiek studentu grupeje? ";
    int m;
    cin>>m;

    for(auto z=0; z<m; z++){
        Grupe.push_back(Stud_iv());
    }
    cout<<setw(10)<<left<<"Vardas"<<setw(15)<<left<<"Pavarde"<<setw(16)<<left<<"Galutinis (Vid.)"<<endl;
    cout<<"-----------------------------------------"<<endl;
    for(auto Past:Grupe){
        cout<<setw(10)<<left<<Past.var<<setw(15)<<left<<Past.pav<<setw(16)<<left<<fixed<<setprecision(2)<<Past.gal<<endl;
        }
    }

    Studentas Stud_iv(){
        int n, laik_nd, sum=0;

        Studentas Pirmas;
        cout<<"Ivesk studento duomenis"<<endl;
        cout<<"Vardas: "; cin>>Pirmas.var;
        cout<<"Pavarde: "; cin>>Pirmas.pav;
        cout<<"Kiek pazymiu gavo studentas uz namu darbus: "<<Pirmas.var<<" "<<Pirmas.pav<<": ";cin>>n;

        for(int i=0; i<n; i++){
                cout<<i+1<<": ";
                while(!(cin>>laik_nd)|| laik_nd < 1 || laik_nd >10){
                    cout<<"Neteisinga ivestis, iveskite skaiciu nuo 1 iki 10.\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout<<i+1<<": ";
                }

            Pirmas.nd.push_back(laik_nd);
            sum+=laik_nd;
        }

        cout<<"Studento egzamino pazimys: ";
        while(!(cin>>Pirmas.egz) || Pirmas.egz < 1 || Pirmas.egz > 10){
            cout<<"Neteisinga ivestis, iveskite skaiciu nuo 1 iki 10.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            cout<<"Studento egzamino pazimys: ";
        }
        Pirmas.gal=double(sum)/double(n)*0.4+0.6*Pirmas.egz;

        return Pirmas;
    }
