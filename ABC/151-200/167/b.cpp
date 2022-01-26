#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  int ans = 0;
  while (a > 0 and k > 0){
    ans++;
    a--;
    k--;
  }
  while (b > 0 and k > 0){
    b--;
    k--;
  }
  while(c > 0 and k > 0){
    ans--;
    c--;
    k--;
  }
  cout << ans << endl;
}