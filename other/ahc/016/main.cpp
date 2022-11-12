#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
template<class T> void print_value(const T& value) { cout << value << '\n'; }
void print_vs(vector<string>& grid) { for (const auto& row : grid) print_value(row); }


bool test_flag = false;


constexpr int n = 5;
constexpr int step = 1;
constexpr int edge = n * (n-1) / 2;
constexpr int query_times = 100;
random_device seed_gen;
mt19937 engine(seed_gen());


int m;
double eps;
vector<string> g;
vector<string> s;


void generate_all_bit() {
  s = vector<string>(1<<edge);

  for (int bit = 0; bit<(1<<edge); ++bit) {
    string now = "";
    rep(i, edge) {
      if (bit>>i & 1) now += '1';
      else now += '0';  
    }
    reverse(now.begin(), now.end());
    s[bit] = now;
  }
}


void encode() {
  g = vector<string>(m);

  rep(i, m) {
    g[i] = string(i*step, '1') + string(edge-i*step, '0');
  }
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


int predict(string h) {
  int cnt = count(h.begin(), h.end(), '1');
  return min(cnt/step, m-1);

  // int idx = lower_bound(g.begin(), g.end(), h) - g.begin();
  // idx = min(idx, m-1);
  // return idx;
}


template<class T> void print(const T& value) { cout << value << endl; }
void output() {
  print(n);

  rep(i, m) print(g[i]);

  rep(i, query_times) {
    string h;
    cin >> h;

    h = decode(h);

    print(predict(h));
  }
}


void test() {
  generate_all_bit();
  print_vs(s);
}


int main() {
  test();

  // init();
  // output();

  // if (test_flag) {
  //   long long seed;
  //   cin >> seed;
  // }
  return 0;
}