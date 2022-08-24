#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#define rng(a) (a).begin(),(a).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
  ll n, k;
  cin >> n >> k;

  vector<ll> left = {0};
  vector<ll> right = {0};
  rep(i, n) {
    ll x;
    cin >> x;
    if (x < 0) left.emplace_back(-x);
    else if (x > 0) right.emplace_back(x);
    else --k;
  }
  sort(rng(left));

  constexpr ll inf = 9e18;
  ll ans = inf;
  for (ll l = 0; l < left.size(); ++l) {
    ll r = k - l;
    if (r > right.size() - 1) continue;

    ll t = min(2*left[l] + right[r], left[l] + 2*right[r]);
    chmin(ans, t);
  }

  cout << ans << '\n';
  return 0;
}