#include <iostream>
using namespace std;

int partition(int* a, int l, int r) {
  int pivot = a[(l + r) / 2];
  int i = l, j = r;
  while (i <= j) {
    while (a[i] < pivot) i++;
    while (a[j] > pivot) j--;
    if (i >= j) break;
    swap(a[i], a[j]);
    ++i;
    --j;
  }
  return j;
}

void quicksort(int* a, int l, int r) {
  if (l < r) {
    int m = partition(a, l, r);
    quicksort(a, l, m);
    quicksort(a, m + 1, r);
  }
}

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];

  quicksort(a, 0, n - 1);

  for (int i = 0; i < n; i++) cout << a[i] << ' ';
  cout << endl;
}
