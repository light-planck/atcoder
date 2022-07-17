#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


/*
点pi(xi, yi)と点pj(xj, yj)が衝突するのは以下の2つの条件を満たすときである。
1. yi = yj

2. 
s[i] = R, s[j] = L (xi < xj)
s[i] = L, s[j] = R (xi > xj)

点1~nを見ていく。
点kのとき、yk = yiとなるようなi(i < k)が存在しており、
xi < xkであり、s[i] = R, s[k] = L
または
xi > xkであり、s[i] = L, s[k] = R


s[i] = Rを満たす最小のmin_x
s[i] = Lを満たす最大のmax_xが存在し、
min_x < max_xならばok
*/


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  vector<ll> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];

  string s;
  cin >> s;

  const int INF = 1e9;

  // <y, <min_x, max_x>>
  map<ll, pair<ll, ll>> mp;
  rep(i, n) {

    // すでにyが存在しているとき
    if (mp.count(y[i])) {
      if (s[i] == 'R') {
        chmin(mp[y[i]].first, x[i]);
      }
      else {
        chmax(mp[y[i]].second, x[i]);
      }
    }

    // yを初めてみるとき
    else {

      // 初期化
      mp[y[i]].first = INF;
      mp[y[i]].second = -1;

      if (s[i] == 'R') {
        mp[y[i]].first = x[i];
      }
      else {
        mp[y[i]].second = x[i];
      }
    }
  }

  bool collision = false;
  for (auto m : mp) {
    ll min_x = m.second.first;
    ll max_x = m.second.second;

    if (min_x == INF || max_x == -1) continue;

    if (min_x < max_x) {
      collision = true;
    }
  }

  if (collision) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}