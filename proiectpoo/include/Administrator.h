#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

struct AdministratorData {
    string username;
    string password;
};

class Administrator {
private:
    vector<AdministratorData> adminData; // lista de administratori

public:
    Administrator();
    bool autentificare(const string& username, const string& password);
    bool incarcaDateleDinFisier(const string& numeFisier);
    bool adaugaAdministrator(const string& username, const string& password);
};

#endif // ADMINISTRATOR_H
