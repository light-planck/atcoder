#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath> // abs, sqrt, cos, ...
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


/*
b = (1, 2, ..., a1, 1, 2, ..., a2, ..., 1, 2, ..., an)
のうち大きい数からk個選べばいい。
bのうち、m以上となる個数がk個以下となるmを求め、その個数をcnt
とするとans = (m以上のb) * cnt
k - cnt > 0なら
ans += (k-cnt) * (m-1)
*/


ll count(vector<ll>& a, ll mid) {
  ll res = 0;
  for (auto ai : a) {
    if (ai >= mid) {
      res += ai - mid + 1;
    }
  }
  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  // 二分探索
  // m以上の個数がk個以下となる最大の楽しさを求める
  ll ng = 0; // 0以上となるのはすべてなので満たさない
  ll ok = 2e9 + 1; // inf以上となるのは0個なので必ず満たす
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if (count(a, mid) <= k) ok = mid;
    else ng = mid;
  }

  // ok以上の楽しさを加算
  ll ans = 0;
  rep(i, n) {
    if (a[i] >= ok) {
      ans += (a[i] + ok) * (a[i] - ok + 1) / 2;
    }
  }

  // 残りの加算
  k -= count(a, ok);
  ans += k * (ok - 1);

  cout << ans << "\n";
  return 0;
}