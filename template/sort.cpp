#include "algobase.h"
using namespace std;

// assume sort in ascending order

void selection_sort(vector<int>& arr) {
  if (arr.empty() && arr.size() < 2)
    return;
  for (int min_index, i = 0; i < arr.size() - 1; i++) {
    min_index = i;
    for (int j = i + 1; j < arr.size(); j++) {
      if (arr[j] < arr[min_index])
        min_index = j;
    }
    swap(arr[i], arr[min_index]);
  }
}

void bubble_sort(vector<int>& arr) {
  if (arr.empty() && arr.size() < 2)
    return;
  for (int e = arr.size() - 1; e > 0; e--) {
    for (int i = 0; i < e; i++) {
      if (arr[i] > arr[i + 1]) {
        swap(arr[i], arr[i + 1]);
      }
    }
  }
}

void insert_sort(vector<int>& arr) {
  if (arr.empty() && arr.size() < 2)
    return;
  for (int i = 1; i < arr.size(); i++) {
    for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--) {
      swap(arr[j], arr[j + 1]);
    }
  }
}