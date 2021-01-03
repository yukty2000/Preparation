/*
GFG
You are given a set of N types of rectangular 3-D boxes, where the ith box has height h, width w and length l. 
Your task is to create a stack of boxes which is as tall as possible, but you can only stack a box on top of another box
if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base of the higher box. 
Of course, you can rotate a box so that any side functions as its base.It is also allowable to use multiple instances of the same type of box. 
Your task is to complete the function maxHeight which returns the height of the highest possible stack so formed.

Input:
n = 4
height[] = {4,1,4,10}
width[] = {6,2,5,12}
length[] = {7,3,6,32}
Output: 60

Input:
n = 3
height[] = {1,4,3}
width[] = {2,5,4}
length[] = {3,6,1}
Output: 15

Constraints:
1<=N<=100
1<=l,w,h<=100

This is an extension of the Longest Increasing Subsequence problem.

*/

/*The function takes an array of heights, width and 
length as its 3 arguments where each index i value 
determines the height, width, length of the ith box. 
Here n is the total no of boxes.*/
int comparator(const vector<int> &a,const vector<int> &b)
{
    return (a[0]*a[1])>(b[0]*b[1]);
}
int maxHeight(int height[],int width[],int length[],int n)
{
    vector<vector<int>> ans;
    for(int i=0;i<n;i++)
    {
        if(length[i]>=width[i])
            ans.push_back({length[i],width[i],height[i]});
        if(length[i]>=height[i])
            ans.push_back({length[i],height[i],width[i]});
        if(width[i]>=height[i])
            ans.push_back({width[i],height[i],length[i]});
        if(height[i]>length[i])
            ans.push_back({height[i],length[i],width[i]});
        if(height[i]>width[i])
            ans.push_back({height[i],width[i],length[i]});
        if(width[i]>length[i])
            ans.push_back({width[i],length[i],height[i]});
    }
    sort(ans.begin(),ans.end(),comparator);
    int m=ans.size();
    int *maxheight=(int *)malloc(m*sizeof(int));
    for(int i=0;i<m;i++)
        maxheight[i]=ans[i][2];
    for(int i=1;i<m;i++)
    {
        for(int j=0;j<=i-1;j++)
        {
            if(ans[i][0]<ans[j][0]&&ans[i][1]<ans[j][1])
                maxheight[i]=max(maxheight[i],maxheight[j]+ans[i][2]);
        }
    }
    int val=*max_element(maxheight,maxheight+m);
    free(maxheight);
    return val;
}
