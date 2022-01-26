#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> l(n);
  rep(i, n) cin >> l[i];
  int cnt = 0;

  for (int i = 0; i < n - 2; i++){
    for (int j = i + 1; j < n -1; j++){
      for (int k = j + 1; k < n; k++){
        if (l[i] == l[j] or l[i] == l[k] or l[j] == l[k])
        continue;
        int mx = max({l[i], l[j], l[k]});
        if (mx < l[i] + l[j] + l[k] - mx) cnt++;
      }
    }
  }

  cout << cnt << endl;
}