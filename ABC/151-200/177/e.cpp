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


// 約数列挙
vector<long long> enumerate_divs(long long n) {
  vector<long long> divs;

  for (long long i = 1; i * i <= n; i++) {
    if (n % i != 0) continue;
    divs.emplace_back(i);

    // n = i * iの場合を除いて、もう一方の約数を追加
    if (n / i != i) divs.push_back(n / i);
  }
  sort(divs.begin(), divs.end());

  return divs;
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

  // <div, cnt>
  map<ll, ll> cnt;
  rep(i, n) {
    auto divs = enumerate_divs(a[i]);
    
    for (auto d : divs) {
      if (d == 1) continue;

      ++cnt[d];
      if (cnt[d] >= 2) {
        cout << "setwise coprime" << "\n";
        return 0;
      }
    }
  }

  cout << "pairwise coprime" << "\n";
  return 0;
}