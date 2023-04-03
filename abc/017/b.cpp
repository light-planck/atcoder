#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  string s;
  cin >> s;

  reverse(s.begin(), s.end());
  ll n = s.size();

  rep(i, n) {
    char c = s[i];
    if (c == 'o' or c == 'k' or c == 'u') continue;
    if (i+1<n and s[i]=='h' and s[i+1]=='c') continue;
    if (i-1>=0 and s[i]=='c' and s[i-1]=='h') continue;
    
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;
  return 0;
}