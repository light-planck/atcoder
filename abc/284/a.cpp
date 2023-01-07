#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector<string> s(n);
  rep(i, n) cin >> s[i];
  reverse(s.begin(), s.end());

  for (auto x : s) cout << x << '\n';
  return 0;
}