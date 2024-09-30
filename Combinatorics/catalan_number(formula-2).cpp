///using formula-2

void solve()
{
    int n;
    cin >> n;
    if (n & 1)
    {
        cout << 0 << endl;
        return;
    }
    int n_fact = 1, n_fact2 = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i <= n / 2)
            n_fact = (n_fact * i) % mod;
        n_fact2 = (n_fact2 * i) % mod;
    }

    int nn = (n_fact * n_fact) % mod;
    int nnn = (nn * (n / 2 + 1)) % mod;

    int inv = bigmod(nnn, mod - 2);
    int ans = (n_fact2 * inv) % mod;

    cout << ans << endl;
}