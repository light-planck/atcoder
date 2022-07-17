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
using P = pair<long long, long long>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;


// 約数列挙
vector<ll> caldiv(ll n) {
  vector<ll> div;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i != 0) continue;
    div.push_back(i);

    // n = i * iの場合を除いて、もう一方の約数を追加
    if (n / i != i) div.push_back(n / i);
  }
  sort(all(div));
  return div;
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  map<ll, ll> cnt;
  rep(i, n) ++cnt[a[i]];

  ll ans = 0;
  rep(i, n) {
    vector<ll> divs = caldiv(a[i]);

    ll len = divs.size();
    ll max_j = 0;
    if (len % 2 == 0) max_j = len / 2;
    else max_j = len/2 + 1;

    for (int j = 0; j < max_j; j++) {
      ll div1 = divs[j];
      ll div2 = a[i] / div1;

      if (div1 == div2) {
        ans += cnt[div1] * cnt[div1];
      }
      else {
      ans += cnt[div1] * cnt[div2] * 2;

      }

      // a = div * divのとき
      // if (div1 == div2) {
      //   if (cnt[div1] >= 2) {
      //     ans += cnt[div1] * (cnt[div1] - 1);
      //   }
      // }
      // else {
      //   // a = 1 * aのとき
      //   if (div1 == 1) {
      //     if (cnt[div1] >= 1 && cnt[div2] >= 1) {
      //       ans += (cnt[div1]) * (cnt[div2]) * 2;
      //     }
      //   }
      //   else {
      //     // aにdivとa/divが含まれているか
      //     if (cnt[div1] >= 1 && cnt[div2] >= 1) {
      //       ans += cnt[div1] * cnt[div2] * 2;
      //     }
      //   }
      // }
    }
  }

  cout << ans << "\n";
  return 0;
}