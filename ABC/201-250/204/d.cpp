#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  vector<ll> t(n);
  rep(i, n) cin >> t[i];

  ll sum = 0;
  rep(i, n) sum += t[i];

  cout << (sum + 2 - 1) / 2 << endl;
  return 0;
}