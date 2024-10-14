#include<bits/stdc++.h>
using namespace std;

long long s[1001][1001], mod = 1e9 + 7;

void Stirling_Number() {
    s[0][0] = 1;
    for (int i = 1; i <= 1000; i++){
        for (int j = 1; j <= i; j++)
            s[i][j] = (s[i - 1][j - 1] + s[i - 1][j] * j) % mod;
    }
}

int main(){
    Stirling_Number();
}
