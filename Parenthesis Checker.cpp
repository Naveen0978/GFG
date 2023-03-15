//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack <int> st;
        
        for(int i=0; i<x.length();i++)
        {
            if(x[i] == '[' or x[i] == '(' or x[i] == '{')
                st.push(x[i]);
            else
            {
                if(st.empty())
                    return false;
                char ch = st.top();
                st.pop();
                if(  (x[i] == ']' and ch == '[') or
                    (x[i] == ')' and ch == '(') or
                    (x[i] == '}' and ch == '{'));
                else
                    return false;
            }
        }
        if(st.empty())
            return true;
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
