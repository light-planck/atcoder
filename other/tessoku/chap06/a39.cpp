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

  using P = pair<ll, ll>;
  vector<P> stop_start;
  rep(i, n) {
    ll start, stop;
    cin >> start >> stop;
    stop_start.emplace_back(stop, start);
  }
  sort(stop_start.begin(), stop_start.end());

  ll now = 0;
  ll ans = 0;
  for (auto [stop, start] : stop_start) {
    if (now > start) continue;

    now = stop;
    ++ans;
  }

  cout << ans << '\n';
  return 0;
}