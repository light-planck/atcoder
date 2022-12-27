#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector<ll> r(n);
  rep(i, n) cin >> r[i];

  vector<ll> b(n);
  rep(i, n) cin >> b[i];

  sort(r.begin(), r.end());
  sort(b.begin(), b.end());
  
  if (r == b) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}