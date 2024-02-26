//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            String s = br.readLine().trim();
            Solution ob = new Solution();
            List<String> ans = ob.AllPossibleStrings(s);
            for(String i: ans)
                System.out.print(i + " ");
            System.out.println();
            
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution
{
    List<String> al;
    public List<String> AllPossibleStrings(String s)
    {
        // Code here
        al = new ArrayList<>();
        subsets(s, "", 0);
         Collections.sort(al);
         return al;
    }
    void subsets(String s, String curr, int idx)
    {
        if(idx==s.length() && curr.length()>0){
            al.add(curr);
            return;
        }
          if (idx < s.length()) {
        subsets(s, curr, idx+1);
        subsets(s, curr+s.charAt(idx), idx + 1);
        }
    }
}