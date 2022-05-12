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
#include <string>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
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


string s;


char step_char(char c, ll step) {
  c = 'A' + (c - 'A' + step) % 3;
  return c;
}


char f(ll t, ll k) {
  if (t == 0) return s[k];
  if (k == 0) return step_char(s[0], t);

  char c = f(t-1, k/2);
  if (k % 2 == 0) return step_char(c, 1);
  else return step_char(c, 2);
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> s;

  ll q;
  cin >> q;

  while (q--) {
    ll t, k;
    cin >> t >> k;
    --k;

    cout << f(t, k) << "\n";
  }
  return 0;
}