#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(all(a));

  vector<ll> s(n + 1);
  rep(i, n) s[i + 1] = s[i] + a[i];

  ll sum = 0;
  rep(i, n - 1) {
    sum += (s[n] - s[i + 1]) - (n - i - 1) * a[i];
  }
  cout << sum << endl;
  return 0;
}