#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int n;
  cin >> n;
  int n2 = 1 << n;

  vector<int> a(n2);
  rep(i, n2) cin >> a[i];

  map<int, int> mp;
  rep(i, n2) mp[a[i]] = i + 1;

  while (a.size() > 2) {
    vector<int> na;
    for (int i = 0; i < a.size(); i += 2) {
      na.push_back(max(a[i], a[i + 1]));
    }
    a = na;
  }
  
  int ans = min(a[0], a[1]);
  cout << mp[ans] << endl;
  return 0;
}