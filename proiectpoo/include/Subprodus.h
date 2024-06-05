#ifndef SUBPRODUS_H
#define SUBPRODUS_H
#include <cstring>
#include <Produs.h>

#include <iostream>
using namespace std;
class Subprodus : public Produs
{
public:
    char numeS[30];
    int greutate;
    int nrproduse;
    char buf[100];
    Subprodus(const char *_numeP=(char*)"N/D", int _codcategorie=0,const char _numeS[30]=(char*)"N/D", int _greutate=0, int _nrproduse=0);
    Subprodus (const Subprodus &s);

    ~Subprodus();
    char* retProdusSubprodus();
    void AfisareSubprodus();
    void setNumeSubprodus(char *numeSubprodus);
    char *getNumeSubprodus();
    void setgreutate(int greutate);
    void setnrproduse(int nrproduse);
    int getCodCategorie();
    int getgreutate();
    int getnrproduse();
    void stergeDinFisier(const string& numeFisier);
    void salveazaFisier(const char* numeFisier) const;
    friend ostream& operator<<(ostream &ostr,Subprodus &s);
    friend istream& operator >>(istream &istr, Subprodus &s);
    Subprodus& operator= (const Subprodus &p);
    Subprodus& operator+(int nradd);
    Subprodus& operator- (int nrsc);
    friend bool operator >=(Subprodus &p1, Subprodus &p2);
};
#endif // SUBPRODUS_H
