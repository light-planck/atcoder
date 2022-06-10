#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9 + 7;

int main() {
  int n;
  cin >> n;

  vector<int> w(n);
  rep(i, n) cin >> w[i];

  vector<int> s(n+1, 0);
  for (int i = 0; i < n; i++) {
    s[i+1] = s[i] + w[i];
  }

  int ans = inf;

  for (int t = 1; t < n; t++) {
    ans = min(ans, abs(s[t] - (s[n] - s[t])));
  }

  cout << ans << endl;
  return 0;
}