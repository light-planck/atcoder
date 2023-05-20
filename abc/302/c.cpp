#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  vector<string> s(n);
  rep(i, n) cin >> s[i];
  sort(s.begin(), s.end());

  do {
    bool ok = true;

    rep(i, n-1) {
      ll cnt = 0;
      rep(j, m) {
        if (s[i][j] != s[i+1][j]) ++cnt;
      }
      if (cnt != 1) {
        ok = false;
      }
    }

    if (ok) {
      cout << "Yes" << '\n';
      exit(0);
    }
  } while (next_permutation(s.begin(), s.end()));

  cout << "No" << '\n';
  return 0;
}