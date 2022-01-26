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
    mp[a] = i + 1;
  }
  rep(i, n) {
    if (i > 0) cout << " ";
    cout << mp[i+1];
  }
  cout << endl;
  return 0;
}