#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int n;
  cin >> n;
  //3次元配列
  vector<vector<pair<int, int>>> p;
  vector<int> a(n);
  p.resize(n);
  rep(i, n) {
    cin >> a[i];
    p[i].resize(a[i]);
    rep(j, a[i]) {
      int x, y;
      cin >> x >> y;
      x--;
      p[i][j] = make_pair(x, y);
    }
  }
  int ans = 0;

  //2^n通りの組み合わせ
  for (int bit = 0; bit < (1 << n); bit++) {
    int cnt = __builtin_popcount(bit);
    bool ok = true;

    //一人ずつ真偽を調べる
    rep(i, n) {

      //i人目が親切なとき
      if (bit & (1 << i)) {

        //i人目の証言a個調べる
        rep(j, a[i]) {

          //x：何番目か y：真偽
          int x = p[i][j].first;
          int y = p[i][j].second;

          //bit[x] == yならば矛盾なし
          //矛盾ありなら次のbit列に進む
          //bit[x] = 0, y = 1
          if (!(bit & (1 << x)) && y == 1) {
            ok = false;
            break;
          }

          //bit[x] = 1, y = 0
          if ((bit & (1 << x)) && y == 0) {
            ok = false;
            break;
          }

          if (!ok) break;
        }

        if (!ok) break;
      }
    }

    //矛盾なし
    if(ok) ans = max(ans, cnt);
  }

  cout << ans << endl;
  return 0;
}