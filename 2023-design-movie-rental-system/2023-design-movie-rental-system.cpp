class MovieRentingSystem {
public:
    unordered_map<int,set<pair<int ,int>>>not_rented;

    set<tuple<int,int,int>>rented;

    map<pair<int ,int>,int>prices;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {

        for(int i=0;i<entries.size();i++)
        {
            int shop=entries[i][0];

            int movie=entries[i][1];

            int price=entries[i][2];

            not_rented[movie].insert({price,shop});

            prices[{shop,movie}]=price;
        }
    }
    
    vector<int> search(int movie) {

        vector<int>result;

        if(not_rented[movie].size()!=0)
        {
            int count=0;

            for(auto &v:not_rented[movie])
            {
                if(count>=5) break;

                result.push_back(v.second);

                count+=1;
                 
            }
        }

          return result;
        
    }
    
    void rent(int shop, int movie) {

        int price=prices[{shop,movie}];

        rented.insert({price,shop,movie});

        not_rented[movie].erase({price,shop});
        
    }
    
    void drop(int shop, int movie) {

        int price=prices[{shop,movie}];

        not_rented[movie].insert({price,shop});

        rented.erase({price,shop,movie});
    }
    
    vector<vector<int>> report() {

        vector<vector<int>>result;

        if(!rented.empty())
        {
            int count=0;
            for(auto v:rented)
            {
                auto [price,shop,movie]=v;

                if(count>=5) break;

                result.push_back({shop,movie});

                count+=1;
            }
        }

       return result;
        
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */