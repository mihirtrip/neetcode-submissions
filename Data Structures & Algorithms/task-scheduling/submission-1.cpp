class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;

        for (char task : tasks) freq[task]++;
        // we will only store the frequency left and not the char since char is irelavant after for
        // loop
        priority_queue<int> pq;

        for (auto it : freq) pq.push(it.second);

        // {remaining frequency of task,next available time}
        queue<pair<int, int>> cooldown;

        int time = 0;

        while (!pq.empty() || !cooldown.empty()) {
            time++;
            // which ever goes first in the queue qill have the lowest remaining time since cooldown
            // time is same for all
            while (!cooldown.empty() && cooldown.front().second == time) {
                pq.push(cooldown.front().first);
                cooldown.pop();
            }

            if (!pq.empty()) {
                int task_left = pq.top();
                pq.pop();

                task_left--;

                if (task_left > 0) {
                    cooldown.push({task_left, time + n + 1});
                }
            }
        }

        return time;
    }
};