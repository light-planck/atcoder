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


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  string s;
  cin >> s;

  vector<P> w;
  rep(i, n) {
    ll wi;
    cin >> wi;
    w.emplace_back(wi, s[i]-'0');
  }
  sort(rng(w));

  ll ok = -1;
  ll ng = n;
  ll ans = 0;
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;


    auto check = [&]() -> bool {
      ll cnt = 0;

      for (auto [weight, is_adult] : w) {
        if (weight >= w[mid].first and is_adult) ++cnt;
        if (weight < w[mid].first and not is_adult) ++cnt;
      }
      
      if (cnt > ans) {
        ans = cnt;
        return true;
      }
      else return false;
    };


    if (check()) ng = mid;
    else ok = mid;

    cout << w[ok].first << "\n";
  }

  cout << ans << "\n";
  return 0;
}