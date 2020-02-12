//������һϵ�й���·�ߡ�ÿһ��·�� routes[i]?�϶���һ��������������ѭ����ʻ��
//���磬��һ��·��?routes[0] = [1, 5, 7]��
//��ʾ��һ�� (�±�Ϊ0) ��������һֱ����?1->5->7->1->5->7->1->...?�ĳ�վ·����ʻ��
//
//�������Ǵ�?S?��վ��ʼ����ʼʱ���ڹ������ϣ���Ҫȥ��?T?վ�� 
//�ڼ���ɳ�����������������ٳ����Ĺ��������������� -1 ��ʾ�����ܵ����յ㳵վ��


class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if(S == T)
        {
            return 0;
        }
        int row = routes.size();//������·�ߵ�����
        //vector<vector<int> >map;//�滮·�ߣ�map[i] ����iվ���·�ߵ��±�
        unordered_map<int,vector<int>> map;
        int i = 0;
        int j = 0;
        int k = 0;
        //vector<int> col_car(1000000,0);
        //map[i][j]  i��վ�ĳ����Ե���j��վ
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
        //��¼���ʹ��ĳ�
        vector<int> visit(row,0);
        queue<int> que;
        que.push(S);
        int minpath = 0;//��̷��ʹ��ĳ�վ
        int num = 0;
        
        while(!que.empty())
        {
            int i = 0;
            num = que.size();
            for(i = 0; i < num ; i++)
            {
                int j = 0;
                //��ǰ���ڵĳ�վ���
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
