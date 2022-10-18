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
  ll n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  map<char, ll> cnt;
  for (auto c : s) ++cnt[c];

  ll change = k - cnt['1'];

  if (abs(change) % 2 != 0) cout << "No" << '\n';
  else cout << "Yes" << '\n';
  return 0;
}