#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/all>
using namespace atcoder;


int main() {
  ll a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  
  using mint = modint998244353;
  mint ans = 0;
  ans = (mint)a*b*c - (mint)d*e*f;
  cout << ans.val() << '\n';
  return 0;
}