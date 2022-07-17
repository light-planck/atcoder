#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  ll sum = 0;
  rep(i, n) {
    cin >> a[i];
    sum += a[i];
  }

  ll x;
  cin >> x;
  ll k = 0;
  k += (x / sum) * n;

  x %= sum;

  rep(i, n) {
    if (x >= 0) {
      x -= a[i];
      k++;
    }
    else break;
  }

  cout << k << endl;
  return 0;
}