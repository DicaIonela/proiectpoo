#ifndef MAGAZIN_H
#define MAGAZIN_H

#include <iostream>
#include <vector>
#include "Subprodus.h"

using namespace std;

class Magazin
{
    public:
    char numeM[20];
    char adresa[20];
    char buf[100];
    Magazin( const char *_numeM=(char*)"N/D", const char *_adresaM=(char*)"N/D");
    Magazin (const Magazin &m);
    ~Magazin();
    char* retNumeMagazin();
    void AfisareMagazin();
    void setNumeMagazin(char *numeMagazin);
    char *getNumeMagazin();
    friend ostream& operator <<(ostream &ostr,Magazin &m);
    friend istream& operator >>(istream &istr, Magazin &m);

};

#endif // MAGAZIN_H
