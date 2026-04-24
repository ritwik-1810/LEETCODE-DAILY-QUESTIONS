class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {

        int size = moves.size();

       

        string strLeft=moves;

        string strRight=moves;

        for(int i=0;i<size;i++)
        {
           if(moves[i]=='_')
           {
              strLeft[i]='L';

              strRight[i]='R';
           }
           
        }

        int count1=0;

        for(int i=0;i<size;i++)
        {
            if(strLeft[i]=='L')
            {
                count1-=1;
            }
            else
            {
                count1+=1;
            }

        }

        
        int count=0;

        for(int i=0;i<size;i++)
        {
            if(strRight[i]=='L')
            {
                count-=1;
            }
            else
            {
                count+=1;
            }

        }

       
       return max(abs(count),abs(count1));

    }
};