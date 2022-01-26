#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

// sum[r] - sum[l] = kを満たす(l, r)の個数を求めたい。
// rを固定したとき、sum[r] = sum[l] + kを満たす回数をカウントすればよい。

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;

  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> sum(n + 1);
  rep(i, n) sum[i + 1] = sum[i] + a[i];

  ll cnt = 0;
  map<ll, int> mp;
  rep(r, n + 1) {
    cnt += mp[sum[r]];
    mp[sum[r] + k]++;
  }

  cout << cnt << "\n";
  return 0;
}