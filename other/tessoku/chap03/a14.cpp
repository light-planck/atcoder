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

  set<ll> st = set(a.begin(), a.end());
  vector<ll> b = vector(st.begin(), st.end());

  rep(i, n) {
    ll idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    cout << idx+1 << '\n';
  }
  return 0;
}