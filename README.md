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
                      1000000 įrašų: Su vector buvo: 330 ms, nuskaitymas 312 ms, rusiavimas ir skirstymas 146 ms, isvedimas 670 ms. Su list: Generavimas 323 ms,                          nuskaitymas 293 ms, rusiavimas ir skirstymas 64 ms, isvedimas 455 ms. List buvo greitesnis.

<img width="979" height="510" alt="image" src="https://github.com/user-attachments/assets/92e75b2f-6dc1-487a-985a-8257db7a5ec1" />

#V1.0 uzduotis

v1.0 commit 45beacf - sutvarkyta 1 strategija
v1.0 commit 848ceb7 - pridėta 2 strategija vector'iui
v1.0 commit 1922220 - pridėti shrink_to_fit

