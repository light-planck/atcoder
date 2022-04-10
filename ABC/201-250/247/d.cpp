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

  ll q;
  cin >> q;

  deque<pair<ll, ll>> deq;
  while (q--) {
    ll t;
    cin >> t;

    // 右端に挿入
    if (t == 1) {
      ll x, c;
      cin >> x >> c;

      if (deq.size()) {
        pair<ll, ll> right = deq.back();
        if (right.first == x) {
          right.second += c;
        }
        else {
          deq.push_back(make_pair(x, c));
        }
      }
      else {
        deq.push_back(make_pair(x, c));
      }
    }

    // 左端を出力
    else {
      ll c;
      cin >> c;

      ll res = 0;
      while (true) {
        pair<ll, ll> left = deq.front();

        if (left.second >= c) {
          res += c * left.first;
          deq.front().second -= c;
          if (left.second == 0) deq.pop_front();
          break;
        }
        else {
          res += left.second * left.first;
          c -= left.second;
          deq.pop_front();
        }
      }

      cout << res << "\n";
    }
  }
  return 0;
}