// Link: https://www.geeksforgeeks.org/problems/sort-a-stack/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);

cout << "~" << "\n";
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void sol(stack<int> &st){
    if(st.empty()) return;
    
    int top = st.top();
    st.pop();
    sol(st);
    
    if(st.empty() || st.top() <= top){
        st.push(top);
    }
    else{
        stack<int> temp;
        while(!st.empty() && st.top() > top){
            temp.push(st.top());
            st.pop();
        }
        
        st.push(top);
        
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }
}

void SortedStack :: sort(){
    sol(this->s);  
}