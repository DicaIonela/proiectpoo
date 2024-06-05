#ifndef PRODUS_H
#define PRODUS_H
#include <cstring>
#include <iostream>
using namespace std;

class Produs
{
    public:
    char numeP[20];
    int codcategorie;
    char buf[100];
    Produs( const char *_numeP=(char*)"N/D", int _codcategorie=0);
    Produs (const Produs &p);
    ~Produs();
    char* retNumeMagazinProdus();
    void AfisareProdus();
    void setNumeProdus(char *numeProdus);
    char *getNumeProdus();
    void setcodcategorie(int nrproduse);
    int getcodcategorie();
    friend ostream& operator <<(ostream &ostr, Produs &p);
    friend istream& operator >>(istream &istr, Produs &p);
    Produs& operator= (const Produs &p);

};

#endif // PRODUS_H
