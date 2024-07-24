class RecentCounter {
private:
    queue<int> q;
public:
    RecentCounter() {}
    int ping(int t) {
        q.emplace(t);
        while(q.front() < t - 3000) q.pop();
        return q.size();
    }
};