#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  int dot = 0;
  vector<int> a(n);
  vector<int> b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  rep(i, n){
    dot += a[i] * b[i];
  }
  
  if (dot == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
}