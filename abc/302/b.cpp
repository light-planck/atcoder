#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep(i, h) cin >> s[i];

  vector<pair<ll, ll>> dij = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

  auto check_ij = [&](ll i, ll j) {
    if (i < 0 or i >= h) return false;
    if (j < 0 or j >= w) return false;
    return true;
  };

  rep(i, h) {
    rep(j, w) {
      for (auto [di, dj] : dij) {
        // set<char> st = {'s', 'n', 'u', 'k', 'e'};
        string snuke = "snuke";
        bool ok = true;
        map<char, pair<ll, ll>> memo;

        rep(k, 5) {
          ll ni = i + di*k;
          ll nj = j + dj*k;

          if (not check_ij(ni, nj)) {
            ok = false;
            break;
          }

          if (snuke[k] != s[ni][nj]) ok = false;
          else {
            memo[s[ni][nj]] = {ni+1, nj+1};
          }
        }

        if (ok) {
          cout << memo['s'].first << " " << memo['s'].second << '\n';
          cout << memo['n'].first << " " << memo['n'].second << '\n';
          cout << memo['u'].first << " " << memo['u'].second << '\n';
          cout << memo['k'].first << " " << memo['k'].second << '\n';
          cout << memo['e'].first << " " << memo['e'].second << '\n';
          exit(0);
        }
      }
    }
  }
  return 0;
}