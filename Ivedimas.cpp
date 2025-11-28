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
    string vardas, pavarde;
    cout<<"Vardas: "; cin>>vardas;
    cout<<"Pavarde: "; cin>>pavarde;
    Pirmas.setVardas(vardas);
    Pirmas.setPavarde(pavarde);
    
    if(atsitiktinis){
        int nd_kiekis = rand()%10 + 1;
        std::vector<int> tmp;
        for(int i=0; i<nd_kiekis; i++){
            laik_nd = rand()%10 + 1;
            tmp.push_back(laik_nd);
            sum+=laik_nd;
        }
        Pirmas.setNd(tmp);
        Pirmas.setEgzaminas(rand()%10 + 1);
        Pirmas.skaiciuotiGalutinis();
        cout<<"Sugeneruoti "<<nd_kiekis<<" namu darbu pazymiai ir egzaminas"<<endl;
    }
    else{
        string ndStr;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n\);

        cout<<"Iveskite studento ("<<Pirmas.vardas()<<" "<<Pirmas.pavarde()<<") namu darbu pazymius (paspauskite 2 kartus ENTER, kad baigti): "<<endl;

        int enter = 0;

        while(true){
            cout<<Pirmas.nd().size()+1<<": ";
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
                    Pirmas.addNd(laik_nd);
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
                Pirmas.setEgzaminas(stoi(egzStr));
                if(Pirmas.egzaminas() >= 1 && Pirmas.egzaminas() <= 10) break;
            }
            cout<<"Neteisinga ivestis, iveskite skaiciu nuo 1 iki 10"<<endl;
        }
        Pirmas.skaiciuotiGalutinis();
    }


    if(!Pirmas.nd().empty()){
        double vid = double(sum)/double(Pirmas.nd().size());
        Pirmas.skaiciuotiGalutinis();
    } else{
        Pirmas.skaiciuotiGalutinis();
    }
    return Pirmas;
}
