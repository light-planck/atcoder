#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;


ll n, k, x;
vector<ll> a;
ll max_cnt = -1;

// y = a[idx]のときの利用回数
ll cnt(ll idx) {
  ll res = 0;
  ll y = a[idx];

  for (ll i = idx; i < n; ++i) {
    res += a[i] / x;
    if (a[i] % x >= y) ++res;
  }

  return res;
}

// y = a[idx]のとき利用回数がk以下か
bool is_ok(ll idx) {
  if (cnt(idx) <= k )
}

// y円以上の品物にクーポンを使うとき
// 利用回数 <= kとなるような
// aのidxを返す
ll bs() {
  ll ng = -1;
  ll ok = n;

  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;

    if (is_ok(mid)) ok = mid;
    else ng = mid;
  }

  return ok;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k >> x;

  a.resize(n);
  rep(i, n) cin >> a[i];

  sort(all(a));

  ll y = bs();
  ll ans = 0;
  rep(i, n) {
    if (a[i] >= y) ans += y;
    else ans += a[i];
  }

  cout << ans << "\n";
  return 0;
}