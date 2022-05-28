#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
#define rng(a) (a).begin(),(a).end()
#define rrng(a) (a).rbegin(),(a).rend()
using namespace std;
using ll = long long;
using P = pair<long long, long long>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;


ll calc_sum(ll x, ll cnt) {
  ll res = cnt * (cnt+1) / 2;
  res *= x;
  return res;
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, a, b;
  cin >> n >> a >> b;

  ll sum = n * (n+1) / 2;
  ll ans;

  ll g = gcd(a, b);
  if (!(g == a || g == b)) {
    ll cnt_a = n/a;
    ll sum_a = calc_sum(a, cnt_a);

    ll cnt_b = n/b;
    ll sum_b = calc_sum(b, cnt_b);

    ll ab = lcm(a, b);
    ll cnt_ab = n / ab;
    ll sum_ab = calc_sum(ab, cnt_ab);

    ans = sum - sum_a - sum_b + sum_ab;
  }
  else {
    ll x = min(a, b);

    ll cnt_x = n/x;
    ll sum_x = calc_sum(x, cnt_x);

    ans = sum - sum_x;
  }

  cout << ans << "\n";
  return 0;
}