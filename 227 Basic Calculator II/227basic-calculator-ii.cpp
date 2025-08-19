class Solution {
private: 
    int solve(int a,int b,char c){
        if(c=='+') return a+b;
        else if(c=='-') return a-b;
        else if(c=='*') return a*b;
        else if(c=='/') return a/b;
        return 0;
    }

    int prec(char c){
        if(c=='+' || c=='-') return 1;
        if(c=='*' || c=='/') return 2;
        return 0;
    }

public:
    int calculate(string s) {
        stack<int> temp;     
        stack<char> st;     
        int n=s.length();

        for(int i=0;i<n;i++){
            if(s[i]==' ') continue;

            if(isdigit(s[i])){
                string t="";
                while(i<n && isdigit(s[i])){
                    t.push_back(s[i]);
                    i++;
                }
                temp.push(stoi(t));
                i--; 
            }
            else {
                while(!st.empty() && prec(st.top())>=prec(s[i])){
                    int op2=temp.top(); temp.pop();
                    int op1=temp.top(); temp.pop();
                    char op=st.top(); st.pop();
                    temp.push(solve(op1,op2,op));
                }
                st.push(s[i]);
            }
        }

        while(!st.empty()){
            int op2=temp.top(); temp.pop();
            int op1=temp.top(); temp.pop();
            char op=st.top(); st.pop();
            temp.push(solve(op1,op2,op));
        }

        return temp.top();
    }
};
