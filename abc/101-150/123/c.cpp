#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

// 移動時間は、移動人数が最も小さい値に左右される。
// 例えば1つだけ移動人数が3で、他は100のとき、
// 各区間は100人ずつ移動するが、3人の区間のときは当然3人
// ずつ移動する。それ以降の区間も3人ずつ移動することになる。
// 3人の区間は100人を3人ずつ移動させるが、100 % 3 = 1なので
// 最後に1人あまる。ゆえに移動回数はn / 3の切り上げとなる。
// それ以降は3人を移動させるため、各区間の移動時間は1分である。
// 都市1-6があって、区間は5つある。移動可能人数が最小値の区間が
// n / minの切り上げかかり、他4つの区間は1分で移動できるので
// 答えは(n + min - 1) / min + 4となる。

int main() {
  ll n;
  cin >> n;
  vector<ll> t(5);
  rep(i, 5) cin >> t[i];
  ll mn = LLONG_MAX/2;
  rep(i, 5) mn = min(mn, t[i]);
  ll ans = (n + mn - 1) / mn + 4;
  cout << ans << endl;
  return 0;
}