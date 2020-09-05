#include <bits/stdc++.h>
#define N 1000000009
#define M 1000000
using namespace std;
typedef long long int lli;
int *KMPpreprocess(string P)
{
    int l=P.length();
    int *F=(int *)malloc((l+1)*sizeof(int));
    F[0]=-1;
    int i=0,j=-1;
    while(i<l)
    {
        while(j>=0&&P[i]!=P[j])
            j=F[j];
        i++;j++;
        F[i]=j;
    }
    return F;
}
void KMP(string P,string T)
{
    int *F=KMPpreprocess(P);
    int l1=P.length();
    int l2=T.length();
    /*for(int i=0;i<=l1;i++)
        cout<<F[i]<<" ";
    cout<<endl;*/
    int i=0,j=-1;
    while(i<l2)
    {
        while(j>=0&&T[i]!=P[j])
            j=F[j];
        i++;j++;
        //cout<<j<<endl;
        if(j==l1)
        {
            printf("Pattern Found at %d index\n",i-j);
            j=F[j];
        }
    }
    free(F);
}
int main()
{
    string T,P;
    cout<<"Enter Text"<<endl;
    cin>>T;
    cout<<"Enter Pattern"<<endl;
    cin>>P;
    KMP(P,T);
}
