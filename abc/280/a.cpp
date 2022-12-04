#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep(i, h) cin >> s[i];

  ll ans = 0;
  rep(i, h) rep(j, w) {
    if (s[i][j] == '#') ++ans;
  }

  cout << ans << '\n';
  return 0;
}