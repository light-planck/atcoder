#include <deque>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  string S;
  cin >> S;

  vector<int> C(N);
  for (auto& c : C) {
    cin >> c;
    --c;
  }

  map<int, deque<char>> deqs;
  for (int i = 0; i < N; ++i) {
    deqs[C[i]].emplace_back(S[i]);
  }

  for (auto& [_, deq] : deqs) {
    char c = deq.back();
    deq.pop_back();
    deq.emplace_front(c);
  }

  for (int i = 0; i < N; ++i) {
    cout << deqs[C[i]].front();
    deqs[C[i]].pop_front();
  }
  cout << '\n';
}
