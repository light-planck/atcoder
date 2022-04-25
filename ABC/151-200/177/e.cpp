#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath> // abs, sqrt, cos, ...
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


// 素因数分解
vector<pair<long long, long long>> prime_factorize(long long n) {
  vector<pair<long long, long long>> primes;

  for (long long i = 2; i * i <= n; ++i) {
    if (n % i != 0) continue;

    long long exponent = 0;
    while (n % i == 0) {
      ++exponent;
      n /= i;
    }

    primes.emplace_back(i, exponent);
  }

  // 上の処理後にnが1でないならnは素数
  if (n != 1) {
    primes.emplace_back(n, 1);
  }

  return primes;
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  // gcd(a0, ..., a_n-1) != 1ならばnot coprime
  ll g = 0;
  rep(i, n) g = __gcd(g, a[i]);
  if (g != 1) {
    cout << "not coprime" << "\n";
    return 0;
  }

  // <prime, cnt>
  map<ll, ll> cnt;

  // 重複する素因数があるか確認
  rep(i, n) {
    auto primes = prime_factorize(a[i]);
    
    for (auto p_ex : primes) {
      ll p = p_ex.first;

      if (p == 1) continue;

      ++cnt[p];
      if (cnt[p] >= 2) {
        cout << "setwise coprime" << "\n";
        return 0;
      }
    }
  }

  cout << "pairwise coprime" << "\n";
  return 0;
}