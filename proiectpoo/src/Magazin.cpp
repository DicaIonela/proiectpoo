#include "Magazin.h"
#include <iostream>
#include <fstream>

using namespace std;
Magazin::Magazin(const char *_numeM,const char *_adresa)
{

    strcpy (numeM, _numeM);
    strcpy (adresa, _adresa);

}

Magazin::~Magazin()
{
    if (numeM!=nullptr)
        delete[] numeM;
}
Magazin::Magazin(const Magazin &m)
{
    if (this!=&m)
    {
        strcpy (numeM, m.numeM);
    }
}


void Magazin::setNumeMagazin(char* numeMagazin)
{
    if(numeM!=nullptr)
    {
        delete[] numeM;
    }
    strcpy (numeM, numeMagazin);
}

ostream& operator <<(ostream &ostr, Magazin &m)
{
    ostr<<"\nNume magazin:"<<m.numeM<<"\nAdresa:"<<m.adresa;
    return ostr;
}
istream& operator >>(istream &istr, Magazin &m)
{
    cout<<"Nume magazin:"<<endl;
    istr>>m.buf;
    strcpy (m.numeM, m.buf);
    cout<<"Adresa:";
    istr>>m.buf;
    strcpy (m.adresa, m.buf);
    return istr;
}
