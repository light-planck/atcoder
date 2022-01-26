#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  string w[] = {"Sunny", "Cloudy", "Rainy"};
  string s;
  cin >> s;
  int j = 0;
  rep(i, 3) {
    if (s == w[i]) j = i;
  }
  j = (j+1)%3;
  cout << w[j] << endl;
  return 0;
}