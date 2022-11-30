#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  map<ll, ll> add;
  rep(i, n) {
    ll a;
    cin >> a;
    add[i] = a;
  }

  ll q;
  cin >> q;

  ll base = 0;

  while (q--) {
    ll type;
    cin >> type;

    if (type == 1) {
      ll x;
      cin >> x;

      base = x;
      add.clear();
    }

    if (type == 2) {
      ll i, x;
      cin >> i >> x;
      --i;

      add[i] += x;
    }

    if (type == 3) {
      ll i;
      cin >> i;
      --i;

      cout << base+add[i] << '\n';
    }
  }
  return 0;
}