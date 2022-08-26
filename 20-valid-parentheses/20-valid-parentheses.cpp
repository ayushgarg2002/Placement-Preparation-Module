class Solution
{
public:
    bool isValid(string s)
    {
        int i, n= s.length(),j;
        stack<char>st;
        for(i=0; i<n; i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                st.push(s[i]);

            else
            {

                if(!st.empty())
                {
                    char ch = st.top();
                    if(ch=='(' && s[i]==')' || ch=='[' && s[i]==']' || ch=='{' && s[i]=='}')
                    {
                        // return true;
                        cout<<ch<<" "<<s[i]<<endl;
                        st.pop();
                    }
                    else
                    return false;
                }
                else
                    return false;
            }
        }
        if(st.empty())
            return true;
        return false;


    }
};