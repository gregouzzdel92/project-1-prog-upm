#include "display.h"

using namespace std;

// fct to display results of the experimentation with given parameters

// Function to display the generated vectors (for testing purposes)
void display_vectors(const vector<vector<int>> &vector_table) {
  for (size_t i = 0; i < vector_table.size(); i++) {
    cout << "Vector " << i + 1 << ": ";
    for (size_t j = 0; j < vector_table[i].size(); j++) {
      cout << vector_table[i][j] << " ";
    }
    cout << endl;
  }
}

// Function to display the results of the experimentation
void display_results(const vector<mean_results> &results) {
  cout << "\n===== RESULTS =====\n\n";

  cout << "Insertion Sort :" << endl;
  cout << "Time (us):    " << results[0].time << endl;
  cout << "Comparisons:  " << results[0].comparaisons << endl;
  cout << "Movements:    " << results[0].mouvements << endl << endl;

  cout << "Selection Sort :" << endl;
  cout << "Time (us):    " << results[1].time << endl;
  cout << "Comparisons:  " << results[1].comparaisons << endl;
  cout << "Movements:    " << results[1].mouvements << endl << endl;

  cout << "Quick Sort :" << endl;
  cout << "Time (us):    " << results[2].time << endl;
  cout << "Comparisons:  " << results[2].comparaisons << endl;
  cout << "Movements:    " << results[2].mouvements << endl << endl;
}