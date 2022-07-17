#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

// 区間の左端l、右端rとする。
// lを固定し、rを.をxに変更できる回数まで動かす。
// xの長さを最大であったら保持する。
// rを移動させることができなくなったら、lを左に動かし、
// 同様にrを動かしていく。

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  int k;
  cin >> k;
  int n = s.size();

  // 累積和
  vector<ll> sum(n + 1);
  rep(i, n) {
    if (s[i] == '.') sum[i + 1] = sum[i] + 1;
    else sum[i + 1] = sum[i];
  }

  int ans = 0;
  int r = 0;
  for (int l = 0; l < n; l++) {
    while (r < n && sum[r + 1] - sum[l] <= k) {
      r++;
    }
    ans = max(ans, r - l);
  }

  cout << ans << "\n";
  return 0;
}