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

  vector<ll> even;
  vector<ll> odd;
  rep(i, n) {
    ll a;
    cin >> a;
    if (a & 1) odd.emplace_back(a);
    else even.emplace_back(a);
  }
  sort(even.begin(), even.end());
  sort(odd.begin(), odd.end());

  ll ans = -1;
  if (even.size() >= 2) {
    ll last = even.size() - 1;
    auto chmax = [](auto& a, auto b) { if (a < b) a = b; };
    chmax(ans, even[last]+even[last-1]);
  }
  if (odd.size() >= 2) {
    ll last = odd.size() - 1;
    auto chmax = [](auto& a, auto b) { if (a < b) a = b; };
    chmax(ans, odd[last]+odd[last-1]);
  }

  cout << ans << '\n';
  return 0;
}