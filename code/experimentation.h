#ifndef EXPERIMENTATION_H
#define EXPERIMENTATION_H

#include "algorithm.h"
#include "common.h"
#include "table_generation.h"
#include <iostream>
#include <string>
#include <vector>


// Function prototypes
Parametres ask_parameters();
void show_parameters(const Parametres &p);
int read_int(const std::string &message);

std::vector<std::vector<int>> test_a_supp_table_vectors(const Parametres &p);

#endif // EXPERIMENTATION_H