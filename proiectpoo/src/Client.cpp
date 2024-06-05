#include "Client.h"
Client::Client()
{
    // Constructor implicit
}

bool Client::autentificare(const string& username, const string& password)
{
    for (const auto& client : dateClienti)
    {
        if (client.username == username && client.password == password)
        {
            return true;
        }
    }
    return false;
}

bool Client::incarcaDateleDinFisier(const string& numeFisier)
{
    ifstream fisier(numeFisier);
    if (!fisier.is_open())
    {
        cerr << "Eroare la deschiderea fisierului: " << numeFisier << endl;
        return false;
    }

    string username, password;
    while (fisier >> username >> password)
    {
        dateClienti.push_back({username, password});
    }

    fisier.close();
    return true;
}
bool Client::adaugaClient(const string& username, const string& password)
{
    dateClienti.push_back({username, password});
    ofstream fisier("Clienti.txt");
    if (!fisier.is_open())
    {
        cerr << "Eroare la deschiderea fisierului pentru scriere: " << "Clienti.txt" << endl;
        return false;
    }

    for (const auto& client : dateClienti)
    {
        fisier << client.username << " " << client.password << endl;
    }

    fisier.close();
    return true;
}
void Client::modificaDateClient(const string& usernameVechi, const string& passwordVeche, const string& usernameNou, const string& passwordNou)
{
    for (auto& client : dateClienti)
    {
        if (client.username == usernameVechi && client.password == passwordVeche)
        {
            client.username = usernameNou;
            client.password = passwordNou;
            break; // Am găsit clientul și am efectuat modificările, deci putem ieși din buclă
        }
    }

    // Salvare modificări în fișier
    ofstream fisier("Clienti.txt");
    if (!fisier.is_open())
    {
        cerr << "Eroare la deschiderea fișierului pentru scriere: Clienti.txt" << endl;
        return;
    }

    for (const auto& client : dateClienti)
    {
        fisier << client.username << " " << client.password << endl;
    }

    fisier.close();
}



