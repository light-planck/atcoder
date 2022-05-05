#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <deque>
#include <iostream>
#include <map>
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
#include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;


const int MOD = 1e9+7;
struct Combination {
  vector<long long> fact, fact_inv, inv;
  int size;

  Combination(int size)
      : size(size),
        fact(vector<long long>(size + 10)),
        fact_inv(vector<long long>(size + 10)), 
        inv(vector<long long>(size + 10)) {
  }

  void init() {
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;

    for (int i = 2; i < size + 10; ++i) {
      fact[i] = fact[i - 1] * i % MOD;
      inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
      fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
    }
  }

  long long comb(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;

    return fact[n] * (fact_inv[k] * fact_inv[n - k] % MOD) % MOD;
  }
};


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  Combination c(n);
  c.init();

  for (int i = 1; i <= k; ++i) {
    ll ans = c.comb(k-1, i-1);
    ans *= c.comb(n-k+1, i);
    ans %= MOD;
    cout << ans << "\n";
  }
  return 0;
}