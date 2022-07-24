class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> vec(26, 0);
        for(int i=0; i<tasks.size();i++)
        {
            vec[tasks[i]-'A']++;
        }
        sort(vec.begin(), vec.end(), greater<int>());
        int coolDown = (vec[0]-1)*n;
        for(int i=1; i<26; i++)
        {
            coolDown -= min(vec[i], vec[0]-1);
        }
        if(coolDown < 0)
            return tasks.size();
        return coolDown + tasks.size();
    }
};