#include "table_generation.h"
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

//---- fct to generate tables for the experimentation with given parameters :

// Function to generate a table of vectors based on the parameters
vector<vector<int>> generate_table_vectors(const Parametres &p) {
  vector<vector<int>> vector_table;

  mt19937 gen(random_device{}());

  for (int i = 0; i < p.num_vectors; i++) {

    vector_table.push_back(generate_vector(p, gen));
  }

  return vector_table;
};

// Function to generate a single vector based on the parameters
vector<int> generate_vector(const Parametres &p, std::mt19937 &gen) {
  vector<int> v(p.size);

  uniform_int_distribution<> dis(p.min, p.max);

  for (int i = 0; i < p.size; i++) {
    v[i] = dis(gen);
  }

  if (p.type == SORTED) {
    sort(v.begin(), v.end());
  } else if (p.type == REVERSED) {
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
  }

  return v;
}
