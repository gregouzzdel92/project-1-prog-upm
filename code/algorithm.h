#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <algorithm>
#include <iostream>
#include <vector>

// Function prototypes
void insertion_sort(std::vector<int> &tab, long long &comparaisons,
                    long long &mouvements);
void selection_sort(std::vector<int> &tab, long long &comparaisons,
                    long long &mouvements);
void quick_sort(std::vector<int> &tab, long long &comparaisons,
                long long &mouvements);
void quick_sort_rec(std::vector<int> &tab, int left, int right,
                    long long &comparaisons, long long &mouvements);

#endif // ALGORITHM_H