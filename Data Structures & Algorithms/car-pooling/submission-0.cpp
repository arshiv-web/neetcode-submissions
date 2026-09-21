class Event{
private:
    int time;
    int effect;
public:
    Event(int t, int e): time(t), effect(e){

    }
    int getTime() const {return time;}
    int getEffect() const {return effect;}
};

static bool compare(const Event& a, const Event& b){
    if(a.getTime() == b.getTime()){
        return a.getEffect() < b.getEffect();
    }
    return a.getTime() < b.getTime();
}

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<Event> events;
        for(auto &x: trips){
            events.push_back(Event(x[1], x[0]));
            events.push_back(Event(x[2], x[0]*-1));
        }

        sort(events.begin(), events.end(), compare);
        int state = 0;
        for(auto &x: events){
            state += x.getEffect();
            if(state < 0 || state > capacity){
                return false;
            }
        }
        return true;
    }
};