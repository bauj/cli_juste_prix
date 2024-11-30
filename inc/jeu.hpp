#pragma once

#include <array>
#include "constantes.hpp"

using TableauScore = std::array<int, NB_SCORES>;

void afficherScore(TableauScore const& scores);
int jouerPartie(int leJustePrix);
