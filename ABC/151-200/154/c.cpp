#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n;
  cin >> n;
  map<int, int> mp;
  rep(i, n) {
    int a;
    cin >> a;
    mp[a]++;
  }
  bool isdif = true;
  for (auto x : mp) {
    if (x.second >= 2) isdif = false;
  }
  if (isdif) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}