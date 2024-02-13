#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 6;

int a[N];

int partition_sort(int a[], int l,int r) {
  int mid = a[r];
  int i = l, j = r;
  while (i < j) {
    while (i < j && a[i] <= mid) {
      i++;
    }
    while (i < j && a[i] >= mid) {
      j--;
    }
    if (i < j) {
      swap(a[i], a[j]);
    } else
      swap(a[i], a[r]);
  }
  return i;
}
void quick_sort(int a[], int l, int r) {
  if (l < r) {
    int mid = partition_sort(a, l, r);
    quick_sort(a, l, mid - 1);
    quick_sort(a, mid + 1, r);
  }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  quick_sort(a, 1, n);

  for (int i = 1; i <= n; i++) {
    cout << a[i] << " \n"[i == n];
  }
  return 0;
}
