#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;

  vector<int> d(n);
  rep(i, n) cin >> d.at(i);
  sort(d.rbegin(), d.rend());

  int ans = 0;

  for (int i = 0; i < n; i++){
    if(i > 0 && d.at(i) == d.at(i-1)) continue;
    ans++;
  }

  cout << ans << endl;
}