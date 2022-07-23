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

  vector<ll> l(2);
  vector<ll> r(2);
  cin >> l[0] >> r[0];
  cin >> l[1] >> r[1];

  vector<ll> line(101);
  rep(i, 2) {
    for (ll j = l[i]; j <= r[i]; ++j) {
      ++line[j];
    }
  }

  ll ans = 0;
  rep(i, 101) {
    if (line[i] == 2) ++ans;
  }

  cout << max(0LL, ans-1) << "\n";
  return 0;
}