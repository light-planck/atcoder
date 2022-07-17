#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  int ans = inf;

  rep(i, n)rep(j, n){
    int time;
    if (i == j) time = a[i] + b[j];
    else time = max(a[i], b[j]);
    ans = min(ans, time);
  }

  cout << ans << endl;
}