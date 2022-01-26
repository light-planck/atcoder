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
  vector<vector<int>> s(m, vector<int>(0));
  rep(i, m) {
    int k;
    cin >> k;
    s[i].resize(k);
    rep(j, k) {
      cin >> s[i][j];
      s[i][j]--;
    }
  }
  vector<int> p(m);
  rep(i, m) cin >> p[i];
  int ans = 0;

  //n個のスイッチに対してon, offの状態が
  //2^n通りある
  for (int bit = 0; bit < (1 << n); bit++) {

    //m個の電球が全て点灯するか
    rep(i, m) {
      int num = 0;
      for (auto t : s[i]) {

        //電球につながっているスイッチでonになっている個数
        if (bit & (1 << t)) num++;
      }

      //1つでも点灯しなかったら違う組み合わせを調べる
      if (num % 2 != p[i]) break;

      //m個の電球が点灯した回数
      if (i == m - 1)ans++;
    }

    
  }

  cout << ans << endl;
  return 0;
}