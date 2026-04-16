#include "display.h"
#include "experimentation.h"
#include <iostream>

using namespace std;

int main() {
  // 1. Def parameters of the experimentation (asking the user)
  Parametres p = ask_parameters();
  show_parameters(p);

  vector<vector<int>> table_vector = test_a_supp_table_vectors(p);
  cout << endl << endl << "Generated vectors:" << endl;
  display_vectors(table_vector);

  // 2. call fct experimentation() to run the experimentation
  // (experimentation.cpp)
  // 3. call fct display() to display results (display.cpp)

  return 0;
}