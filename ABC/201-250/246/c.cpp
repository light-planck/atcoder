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
商品の値段をaとすると
1. a > x => -x
2. 0 < a <= x => -a
の2通りの割引パターンが存在する。
1.の場合、aの値によらず割引額はxの定数倍である。
*/


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, k, x;
  cin >> n >> k >> x;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  // クーポンを利用しない場合の合計金額
  ll ans = 0;
  rep(i, n) ans += a[i];

  // 無限にクーポンが使えるならば
  // sigma(a[i]/x) * x円割引される
  ll cnt = 0;
  rep(i, n) cnt += a[i] / x;
  chmin(cnt, k);
  ans -= cnt * x;
  k -= cnt;

  // まだクーポンを使えるならば
  // 商品の価格はa[i] % xであるから
  // それらの大きい順に割引していく
  rep(i, n) a[i] %= x;
  sort(a.rbegin(), a.rend());
  rep(i, n) {
    if (k == 0) break;
    
    ans -= a[i];
    --k;
  }

  cout << ans << "\n";
  return 0;
}