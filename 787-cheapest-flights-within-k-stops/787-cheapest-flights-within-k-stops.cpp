class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       
        vector<pair<int, int> > v[n];
        
        for(int i=0;i<flights.size();i++) {
            v[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));
        }
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
		// store cheapest cost from src to a particular node for 0 to K+1 number of stops
        vector <vector<int> > cost(n, vector<int>(k+2, INT_MAX));
        
        cost[src][0] =0;
        
        pq.push(make_pair(0, make_pair(src, 0)));
        
        while(!pq.empty()) {
            
            pair<int, pair<int, int>> p = pq.top();
            pq.pop();
            
            int node = p.second.first;
            int currcost = p.first;
            int stops = p.second.second;
            
            if(node == dst)
                return currcost;
            
            if(stops>k)
                continue;
            
            for(int i=0;i<v[node].size();i++)
                if(cost[v[node][i].first][stops+1] > v[node][i].second + cost[node][stops]) {
                    cost[v[node][i].first][stops+1] = v[node][i].second + cost[node][stops];
                    pq.push(make_pair(cost[v[node][i].first][stops+1], make_pair(v[node][i].first, stops+1)));
                    //cout<<node<<" "<<v[node][i].first<<" "<<cost[v[node][i].first][stops+1]<<" "<<stops+1<<endl;
                }
            }
        return -1;
    }
};