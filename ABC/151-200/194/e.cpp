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


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  // 0~nまでの整数の集合
  set<ll> st;
  rep(i, n+1) st.insert(i);

  // aの出現回数
  map<ll, ll> mp;

  // a0 ~ am-1のmexを求める
  rep(i, m) {
    ++mp[a[i]];

    if (st.count(a[i])) {
      st.erase(a[i]);
    }
  }
  ll ans = n;
  chmin(ans, *st.begin());

  // am ~ an-mまで見る
  for (int i = m; i < n; ++i) {
    ll prev = a[i - m];
    ll now = a[i];

    --mp[prev]; ++mp[now];

    if (now != prev) {
      if (mp[prev] == 0) st.insert(prev);
      if (st.count(now)) st.erase(now);
    }

    // 更新
    chmin(ans, *st.begin());
  }

  cout << ans << "\n";
  return 0;
}