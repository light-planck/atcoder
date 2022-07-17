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


ll f(ll x, ll m) {
  return x % m;
}

ll memo[100100];

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, x, m;
  cin >> n >> x >> m;

  vector<vector<ll>> pos(m);

  ll start = 0;
  ll stop = 0;
  ll period = 1;

  memo[0] = x;
  pos[x].emplace_back(0);

  ll i = 1;
  while (true) {
    ll prev = memo[i - 1];

    ll now = f(prev * prev , m);
    memo[i] = now;
    pos[now].emplace_back(i);

    // 2回カウントしたら周期を求める
    if (pos[now].size() == 2) {

      // 周期開始インデックス
      start = pos[now][0];
      stop = pos[now][1];
      period = stop - start;
      break;
    }

    ++i;
  }

  // 周期に入る前までの和
  ll sum1 = 0;
  for (ll i = 0; i < start; ++i) sum1 += memo[i];

  // 1周期の和
  ll period_sum = 0;
  for (ll i = start; i < stop; ++i) period_sum += memo[i];
  // 周期の総和
  ll sum2 = period_sum * ((n-start) / period);

  // あまりの総和
  ll sum3 = 0;
  for (ll i = start; i < start + ((n-start) % period); ++i) sum3 += memo[i];

  cout << sum1 + sum2 + sum3 << "\n";
  return 0;
}