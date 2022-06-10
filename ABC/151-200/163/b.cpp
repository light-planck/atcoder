#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n, m;
  cin >> n >> m;
  rep(i, m){
    int a;
    cin >> a;
    n -= a;
  }
  if (n >= 0) cout << n << endl;
  else cout << -1 << endl;
  return 0;
}