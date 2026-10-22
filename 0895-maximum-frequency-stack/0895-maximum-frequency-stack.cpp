class FreqStack {
public:
    int maxFreq=0;
    unordered_map<int,int>freq;
    unordered_map<int,stack<int>>freqSt;
    FreqStack() {
        
    }
    void push(int val) {
        
        freq[val]++;

        if(freq[val]>maxFreq)
        {
            maxFreq=freq[val];
        }

        freqSt[freq[val]].push(val);
    }
    int pop() {

        int ans=freqSt[maxFreq].top();

        freqSt[maxFreq].pop();

        freq[ans]--;

        if(freqSt[maxFreq].size()==0)
        {
            freqSt.erase(maxFreq);
            maxFreq-=1;
        }

        return ans;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */