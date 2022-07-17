#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n, k, q;
  cin >> n >> k >> q;

  // <num, win>
  map<int, int> mp;
  rep(i, n) mp[i] = 0;
  rep(i, q) {
    int a;
    cin >> a;
    a--;
    mp[a]++;
  }

  rep(i, n) {
    if (mp[i] > q - k) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}