#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, c;
  cin >> n >> c;

  // 原点Oを初項として挿入
  vector<ll> x(n+1), v(n+1);
  rep(i, n) cin >> x[i+1] >> v[i+1];

  ll ans = 0;
  for (ll a = 0; a <= n; ++a) {
    for (ll b = n; b >= 0; --b) {
      // a, bが原点でない限り、x[a] < x[b]を満たす必要がある
      if (b != 0 and (x[a]>x[b])) continue;

      // 距離は2OA+OB, OA+2OBのいずれか
      ll oa = x[a];
      ll ob = c - x[b];

      // 栄養価を0~a, n~bまで求める
      ll sum = 0;
      rep(i, a) sum += v[i];
      ll rev_sum = 0;
      for (ll i = n; i >= b; --i) sum += v[i];

      ll tmp = (sum-2*oa) + (rev_sum-ob);
      tmp = max(tmp, (sum-oa) + (rev_sum-2*ob));
      ans = max(ans, tmp);
    }
  }

  cout << ans << '\n';
  return 0;
}