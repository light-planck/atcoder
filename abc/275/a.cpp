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

  vector<ll> h(n);
  rep(i, n) cin >> h[i];

  ll max = *max_element(h.begin(), h.end());
  rep(i, n) {
    if (h[i] == max) cout << i+1 << '\n';
  }
  return 0;
}