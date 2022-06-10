#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n, k;
  cin >> n >> k;
  int ans = 0;
  vector<int> s(n);
  rep(i, k){
    int d;
    cin >> d;
    rep(i, d){
      int a;
      cin >> a;
      s[a-1]++;
    }
  }
  rep(i, n) if (s[i] == 0) ans++;
  cout << ans << endl;
}