class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, 
        greater<pair<int,int>>> pq;
        vector<bool> visited(n,false);
        pq.push({0,0});

        int cost = 0;
        int count = 0;

        while(count < n){
            auto [dist,u] = pq.top();
            pq.pop();

            if(visited[u]) continue;

            visited[u] = true;
            cost += dist;
            count++;

            for(int v=0;v<n;v++){
                if(!visited[v]){
                    int d = abs(points[u][0]-points[v][0]) 
                    + abs(points[u][1]-points[v][1]);
                    pq.push({d,v});
                }
            }
        }

        return cost;
    }
};