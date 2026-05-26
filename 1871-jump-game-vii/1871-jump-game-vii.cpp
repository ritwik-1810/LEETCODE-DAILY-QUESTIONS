class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

         int n = s.size();

        queue<int> q;

        q.push(0);

        int farthest = 0;

        while(!q.empty())
        {
            int idx = q.front();
            q.pop();

            int start = max(idx + minJump, farthest + 1);
            int end = min(idx + maxJump, n - 1);

            for(int i = start; i <= end; i++)
            {
                if(s[i] == '0')
                {
                    if(i == n - 1)
                        return true;

                    q.push(i);
                }
            }

            farthest = end;
        }

        return n == 1;
        
    }
};