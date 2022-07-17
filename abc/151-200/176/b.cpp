#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  string n;
  cin >> n;
  ll sum = 0;
  rep(i, n.size()) sum += (ll)(n[i] - '0');
  if (sum % 3 == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
}