#pragma once

enum class ChoixMenu {
	JOUER = 'a',
	AFFICHER_SCORES = 'b',
	QUITTER = 'q',
	INCORRECT
};

void afficherMenu();
ChoixMenu demanderChoixMenu();