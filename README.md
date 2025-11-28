# 1-uzduotis

#v.01 uzduotis

v.01 commit 6b38210 - Buvo įkeltas pirmasis main.cpp failas. 
v.01 commit e05a3a7 - Pridėta median funkcija.
v.01 commit 4477047 - Pridėtas galutinis vidurkis su mediana ir namų darbai tapo nežinomas skaičius (n).
v.01 commit af84c7e - Pridėtas atsitiktinis balų generavimas bei failo nuskaitymas.
v.01 commit 14ece73 - Pilnai sutvarkytas "būdo įvedimo" įvedimas.
v.01 commit 659688c - ištrintas cin>>ivBudas.
v.01 commit 575315c - Jeigu failo nepavyksta rasti/atidaryti/nuskaityti programa yra uždaroma, patobulinti įvedimai.
v.01 commit 282acf3 - Sutvarkyta dar daugiau įvedimu ir output'as
v.01 commit 7f20ba3 - Dabar galima rūšiuoti pagal vardą arba pavardę, rezultatai įrašomi į atskira tekstinį failą. Padaryta/pataisyta taip, kad į studentų vardą ar pavardę negalima būtų rašyti skaičių. Bei šiaip padaryta, kad atrodytu labiau esthetically pleasing paskutinis, galutinis variantas.

#V0.2 uzduotis

v.02 commit f819fa9 - pridėtas failų generavimas
v.02 commit 94cc77f - patobulintas kodas ir failų generavimas
v.02 commit 5e2f438 - pataisytos atidumo klaidos bei padarytas išskirstymas į 2 failus (vargsiukai ir kietiakai)
v.02 commit 3a8e0ec - Pridėti 7 failai: Failai.cpp; Failai.h; Studentas.h; Ivedimas.cpp; Ivedimas.h; Utils.cpp; Utils.h;
v.02 commit e3889c5 - Sukurti headers ir cpp failai (pataisytas main.cpp)
v.02 commit 4bdf760 - programos veikimo greičio analizės
v.02 commit 3dc69b1 - Patobulintas laiko skaičiavimas ir pridėtas pasirinkimas, kokio dydžio sukurti failą bei pasirinkti failo pavadinimą, iš kurio skaityti duomenis (sudėti paskutiniai štrihai)
v.02 commit f7f7ffa - Pataisytos sintaksės klaidos, kurios neleido failams pasileisti

Failų laikai: 1000 irašų failas: generavimas - 3ms, nuskaitymas 3ms, rusiavimas ir isvedimas 11ms. 
              10000 irašų failas: generavimas - 34ms, nuskaitymas 29ms, rusiavimas ir isvedimas 83ms.
              100000 irašų failas: generavimas - 336ms, nuskaitymas 276ms, rusiavimas ir isvedimas 944ms. 
              1000000 irašų failas: generavimas - 3.31s, nuskaitymas 2.79s, rusiavimas ir isvedimas 10.63s. 
              10000000 irašų failas: generavimas - 32.43s, nuskaitymas 28.90s, rusiavimas ir isvedimas 129.74s.

#V0.3 uzduotis

v.03 commit 88b6e38 - Įvestas vidurkio ir medianos išvedimas pagal dydį.
v.03 commit 5a27a20 - Pridėtas std::vector<Studentas>.
v.03 commit 7c310ad - Pakeisti visi <Studentas> į Konteineris.
v.03 commit 1b24da2 - Read pakeista į Skaitymą.
v.03 commit c36349f - Pakeistas sort į Skirstymą ir ištrinta nereikalingų eilučių.
v.03 commit 5bc035f - Pakeista skirstymo vieta, pakeistas vienas <studentas> į Konteineris.
v.03 commit 2e8dc92 - Pakeista endIsvedimas ir trukmeIsvedimas vieta kode. 
v.03 commit bf045ee - Pakeistos rašymo klaidos ir pridėtas out.close.
v.03 commit d7182e3 - Pakeistas failas Studentas.h.
v.03 commit 66059b6 - Pakeistas failas Failai.h.
v.03 commit 2ba014f - Pakeistas failas Failai.cpp.
v.03 commit f9d62f2 - Dar kartą pakeistas Studentas.h.
v.03 commit 15b1bf4 - Istrintas rusiavimas pagal varda ir pavarde, bei minor pakeitimai.
v.03 commit 7048f7a - Faile Studentas.h pridėta pragma once.
v.03 commit f704b2c - Prie main.cpp pridėtas NAUDOTI_LIST.
v.03 commit 372756f - Paskutiniai pakeitimai Studentas.h.
v.03 commit d531d43 - Pridėtas ranka rašomo studento adresas Ram'e.

Sistemos parametrai: CPU: AMD Ryzen 7 5800X 8-core Processor. RAM: 32gb, DDR4, 3600MHz. SSD: Samsung SSD 980 PRO 1TB. Skaitymo greitis 7,000 MB/s, o rašymo 5000 MB/s.
Failų laiko vidurkis: 1000 įrašų: (5 bandymai) Generavimas 3 ms, nuskaitymas 3 ms, rusiavimas ir skirstymas 0 ms, isvedimas 5.2 ms.
                      10000 įrašų: (5 bandymai) Generavimas 32.4 ms, nuskaitymas 28.6 ms, rusiavimas ir skirstymas 5.2 ms, isvedimas 45 ms.
                      100000 įrašų (5 bandymai) Generavimas 323 ms, nuskaitymas 293.4 ms, rusiavimas ir skirstymas 64.4 ms, isvedimas 455 ms.
                      1000000 įrašų (5 bandymai) Generavimas 3.25 s, nuskaitymas 2.986 s, rusiavimas ir skirstymas 910.2 ms, isvedimas 4.644 s.
                      10000000 įrašų (5 bandymai) Generavimas 33.044 s, nuskaitymas 29.196 s, rusiavimas ir skirstymas 12.132 s, isvedimas 45.59 s.
                      1000000 įrašų: Su vector buvo: 330 ms, nuskaitymas 312 ms, rusiavimas ir skirstymas 146 ms, isvedimas 670 ms. Su list: Generavimas 323 ms, nuskaitymas 293 ms, rusiavimas ir skirstymas 64 ms, isvedimas 455 ms. 
                      List buvo greitesnis.

<img width="979" height="510" alt="image" src="https://github.com/user-attachments/assets/92e75b2f-6dc1-487a-985a-8257db7a5ec1" />

#V1.0 uzduotis
Iš pradžių pasirenkama, kokio dydžio studentų failą norima generuoti (galima ir negeneruoti).
Pasirenkamas duomenų įvedimo būdas: 1) įvesti ranka, 2) generuoti kelis atsitiktinai, 3) nuskaityti iš failo.
1) Įvedamas studentų skaičius, jų vardai ir pavardės, tada yra surašomi namų darbų pažymiai (kai nusprendžiame, kad pakanka pažymių, du kartus paspaudžiam ENTER) ir galiausiai įvedamas egzamino pažimys. 2)
2) Įvedamas studentų skaičius, jų vardai ir pavardės, o pažymiai yra sugeneruojami atsitiktinai. 3)
3) Duomenys yra nuskaitomi iš failo, kurį prieš tai pasirinkome sugeneruoti.
Po duomenų suvedimo galima pasirinkti, kaip apskaičiuoti galutinį balą, pagal vidurkį, medianą arba abu.
Galiausiai studentai yra suskirstomi į du failus: "kietiakai.txt", kurių galutinis balas yra didesnis už 5, ir "vargsiukai.txt", kurių galutinis balas yra mažesnis už 5.

v1.0 commit 45beacf - sutvarkyta 1 strategija.
v1.0 commit 848ceb7 - pridėta 2 strategija vector'iui.
v1.0 commit 1922220 - pridėti shrink_to_fit.
v1.0 commit 8b0cf6d - pridėta 2 strategija list'ui.
v1.0 commit 8be65f5 - pridėta 3 strategija vector'iui.
v1.0 commit a4022b9 - sutvarkyta 2 vectori'iu strategija.
v1.0 commit 76cf71a - sutvarkyta 3 vectori'iu strategija.
v1.0 commit 337a7be - pridėta 3 strategija list'ui.
v1.0 commit f19e5fd - pakeista 2 vector'iaus strategija iš remove_if į partition.
v1.0 commit 1b530ea - sutvarkytos klaidos.
v1.0 commit 22812d4 - ištrintos nereikalingos eilutės.
v1.0 commit f5e9545 - pakeista, kad būtų galima pasirinkti, kurią strategiją naudoti.

Sistemos parametrai: CPU: AMD Ryzen 7 5800X 8-core Processor. RAM: 32gb, DDR4, 3600MHz. SSD: Samsung SSD 980 PRO 1TB. Skaitymo greitis 7,000 MB/s, o rašymo 5000 MB/s.
Naudojant vector:
Failų laiko vidurkis: 1000 įrašų: (5 bandymai) Generavimas 3.4 ms, nuskaitymas 3 ms, 1 strategijos rusiavimas 0 ms, 2 strategijos rusiavimas 0 ms, 3 strategijos rusiavimas 0 ms, rusiavimas ir skirstymas 1 ms, isvedimas 5 ms.
                      10000 įrašų: (5 bandymai) Generavimas 33.4 ms, nuskaitymas 29.2 ms, 1 strategijos rusiavimas 3 ms, 2 strategijos rusiavimas 1.2 ms, 3 strategijos rusiavimas 1 ms, rusiavimas ir skirtsymas 15 ms, isvedimas 44.8 ms.
                      100000 įrašų: (5 bandymai) Generavimas 333.8 ms, nuskaitymas 302.2 ms, 1 strategijos rusiavimas 31.2 ms, 2 strategijos rusiavimas 23 ms, 3 strategijos rusiavimas 18.4 ms, rusiavimas ir skirstymas 182.8 ms, isvedimas 450.6 ms.
                      1000000 įrašų: (5 bandymai) Generavimas 3.308 s, nuskaitymas 2.998 s, 1 strategijos rusiavimas 316 ms, 2 strategijos rusiavimas 241.8 ms, 3 strategijos rusiavimas 204.2 ms, rusiavimas ir skirstymas 2.186 s, isvedimas 4.604 s.
                      10000000 įrašų: (5 bandymai) Generavimas 33.08 s, nuskaitymas 29.762 s, 1 strategijos rusiavimas 2.942 s, 2 strategijos rusiavimas 2.41 s, 3 strategijos rusiavimas 2.006 s, rusiavimas ir skirstymas 24.74 s, isvedimas 44.376 s.
Naudojant list:
Failų laiko vidurkis: 1000 įrašų: (5 bandymai) Generavimas 2.64 ms, nuskaitymas 2.09 ms, 1 strategijos rusiavimas 0 ms, 2 strategijos rusiavimas 0 ms, 3 strategijos rusiavimas 0 ms, rusiavimas ir skirstymas 0 ms, isvedimas 3.96 ms.
                      10000 įrašų: (5 bandymai) Generavimas 26.2 ms, nuskaitymas 18.2 ms, 1 strategijos rusiavimas 2 ms, 2 strategijos rusiavimas 0 ms, 3 strategijos rusiavimas 0.6 ms, rusiavimas ir skirstymas 6.6 ms, isvedimas 33.4 ms.
                      100000 įrašų: (5 bandymai) Generavimas 256.2 ms, nuskaitymas 180.2 ms, 1 strategijos rusiavimas 20.8 ms, 2 strategijos rusiavimas 5.2 ms, 3 strategijos rusiavimas 13.2 ms, rusiavimas ir skirstymas 84.6 ms, isvedimas 334.8 ms.
                      1000000 įrašų: (5 bandymai) Generavimas 2.52 s, nuskaitymas 1.86 s, 1 strategijos rusiavimas 215.8 ms, 2 strategijos rusiavimas 44.8 ms, 3 strategijos rusiavimas 171.6 ms, rusiavimas ir skirstymas 1.26 s, isvedimas 3.4 s.
                      10000000 įrašų: (5 bandymai) Generavimas 25.4 s, nuskaitymas 18.4 s, 1 strategijos rusiavimas 2.152 s, 2 strategijos rusiavimas 464.6 ms , 3 strategijos rusiavimas 1.73 s, rusiavimas ir skirstymas 16 s, isvedimas 34.8 s. 
<img width="515" height="542" alt="image" src="https://github.com/user-attachments/assets/27b3a58a-c8b2-4b49-b299-4e96b6324b33" />
Testavimo išvados: vector konteineryje 3 strategija (stable_partition) veikia greičiausiai, tada 2 (partition) ir 1. Tuo tarpu list konteineryje 2 strategija veikia greičiausiai, tada 3 strategija ir galiausiai 1.

#2-uzduotis

#v1.1

v1.1 commit f4d4101 - pakeistas iš struct Studentas į class Studentas.
v1.1 commit ddad3e2 - pridėti konstruktoriai ir getteriai.
v1.1 commit 7a2e645 - pridėti setteriai.
v1.1 commit fc81fea - pridėti kiti metodai.
v1.1 commit be7850b - pridėta eilutė išvedimui.
v1.1 commit 77e56a6 - pridėtos ne-member funkcijos.
v1.1 commit ee4a780 - pridėtas Studentas.cpp failas.
v1.1 commit 325ee1d - pridėtas galutinio balo skaičiavimas.
v1.1 commit dd954f1 - pridėtas perskaitymas iš srauto.
v1.1 commit 1d51716 - pridėtas abiejų galutinių balų skaičiavimas.
v1.1 commit d00fe96 - pridėtas išvedimas į srautą.
v1.1 commit b8e2daa - sutvarkytas konteineris, kad veiktų class.
v1.1 commit 721e281 - panaikintas vector arba list pasirinkimas.
v1.1 commit 2fcb02b - sutvarkytas Ivedimas.cpp failas, kad veiktų class.
v1.1 commit 2d5016a - sutvarkytos Studentas.cpp atidumo klaidos.
v1.1 commit 50952f4 - sutvarkytas Failai.cpp, kad veiktų class.
v1.1 commit 02d3f32 - sutvarkytas Studentas.h failas, kad veiktų class.
v1.1 commit 65e6b2c - sutvarkytas Utils.h failas, kad veiktų class.
v1.1 commit 01b514f - pataisytos minor klaidos main.cpp ir Failai.cpp.

Naudojant struct:
Failų laiko vidurkis: 100000 įrašų: (5 bandymai) Generavimas 333.8 ms, nuskaitymas 302.2 ms, 2 strategijos rusiavimas 23 ms, rusiavimas ir skirstymas 182.8 ms, isvedimas 450.6 ms.
                      1000000 įrašų: (5 bandymai) Generavimas 3.308 s, nuskaitymas 2.998 s, 2 strategijos rusiavimas 241.8 ms, rusiavimas ir skirstymas 2.186 s, isvedimas 4.604 s
Naudojant class:
Failų laiko vidurkis: 100000 įrašų (5 bandymai) Generavimas 320.2 ms, nuskaitymas 305 ms, 2 strategijos rusiavimas 6.2 ms, rusiavimas ir skirstymas 22 ms, isvedimas 184.8 ms.
                      1000000 įrašų (5 bandymai) Generavimas 3.254 s, nuskaitymas 3.122 s, 2 strategijos rusiavimas 70.8 ms, rusiavimas ir skirstymas 315.4 ms, isvedimas 1.9 s.

Išvados: naudojant struct, nuskaitymas vyksta šiek tiek greičiau nei class, generavimas šiek tiek lėčiau, o rūšiavimas, skirstymas ir išvedimas vyksta žymiai greičiau naudojant class.

#v1.2

v1.2 commit ddc11cf – pridėtas „Rule of Three“ į „Studentas.h“.
v1.2 commit 2663fb9 – pridėtas destructor į “Studentas.cpp”.
v1.2 commit 8f55c1a – pridėtas copy constructor į “Studentas.cpp”.
v1.2 commit 8b304be – pridėtas copy assignment į “Studentas.cpp”.
v1.2 commit 6fecc3f – sutvarkytas nuskaitymas “Studentas.cpp”.
v1.2 commit 78851e8 – pakeista, kad būtų toks pat formatas, kaip failų generavimas “Studentas.cpp”.
v1.2 commit a52031b – sutvarkytos klaidos “Studentas.cpp”.
v1.2 commit 43823e2 – patvarkytas “Ivedimas.cpp” tmp užpildymas.
v1.2 commit c6bbdf9 – pridėtas operator>> į “Failai.cpp”.
v1.2 commit 72ecbec – pridėtas operator<< į “main.cpp”.
v1.2 commit 60dbed1 – pridėtas include “Studentas.h” į “Failai.cpp”.
v1.2 commit 8449777 – pridėtas include <limits> į “Ivedimas.cpp”.
v1.2 commit 0e049c3 – sutvarkyta klaida “main.cpp”.

Rule of Three implementacija:

Kopijavimo konstruktorius:
Studentas::Studentas(const Studentas& other){
    vardas_ = other.vardas_;
    pavarde_ = other.pavarde_;
    nd_ = other.nd_;
    egzaminas_ = other.egzaminas_;
    galVid_ = other.galVid_;
    galMed_ = other.galMed_;
}
Panaudojimas: Sūkuriant naujus studentus kopijuojant iš esamų, dirbant su STL konteineriais.

Kopijavimo Priskyrimo operatorius:
Studentas& Studentas::operator=(const Studentas& other){
    if(this != &other){
        vardas_ = other.vardas_;
        pavarde_ = other.pavarde_;
        nd_ = other.nd_;
        egzaminas_ = other.egzaminas_;
        galVid_ = other.galVid_;
        galMed_ = other.galMed_;
    }
    return *this;
}
Panaudojimas: Automatiškai iškviečiamas sunaikinant objektus.

Išvesties operatorius: 
std::ostream& operator<<(std::ostream& os, const Studentas& s){
    os<<std::left<<std::setw(15)<<s.vardas_
      <<std::left<<std::setw(20)<<s.pavarde_
      <<std::fixed<<std::setprecision(2)
      <<std::left<<std::setw(16)<<s.galVid_
      <<std::left<<std::setw(16)<<s.galMed_;
      return os;
}

Įvesties operatorius:
std::istream& operator>>(std::istream& is, Studentas& s){
    return s.readStudent(is);
}

<img width="456" height="295" alt="image" src="https://github.com/user-attachments/assets/1212d015-3ad6-4433-931c-a7df2e9fcfc7" />
<img width="690" height="598" alt="image" src="https://github.com/user-attachments/assets/b5bfed17-dd22-4637-b9f1-e25d52cf3101" />
<img width="448" height="500" alt="image" src="https://github.com/user-attachments/assets/27772ec5-8cef-484b-b52b-e6069ab790b6" />

