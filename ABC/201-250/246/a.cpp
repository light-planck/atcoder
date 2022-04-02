#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;


struct Vector{
  int x, y;
};


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // vector<pair<int, int>> p(3);
  // rep(i, 3) cin >> p[i].first >> p[i].second;

  map<int, int> seen_x;
  map<int, int> seen_y;
  int x4 = 0;
  int y4 = 0;
  rep(i, 3) {
    int x, y;
    cin >> x >> y;
    ++seen_x[x];
    ++seen_y[y];
  }

  for (auto mp : seen_x) {
    if (mp.second == 1) x4 = mp.first;
  }

  for (auto mp : seen_y) {
    if (mp.second == 1) y4 = mp.first;
  }

  // for (int xi = -100; xi <= 100; xi++) {
  //   for (int yi = -100; yi <= 100; yi++) {
  //     // Vector a, b;
  //     // a.x = p[1].first - p[0].first;
  //     // a.y = p[1].second - p[0].second;

  //     // b.x = p[2].first - p[0].first;
  //     // b.y = p[2].second - p[0].second;

  //     // if ((xi - p[0].first) == (a.x + b.x) && (yi - p[0].second) == (a.y + b.y)) {
  //     //   cout << xi << " " << yi << "\n";
  //     //   return 0;
  //     // }


  //   }
  // }

  cout << x4 << " " << y4 << "\n";
  return 0;
}