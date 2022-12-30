#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
  char c;
  cin >> c;
  if (vowel.count(c)) cout << "vowel" << '\n';
  else cout << "consonant" << '\n';
  return 0;
}