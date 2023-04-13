#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep(i, h) cin >> s[i];

  rep(i, h) rep(j, w-1) {
    if (s[i][j] == 'T' and s[i][j+1] == 'T') {
      s[i][j] = 'P';
      s[i][j+1] = 'C';
    }
  }

  for (auto row : s) cout << row << '\n';
  return 0;
}