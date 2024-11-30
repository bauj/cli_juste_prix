#include "menu.hpp"

#include <iostream>
using namespace std;

void afficherMenu() {
	cout << "\n> Menu\n";
	cout << static_cast<char>(ChoixMenu::JOUER) << " : jouer" << endl;
	cout << static_cast<char>(ChoixMenu::AFFICHER_SCORES) << " : afficher les scores"
			 << endl;
	cout << static_cast<char>(ChoixMenu::QUITTER) << " : quitter" << endl;
}

ChoixMenu demanderChoixMenu() {
	cout << "Votre choix : ";
	char saisieChoix;
	cin >> saisieChoix;

	if (saisieChoix == static_cast<char>(ChoixMenu::JOUER) ||
			saisieChoix == static_cast<char>(ChoixMenu::AFFICHER_SCORES) ||
			saisieChoix == static_cast<char>(ChoixMenu::QUITTER)) {
		return static_cast<ChoixMenu>(saisieChoix);
	} else {
		return ChoixMenu::INCORRECT;
	}
}