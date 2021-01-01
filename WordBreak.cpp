/*
GeeksForGeeks
Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words. 

Input:
n = 12
B = { "i", "like", "sam", "sung", "samsung", "mobile",
"ice","cream", "icecream", "man", "go", "mango" }
A = "ilike"
Output: 1

*/

struct TrieNode
{
    TrieNode *key[26];
    bool endOfWord;
    TrieNode()
    {
        for(int i=0;i<26;i++)
            key[i]=NULL;
        endOfWord=false;
    }
};
void insertnumber(TrieNode *root,string word)
{
    TrieNode *temp=root;
    int l=word.length();
    for(int i=0;i<l;i++)
    {
        if(temp->key[word[i]-97]==NULL)
        {
            TrieNode *temp1=new TrieNode();
            temp->key[word[i]-97]=temp1;
            temp=temp1;
        }
        else
        {
            temp=temp->key[word[i]-97];
        }
        if(i==l-1)
            temp->endOfWord=true;
    }
}

int searchnumber(TrieNode *root,string A,vector<int> vis,int i,int j)
{
    if(vis[i]!=-1)
        return vis[i];
    int ans=0;
    TrieNode *temp=root;
    for(int k=i;k<=j;k++)
    {
        if(temp->key[A[k]-97]==NULL)
            break;
        temp=temp->key[A[k]-97];
        if(temp->endOfWord)
        {
            ans|= searchnumber(root,A,vis,k+1,j);
            if(ans==1)
                break;
        }
    }
    vis[i]=ans;
    return vis[i];
}

int wordBreak(string A, vector<string> &B) {
    TrieNode *root=new TrieNode();
        for(auto it=B.begin();it!=B.end();it++)
        {
            insertnumber(root,*it);
        }
        int n=A.length();
        vector<int> vis(n+1,-1);
        vis[n]=1;
        return searchnumber(root,A,vis,0,n-1);
}
