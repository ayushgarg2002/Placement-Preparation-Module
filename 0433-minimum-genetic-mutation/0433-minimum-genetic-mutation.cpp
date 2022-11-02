class Solution {
public:
   int minMutation(string start, string end, vector<string>& bank) {
        if (start == end) return 0;
        else if (bank.size() == 0) return -1;
        
        // Initialize a bank set for fast query
        unordered_set<string> bank_set(bank.begin(), bank.end());
        if (bank_set.count(end) == 0) return -1;
        
        // Prevent infinite loop 
        unordered_set<string> visited;
        visited.insert(start);
        
        queue<string> q;
        q.push(start);
        
        const vector<char> mut_options = {'A', 'C', 'G', 'T'};
        
        int mut_count = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                string front = q.front();
                q.pop();
                
                // Generate all mutations from current gene
                for (int i = 0; i < front.length(); ++i) {
                    char original_c = front[i]; // Record original char
                    for (const char c: mut_options) { // Try to mutate current position
                        if (c != original_c) {
                            front[i] = c;
                            if (front == end) return mut_count;
                            if (!visited.count(front) > 0 && bank_set.count(front) > 0) {
                                q.push(front);
                                visited.insert(front);
                            }
                        }
                    }
                    front[i] = original_c;
                }
            }
            ++mut_count;
        }
        
        return -1;
    }
};