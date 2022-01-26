#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n;
  cin >> n;
 
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);

  vector<int> b(n);
  rep(i, n) cin >> b.at(i);

  sort(a.rbegin(), a.rend());
  sort(b.begin(), b.end());

  int d = b.at(0) - a.at(0);
  if(d >= 0) cout << d + 1 << endl;
  else cout << 0 << endl;
}