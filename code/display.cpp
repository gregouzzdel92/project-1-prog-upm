#include "display.h"

// fct to display results of the experimentation with given parameters

// Function to display the generated vectors (for testing purposes)
void display_vectors(const std::vector<std::vector<int>> &vector_table) {
  for (size_t i = 0; i < vector_table.size(); i++) {
    std::cout << "Vector " << i + 1 << ": ";
    for (size_t j = 0; j < vector_table[i].size(); j++) {
      std::cout << vector_table[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
