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


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, a, b;
  cin >> n >> a >> b;

  for (ll i = 0; i < n*a; ++i) {
    for (ll j = 0; j < n*b; ++j) {
      ll x = i/a;
      ll y = j/b;

      if (x % 2 == 0) {
        if (y % 2 == 0) {
          cout << ".";
        }
        else {
          cout << "#";
        }
      }
      else {
        if (y % 2 == 0) {
          cout << "#";
        }
        else {
          cout << ".";
        }
      }
    }
    cout << "\n";
  }
  return 0;
}