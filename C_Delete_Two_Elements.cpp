#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
typedef long long ll;
#define NN 3000
#define mod 1e9 + 7
#include <algorithm>
#include <string>
#include <iomanip>
#define long long int

/*------------------------------Dont dare to touch above it------------------------------------------*/
void solve()
{
    //(i,j)=sumt
    int n;
    cin >> n;
    double sum = 0;
    unordered_map<double, ll> mp;
    for (int i = 0; i < n; i++)
    {
        double x;
        cin >> x;
        mp[x]++;
        sum += x;
    }
    ll ans = 0;
    /*
    sum/n=sumt/(n-2)
    sum*(n-2)/n=sumt
    */
    double sumt = (sum / n) * (n - 2);

    for (auto it : mp)
    {
        ll ai = it.first;
        if (mp[ai])
        {
            /*
            n= 20 
            20-7=13
            n-2= 20/5*3=12
            j=13-12=1


            */
            double k = sum - ai;
            double aj = k - sumt;
            if (ai == aj)
            {
                ll xt = it.second;
                ans += (xt - 1) * (xt) / 2;
            }
            else if (mp.find(aj) != mp.end())
            {
                ans += mp[aj] * it.second;
                mp[aj] = 0;
                mp[ai] = 0;
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
