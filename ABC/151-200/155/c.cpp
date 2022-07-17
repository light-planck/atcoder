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
  int max = -1;
  for (auto x : mp) {
    if (x.second > max) max = x.second;
  }
  for (auto x : mp) {
    if (x.second == max) cout << x.first << endl;
  }
  return 0;
}