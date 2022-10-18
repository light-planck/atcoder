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
  path.emplace_back(1);

  rep(i, n) cin >> x[i] >> y[i];
}


ldouble calc_dist(ll i, ll j) {
  return hypot(x[i]-x[j], y[i]-y[j]);
}


void greedy() {
  ll now_city = 0;

  while ((ll)path.size() < n) {
    seen[now_city] = true;

    ll next_city = 0;
    ldouble dist = 1e18;

    rep(i, n) {
      if (i == now_city) continue;
      if (seen[i]) continue;

      ldouble d = calc_dist(now_city, i);
      if (d < dist) {
        next_city = i;
        dist = d;
      }
    }

    path.emplace_back(next_city + 1);
    now_city = next_city;
  }

  path.emplace_back(1);
}


void output() {
  for (auto v : path) cout << v << '\n';
}


int main() {
  input();
  greedy();
  output();
  return 0;
}