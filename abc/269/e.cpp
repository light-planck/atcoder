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


void print(ll a, ll b, ll c, ll d) {
  cout << "? " << a << " " << b << " " << c << " " << d << endl;
}


int main() {
  ll n;
  cin >> n;

  ll up = 1; ll down = n + 1;
  while (abs(up-down) > 1) {
    ll mid = (up+down) / 2;

    print(up, mid-1, 1, n);
    ll t;
    cin >> t;
  
    if (t == abs(mid-up)) up = mid; else down = mid;
  }
  ll i = up;

  ll left = 1; ll right = n + 1;
  while (abs(left-right) > 1) {
    ll mid = (left+right) / 2;

    print(1, n, left, mid-1);
    ll t;
    cin >> t;
  
    if (t == abs(mid-left)) left = mid; else right = mid;
  }
  ll j = left;

  cout << "! " << i << " " << j << endl;
  return 0;
}