#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  map<char, int> mp;
  rep(i, n) mp[s[i]]++;
  int x = min(mp['0'], mp['1']);
  cout << x * 2 << endl;
  return 0;
}