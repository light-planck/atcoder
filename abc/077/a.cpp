#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n = 2;
  vector<string> s(n);
  rep(i, n) cin >> s[i];

  vector<string> t;
  rep(i, n) {
    auto ti = s[n-1-i];
    reverse(ti.begin(), ti.end());
    t.emplace_back(ti);
  }

  if (t == s) cout << "YES" << '\n';
  else cout << "NO" << '\n';
  return 0;
}