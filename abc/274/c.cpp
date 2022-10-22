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
  ll n;
  cin >> n;

  vector<ll> a(n+1);
  rep(i, n) cin >> a[i+1];

  vector<ll> dist(2*n + 2);
  dist[1] = 0;

  for (ll i = 1; i <= n; ++i) {
    dist[2*i] = dist[a[i]] + 1;
    dist[2*i + 1] = dist[a[i]] + 1;
  }

  for (ll i = 1; i <= 2*n + 1; ++i) {
    cout << dist[i] << '\n';
  }
  return 0;
}