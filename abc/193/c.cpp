#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  ll n;
  cin >> n;

  // a ^ b <= nを満たすような数を重複なしで管理
  // 4^2 = 2^4 = 16など重複がありうる
  set<ll> st;

  // a ^ b <= nを満たす個数
  // b >= 2より、a^2 <= nが条件
  // a * aのときにオーバーフローする可能性があるのでll a
  for (ll a = 2; a * a <= n; a++) {

    // b >= 2なので
    ll x = a * a;
    while (x <= n) {
      st.insert(x);

      // a^3, a^4, ...
      x *= a;
    }
  }

  cout << n - st.size() << endl;
  return 0;
}