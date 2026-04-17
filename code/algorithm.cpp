#include "algorithm.h"

using namespace std;

// Implementation of the algorithms to compare

// 1. Algorithm 1: insertion sort algorithm
void insertion_sort(std::vector<int> &tab, long long &comparaisons,
                    long long &mouvements) {
  int n = tab.size();
  for (int i = 1; i < n; i++) { // start with 2nd elem
    int key = tab[i];           // elem to sort
    int j = i - 1;

    // Move elements of tab[0..i-1], that are greater than key,
    // to one position ahead of their current position
    while (j >= 0 && tab[j] > key) {
      comparaisons++;
      tab[j + 1] = tab[j];
      mouvements++;
      j = j - 1;
    }
    if (j >= 0) {
      comparaisons++; // for last comparison that fails
    }
    tab[j + 1] = key;
    mouvements++;
  }
}

// 2. Algorithm 2: selection sort algorithm
void selection_sort(std::vector<int> &tab, long long &comparaisons,
                    long long &mouvements) {
  int n = tab.size();
  for (int i = 0; i < n - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
      comparaisons++;
      if (tab[j] < tab[min_idx]) {
        min_idx = j;
      }
    }
    swap(tab[i], tab[min_idx]);
    mouvements += 3; // counting the swap as 3 movements
  }
}

// 3. Algorithm 3: quick sort algorithm
void quick_sort(std::vector<int> &tab, long long &comparaisons,
                long long &mouvements) {
  quick_sort_rec(tab, 0, tab.size() - 1, comparaisons, mouvements);
}

void quick_sort_rec(std::vector<int> &tab, int left, int right,
                    long long &comparaisons, long long &mouvements) {

  if (left >= right)
    return;

  int pivot = tab[(left + right) / 2];
  int i = left;
  int j = right;

  while (i <= j) {

    while (tab[i] < pivot) {
      comparaisons++;
      i++;
    }
    comparaisons++;

    while (tab[j] > pivot) {
      comparaisons++;
      j--;
    }
    comparaisons++;
    if (i <= j) {
      std::swap(tab[i], tab[j]);
      mouvements += 3;
      i++;
      j--;
    }
  }

  quick_sort_rec(tab, left, j, comparaisons, mouvements);
  quick_sort_rec(tab, i, right, comparaisons, mouvements);
}
