#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  pair<ll, ll> prev = {1, 1};
  rep(i, n) {
    ll t, a;
    cin >> t >> a;

    auto [pt, pa] = prev;
    auto round = [](ll a, ll b) { return (a + b - 1) / b; };
    ll k = max(round(pt, t), round(pa, a));
    prev = {k*t, k*a};
  }

  cout << prev.first + prev.second << '\n';
  return 0;
}