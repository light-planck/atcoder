#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  map<string, ll> score;
  rep(i, n) {
    string s;
    cin >> s;
    ++score[s];
  }

  ll m;
  cin >> m;
  rep(i, m) {
    string t;
    cin >> t;
    --score[t];
  }

  ll ans = 0;
  for (auto [s, cnt] : score) {
    auto chmax = [](auto& a, auto b) { if (a < b) a = b; };
    chmax(ans, cnt);
  }

  cout << ans << '\n';
  return 0;
}