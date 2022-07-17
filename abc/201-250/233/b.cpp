#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

// string sに対し、0-indexedで
// s.substr(a, b)はs[a]からb文字を取り取ったもの。
// s.substr(x)はs[x]から最後まで切り取ったもの。

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int l, r;
  cin >> l >> r;
  l--; r--;
  string s;
  cin >> s;
  string a = s.substr(0, l);
  string b = s.substr(l, r - l + 1);
  string c = s.substr(r + 1);
  reverse(all(b));
  cout << a << b << c << "\n";
  return 0;
}