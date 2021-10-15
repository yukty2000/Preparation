/* GFG
Given a fraction. Convert it into a decimal. 
If the fractional part is repeating, enclose the repeating part in parentheses.
 

Example 1:

Input: numerator = 1, denominator = 3
Output: "0.(3)"
Explanation: 1/3 = 0.3333... So here 3 is 
recurring.
Example 2:

Input: numerator = 5, denominator = 2
Output: "2.5"
Explanation: 5/2 = 2.5
 

Your Task:
You don't need to read or print anyhting. Your task is to complete the function fractionToDecimal() which takes numerator and denominator as input parameter and returns its decimal form in string format.

Note: In case, the numerator is divisible by the denominator, just print the integer value.
 

Expected Time Compelxity: O(k) where k is constant.
Expected Space Complexity: O(k)
 

Constraints:
1 ≤ numerator, denominator ≤ 2000
*/

typedef pair<string,int> psi;
	string fractionToDecimal(int num, int den) {
	    // Code here
	    int val=num/den;
	    string s="";
	    s+=to_string(val);
	    int rem=num%den;
	    if(rem==0)
	        return s;
	    s+=".";
	    string der="";
	    int l=0;
	    map<int,int> m;
	    while(rem!=0)
	    {
	        m.insert({rem,l});
	        rem*=10;
	        val=rem/den;// val is a single digit
	        der+=to_string(val);
	        l++;
	        rem=rem%den;
	        if(rem==0)
	        {
	            s+=der;
	            break;
	        }
	        auto it=m.find(rem);
	        if(it!=m.end())
	        {
	            string temp=der.substr(0,it->second);
	            s+=temp;
	            der =der.substr(it->second,l);
	            s+="("+der+")";
	            break;
	        }
	    }
	    return s;
	}
