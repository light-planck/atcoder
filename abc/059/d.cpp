#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  ll n = s.size();
  map<char, vector<ll>> pos;
  rep(i, n) pos[s[i]].emplace_back(i);

  for (auto [c, vi] : pos) {
    ll m = vi.size();
    if (m <= 1) continue;

    rep(j, m-1) if (vi[j+1]-vi[j] <= 2) {
      cout << vi[j]+1 << " " << vi[j+1]+1 << '\n';
      return 0;
    }
  }

  cout << -1 << " " << -1 << '\n';
  return 0;
}