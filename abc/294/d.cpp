#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, q;
  cin >> n >> q;

  set<ll> person;
  rep(i, n) person.emplace(i);
  set<ll> called;

  while (q--) {
    ll t;
    cin >> t;

    if (t == 1) {
      ll p = *person.begin();
      person.erase(p);
      called.emplace(p);
    }
    if (t == 2) {
      ll x;
      cin >> x;
      --x;
      called.erase(x);
    }
    if (t == 3) {
      ll p = *called.begin();
      cout << p+1 << '\n';
    }
  }
  return 0;
}