/* Leetcode
Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.

 

Example 1:

Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].
Example 2:

Input: n = 2
Output: 15
Explanation: The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.
Example 3:

Input: n = 33
Output: 66045
 

Constraints:

1 <= n <= 50 

*/

class Solution {
public:
    int countVowelStrings(int n) {
        if(n==1)
            return 5;
        vector<int> DP(5,0);
        for(int i=0;i<5;i++)
            DP[i]=5-i;
        for(int i=2;i<=n;i++)
        {
            for(int j=3;j>=0;j--)
                DP[j]+=DP[j+1];
        }
        return DP[0];
    }
};
