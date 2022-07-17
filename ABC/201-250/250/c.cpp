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

  ll n, q;
  cin >> n >> q;
  
  vector<ll> a(n);
  rep(i, n) a[i] = i+1;

  // <a, idx>
  map<ll, ll> pos;
  rep(i, n) pos[a[i]] = i;

  while (q--) {
    int x;
    cin >> x;

    ll idx1 = pos[x];
    ll idx2 = idx1 + 1;
    if (idx2 >= n) idx2 = idx1 - 1;
    swap(a[idx1], a[idx2]);
    swap(pos[a[idx1]], pos[a[idx2]]);
  }

  rep(i, n) cout << a[i] << endl;
  return 0;
}