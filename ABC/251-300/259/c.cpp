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

  string s;
  cin >> s;

  string t;
  cin >> t;

  ll n = s.size();
  ll m = t.size();

  if (n > m) {
    cout << "No" << "\n";
    return 0;
  }

  ll i = 0;
  ll j = 0;
  while (j < m) {
    if (i == n) {
      while (j < m) {
        if (s[i-1] == t[j]) ++j;
        else {
          cout << "No" << "\n";
          return 0;
        }
      }
    }
    else {
      if (s[i] == t[j]) {
        ++i;
        ++j;
      }
      else {
        if (i - 2 >= 0 and s[i - 1] == s[i - 2] and t[j] == s[i - 1] and t[j] == s[i - 2]) ++j;
        else {
          cout << "No" << "\n";
          return 0;
        }
      }
    }

  }

  if (i == n and j == m) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}