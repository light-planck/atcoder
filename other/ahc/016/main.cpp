#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;


bool test = true;


constexpr int n = 15;
constexpr int step = 1;
constexpr int edge = n * (n-1) / 2;
constexpr int query_times = 100;
random_device seed_gen;
mt19937 engine(seed_gen());


int m;
double eps;
vector<string> g;


void encode() {
  g = vector<string>(m);

  rep(i, m) {
    g[i] = string(i*step, '1') + string(edge-i*step, '0');
  }

  sort(g.begin(), g.end());
}


void init() {
  cin >> m >> eps;
  encode();
}


int rand_int(int l, int r) {
  uniform_int_distribution<> dist(l, r);
  return dist(engine);
}


string decode(string h) {
  for (auto& c : h) {
    bool change = 100*eps > rand_int(0, 999);
    if (change) {
      if (c == '0') c = '1';
      else c = '0';
    }
  }
  return h;
}


template<class T> void print(const T& value) { cout << value << endl; }
void output() {
  print(n);

  rep(i, m) print(g[i]);

  rep(i, query_times) {
    string h;
    cin >> h;

    h = decode(h);

    int idx = lower_bound(g.begin(), g.end(), h) - g.begin();
    idx = min(idx, m-1);
    print(idx);
  }
}


int main() {
  init();
  output();

  if (test) {
    long long seed;
    cin >> seed;
  }
  return 0;
}