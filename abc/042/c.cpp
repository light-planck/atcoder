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

  set<char> st;
  rep(i, k) {
    ll d;
    cin >> d;
    st.emplace(d+'0');
  }

  for (ll i = n; i <= 10*n; ++i) {
    string s = to_string(i);
    bool ok = true;
    for (auto c : s) if (st.count(c)) ok = false;
    if (ok) {
      cout << i << '\n';
      return 0;
    }
  }
  return 0;
}