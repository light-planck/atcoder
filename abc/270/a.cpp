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
  ll a, b;
  cin >> a >> b;

  map<ll, vector<ll>> mp;
  mp[0] = {0};
  mp[1] = {1};
  mp[2] = {2};
  mp[3] = {1, 2};
  mp[4] = {3};
  mp[5] = {1, 3};
  mp[6] = {2, 3};
  mp[7] = {1, 2, 3};

  vector<ll> points = {0, 1, 2, 4};
  vector<ll> av = mp[a];
  vector<ll> bv = mp[b];

  set<ll> st;
  for (auto i : av) st.emplace(i);
  for (auto i : bv) st.emplace(i);

  ll ans = 0;
  for (auto i : st) ans += points[i];
  cout << ans << '\n';
  return 0;
}