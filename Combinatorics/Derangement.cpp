#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9, mod = 1e9 + 7;

int derangement[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  derangement[0] = 1;
  derangement[1] = 0;
  for (int i = 1; i < N; i++) {
      derangement[i] = 1LL * (i - 1) * (derangement[i - 1] + derangement[i - 2]) % mod;
  }
  int n; cin >> n;
  cout << derangement[n] << '\n';
  return 0;
}