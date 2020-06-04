class StockSpanner {
public:
    StockSpanner() {
        //int next=0;
    }
    
    vector<pair<int, int>> map;
    
    int next(int price) {
        int span = 1;
        int index = map.size() - 1;
        
        while(index >= 0 && price >= map[index].first)
        {
            span = span +  map[index].second;
            index = index - map[index].second;
        }
        map.push_back(make_pair(price, span));
        return span;
    }
    
};
