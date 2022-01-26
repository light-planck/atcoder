#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  string s;
  cin >> s;
  string Mx = s;
  string mn = s;
  int len = s.size();
  string t = s;

  // 右
  rep(i, len-1) {
    string t;
    rep(j, len) {
      t += s[(i + 1 + j) % len];
    }
    if (t > Mx) Mx = t;
    if (t < mn) mn = t;
  }

  // 左
  rep(i, len-1) {
    string t;
    rep(j, len) {
      t += s[(i + len-1 + j) % len];
    }
    if (t > Mx) Mx = t;
    if (t < mn) mn = t;
  }

  cout << mn << endl;
  cout << Mx << endl;
  return 0;
}