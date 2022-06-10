#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;


const int mod = 1e9 + 7;


/*
dp[i]を総和がiとなるような数列の個数とする。
そのような数列で、最後の項xは3 <= x <= iである。
最後の項が3のときそれより前の数列の個数はdp[i - 3]。
4のときdp[i - 4]
...
i - 1のときdp[1]
iのときdp[0]
*/

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int s;
  cin >> s;

  // 総和がiとなるような数列の個数
  vector<int> dp(s + 1);
  dp[0] = 1;
  
  for (int i = 0; i <= s; ++i) {
    for (int j = 0; j <= i - 3; ++j) {
      dp[i] += dp[j];
      dp[i] %= mod;
    }
  }

  cout << dp[s] << "\n";
  return 0;
}