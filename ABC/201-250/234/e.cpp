#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

// 初項は1~9
// 公差は-9~8 d = 9のとき、09となり不適切
// 桁数は1~18
// 合わせて9 * 18 * 18 = 2916であり十分高速

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll x;
  cin >> x;

  vector<ll> ans;

  // 初項
  for (int first = 1; first <= 9; ++first) {

    // 公差
    for (int d = -9; d <= 8; ++d) {
      string s;
      int digit = first;

      // 桁数
      for (int i = 1; i <= 18; ++i) {
        s += digit + '0';
        ll num = stoll(s);
        ans.push_back(num);

        digit += d;
        if (digit < 0 || digit >= 10) break;
      }
    }
  }
  
  sort(all(ans));
  int idx = lower_bound(all(ans), x) - ans.begin();
  cout << ans[idx] << "\n";
  return 0;
}