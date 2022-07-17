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


double memo[101][101][101];


double rec(ll x, ll y, ll z) {
  if (x == 100 or y == 100 or z == 100) return 0;

  if (memo[x][y][z] >= 0) return memo[x][y][z];

  double res = 0;
  res += x * (rec(x+1, y, z)+1);
  res += y * (rec(x, y+1, z)+1);
  res += z * (rec(x, y, z+1)+1);
  res /= x + y + z;

  return memo[x][y][z] = res;
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll a, b, c;
  cin >> a >> b >> c;

  rep(i, 101) rep(j, 101) rep(k, 101) memo[i][j][k] = -1;

  printf("%.10f\n", rec(a, b, c));
  return 0;
}