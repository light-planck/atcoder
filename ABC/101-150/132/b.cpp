#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  int cnt = 0;

  rep(i, n-2) {
    int a = p[i];
    int b = p[i+1];
    int c = p[i+2];
    if (b == a + b + c - max({a, b, c}) - min({a, b, c})) {
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}