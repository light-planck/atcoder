#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  vector<ll> A(N);
  for (auto& a : A) cin >> a;

  map<ll, vector<ll>> idx;
  ll ans = 0;
  map<ll, ll> cnt_j;
  rep(i, N) {
    idx[A[i]].emplace_back(i);
    ll cnt = idx[A[i]].size();

    if (cnt == 1) continue;

    ll cnt_i = 0;
    rep(j, cnt - 1) {
      if (idx[A[i]][j + 1] - idx[A[i]][j] > 1) ++cnt_i;
    }

    cnt_j[A[i]] += idx[A[i]].back() - idx[A[i]][cnt - 2] - 1;
    ans += cnt_i * cnt_j[A[i]];
  }

  cout << ans << '\n';
}
