class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;

        for (const string& op : operations) {
            if (op == "C") {
                record.pop_back();
            } else if (op == "D") {
                record.push_back(2 * record.back());
            } else if (op == "+") {
                int sum = record.back() + record[record.size() - 2];
                record.push_back(sum);
            } else {
                record.push_back(stoi(op)); // Convert string to int
            }
        }

        int total = 0;
        for (int score : record) {
            total += score;
        }

        return total;
    }
};
