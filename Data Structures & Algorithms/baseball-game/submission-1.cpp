class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;
        int len = operations.size();

        for (int i = 0; i < len; i++)
        {
            string data = operations[i];
            if (data == "+")
            {
                int temp1 = record.back();
                record.pop_back();
                int temp2 = record.back();
                record.pop_back();
                record.push_back(temp2);
                record.push_back(temp1);
                record.push_back(temp1 + temp2);
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