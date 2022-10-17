
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

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  for (ll i = 0; i < n; ++i) {
    for (ll j = i+1; j < n; ++j) {
      for (ll k = j+1; k < n; ++k) {
        if (a[i]+a[j]+a[k] == 1000) {
          cout << "Yes" << '\n';
          return 0;
        }
      }
    }
  }

  cout << "No" << '\n';
  return 0;
}