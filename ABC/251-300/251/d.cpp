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
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll w;
  cin >> w;

  vector<ll> a;
  for (ll i = 1; i <= w; ++i) {
    ll len = a.size();
    bool flag = false;

    if (len == 0) {
      // cout << "size: " << len << "\n";

      a.emplace_back(i);
      continue;
    }
    else if (len == 1) {
      // cout << "size: " << len << "\n";

      if (a[0] == i) continue;
    }
    else if (len == 2) {
      // cout << "size: " << len << "\n";

      if (a[0] == i) continue;
      if (a[1] == i) continue;

      if (a[0] + a[1] == i) continue;
    }
    else {
      // cout << "size: " << len << "\n";

      
      for (ll j = 0; j < len; ++j) {
        if (a[j] == i) {
          flag = true;
          continue;
        }

        for (ll k = j + 1; k < len; ++k) {
          if (a[k] == i) {
            flag = true;
            continue;
          }

          // cout << j << " " << k << " " << a[j] + a[k] << "\n";
          if (a[j] + a[k] == i) {
            flag = true;
            continue;
          }

          for (ll l = k + 1; l < len; ++l) {
            // cout << j << " " << k << " " << l << " " << a[j] + a[k] + a[l] << endl;

            if (a[l] == i) {
              flag = true;
              continue;
            }

            if (a[j] + a[l] == i) {
              flag = true;
              continue;
            }
            if (a[k] + a[l] == i) {
              flag = true;
              continue;
            }

            if (a[j] + a[k] + a[l] == i) {
              flag = true;
              continue;
            }
          }
        }

        if (flag) break;
      }
    }

    // cout << i << "を追加" << "\n";
    if (!flag)
    a.emplace_back(i);
  }

  cout << a.size() << "\n";
  for (auto ai : a) cout << ai << "\n";
  return 0;
}