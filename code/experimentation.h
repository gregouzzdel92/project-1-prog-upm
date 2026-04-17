#ifndef EXPERIMENTATION_H
#define EXPERIMENTATION_H

#include "algorithm.h"
#include "common.h"
#include "table_generation.h"
#include <chrono>
#include <iostream>
#include <string>
#include <vector>


struct mean_results {
  double time;
  double comparaisons;
  double mouvements;
};

// Function prototypes
// Fct for parameters of the experimentation (asking the user) and displaying
Parametres ask_parameters();
void show_parameters(const Parametres &p);
int read_int(const std::string &message);
std::vector<std::vector<int>> test_a_supp_table_vectors(const Parametres &p);

// Fct to run the experimentation with given parameters
std::vector<mean_results>
run_experimentation(const std::vector<std::vector<int>> &table_vectors);

#endif // EXPERIMENTATION_H
