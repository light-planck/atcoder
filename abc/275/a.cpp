#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector<ll> h(n);
  rep(i, n) cin >> h[i];

  cout << max_element(h.begin(), h.end()) - h.begin() + 1 << '\n';
  return 0;
}