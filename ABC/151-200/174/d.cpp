#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

// 操作完了後の石の並びは赤をx、白をoとすると4個の場合は以下の通り。
// oooo, xooo, xxoo, xxxo, xxxx
// 与えられたsの並びから上記の並びにするのに必要な回数を計算する。
// しきりをひとつ用意し、それよりも左は赤、右は白となるようにする。
// x|ooo
// しきりより左にある白の個数をw、右にある赤の個数をrとする。これらを0にすればよい。
// w <= rのとき、白の個数分だけ赤と交換し、(w回)残りのw-r個の赤石を白石に変える(r-w回)。
// w > rのとき、同様に、r個分赤と白を交換し、(r回)残りの白を赤にする(w-r回)。
// ゆえに、操作回数はmax(w, r)。

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int r = 0;
  int w = 0;
  rep(i, n) {
    if (s[i] == 'R') r++;
  }
  int ans = r;
  rep(i, n) {
    if (s[i] == 'W') w++;
    else r--;
    ans = min(ans, max(w, r));
  }
  cout << ans << endl;
  return 0;
}