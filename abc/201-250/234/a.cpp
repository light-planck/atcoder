#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

ll f(ll t) {
  return t * t + 2 * t + 3;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  
  ll t;
  cin >> t;
  
  cout << f(f(f(t) + t) + f(f(t))) << "\n";
  return 0;
}