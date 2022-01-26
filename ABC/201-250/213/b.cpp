#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> x;

  rep(i, n){
    int a;
    cin >> a;
    x.push_back({a, i + 1});
  }

  sort(x.rbegin(), x.rend());
  cout << x[1].second << endl;
}