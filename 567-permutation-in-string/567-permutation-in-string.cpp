class Solution {
public:
 
    bool checkInclusion(string s1, string s2)
{
   
   
   vector<int> fre(26, 0);

    int len = s1.length();
    for(int i=0; i<len; i++)
    {
        fre[s1[i]-'a']++;
    }
    cout<<"size is "<<s2.size()<<endl;
    int len2=s2.length();
    int j=0;
   vector<int> fre1(26, 0);

    for(int i=0; i<s2.size(); i++)
    {

        if(i>=len)
        {
            fre1[s2[j]-'a']--;
            j++;
        }

        fre1[s2[i]-'a']++;
        if(fre==fre1)
        {
           // for(auto x: fre1)
               // cout<<x<<" ";
            return true;
        }


    }

    return false;
}
};