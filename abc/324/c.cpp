#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  string T;
  cin >> N >> T;

  set<ll> ans;
  rep(i, N) {
    string s;
    cin >> s;

    if (abs(ssize(s) - ssize(T)) > 1) continue;

    bool found = false;
    if (s == T) {
      ans.emplace(i + 1);
      found = true;
    }

    if (found) continue;
    rep(j, ssize(s) + 1) {
      rep(k, 'z' - 'a') {
        string u = s.substr(0, j) + (char)('a' + k) + s.substr(j);

        if (u == T) {
          ans.emplace(i + 1);
          found = true;
        }
      }
    }

    if (found) continue;
    rep(j, ssize(s)) {
      string u = s.substr(0, j) + s.substr(j + 1);

      if (u == T) {
        ans.emplace(i + 1);
        found = true;
      }
    }

    if (found) continue;
    rep(j, ssize(s)) {
      rep(k, 'z' - 'a') {
        string u = s;
        u[j] = 'a' + k;

        if (u == T) {
          ans.emplace(i + 1);
        }
      }
    }
  }

  cout << ssize(ans) << '\n';
  for (auto x : ans) {
    cout << x << '\n';
  }
}
