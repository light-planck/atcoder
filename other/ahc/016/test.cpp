#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

random_device seed_gen;
mt19937 engine(seed_gen());
int rand_int(int l, int r) {
  uniform_int_distribution<> dist(l, r);
  return dist(engine);
}


string decode(string h) {
  for (auto& c : h) {
    bool change = 100*0.04 > rand_int(0, 999);
    if (change) {
      if (c == '0') c = '1';
      else c = '0';
    }
  }
  return h;
}


int main() {
  string s = string(1000, '0');
  s = decode(s);
  cout << s << '\n';
  return 0;
}