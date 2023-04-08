#include <iostream>
using namespace std;

#define ll long long

ll partition(ll* a, ll l, ll r) {
  ll pivot = a[(l + r) / 2];
  ll i = l, j = r;
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

void quicksort(ll* a, ll l, ll r) {
  if (l < r) {
    ll m = partition(a, l, r);
    quicksort(a, l, m);
    quicksort(a, m + 1, r);
  }
}

int main() {
  ll n;
  cin >> n;
  ll a[n];
  for (ll i = 0; i < n; i++) cin >> a[i];
  quicksort(a, 0, n - 1);
  for (ll i = 0; i < n; i++) cout << a[i] << ' ';
  cout << endl;
}
