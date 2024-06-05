#include "Administrator.h"

Administrator::Administrator() {
    // Constructor implicit
}

bool Administrator::autentificare(const string& username, const string& password) {
    for (const auto& admin : adminData) {
        if (admin.username == username && admin.password == password) {
            return true;
        }
    }
    return false;
}

bool Administrator::incarcaDateleDinFisier(const string& numeFisier) {
    ifstream fisier(numeFisier);
    if (!fisier.is_open()) {
        cerr << "Eroare la deschiderea fisierului: " << numeFisier << endl;
        return false;
    }

    string username, password;
    while (fisier >> username >> password) {
        adminData.push_back({username, password});
    }

    fisier.close();
    return true;
}
bool Administrator::adaugaAdministrator(const string& username, const string& password) {
    adminData.push_back({username, password});
    ofstream fisier("Administratori.txt");
    if (!fisier.is_open()) {
        cerr << "Eroare la deschiderea fisierului pentru scriere: " << "Administratori.txt" << endl;
        return false;
    }

    for (const auto& admin : adminData) {
        fisier << admin.username << " " << admin.password << endl;
    }

    fisier.close();
    return true;
}
