#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep(i, h) cin >> s[i];

  const vector<pair<ll, ll>> dij = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

  auto check_ij = [&](ll i, ll j) {
    if (i < 0 or i >= h) return false;
    if (j < 0 or j >= w) return false;
    return true;
  };

  rep(i, h) {
    rep(j, w) {
      for (auto [di, dj] : dij) {
        string snuke = "snuke";
        bool ok = true;
        const ll len = 5;
        vector<pair<ll, ll>> rc(len);

        rep(k, len) {
          ll ni = i + di*k;
          ll nj = j + dj*k;

          if (not check_ij(ni, nj)) {
            ok = false;
            break;
          }

          if (snuke[k] != s[ni][nj]) ok = false;
          else rc[k] = {ni+1, nj+1};
        }

        if (ok) {
          for (auto [r, c] : rc) {
            cout << r << " " << c << '\n';
          }
          exit(0);
        }
      }
    }
  }
  return 0;
}