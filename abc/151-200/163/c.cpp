#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n);
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    x--;
    a[x].push_back(i);
  }

  rep(i, n) {
    cout << a[i].size() << endl;
  }
  return 0;
}