#include "Produs.h"

Produs::Produs(const char *_numeP, int _codcategorie)
{

    strcpy (numeP, _numeP);
    codcategorie=_codcategorie;
}

Produs::~Produs()
{
    if (numeP!=nullptr)
        delete[] numeP;
}
Produs::Produs(const Produs &p)
{
    if (this!=&p)
    {
        strcpy (numeP, p.numeP);
        codcategorie=p.codcategorie;
    }
}


void Produs::setNumeProdus(char* numeProdus)
{
    if(numeP!=nullptr)
    {
        delete[] numeP;
    }
    strcpy (numeP, numeProdus);
}
int Produs::getcodcategorie()
{
    return codcategorie;
}
char *Produs::getNumeProdus()
{
    return numeP;
}
void Produs::setcodcategorie(int codcategorie)
{
    this->codcategorie=codcategorie;
}
ostream& operator <<(ostream &ostr, Produs &p)
{
    ostr<<"\nNumele categoriei:"<<p.numeP<<"\nCod categorie:"<<p.codcategorie;
    return ostr;
}
istream& operator >>(istream &istr, Produs &p)
{
    cout<<"Numele categoriei:"<<endl;
    istr>>p.buf;
    strcpy (p.numeP, p.buf);
    cout<<",Cod:";
        istr>>p.codcategorie;
    return istr;
}
Produs& Produs::operator=(const Produs &p)
{
    if(numeP!=nullptr)
    {
        delete[] numeP;
        strcpy (numeP, p.numeP);
        codcategorie=p.codcategorie;
    }
    return *this;
}
