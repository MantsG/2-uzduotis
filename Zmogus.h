#ifndef ZMOGUS_H_INCLUDED
#define ZMOGUS_H_INCLUDED

#include <string>
#include <iostream>

class Zmogus{
protected:
    std::string vardas_;
    std::string pavarde_;


public:
    Zmogus() = default;
    Zmogus(const std::string& vardas, const std::string& pavarde)
        : vardas_(vardas), pavarde_(pavarde) {}

    virtual ~Zmogus() = default;

    std::string vardas() const {return vardas_;}
    std::string pavarde() const {return pavarde_;}

    void setVardas(const std::string& v) {vardas_ = v;}
    void setPavarde(const std::string& p) {pavarde_ = p;}

    virtual std::ostream& write(std::ostream& os) const = 0;
    virtual std::istream& read(std::istream& is) = 0;
};

#endif // ZMOGUS_H_INCLUDED
