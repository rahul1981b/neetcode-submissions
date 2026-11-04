class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;

        for (int i = 0; i < operations.size(); i++)
        {
            string data = operations[i];
            if (data == "+")
            {
                record.push_back(record[record.size() - 1] + record[record.size() - 2]);
            }
            else if (data == "C")
            {
                record.pop_back();
            }
            else if (data == "D")
            {
                record.push_back(record.back() * 2);
            }
            else
            {
                record.push_back(stoi(operations[i]));
            }
        }
        int sum = 0;
        for (int i = 0; i < record.size(); i++)
        {
            sum = sum + record[i];
        }
        return sum;
    }
};