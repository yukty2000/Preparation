#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long int lli;
void TowersofHanoi(int n,char frompeg,char auxpeg,char topeg)
{
    if(n==1)
    {
        printf("Move %d peg from %c peg to %c peg\n",n,frompeg,topeg);
        return;
    }
    TowersofHanoi(n-1,frompeg,topeg,auxpeg);
    printf("Move %d peg from %c peg to %c peg\n",n,frompeg,topeg);
    TowersofHanoi(n-1,auxpeg,frompeg,topeg);
}
int main()
{
    cout<<"Enter n\n";
    int n;
    cin>>n;
    TowersofHanoi(n,'A','B','C');
    return 0;
}
