#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n; cin >> n;
  vector<int> p(n); rep(i, n) cin >> p[i];
  int cnt = 0;
  rep(i, n) {
    if (p[i] != i+1) cnt++;
  }
  if (cnt < 3) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}