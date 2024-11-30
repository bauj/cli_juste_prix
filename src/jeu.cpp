#include "jeu.hpp"

#include <chrono>
#include <iomanip>
#include <iostream>

#include "constantes.hpp"

using namespace std;

void afficherScore(TableauScore const& scores) {
	cout << "> Dernieres parties : \n";
	for (auto const& score : scores) {
		cout << " .. ";
		if (score == 0) {
			cout << " (vide)\n";
		} else {
			cout << score << " essai(s)\n";
		}
	}
}

int jouerPartie(int leJustePrix) {
	auto propal{0l};
	auto nbTentative{0u};

	using Duree = std::chrono::duration<double>;

	auto t0 = std::chrono::system_clock::now();

	do {
		cout << " > Entrez votre proposition : ";
		while (true) {
			cin >> propal;
			if (std::cin.fail() || std::cin.peek() != '\n') {
				cout << "[!] Erreur d'entrée. On attend un nombre entier." << endl;
				cout << "[!] Ressayez : ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			} else {
				break;
			}
		}

		if (propal >= BORNE_MIN) {
			nbTentative++;
			if (propal == leJustePrix) {
				cout << "*  Bravo ! Vous avez trouvé le juste prix !  *\n";
			} else if (propal > leJustePrix) {
				cout << " [!] C'est moins !";
				auto difference = abs(propal - leJustePrix);
				if (difference > ECART_WARNING) cout << " (beaucoup moins)";
				cout << endl;
			} else {
				cout << " [!] C'est plus !";
				auto difference = abs(propal - leJustePrix);
				if (difference > ECART_WARNING) cout << " (beaucoup plus)";
				cout << endl;
			}
		}
	} while (propal != leJustePrix && propal >= BORNE_MIN);

	auto tend = std::chrono::system_clock::now();
	auto duree = std::chrono::duration_cast<Duree>(tend - t0);

	if (propal == leJustePrix) {
		cout << "Partie terminée en " << nbTentative << " tentative(s) en "
				 << std::fixed << std::setprecision(4) << duree.count() << " secondes."
				 << endl;
	} else {
		cout << "Partie abandonnée ..." << endl;
	}
	return nbTentative;
}