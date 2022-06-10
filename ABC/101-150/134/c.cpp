#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<int> b(n);
  rep(i, n) b[i] = a[i];
  sort(a.rbegin(), a.rend());
  rep(i, n) {
    if (a[0] == b[i]) cout << a[1] << endl;
    else cout << a[0] << endl;
  }
  return 0;
}