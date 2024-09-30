const int MOD = 1e9+7;
const int MAX = 1e5+5;

int catalan[MAX];
void init(int n)
{
    catalan[0] = catalan[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
        {
            catalan[i] += (catalan[j] * catalan[i - j - 1]) % MOD;
            if (catalan[i] >= MOD)
            {
                catalan[i] -= MOD;
            }
        }
    }
}