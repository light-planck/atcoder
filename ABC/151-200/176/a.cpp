#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n, x, t;
  cin >> n >> x >> t;
  int time = 0;
  while (n > 0){
    n -= x;
    time += t;
  }
  cout << time << endl;
}