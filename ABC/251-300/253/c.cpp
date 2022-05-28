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


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll q;
  cin >> q;

  set<ll> st;
  map<ll, ll> cnt;
  while (q--) {
    ll type;
    cin >> type;
    
    if (type == 1) {
      ll x;
      cin >> x;

      ++cnt[x];
      st.insert(x);
    }
    else if (type == 2) {
      ll x, c;
      cin >> x >> c;

      cnt[x] -= min(c, cnt[x]);

      if (cnt[x] == 0) st.erase(x);
    }
    else {
      cout << *rbegin(st) - *begin(st) << "\n";
    }

    // cout << "q: " << q << "\n";
    // for (auto x : st) {
    //   cout << x << " ";
    // }
    // cout << "\n";
  }
  return 0;
}