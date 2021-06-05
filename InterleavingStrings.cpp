/* 
  Leetcode -
  Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

Example 1:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true
*/
class Solution {
public:
    unordered_map<string,bool> mem;
    bool checkstring(string s1,int i1,string s2,int i2,string s3,int i3,int l1,int l2,int l3)
    {
        if(i3==l3)
        {
            return (i1==l1&&i2==l2)?true:false;
        }
        string key = to_string(i1)+"*"+to_string(i2)+"*"+to_string(i3);
        if(mem.find(key)!=mem.end())
        {
            return mem[key];
        }
        if(i1==l1)
            return mem[key]=s2[i2]==s3[i3]?checkstring(s1,i1,s2,i2+1,s3,i3+1,l1,l2,l3):false;
        if(i2==l2)
            return mem[key]=s1[i1]==s3[i3]?checkstring(s1,i1+1,s2,i2,s3,i3+1,l1,l2,l3):false;
        bool one=false,two=false;
        if(s1[i1]==s3[i3])
        {
            one = checkstring(s1,i1+1,s2,i2,s3,i3+1,l1,l2,l3);
        }
        if(s2[i2]==s3[i3])
        {
            two = checkstring(s1,i1,s2,i2+1,s3,i3+1,l1,l2,l3);
        }
        return mem[key]= one or two;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int l1=s1.length();
        int l2=s2.length();
        int l3=s3.length();
        if(l1+l2!=l3)
            return false;
        return checkstring(s1,0,s2,0,s3,0,l1,l2,l3);
    }
};
  
