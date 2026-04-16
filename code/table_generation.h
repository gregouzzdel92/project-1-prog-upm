#ifndef TABLE_GENERATION_H
#define TABLE_GENERATION_H

#include "common.h"
#include <random>
#include <vector>

// Function prototypes
std::vector<std::vector<int>> generate_table_vectors(const Parametres &p);
std::vector<int> generate_vector(const Parametres &p, std::mt19937 &gen);

#endif // TABLE_GENERATION_H