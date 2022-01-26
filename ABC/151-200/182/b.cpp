#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int gcd = 0;
  int ans = 0;
  
  for (int i = 2; i <= 1000; i++){
    int cnt = 0;
    for (int j = 0; j < n; j++){
      if (a[j] % i == 0) cnt++;
    }
    if (cnt > gcd){
      gcd = cnt;
      ans = i;
    }
  }
  
  cout << ans << endl;
}