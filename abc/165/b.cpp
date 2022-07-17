#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  ll x;
  cin >> x;
  ll sum = 100;
  int cnt = 0;
  
  while (sum < x){
    cnt++;
    sum += sum / 100;
  }

  cout << cnt << endl;
}