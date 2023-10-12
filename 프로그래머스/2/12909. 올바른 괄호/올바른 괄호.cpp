#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack <char> st;
    int l=s.size();
    for(int i=0;i<l;i++){
        if(s[i]=='(') st.push('(');
        else{
            if(st.empty()) {st.push(')'); break;}
            else st.pop();
        }
    }
    if(st.empty()) answer=true;
    else answer=false;

    return answer;
}
