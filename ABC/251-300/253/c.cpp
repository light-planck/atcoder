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

  multiset<ll> st;
  while (q--) {
    ll t;
    cin >> t;

    if (t == 1) {
      ll x;
      cin >> x;
      st.insert(x);
    }
    else if (t == 2) {
      ll x, c;
      cin >> x >> c;
      
      while (c > 0 and (st.find(x) != st.end())) {
        st.erase(st.find(x));
        --c;
      }
    }
    else {
      cout << *st.rbegin() - *st.begin() << "\n";
    }
  }
  return 0;
}