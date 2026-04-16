#include "experimentation.h"
#include "table_generation.h"

using namespace std;

// fct to run the experimentation with given parameters

// Function to ask the user for parameters of the experimentation
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