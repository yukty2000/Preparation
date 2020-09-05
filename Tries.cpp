#include <bits/stdc++.h>
#define N 1000000009
#define M 1000000
using namespace std;
typedef long long int lli;
struct TrieNode
{
    bool endofword;
    struct TrieNode *children[26];
};
struct TrieNode *getNode()
{
    struct TrieNode* node=new TrieNode();
    node->endofword=false;
    for(int i=0;i<26;i++)
    {
        node->children[i]=NULL;
    }
}
void insertNode(struct TrieNode *root,string s)
{
    if(root==NULL)
    {
        root=getNode();
    }
    int l=s.length();
    struct TrieNode* pcrawl=root;
    for(int i=0;i<l;i++)
    {
        int index=s[i]-'a';
        struct TrieNode* temp=pcrawl->children[index];
        if(temp==NULL)
        {
            pcrawl->children[index]=getNode();
        }
        pcrawl=pcrawl->children[index];
    }
    pcrawl->endofword=true;
}
bool searchNode(struct TrieNode *root,string s)
{
    if(root==NULL)
        return false;
    int l=s.length();
    struct TrieNode* pcrawl=root;
    for(int i=0;i<l;i++)
    {
        struct TrieNode* temp=pcrawl->children[s[i]-'a'];
        if(temp==NULL)
        {
            return false;
        }
        pcrawl=pcrawl->children[s[i]-'a'];
    }
    return (pcrawl!=NULL&&pcrawl->endofword);
}
int main()
{
    string keys[]={"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);
    struct TrieNode *root=getNode();
    for(int i=0;i<n;i++)
        insertNode(root,keys[i]);
    cout<<"Inserted\n";
    searchNode(root,"any")?cout<<"Yes\n":cout<<"No\n";
    searchNode(root,"b")?cout<<"Yes\n":cout<<"No\n";
    return 0;
}
