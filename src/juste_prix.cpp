#include <array>
#include <iostream>
#include <random>

#include "constantes.hpp"
#include "jeu.hpp"
#include "menu.hpp"

using namespace std;

int main() {
	auto scores = array<int, NB_SCORES>{0, 0, 0};
	auto indiceCourant{0};

	auto generateurAleatoire = std::random_device{};
	auto generateur = mt19937{generateurAleatoire()};
	auto distribution =
			std::uniform_int_distribution{BORNE_MIN, BORNE_MAX};	// functor

	cout << "   --------------------------\n";
	cout << "   Bienvenue au Juste Prix !!\n";
	cout << "   --------------------------\n";

	auto continuer{true};
	while (continuer) {
		afficherMenu();
		auto choix = demanderChoixMenu();
		switch (choix) {
			case (ChoixMenu::JOUER): {
				scores[indiceCourant] = jouerPartie(distribution(generateur));
				indiceCourant = (indiceCourant + 1) % NB_SCORES;
				break;
			}
			case (ChoixMenu::AFFICHER_SCORES): {
				afficherScore(scores);
				break;
			}
			case (ChoixMenu::QUITTER):
				cout << "Au revoir !\n";
				continuer = false;
				break;

			case (ChoixMenu::INCORRECT):
				return EXIT_FAILURE;

			default:
				return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}
