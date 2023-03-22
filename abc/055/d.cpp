#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  string s;
  cin >> s;

  rep(a, 2) rep(b, 2) {
    vector<ll> animals(n, -1);
    animals[0] = a;
    animals[n-1] = b;
    bool ok = true;
    rep(i, n) {
      ll prev = (i-1+n) % n;
      ll next = (i+1) % n;
      if (animals[i] == 1) {
        if (s[i] == 'o') {
          if (animals[next] == -1) animals[next] = animals[prev];
          else if (animals[next] != animals[prev]) ok = false;
        }
        else {
          if (animals[next] == -1) animals[next] = animals[prev] ^ 1;
          else if (animals[next] == animals[prev]) ok = false;
        }
      }
      else {
        if (s[i] == 'o') {
          if (animals[next] == -1) animals[next] = animals[prev] ^ 1;
          else if (animals[next] == animals[prev]) ok = false;
        }
        else {
          if (animals[next] == -1) animals[next] = animals[prev];
          else if (animals[next] != animals[prev]) ok = false;
        }
      }
    }

    if (not ok) continue;

    for (auto d : animals) {
      if (d == 1) cout << 'S';
      else cout << 'W';
    }
    cout << '\n';
    return 0;
  }

  cout << -1 << '\n';
  return 0;
}