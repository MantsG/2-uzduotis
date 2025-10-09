#include "Ivedimas.h"
#include "Utils.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
using std::cin;
using std::string;



Studentas Stud_iv(bool atsitiktinis){
    int laik_nd, sum=0;

    Studentas Pirmas;
    cout<<"Ivesk studento duomenis"<<endl;
    cout<<"Vardas: "; cin>>Pirmas.var;
    cout<<"Pavarde: "; cin>>Pirmas.pav;

    if(atsitiktinis){
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

        cout<<"Iveskite studento ("<<Pirmas.var<<" "<<Pirmas.pav<<") namu darbu pazymius (paspauskite 2 kartus ENTER, kad baigti): "<<endl;

        int enter = 0;

        while(true){
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
            cout<<"Neteisinga ivestis, iveskite skaiciu nuo 1 iki 10 arba paspauskite 2 kartus ENTER pabaigai"<<endl;
        }
        string egzStr;

        while(true){
            cout<<"Studento egzamino pazimys: ";
            cin>>egzStr;
            if(!egzStr.empty() && all_of(egzStr.begin(), egzStr.end(), ::isdigit)){
                Pirmas.egz = stoi(egzStr);
                if(Pirmas.egz >= 1 && Pirmas.egz <= 10) break;
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
