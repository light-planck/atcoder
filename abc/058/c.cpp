#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector<string> s(n);
  rep(i, n) cin >> s[i];

  ll m = 26;
  vector cnt(n, vector<ll>(m));
  rep(i, n) {
    for (auto c : s[i]) ++cnt[i][c-'a'];
  }

  string ans = "";
  rep(j, m) {
    auto chmin = [](auto& a, auto b) { if (a > b) a = b; };
    ll min_cnt = 1e18;

    rep(i, n) {
      chmin(min_cnt, cnt[i][j]);
    }

    string tmp = string(min_cnt, 'a'+j);
    if (tmp != "") ans += tmp;
  }

  cout << ans << '\n';
  return 0;
}