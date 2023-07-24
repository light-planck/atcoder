#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() { 
  ll n, p, q;
  cin >> n >> p >> q;

  vector<ll> d(n);
  rep(i, n) cin >> d[i];

  cout << min(p, q + *min_element(d.begin(), d.end())) << '\n';
  return 0;
}