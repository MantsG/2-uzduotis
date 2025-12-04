#ifndef ZMOGUS_H_INCLUDED
#define ZMOGUS_H_INCLUDED

#include <string>
#include <iostream>

class Zmogus{
public
    virtual ~Zmogus() = default;
    
    virtual const std::string& vardas() const = 0;
    virtual const std::string& pavarde() const = 0;
    
    virtual std::istream& read(std::istream& is) = 0;
    virtual std::ostream& write(std::ostream& os) = 0;
};


#endif // ZMOGUS_H_INCLUDED
