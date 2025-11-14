
class Solution {
public:
    int carFleet(int target, vector<int> position, vector<int> speed) {
        int n = position.size();
        stack<pair<int,int>> stk;
        vector<pair<int,int>> cars;
        for(int i=0; i<n; i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());

        stk.push(cars.front());
        for(int i=1; i<n; i++) {
            long long backSpeed = stk.top().second, backRemDis = target - stk.top().first;
            long long curSpeed = cars[i].second, curRemDis = target - cars[i].first;

            while (stk.size() && backRemDis * curSpeed <= curRemDis *  backSpeed) {
                stk.pop();
                if(stk.size()) {
                    backSpeed = stk.top().second, backRemDis = target - stk.top().first;
                }
            }
            stk.push(cars[i]);
        }

        return stk.size();
    }
};
