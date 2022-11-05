#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector<ll> p(n);
  rep(i, n) cin >> p[i];

  prev_permutation(p.begin(), p.end());
  for (auto x : p) cout << x << '\n';
  return 0;
}