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

#include <atcoder/modint>
using namespace atcoder;

int main() {
  using mint = modint998244353;
  mint x = 2;
  cout << x.inv().val() << '\n';
  return 0;
}