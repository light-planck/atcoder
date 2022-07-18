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
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;

  vector<ll> ans(n, -1);
  vector<ll> under(n, -1);
  set<ll> st;
  dsu uf(n);

  rep(i, n) {
    ll p;
    cin >> p;
    --p;

    auto itr = st.lower_bound(p);
    if (itr == st.end()) {
      st.emplace(p);
    }
    else {
      under[p] = *itr;
      uf.merge(*itr, p);
      st.erase(*itr);
      st.emplace(p);
    }

    if (uf.size(p) == k) {
      ll now = p;
      st.erase(p);
      ll j = k;

      while (j--) {
        ans[now] = i + 1;
        now = under[now];
      }
    }
  }

  rep(i, n) cout << ans[i] << "\n";
  return 0;
}