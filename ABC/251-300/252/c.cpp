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

  vector<string> s(n);
  rep(i, n) cin >> s[i];

  ll ans = 1e18;
  for (ll i = 0; i <= 9; ++i) {

    vector<ll> idx;

    // s[j]
    rep(j, n) {
      
      rep(k, 10) {
        if (s[j][k] == '0' + i) {
          idx.emplace_back(k);
          break;
        }
      }
    }

    sort(rng(idx));

    // cout << i << ": ";
    // rep(l, n) {
    //   if (l) cout << " ";

    //   cout << idx[l];
    // }
    // cout << endl;

    // cout << i << ": ";

    set<ll> st;
    // ll t = 0;

    map<ll, ll> mp;

    vector<ll> idx2;

    ll max_t = 0;
    for (auto x : idx) {
      ll t = x + 10 * mp[x];
      chmax(max_t, t);

      ++mp[x];
    }

    // for (auto x : idx) {
    //   if (st.count(x)) {
    //     t += 10;
    //   }
    //   else {
    //     st.insert(x);

    //     if (t > x) t += x;
    //     else t = x;
    //   }

    //   cout << t << " ";
    // }
    // cout << endl;

    chmin(ans, max_t);
  }

  cout << ans << "\n";
  return 0;
}