#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  bool zoro = false;
  vector<int> d(n);
  vector<int> e(n);
  rep(i, n) cin >> d[i] >> e[i];
  
  for (int i = 0; i <= n - 3; i++){
    if (d[i] == e[i] && d[i+1] == e[i+1] && d[i+2] == e[i+2]) zoro = true;
  }

  puts(zoro ? "Yes" : "No");
}