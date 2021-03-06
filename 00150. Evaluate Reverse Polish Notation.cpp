
//Accepted	20 ms	cpp
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        stack<int> st;
        int len = tokens.size();
        for(int i=0;i<len;i++)
        {
            string tmp = tokens[i];
            if(tmp == "+" || tmp == "-" || tmp == "*" || tmp == "/")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if(tmp == "+")
                    st.push(a+b);
                else if(tmp == "-")
                    st.push(b-a);
                else if(tmp == "*")
                    st.push(a*b);
                else
                    st.push(b/a);
            }
            else
            {
                int len = tmp.length();
                int num = 0;
                if(tmp[0] == '-')
                {
                    for(int j=1;j<len;j++)
                        num = num*10 + tmp[j]-'0';
                    st.push(num*-1);
                }
                else
                {
                    for(int j=0;j<len;j++)
                        num = num*10 + tmp[j]-'0';
                    st.push(num);
                }
            }
        }
        return st.top();

    }
};
