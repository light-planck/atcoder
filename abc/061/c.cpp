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

  map<ll, ll> mp;
  rep(i, n) {
    ll a, b;
    cin >> a >> b;
    mp[a] += b;
  }

  while (true) {
    for (auto [a, b] : mp) {
      if (k - b <= 0) {
        cout << a << '\n';
        return 0;
      }
      else k -= b;
    }
  }
  return 0;
}