#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
template<class T> void print(const T& value) { cout << value << endl; }
void print_vs(vector<string>& grid) { for (const auto& row : grid) print(row); }


bool test_flag = false;


constexpr int n = 15;
constexpr int edge = n * (n-1) / 2;
constexpr int query_times = 100;
random_device seed_gen;
mt19937 engine(seed_gen());


int m;
double eps;
vector<string> g;
vector<string> s;
int len_s;


// void generate_all_bit() {
//   len_s = 1 << edge;
//   s = vector<string>(len_s);

//   for (int bit = 0; bit<len_s; ++bit) {
//     string now = "";
//     rep(i, edge) {
//       if (bit>>i & 1) now += '1';
//       else now += '0';  
//     }
//     reverse(now.begin(), now.end());

//     s[bit] = now;
//   }
// }


int rand_int(int l, int r) {
  assert(l <= r);

  uniform_int_distribution<> dist(l, r);
  return dist(engine);
}


int rand_choice(int r) {
  return rand_int(0, r-1);
}


// void encode1() {
//   generate_all_bit();

//   g.emplace_back(s[0]);
//   g.emplace_back(s.back());

//   set<int> used = {0, len_s-1};

//   while ((int)g.size() < m) {
//     int idx = rand_choice(len_s);
//     if (used.count(idx)) continue;

//     assert(idx < len_s);

//     g.emplace_back(s[idx]);
//     used.emplace(idx);
//   }

//   sort(g.begin(), g.end());
// }


void encode() {
  g = vector<string>(m);

  rep(i, m) {
    g[i] = string(i, '1') + string((n*(n-1)/2)-i, '0');
  }
}


void init() {
  cin >> m >> eps;
  
  encode();
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


int hamming_dist(string s, string t) {
  int diff = 0;
  int len = s.size();
  // assert((int)t.size() == len);

  rep(i, len) {
    if (s[i] != t[i]) ++diff;
  }

  return diff;
}


int min_hd(string h) {
  // ハミング距離が最小になるようなidxを求める
  int min_dist = 1e9;
  int idx = 0;
  rep(i, m) {
    int dist = hamming_dist(h, g[i]);
    if (dist < min_dist) {
      min_dist = dist;
      idx = i;
    }
  }
  return idx;
}


int predict(string h) {
  return min_hd(h);
}


void output() {
  print(n);

  rep(i, m) print(g[i]);

  rep(i, query_times) {
    string h;
    cin >> h;

    // h = decode(h);
    print(predict(h));
  }
}


void test() {
  // generate_all_bit();
  // encode();

  // print(s[0].size());
  // print(g.back().size());
}


int main() {
  // test();

  init();
  output();

  if (test_flag) {
    long long seed;
    cin >> seed;
  }
  return 0;
}