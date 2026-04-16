#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

// Enumeration for the type of vector to generate
enum TypeVector { RANDOM, SORTED, REVERSED };

// Structure to hold the parameters of the experimentation
struct Parametres {
  int size;
  int min;
  int max;
  TypeVector type;
  int num_vectors;
};

// Function prototypes
Parametres ask_parameters();               // experimentation.cpp
void show_parameters(const Parametres &p); // experimentation.cpp
vector<vector<int>>
generate_table_vectors(const Parametres &p); // table_generation.cpp
vector<int> generate_vector(const Parametres &p,
                            std::mt19937 &gen); // table_generation.cpp
void display_vectors(const vector<vector<int>> &vector_table); // display.cpp
int read_int(const string &message); // experimentation.cpp

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

// function to show the parameter values entered by the user
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

// Call the function to generate tables with these parameters
// generate_tables(size, min, max, vector_type, num_vectors);

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

int main() {
  Parametres p = ask_parameters();
  show_parameters(p);
  vector<vector<int>> table_vector = generate_table_vectors(p);
  cout << endl << endl << "Generated vectors:" << endl;
  display_vectors(table_vector);
  return 0;
}