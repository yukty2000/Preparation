/* GFG  - My implementation
Given a string S. The task is to print all permutations of a given string.

 

Example 1:

Input: ABC
Output:
ABC ACB BAC BCA CAB CBA
Explanation:
Given string ABC has permutations in 6 
forms as ABC, ACB, BAC, BCA, CAB and CBA .
Example 2:

Input: ABSG
Output:
ABGS ABSG AGBS AGSB ASBG ASGB BAGS 
BASG BGAS BGSA BSAG BSGA GABS GASB 
GBAS GBSA GSAB GSBA SABG SAGB SBAG 
SBGA SGAB SGBA
Explanation:
Given string ABSG has 24 permutations.
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function find_permutaion() which takes the string S as input parameter and returns a vector of string in lexicographical order.

 

Expected Time Complexity: O(n! * n)

Expected Space Complexity: O(n)

 

Constraints:
1 <= length of string <= 5

*/
class Solution
{
	public:
	    void generate_permutations(int i,string s,int l,vector<string> &ans)
	    {
	        if(i==l-1)
	        {
	            ans.push_back(s);
	            return;
	        }
	        // without swapping
	        generate_permutations(i+1,s,l,ans);
	        // swap with each
	        for(int j=i+1;j<l;j++)
	        {
	            swap(s[i],s[j]);
	            generate_permutations(i+1,s,l,ans);
	            swap(s[i],s[j]);
	        }
	        return;
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here 
		    vector<string> ans;
		    int l=S.length();
		    generate_permutations(0,S,l,ans);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};
