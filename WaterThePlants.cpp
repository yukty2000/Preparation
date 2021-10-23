/* GFG 
A gallery with plants is divided into n parts, numbered : 0,1,2,3...n-1. There are provisions for attaching water sprinklers at every partition. A sprinkler with range x at partition i can water all partitions from i-x to i+x.
Given an array gallery[ ] consisting of n integers, where gallery[i] is the range of sprinkler at partition i (power==-1 indicates no sprinkler attached), return the minimum number of sprinklers that need to be turned on to water the complete gallery.
If there is no possible way to water the full length using the given sprinklers, print -1.

Example 1:

Input:
n = 6
gallery[ ] = {-1, 2, 2, -1, 0, 0}
Output:
2
Explanation: Sprinklers at index 2 and 5
can water thefull gallery, span of
sprinkler at index 2 = [0,4] and span
â€‹of sprinkler at index 5 = [5,5].
Example 2:

Input:
n = 9
gallery[ ] = {2, 3, 4, -1, 2, 0, 0, -1, 0}
Output:
-1
Explanation: No sprinkler can throw water
at index 7. Hence all plants cannot be
watered.
Example 3:

Input:
n = 9
gallery[ ] = {2, 3, 4, -1, 0, 0, 0, 0, 0}
Output:
3
Explanation: Sprinkler at indexes 2, 7 and
8 together can water all plants.
Your task:
Your task is to complete the function min_sprinklers() which takes the array gallery[ ] and the integer n as input parameters and returns the value to be printed.

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ n ≤ 10^5
gallery[i] ≤ 50

*/
typedef pair<int,int> pii;
bool comparator(const pii &a,const pii &b)
{
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}
int min_sprinklers(int gallery[], int n)
{
    // code here
    if(n==0)
        return 0;
    vector<pii> v;
    for(int i=0;i<n;i++)
    {
        if(gallery[i]==-1)
        {
            continue;
        }
        v.push_back(pii(max(0,i-gallery[i]),min(i+gallery[i],n-1)));
    }
    sort(v.begin(),v.end(),comparator);
    if(v.empty())
        return -1;
    int max_reachable=v[0].second,range=v[0].first;
    if(range!=0)
        return -1;
    int ans=1;
    int i=1;
    for(;i<v.size();i++)
    {
        if(v[i].first>0)
            break;
        max_reachable=max(max_reachable,v[i].second);
    }
    range=max_reachable+1;
    for(;i<v.size();i++)
    {
        if(v[i].first<=range)
        {
            if(v[i].second>max_reachable)
            {
                if(range==max_reachable+1)  // first time
                    ans++;
                max_reachable=v[i].second;
            }
        }
        else if(v[i].first>max_reachable+1)
            return -1;
        else
        {
            range=max_reachable+1;
            if(v[i].second>max_reachable)
            {
                ans++;
                max_reachable=v[i].second;
            }
        }
        if(max_reachable==n-1)
            break;
        //cout<<max_reachable<<" "<<range<<endl;
    }
    if(max_reachable!=n-1)
        return -1;
    return ans;
}
