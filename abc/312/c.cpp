#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N, M;
  cin >> N >> M;

  vector<ll> A(N);
  for (auto& a : A) cin >> a;

  vector<ll> B(M);
  for (auto& b : B) cin >> b;

  ll ng = 0;
  ll ok = 1e9 + 1;
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;

    auto check = [&]() {
      ll cnt_a = ranges::count_if(A, [&](ll x) { return x <= mid; });
      ll cnt_b = ranges::count_if(B, [&](ll x) { return x >= mid; });
      return cnt_a >= cnt_b;
    };

    if (check())
      ok = mid;
    else
      ng = mid;
  }

  cout << ok << '\n';
}
