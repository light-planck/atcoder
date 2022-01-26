#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int idx = 0;
  int sum = 0;
  rep(i, n) {
    int b;
    cin >> b;
    sum += b;
  }
  vector<int> c(n-1);
  rep(i, n-1) cin >> c[i];

  rep(i, n-1) {
    if (a[i] + 1 == a[i+1]) {
      idx = a[i];
      sum += c[idx-1];
    }
  }
  cout << sum << endl;
  return 0;
}