#include <iostream>
using namespace std;

int merge(int* a, int l, int m, int r) {
  int n1 = m - l + 1, n2 = r - m;
  int a1[n1], a2[n2];

  for (int i = 0; i < n1; i++) a1[i] = a[l + i];
  for (int j = 0; j < n2; j++) a2[j] = a[m + 1 + j];

  int i = 0, j = 0, k = l;
  int cnt = 0;

  while (i < n1 && j < n2) {
    if (a1[i] <= a2[j]) {
      a[k] = a1[i];
      i++;
    } else {
      a[k] = a2[j];
      j++;
      cnt += n1 - i;
    }
    k++;
  }

  while (i < n1) {
    a[k] = a1[i];
    i++;
    k++;
  }

  while (j < n2) {
    a[k] = a2[j];
    j++;
    k++;
  }

  return cnt;
}

int mergeSort(int* a, int l, int r) {
  int cnt = 0;
  if (l < r) {
    int m = l + (r - l) / 2;
    cnt += mergeSort(a, l, m);
    cnt += mergeSort(a, m + 1, r);
    cnt += merge(a, l, m, r);
  }
  return cnt;
}

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];

  int ans = mergeSort(a, 0, n - 1);

  // for (int i = 0; i < n; i++) cout << a[i] << ' ';
  // cout << endl;

  cout << ans << endl;
}
