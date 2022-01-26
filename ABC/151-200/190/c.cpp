#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  rep(i, m) cin >> a[i] >> b[i];
  int k;
  cin >> k;
  vector<int> c(k), d(k);
  rep(i, k) cin >> c[i] >> d[i];
  int ans = 0;

  // 2^k
  // bit[i] = 0 -> c, b[i] = 1 -> dの皿にボールを置く
  // bit = 1001 d[0], c[1], c[2], d[3]にバールが置かれている
  for (int bit = 0; bit < (1 << k); bit++) {

    // 満たす条件の個数
    int cnt = 0;

    // ball[i] 皿iにボールが載っているとき1,　そうでないなら0
    vector<int> ball(n+1);

    // bitが立っているか
    for (int i = 0; i < k; i++) {
      if (bit & (1 << i)) ball[d[i]]++;
      else ball[c[i]]++;
    }

    // 満たす条件のカウント
    for (int i = 0; i < m; i++) {

      // ボールを置く場所が重複する場合があるので1以上のとき
      if (ball[a[i]] >= 1 && ball[b[i]] >= 1) cnt++;
    }

    ans = max(ans, cnt);
  }

  cout << ans << endl;
  return 0;
}