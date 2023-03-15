//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
            if(s.empty())
                return -1;
            return minEle;
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           //Write your code here
            if(s.empty())
                return -1;
            int el = s.top();
            s.pop();
            int x = minEle;
            if(el < minEle)
            {
                minEle = 2*minEle - el;
                return x;
            }
            else
                return el;
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           //Write your code here
            int val = x;
            if(s.empty())
            {
                minEle = val;
                s.push(val);
            }
            else
            {
                if(val<minEle)
                {
                    s.push(2*val - minEle);
                    minEle = val;
                }
                else
                {
                    s.push(val);
                }
            }
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends
