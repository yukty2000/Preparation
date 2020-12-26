/*  GFG Problem-
    A frog jumps either 1, 2, or 3 steps to go to the top. In how many ways can it reach the top. As the answer will be large find the answer modulo 1000000007.
    Input:
    N = 1
    Output: 1
    
    Input:
    N = 4
    Output: 7
    
    */
lli countWays(int n){
    lli x,y,z;
    x=y=z=0;
    if(n==1)
        return 1;
    else
        x=1;
    if(n==2)
        return 2;
    else
        y=2;
    if(n==3)
        return 4;
    else
        z=4;
    for(int i=4;i<=n;i++)
    {
        lli temp=((z%N)+(y%N)+(x%N))%N;
        x=y;
        y=z;
        z=temp;
    }
    return z;
}
