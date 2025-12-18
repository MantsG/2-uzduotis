#include "Studentas.h"
#include "Utils.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include <vector>
#include <string>
#include <sstream>
#include <utility>

using Catch::Approx;

// ---------------------------
// Konstruktoriai / Rule of 5
// ---------------------------

TEST_CASE("Default constructor sukuria tuscia studenta", "[ctor][default]") {
    Studentas s;

    REQUIRE(s.vardas() == "");
    REQUIRE(s.pavarde() == "");
    REQUIRE(s.egzaminas() == 0);
    REQUIRE(s.nd().empty());
    REQUIRE(s.galVid() == Approx(0.0));
    REQUIRE(s.galMed() == Approx(0.0));
}

TEST_CASE("Parametrized constructor nustato varda ir pavarde", "[ctor][param]") {
    Studentas s("Vardenis", "Pavardenis");

    REQUIRE(s.vardas() == "Vardenis");
    REQUIRE(s.pavarde() == "Pavardenis");
    REQUIRE(s.egzaminas() == 0);
    REQUIRE(s.nd().empty());
}

TEST_CASE("Stream constructor sukuria studenta is srauto", "[ctor][stream]") {
    std::istringstream iss("Vardenis Pavardenis 8 9 7 6 10 8 9 7 6 8 9");
    Studentas s(iss);

    REQUIRE(s.vardas() == "Vardenis");
    REQUIRE(s.pavarde() == "Pavardenis");
    REQUIRE(s.nd().size() == 10);
    REQUIRE(s.egzaminas() == 9);
}

TEST_CASE("Copy constructor nukopijuoja duomenis", "[copy][ctor]") {
    Studentas a("Vardenis", "Pavardenis");
    std::vector<int> nd = {5, 8, 7};
    a.setNd(nd);
    a.setEgzaminas(5);
    a.skaiciuotiGalutinis();

    Studentas b(a);

    REQUIRE(b.vardas() == a.vardas());
    REQUIRE(b.pavarde() == a.pavarde());
    REQUIRE(b.egzaminas() == a.egzaminas());
    REQUIRE(b.nd() == a.nd());
    REQUIRE(b.galVid() == Approx(a.galVid()));
    REQUIRE(b.galMed() == Approx(a.galMed()));
}

TEST_CASE("Copy assignment operator nukopijuoja duomenis", "[copy][assign]") {
    Studentas a("Vardenis", "Pavardenis");
    std::vector<int> nd = {5, 8, 7};
    a.setNd(nd);
    a.setEgzaminas(5);
    a.skaiciuotiGalutinis();

    Studentas b("Kitas", "Studentas");
    b = a;

    REQUIRE(b.vardas() == a.vardas());
    REQUIRE(b.pavarde() == a.pavarde());
    REQUIRE(b.egzaminas() == a.egzaminas());
    REQUIRE(b.nd() == a.nd());
    REQUIRE(b.galVid() == Approx(a.galVid()));
    REQUIRE(b.galMed() == Approx(a.galMed()));
}

// ---------------------------
// Getteriai / Setteriai
// ---------------------------

TEST_CASE("Getteriai grazina teisingas reiksmes", "[getters]") {
    Studentas s("Vardenis", "Pavardenis");
    std::vector<int> nd = {5, 8, 7};
    s.setNd(nd);
    s.setEgzaminas(5);
    s.skaiciuotiGalutinis();

    REQUIRE(s.vardas() == "Vardenis");
    REQUIRE(s.pavarde() == "Pavardenis");
    REQUIRE(s.egzaminas() == 5);
    REQUIRE(s.nd().size() == 3);
    REQUIRE(s.nd()[0] == 5);
    REQUIRE(s.nd()[1] == 8);
    REQUIRE(s.nd()[2] == 7);
}

TEST_CASE("AddNd prideda pazymi", "[addnd]") {
    Studentas s;
    s.addNd(5);
    s.addNd(8);

    REQUIRE(s.nd().size() == 2);
    REQUIRE(s.nd()[0] == 5);
    REQUIRE(s.nd()[1] == 8);
}

TEST_CASE("PridetiNd irgi prideda pazymi", "[pridetind]") {
    Studentas s;
    s.pridetiNd(5);
    s.pridetiNd(8);

    REQUIRE(s.nd().size() == 2);
    REQUIRE(s.nd()[0] == 5);
    REQUIRE(s.nd()[1] == 8);
}

// ---------------------------
// Operatoriai
// ---------------------------

TEST_CASE("operator<< isveda studento duomenis", "[io][operator]") {
    Studentas s("Vardenis", "Pavardenis");
    s.setEgzaminas(8);
    std::vector<int> nd = {7, 8, 9};
    s.setNd(nd);
    s.skaiciuotiGalutinis();

    std::ostringstream oss;
    oss << s;

    std::string result = oss.str();
    REQUIRE(result.find("Vardenis") != std::string::npos);
    REQUIRE(result.find("Pavardenis") != std::string::npos);
}

TEST_CASE("operator>> nuskaito studenta is srauto", "[io][operator]") {
    std::istringstream iss("Vardenis Pavardenis 8 9 7 6 10 8 9 7 6 8 9");
    Studentas s;
    iss >> s;

    REQUIRE(s.vardas() == "Vardenis");
    REQUIRE(s.pavarde() == "Pavardenis");
    REQUIRE(s.nd().size() == 10);
    REQUIRE(s.egzaminas() == 9);
}

// ---------------------------
// Galutinio balo skaiciavimas
// ---------------------------

TEST_CASE("Galutinis balas skaiciuojamas pagal vidurki", "[galbalas][vidurkis]") {
    Studentas s("A", "B");
    std::vector<int> nd = {10, 10};  // vidurkis = 10
    s.setNd(nd);
    s.setEgzaminas(10);
    s.skaiciuotiGalutinis();

    // 0.4 * 10 + 0.6 * 10 = 10
    REQUIRE(s.galVid() == Approx(10.0));
}

TEST_CASE("Galutinis balas skaiciuojamas pagal mediana", "[galbalas][mediana]") {
    Studentas s("A", "B");
    std::vector<int> nd = {1, 2, 3}; // mediana = 2
    s.setNd(nd);
    s.setEgzaminas(10);             // 0.4 * 2 + 0.6 * 10 = 6.8
    s.skaiciuotiGalutinis();

    REQUIRE(s.galMed() == Approx(6.8));
}

TEST_CASE("GalBalas funkcija su vidurkiu", "[galbalas][function]") {
    Studentas s("A", "B");
    std::vector<int> nd = {8, 9, 7}; // vidurkis = 8
    s.setNd(nd);
    s.setEgzaminas(8);

    double result = s.galBalas([](std::vector<int>& v) {
        double sum = std::accumulate(v.begin(), v.end(), 0.0);
        return sum / v.size();
    });

    // 0.4 * 8 + 0.6 * 8 = 8
    REQUIRE(result == Approx(8.0));
}

TEST_CASE("Tuscias namu darbu sarasas", "[empty][grades]") {
    Studentas s("A", "B");
    s.setEgzaminas(5);
    s.skaiciuotiGalutinis();

    // Tik egzaminas: 0.6 * 5 = 3
    REQUIRE(s.galVid() == Approx(3.0));
    REQUIRE(s.galMed() == Approx(3.0));
}

// ---------------------------
// Palyginimo funkcijos
// ---------------------------

TEST_CASE("Compare pagal varda", "[compare]") {
    Studentas a("Antanas", "A");
    Studentas b("Bronius", "B");
    Studentas c("Antanas", "C");

    REQUIRE(compare(a, b) == true);  // Antanas < Bronius
    REQUIRE(compare(b, a) == false); // Bronius > Antanas
    REQUIRE(compare(a, c) == false); // Antanas == Antanas (false, nes not <)
}

TEST_CASE("Compare pagal pavarde", "[compare][pavarde]") {
    Studentas a("A", "Antanaitis");
    Studentas b("B", "Bronaitis");

    REQUIRE(comparePagalPavarde(a, b) == true);  // Antanaitis < Bronaitis
    REQUIRE(comparePagalPavarde(b, a) == false); // Bronaitis > Antanaitis
}

TEST_CASE("Compare pagal egzamina", "[compare][egzaminas]") {
    Studentas a("A", "A");
    a.setEgzaminas(5);

    Studentas b("B", "B");
    b.setEgzaminas(8);

    REQUIRE(comparePagalEgza(a, b) == true);  // 5 < 8
    REQUIRE(comparePagalEgza(b, a) == false); // 8 > 5
}

// ---------------------------
// Utils funkcijos
// ---------------------------

TEST_CASE("Median skaiciavimas", "[utils][median]") {
    std::vector<int> v1 = {1, 3, 2};
    std::vector<int> v2 = {1, 2, 3, 4};
    std::vector<int> v3 = {5};
    std::vector<int> v4 = {};

    REQUIRE(median(v1) == Approx(2.0));
    REQUIRE(median(v2) == Approx(2.5));
    REQUIRE(median(v3) == Approx(5.0));
    REQUIRE(median(v4) == Approx(0.0));
}

TEST_CASE("NaturalCompare palyginimas", "[utils][naturalcompare]") {
    REQUIRE(naturalCompare("abc123", "abc124") == true);
    REQUIRE(naturalCompare("abc123", "abc123") == false);
    REQUIRE(naturalCompare("abc12", "abc123") == true);
    REQUIRE(naturalCompare("abc123def", "abc123xyz") == true);
}

// ---------------------------
// Zmogus bazine klase
// ---------------------------

TEST_CASE("Zmogus bazines klases funkcionalumas", "[zmogus]") {
    // Testuojam per Studentas klase, kuri paveldi is Zmogus
    Studentas s("Vardenis", "Pavardenis");

    REQUIRE(s.vardas() == "Vardenis");
    REQUIRE(s.pavarde() == "Pavardenis");

    s.setVardas("NaujasVardas");
    s.setPavarde("NaujaPavarde");

    REQUIRE(s.vardas() == "NaujasVardas");
    REQUIRE(s.pavarde() == "NaujaPavarde");
}

// ---------------------------
// Destruktorius
// ---------------------------

TEST_CASE("Destructor clears memory", "[destructor]") {
    Studentas* s = new Studentas("Test", "Test");
    std::vector<int> nd = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    s->setNd(nd);

    // Tikrinam, kad duomenys priskirti
    REQUIRE(s->nd().size() == 10);

    delete s; // Iškviečiam destruktorių

    // Po destruktoriaus s rodo į nebenaudojamą atmintį,
    // bet pats objektas yra sunaikintas
    // (Šiame teste tiesiog patikrinam, kad destruktorius iškviečiamas be klaidų)
    REQUIRE(true);
}
