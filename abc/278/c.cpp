#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, q;
  cin >> n >> q;

  map<pair<ll, ll>, bool> follow;

  while (q--) {
    ll type, a, b;
    cin >> type >> a >> b;

    if (type == 1) {
      follow[{a, b}] = true;
    }
    if (type == 2) {
      follow[{a, b}] = false;
    }
    if (type == 3) {
      if (follow[{a, b}] and follow[{b, a}]) cout << "Yes" << '\n';
      else cout << "No" << '\n';
    }
  }
  return 0;
}