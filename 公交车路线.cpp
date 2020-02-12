//我们有一系列公交路线。每一条路线 routes[i]?上都有一辆公交车在上面循环行驶。
//例如，有一条路线?routes[0] = [1, 5, 7]，
//表示第一辆 (下标为0) 公交车会一直按照?1->5->7->1->5->7->1->...?的车站路线行驶。
//
//假设我们从?S?车站开始（初始时不在公交车上），要去往?T?站。 
//期间仅可乘坐公交车，求出最少乘坐的公交车数量。返回 -1 表示不可能到达终点车站。


class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if(S == T)
        {
            return 0;
        }
        int row = routes.size();//公交车路线的数量
        //vector<vector<int> >map;//规划路线，map[i] 存在i站点的路线的下标
        unordered_map<int,vector<int>> map;
        int i = 0;
        int j = 0;
        int k = 0;
        //vector<int> col_car(1000000,0);
        //map[i][j]  i车站的车可以到达j车站
        for(i = 0; i < row; i++)
        {
            for (const auto &station : routes[i]){
                map[station].push_back(i);
            }
            // for(j = 0; j < routes[i].size(); j++)
            // {
            //     map[routes[i][j]].push_back(i);
            //     //col_car[routes[i][j]]++;
            // }
        }
        //return 0;
        //记录访问过的车
        vector<int> visit(row,0);
        queue<int> que;
        que.push(S);
        int minpath = 0;//最短访问过的车站
        int num = 0;
        
        while(!que.empty())
        {
            int i = 0;
            num = que.size();
            for(i = 0; i < num ; i++)
            {
                int j = 0;
                //当前所在的车站编号
                int count = que.front();
                que.pop();
                for(j = 0; j < map[count].size(); j++)
                {
                    int n = map[count][j];
                    if(!visit[n])
                    {
                        visit[n] = 1;
                        for(k = 0; k < routes[n].size(); k++)
                        {
                            int step = routes[n][k];
                            if(step == T)
                            {
                                return minpath + 1;
                            }
                            que.push(step);
                        }
                    }    
                }
            }
            // if(num ==5)
            // {
            //     return que.empty();
            // }
            minpath++;
        }

        return -1;
    }
};
