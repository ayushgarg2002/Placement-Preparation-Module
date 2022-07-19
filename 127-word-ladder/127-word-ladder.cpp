class Solution {
public:
    /*
    using bfs to get shortest trnasformation sequence
    now for a word like "hit"(beginword) I need to convert every character from 'a' to 'z'
    example for h in hit  i can change it from a to z similary for i in hit i can change it from a to z and check if its present in our list or not, if it is then keep count of the ladder / changes it takes to reach to that word.
    Finallt if word after changing == end word then return ans
    
    to search for word every time if its present in wordlist or not in o(1) we use unordered set
    */
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        unordered_set<string>st(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        while(!q.empty())
        {
            auto temp=q.front();
            string word=temp.first;
            int ladder=temp.second;
            q.pop();
            if(word==endWord)
            {
                return ladder;
            }
            st.erase(word);
            //example "hit"
            for(int i=0;i<word.size();i++)
            {
                //keep the current character so that you can replace it to its original place after use
                char c=word[i];
                for(int j=0;j<26;j++)
                {
                    word[i]='a'+j;
                    //search the changed word in dictionary
                    if(st.find(word)!=st.end())
                    {
                        q.push({word,ladder+1});
                    }
                }
                //make the word as before to continue changing other character
                word[i]=c;
            }
        }
        return 0;
    }
};