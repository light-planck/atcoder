#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n;
  cin >> n;
  map<string, int> mp;
  rep(i, n) {
    string s;
    cin >> s;
    mp[s]++;
  }

  int mx = -1;
  for (auto x : mp) {
    if (mx < x.second) mx = x.second;
  }

  for (auto x : mp) {
    if (x.second == mx) {
      cout << x.first << endl;
      return 0;
    }
  }
  return 0;
}