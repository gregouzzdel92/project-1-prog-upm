#include "experimentation.h"
#include "table_generation.h"

using namespace std;

// fct for the parameters of the experimentation (asking the user) and
// displaying them Function to ask the user for parameters of the
// experimentation
Parametres ask_parameters() {
  Parametres p;
  string vector_type_str;

  p.size = read_int("Enter the size of the vectors: ");

  while (p.size <= 0) {
    cout << "Size must be > 0\n";
    p.size = read_int("Enter the size: ");
  }

  p.min = read_int("Enter the minimum value: ");
  p.max = read_int("Enter the maximum value: ");

  if (p.min > p.max) {
    cout << "Swapping min and max\n";
    swap(p.min, p.max);
  }

  while (true) {
    cout << "Enter type (random, sorted, reversed): ";
    cin >> vector_type_str;

    if (vector_type_str == "random") {
      p.type = RANDOM;
      break;
    }
    if (vector_type_str == "sorted") {
      p.type = SORTED;
      break;
    }
    if (vector_type_str == "reversed") {
      p.type = REVERSED;
      break;
    }

    cout << "Invalid type, try again.\n";
  }

  p.num_vectors = read_int("Enter number of vectors: ");

  while (p.num_vectors <= 0) {
    cout << "Number must be > 0\n";
    p.num_vectors = read_int("Enter number of vectors: ");
  }

  return p;
}

// Function to read an integer with error handling
int read_int(const string &message) {
  int value;

  while (true) {
    cout << message;
    cin >> value;

    if (cin.fail()) {
      cin.clear();             // reset erreur
      cin.ignore(10000, '\n'); // vider buffer
      cout << "Invalid input. Try again.\n";
    } else {
      return value;
    }
  }
}

// function to show the parameter values entered by the user (for confirmation)
void show_parameters(const Parametres &p) {
  cout << "Parameters of the experimentation:" << endl;
  cout << "Size of the vectors: " << p.size;
  cout << "  |  Min: " << p.min;
  cout << "  |  Max: " << p.max;

  cout << "  |  Type of vectors: ";
  switch (p.type) {
  case RANDOM:
    cout << "random";
    break;
  case SORTED:
    cout << "sorted";
    break;
  case REVERSED:
    cout << "reversed";
    break;
  }

  cout << "  |  Nb of vectors to generate: " << p.num_vectors << endl << endl;
  return;
}

// Function to test the generation of table vectors (for debugging)
vector<vector<int>> test_a_supp_table_vectors(const Parametres &p) {
  return generate_table_vectors(p);
};

// fct to run the experimentation with given parameters
vector<mean_results>
run_experimentation(const vector<vector<int>> &table_vectors) {
  int n = table_vectors.size();

  mean_results mean_insertion = {0, 0, 0};
  mean_results mean_selection = {0, 0, 0};
  mean_results mean_quick = {0, 0, 0};

  for (const auto &v : table_vectors) {

    // INSERTION
    {
      vector<int> v_copy = v;
      long long comp = 0, mouv = 0;

      auto start = chrono::high_resolution_clock::now();

      insertion_sort(v_copy, comp, mouv);

      auto end = chrono::high_resolution_clock::now();

      auto duration =
          chrono::duration_cast<chrono::microseconds>(end - start).count();

      mean_insertion.time += duration;
      mean_insertion.comparaisons += comp;
      mean_insertion.mouvements += mouv;
    }

    // SELECTION
    {
      vector<int> v_copy = v;
      long long comp = 0, mouv = 0;

      auto start = chrono::high_resolution_clock::now();

      selection_sort(v_copy, comp, mouv);

      auto end = chrono::high_resolution_clock::now();

      auto duration =
          chrono::duration_cast<chrono::microseconds>(end - start).count();

      mean_selection.time += duration;
      mean_selection.comparaisons += comp;
      mean_selection.mouvements += mouv;
    }

    // QUICK
    {
      vector<int> v_copy = v;
      long long comp = 0, mouv = 0;

      auto start = chrono::high_resolution_clock::now();

      quick_sort(v_copy, comp, mouv);

      auto end = chrono::high_resolution_clock::now();

      auto duration =
          chrono::duration_cast<chrono::microseconds>(end - start).count();

      mean_quick.time += duration;
      mean_quick.comparaisons += comp;
      mean_quick.mouvements += mouv;
    }
  }

  // Calculating the mean results for each algorithm
  mean_insertion.time /= n;
  mean_insertion.comparaisons /= n;
  mean_insertion.mouvements /= n;

  mean_selection.time /= n;
  mean_selection.comparaisons /= n;
  mean_selection.mouvements /= n;

  mean_quick.time /= n;
  mean_quick.comparaisons /= n;
  mean_quick.mouvements /= n;

  return {mean_insertion, mean_selection, mean_quick};
}
