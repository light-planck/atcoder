#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll a, b;
  cin >> a >> b;
  --a; --b;

  ll h = 100; ll w = 100;
  vector<string> s(h, string(w, '.'));
  for (ll i = h/2; i < h; ++i) s[i] = string(w, '#');

  // 上半分の白をb個黒に塗る
  for (ll i = 0; i < h/2 - 1; i += 2) for (ll j = 0; j < w; j += 2) {
    if (b > 0){
      s[i][j] = '#';
      --b;
    }
    if (b == 0) break;
  }

  // 下半分の黒をa個分白に塗る
  for (ll i = h/2 + 1; i < h; i += 2) for (ll j = 0; j < w; j += 2) {
    if (a > 0) {
      s[i][j] = '.';
      --a;
    }
    if (a == 0) break;
  }

  cout << h << " " << w << '\n';
  for (string row : s) cout << row << '\n';

  // debug
  // rep(i, h) {
  //   cout << i << ": ";
  //   cout << s[i] << '\n';
  // }
  return 0;
}