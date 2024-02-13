#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1; // Define the size of the bucket
vector<int> bucket[N];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    bucket[x / 1000].push_back(x);
  }
  for (int i = 0; i < N; i++) {
    if (!bucket[i].empty()) {
      sort(bucket[i].begin(),
           bucket[i].end()); // Sort the bucket in ascending order
    }
  }

  for (int i = 0; i < N; i++) {
    for (auto item : bucket[i]) {
      cout << item << " ";
    }
  }
  cout << endl;
  return 0;
}
