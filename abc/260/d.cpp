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

  vector<ll> p(n);
  rep(i, n) {
    cin >> p[i];
    --p[i];
  }

  priority_queue<ll, vector<ll>, greater<ll>> heap;
  ll cnt = 0;
  vector<ll> ans(n, -1);
  dsu uf(n);
  set<ll> st;
  
  vector<vector<ll>> group(n, vector<ll>());
  rep(i, n) {
    heap.emplace(p[i]);
    st.insert(p[i]);

    // if (not heap.empty()) {
    //   ll u = heap.top();
    //   if (p[i] < u) {
    //     uf.merge(u, p[i]);
    //     // if (uf.size(u) == k) {
    //     //   cnt = k;
    //     //   while(cnt) {
    //     //     auto v = heap.top();
    //     //     heap.pop();
    //     //     --cnt;
    //     //     ans[v] = i + 1;
    //     //   }
    //     // }

    //       ll leader = uf.leader(u);
    //     if (uf.size(u) == k) {
    //       for (auto v : group[leader]) {
    //         ans[v] = i + 1;
    //       }
    //     }
    //     else {
    //       group[leader].emplace_back(p[i]);
    //     }
    //   }
    // }

    if (not st.empty()) {
      ll min_p = *st.begin();
      auto itr = st.lower_bound(p[i]);
      if (itr != st.end()) {
        uf.merge(*itr, p[i]);
        if (uf.size(*itr) == k) {
          cnt = k;
          for (; itr != st.end() or k; ++itr) {
            ans[*itr] = i + 1;
            st.erase(*itr);
            --cnt;
          }
        }
      }
    }
  }

  rep(i, n) cout << ans[i] << "\n";
  return 0;
}