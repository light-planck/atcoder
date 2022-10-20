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


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  ll h, w, i, j;
  cin >> h >> w >> i >> j;
  --i; --j;

  ll n;
  cin >> n;

  // i行目にある壁の列数
  map<ll, vector<ll>> ij;
  // j列目にある壁の行数
  map<ll, vector<ll>> ji;
  rep(_, n) {
    ll r, c;
    cin >> r >> c;
    --r; --c;
    ij[r].emplace_back(c);
    ji[c].emplace_back(r);
  }
  for (auto& [_, js] : ij) {
    js.emplace_back(0);
    js.emplace_back(w);
    sort(js.begin(), js.end());
  }
  for (auto& [_, is] : ji) {
    is.emplace_back(0);
    is.emplace_back(h);
    sort(is.begin(), is.end());
  }

  ll q;
  cin >> q;
  while (q--) {
    char c; ll l;
    cin >> c >> l;

    if (c == 'L') {
      if (ij[i].size() == 0) j = max(0LL, j-l);
      else {
        auto wall = *lower_bound(ij[i].begin(), ij[i].end(), j);
        j = max(j-l, wall+1);
      }
      j = max(0LL, j);
    }
    if (c == 'R') {
      auto itr = lower_bound(ij[i].begin(), ij[i].end(), j);
      j = min({w-1, j+l, *itr-1});
    }
    if (c == 'U') {
      auto itr = lower_bound(ji[j].begin(), ji[j].end(), i);
      i = max({0LL, i-l, *itr+1});
    }
    if (c == 'D') {
      auto itr = lower_bound(ji[j].begin(), ji[j].end(), i);
      i = max({h-1, i+l, *itr-1});
    }

    cout << i+1 << " " << j+1 << '\n';
  }
  return 0;
}