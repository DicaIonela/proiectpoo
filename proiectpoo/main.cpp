#include <iostream>
#include "Magazin.h"
#include "Subprodus.h"
#include "Administrator.h"
#include "Client.h"
#include "Produs.h"
#include <fstream>
#include <random>
#include <algorithm>
using namespace std;

void MeniuAdministrator()
{
    //cout << "1. Adauga produs" << endl;
    cout << "1. Adauga produs" << endl;
    cout << "2. Afiseaza toate produsele" << endl;
    cout << "3. Sterge produs" << endl;
    cout << "4. Adauga un nou administrator" << endl;
    cout << "5. Iesire" << endl;
    cout << "Alege o optiune: ";
}
void MeniuClient()
{
    cout << "\n1. Afiseaza toate produsele" << endl;
    cout << "2. Modifica-ti datele de conectare" << endl;
    cout << "3. Promotie disponibila pentru dumneavoastra" << endl;
    cout << "4. Cauta produs" << endl;
    cout << "5. Iesire" << endl;
    cout << "Alege o optiune: ";
}
void MeniuPrincipal()
{

    cout << "\n1. Administrator" << endl;
    cout << "2. Client" << endl;
    cout << "Alege o optiune: ";
}
void citesteSubproduseDinFisier(const string& numeFisier, vector<Subprodus*>& listaSubproduse)
{
    ifstream fisier(numeFisier);
    if (!fisier.is_open())
    {
        cerr << "Eroare la deschiderea fișierului pentru citire: " << numeFisier << endl;
        return;
    }

    string numeProdus;
    int codCategorie;
    char numeSubprodus[30];
    int greutate;
    int nrproduse;

    while (fisier >> numeProdus >> codCategorie >> numeSubprodus >> greutate >> nrproduse)
    {
        Subprodus* subprodus = new Subprodus(numeProdus.c_str(), codCategorie, numeSubprodus, greutate, nrproduse);
        listaSubproduse.push_back(subprodus);
    }

    fisier.close();
}
void stergeDinFisier(const string& numeFisier, const string& numeProdusDeSters)
{
    // Deschide fișierul în modul citire
    ifstream inFile(numeFisier);
    // Verifică dacă fișierul s-a deschis corect
    if (!inFile.is_open())
    {
        cerr << "Eroare la deschiderea fisierului pentru citire!" << endl;
        return;
    }

    // Citire linie cu linie și stocare într-un vector
    vector<string> linii;
    string linie;
    while (getline(inFile, linie))
    {
        // Adaugă linia în vector doar dacă nu conține numele produsului de șters
        if (linie.find(numeProdusDeSters) == string::npos)
        {
            linii.push_back(linie);
        }
    }
    // Închide fișierul de citire
    inFile.close();

    // Deschide fișierul în modul scriere, ștergând conținutul anterior
    ofstream outFile(numeFisier);
    // Verifică dacă fișierul s-a deschis corect
    if (!outFile.is_open())
    {
        cerr << "Eroare la deschiderea fisierului pentru scriere!" << endl;
        return;
    }

    // Scrie liniile rămase în fișierul de ieșire
    for (const string& linie : linii)
    {
        outFile << linie << endl;
    }

    // Închide fișierul de ieșire
    outFile.close();
}
static void stergeDinVector(vector<Subprodus>& listaSubproduse, const string& numeSubprodus)
{
    listaSubproduse.erase(remove_if(listaSubproduse.begin(), listaSubproduse.end(), [&](const Subprodus& subprodus)
    {
        return subprodus.numeS == numeSubprodus;
    }), listaSubproduse.end());
}
void cautaSubprodus(const vector<Subprodus*>& listaSubproduse, const string& numeCautat) {
    bool gasit = false;
    for (const auto& subprodus : listaSubproduse) {
        if (subprodus->getNumeSubprodus() == numeCautat) {
            cout << "Informatii despre subprodusul '" << numeCautat << "':" << endl;
            cout<<*subprodus;
            gasit = true;
            break;
        }
    }
    if (!gasit) {
        cout << "Nu avem acest subprodus." << endl;
    }
}

int main()

{
    //Magazin magazin();
    vector<Subprodus*> listaSubproduse;
    cout << "Bine ati venit in meniul principal!" << endl;
    Magazin magazin("La bunici", "strada lalelelor, nr. 38.");
    cout<<magazin.numeM<<", "<<magazin.adresa;
    Administrator admin;
    Client client;

    bool autentificat = false;
    int optiune;
    if (!admin.incarcaDateleDinFisier("Administratori.txt"))
    {
        cerr << "Eroare la incarcarea datelor administratorilor." << endl;
        return 1;
    }
    if (!client.incarcaDateleDinFisier("Clienti.txt"))
    {
        cerr << "Eroare la incarcarea datelor clientilor." << endl;
        return 1;
    }

    MeniuPrincipal();
    int optmp;
    cin>>optmp;
    switch (optmp)
    {
    case 1:
    {
        string username, password;
        cout << "Introdu username: ";
        cin >> username;
        cout << "Introdu password: ";
        cin >> password;

        if (admin.autentificare(username, password))
        {
            cout << "Autentificare reusita!" << endl;
            do
            {
                MeniuAdministrator();
                int optiune;
                cin >> optiune;

                switch (optiune)
                {
                case 1:
                {
                    /*if (!autentificat)
                    {
                        cout << "Trebuie sa fii autentificat pentru a adauga un produs." << endl;
                        break;
                    }*/
                    char numeP[100], numeS[30];
                    int codcategorie, greutate, nrproduse;
                    /*Subprodus subprodus;
                    cin>>subprodus;*/
                    cout << "Introdu numele produsului: ";
                    cin.ignore();
                    cin.getline(numeP, 100);
                    cout << "Introdu codul categoriei: ";
                    cin >> codcategorie;
                    cout << "Introdu numele subprodusului: ";
                    cin.ignore();
                    cin.getline(numeS, 30);
                    cout << "Introdu greutatea: ";
                    cin >> greutate;
                    cout << "Introdu numarul de produse: ";
                    cin >> nrproduse;

                    Subprodus* subprodus1 = new Subprodus(numeP, codcategorie, numeS, greutate, nrproduse);
                    subprodus1->salveazaFisier("subproduse.txt");
                    cout << "Produs adaugat cu succes!" << endl;
                    break;
                }

                case 2:
                {
                    citesteSubproduseDinFisier("subproduse.txt", listaSubproduse);
                    cout << "Produsele citite din fisier sunt:" << endl;
                    for (const auto& subprodus : listaSubproduse)
                    {
                        cout << *subprodus << endl;
                    }
                    break;

                }
                case 3:
                {

                    char numeProdus[100];
                    cout << "Introdu numele produsului de sters: ";
                    cin.ignore();
                    cin.getline(numeProdus, 100);
                    stergeDinFisier("subproduse.txt", numeProdus);
                    for (auto it = listaSubproduse.begin(); it != listaSubproduse.end(); ++it)
                    {
                        if ((*it)->numeS == numeProdus)
                        {
                            listaSubproduse.erase(it);
                            break;
                        }
                    }
                    cout << "Produs sters (daca a fost gasit)!" << endl;
                    citesteSubproduseDinFisier("subproduse.txt", listaSubproduse);
                    break;
                }
                case 4:
                {
                    string user, pass;
                    cout<<"Introdu username pentru noul administrator:";
                    cin>>user;
                    cout<<"\nIntrodu parola pentru noul administrator:";
                    cin>>pass;
                    admin.adaugaAdministrator(user,pass);
                    break;
                }


                case 5:
                {
                    cout << "Iesire..." << endl;
                    return 0;
                }
                default:
                {
                    cout << "Optiune invalida. Te rog sa incerci din nou." << endl;
                    break;
                }
                }
            }
            while (optiune != 6);
        }
        else
        {
            cout << "Autentificare esuata. Username sau parola gresita." << endl;
        }
    }

    case 2:
    {

        cout << "Deci sunteti un client!\n Ati creat deja un cont? Da/Nu\n";
        string raspuns;
        string username, password;
        cin>>raspuns;
        if (raspuns=="Da"||raspuns=="da")
        {
            cout << "Introdu username: ";
            cin >> username;
            cout << "Introdu password: ";
            cin >> password;
        }
        if (raspuns=="Nu"||raspuns=="nu")
        {
            cout << "Introdu username-ul pentru noul tau cont: ";
            cin >> username;
            cout << "Introdu parola pentru noul tau cont: ";
            cin >> password;
            client.adaugaClient(username, password);
        }
        if (client.autentificare(username, password))
        {
            cout << "Autentificare reusita!" << endl;
            do
            {
                MeniuClient();
                int optiune;
                cin >> optiune;
                switch (optiune)
                {
                case 1:
                {
                    citesteSubproduseDinFisier("subproduse.txt", listaSubproduse);
                    cout << "Produsele citite din fisier sunt:" << endl;
                    for (const auto& subprodus : listaSubproduse)
                    {
                        cout << *subprodus << endl;
                    }
                    break;
                }
                case 2:
                {
                    char userv[30],passv[30],user[30],pass[30];
                    cout<<"\nIntrodu vechiul nume de utilizator:";
                    cin>>userv;
                    cout<<"\nIntrodu parola veche:";
                    cin>>passv;
                    cout<<"\nIntrodu noul nume de utilizator:";
                    cin>>user;
                    cout<<"\nIntrodu parola noua:";
                    cin>>pass;
                    client.modificaDateClient("username_vechi", "parola_veche", "username_nou", "parola_noua");
                }
                case 3:
                {
                    random_device rd;
                    mt19937 generare(rd());


                    int limitast = 100;
                    int limitadr = 1000;

                    uniform_int_distribution<int> dist(limitast, limitadr);

                    int random = dist(generare);

                    // Afișarea numărului generat
                    cout << "Ai primit un cod de reducere: " << random <<"\nVino in magazinele noastre pentru a-l verifica si utiliza!"<< endl;
                }
                case 4:
                {
                    char numecautat[20];
                    cout<<"Introduceti numele produsului:";
                    cin>>numecautat;
                    cautaSubprodus(listaSubproduse,numecautat);
                    break;
                }
                case 5:
                {
                    cout << "Iesire..." << endl;
                    return 0;
                }


                }
            }
            while (optiune!=5);
        }
        else
        {
            cout << "Autentificare esuata. Username sau parola gresita." << endl;
        }
    }
    }

    return 0;


}
