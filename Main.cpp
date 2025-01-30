de#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// Présentation d'un log
struct LOG {
    string date;
    string type;
    string message;
};

// Fonction pour lire le fichier log et stocker les entrées
vector<LOG> lireLogs(const string &nomFichier) {
    vector<LOG> logs;
    ifstream fichier(nomFichier);
    
    if (!fichier) {
        cerr << "Erreur : Impossible d'ouvrir ce fichier !" << endl;
        return logs;
    }

    string ligne;
    while (getline(fichier, ligne)) {
        istringstream iss(ligne);
        string date, type, message;

        if (iss >> date >> type) { 
            string date = date.substr(0, 10); //format de date

            getline(iss, message); // Lire le reste du message
            logs.push_back({date, type, message});
        }
    }

    fichier.close();
    return logs;
}

// Fonction pour afficher les statistiques des logs
void afficherstatistiques(const vector<LOG> &logs) {
    int info = 0, warning = 0, error = 0;
    
    for (auto log : logs) {
        // Suppression des espaces autour du type
        log.type.erase(0, log.type.find_first_not_of(" "));
        log.type.erase(log.type.find_last_not_of(" ") + 1);

        if (log.type == "INFO") info++;
        else if (log.type == "WARNING") warning++;
        else if (log.type == "ERROR") error++;
    }

    cout << "\nStatistiques des événements :\n";
    cout << "INFO: " << info << endl;
    cout << "WARNING: " << warning << endl;
    cout << "ERROR: " << error << endl;   
}

// Fonction pour filtrer et afficher les logs selon un critère
void filtrerLogs(const vector<LOG> &logs, int choix) {
    string critere;

    if (choix == 2) {
        cout << "Entrer une date au format année-mois-jour : ";
    } else if (choix == 3) {
        cout << "Entrer le type d'événements (WARNING, INFO, ERROR) en majuscules : ";
    } else if (choix == 4) {
        cout << "Entrer le mot-clé à rechercher : ";
    }

    cin >> critere;

 //Convertir le critère en minuscules pour la recherche par mot-clé
   string critere_lower = critere;
   transform(critere_lower.begin(), critere_lower.end(), critere_lower.begin(), ::tolower);

    cout << "\nRésultats filtrés :\n";
    int i = 0;
    for (const auto &log : logs) {

 //Convertir le message en minuscules pour une comparaison insensible à la casse
        string message_lower = log.message;
    transform(message_lower.begin(), message_lower.end(), message_lower.begin(), ::tolower);

        if ((choix == 2 && log.date == critere) ||
            (choix == 3 && log.type == critere) ||
            (choix == 4 && message_lower.find(critere) != string::npos)) {
            cout << log.date << " " << log.type << " " << log.message << endl;
            i++;
        }
    }
    if (i == 0) {
        cout << "Aucun résultat trouvé pour ce critère." << endl;
    }
}

// Interface utilisateur
int main() {
    string nomFichier;
    
    cout << "Entrez le nom du fichier log à analyser (ex: fichier.txt) : ";
    cin >> nomFichier;

    vector<LOG> logs = lireLogs(nomFichier);
    if (logs.empty()) return 1;

    int choix;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Afficher les statistiques\n";
        cout << "2. Filtrer les logs par date\n";
        cout << "3. Filtrer les logs par type d'événements\n";
        cout << "4. Rechercher un mot-clé dans les messages\n";
        cout << "5. Quitter\n";
        cout << "Choix : ";
        cin >> choix;
        
        switch (choix) {
            case 1:
                afficherstatistiques(logs);
                break;
            case 2:
                filtrerLogs(logs, 2);
                break;
            case 3:
                filtrerLogs(logs, 3);
                break;
            case 4:
                filtrerLogs(logs, 4);
                break;
            case 5:
                cout << "Au revoir!" << endl;
                break;
            default:
                cout << "Votre choix est invalide!" << endl;
        }
    } while (choix != 5);

    return 0;
}
