class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {

        int size = patterns.size();

        int count=0;

        for(int i=0;i<size;i++)
        {
            if(word.find(patterns[i])!=string::npos)
            {
                count+=1;
            }
        }

        return count;
        
    }
};