#ifndef COMMON_H
#define COMMON_H

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

#endif // COMMON_H