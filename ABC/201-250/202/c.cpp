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
  vector<int> av(n), bv(n), cv(n);
  rep(i, n) cin >> av[i];
  rep(i, n) cin >> bv[i];
  rep(i, n) cin >> cv[i];
  sort(all(av));
  ll ans = 0;

  //jをまず決定する
  for (int j = 1; j <= n; j++) {
    int c = cv[j-1];
    int b = bv[c-1];

    //a = bとなるような個数をカウント
    auto low = lower_bound(all(av), b);
    auto up = upper_bound(all(av), b);
    ans += (up - low);
  }

  cout << ans << endl;
  return 0;
}