#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  #define rng(a) (a).begin(),(a).end()
  sort(rng(a));
  ll max_a = a.back();

  auto round = [](ll x, ll y) { return (x + y - 1) / y; };

  constexpr ll inf = 9e18;
  ll dx = inf;
  ll r = 0; ll x = round(max_a, 2);
  rep(i, n-1) {
    if (abs(a[i] - x) < dx) {
      dx = abs(a[i] - x);
      r = a[i];
    }
  }

  cout << max_a << " " << r << '\n';
  return 0;
}