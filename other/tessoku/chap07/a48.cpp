// p.260 焼きなまし法
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
using ldouble = long double;


ll n;
vector<ll> x, y;
vector<bool> seen;
vector<ll> path;


void input() {
  cin >> n;

  x = vector<ll>(n);
  y = vector<ll>(n);
  seen = vector<bool>(n);

  rep(i, n) cin >> x[i] >> y[i];
}


ldouble calc_dist(ll i, ll j) {
  return hypot(x[i]-x[j], y[i]-y[j]);
}


ldouble calc_score() {
  ldouble score = 0;
  rep(i, n) score += calc_dist(path[i], path[i+1]);

  return score;
}


ll rand_int(ll a, ll b) {
  return a + rand()%(b-a+1);
}


ldouble rand_double() {
  return 1.0 * rand() / RAND_MAX;
}


void greedy() {
  path.emplace_back(0);

  while ((ll)path.size() < n) {
    ll now_city = path.back();
    seen[now_city] = true;

    ll next_city = 0;
    ldouble dist = 1e9;

    rep(i, n) {
      if (i == now_city) continue;
      if (seen[i]) continue;

      ldouble d = calc_dist(now_city, i);
      if (d < dist) {
        next_city = i;
        dist = d;
      }
    }

    path.emplace_back(next_city);
  }

  path.emplace_back(0);
}


void burning() {
  // ll time_limit = 0.98 * CLOCKS_PER_SEC;
  ldouble score = calc_score();

  ll limit = 460000;
  // ll ti = clock();
  for (ll t = 1; t <= limit; ++t) {
    // if (clock()-ti >= time_limit) break;

    ll l = rand_int(1, n-1); ll r = rand_int(1, n-1);
    if (l > r) swap(l, r);

    reverse(path.begin()+l, path.begin()+r+1);
    ldouble new_score = calc_score();

    ldouble T = 30.0 - 28.0*t/limit;
    ldouble prob = exp(min((ldouble)0, score-new_score)/T);

    if (rand_double() < prob) score = new_score;
    else reverse(path.begin()+l, path.begin()+r+1);
  }
}


void output() {
  for (auto v : path) cout << v+1 << '\n';
}


int main() {
  input();

  greedy();
  burning();

  output();
  return 0;
}