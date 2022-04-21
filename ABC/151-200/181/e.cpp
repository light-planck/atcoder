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


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;

  vector<ll> h(n);
  rep(i, n) cin >> h[i]; 
  sort(all(h));

  vector<ll> w(m);
  rep(i, m) cin >> w[i];

  // left, right[k]: 左からk人の差の総和
  vector<ll> left(n + 1), right(n + 1);
  for (int i = 2; i < n; i += 2) {
    left[i] = left[i - 2] + (h[i - 1] - h[i - 2]);
    right[i] = right[i - 2] + (h[n - i + 1] - h[n - i]);
  }

  ll ans = 1e18;
  rep(i, m) {
    ll idx = lower_bound(all(h), w[i]) - h.begin();
    ll tmp = 0;

    if (idx % 2 == 0) {
      tmp = left[idx] + right[n - idx - 1] + abs(w[i] - h[idx]);
    }
    else {
      tmp = left[idx - 1] + right[n - idx] + abs(w[i] - h[idx - 1]);
    }

    chmin(ans, tmp);
  }

  cout << ans << "\n";
  return 0;
}