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
#include <random>
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


ll n, k;

ll a[11];
ll b[11];

ll x[6000];
ll y[6000];


ll px[101];
ll py[101];
ll qx[101];
ll qy[101];


void input() {
  cin >> n >> k;
  rep(i, 10) cin >> a[i + 1];
  rep(i, n) cin >> x[i + 1] >> y[i + 1];
}


void random_calc() {
  std::random_device seed_gen;
  std::default_random_engine engine(seed_gen());

  // 0以上9以下の値を等確率で発生させる
  constexpr int mx = 1000;
  std::uniform_int_distribution<> dist(-mx, mx);

  for (ll i = 1; i <= 90; ++i) {
    px[i] = dist(engine);
    py[i] = dist(engine);
    qx[i] = dist(engine);
    qy[i] = dist(engine);
  }
}


void output() {
  for (ll i = 1; i <= 90; ++i) {
    cout << px[i] << " " << py[i] << " " << qx[i] << " " << qy[i] << "\n";
  }
}


double compute_score() {
  double child = 0;
  for (ll d = 1; d <= 10; ++d) child += min(a[d], b[d]);
  double mother = 0;
  for (ll d = 1; d <= 10; ++d) mother += a[d];
  double score = 1e6 * child / mother;
  return score;
}


int main() {
  input();
  random_calc();
  output();
  return 0;
}