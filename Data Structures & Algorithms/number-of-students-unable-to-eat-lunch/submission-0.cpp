class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int sq  = 0;
        int cir = 0;
        for (int i = 0; i < (int) students.size(); i++)
        {
            students[i] == 0 ? sq++ : cir++;
        }

        for (int sandwich : sandwiches)
        {
            if (sandwich == 0)
            {
                if (sq > 0) sq--;
                else break;
            } 
            else
            {
                if (cir > 0) cir--;
                else break;
            }
        }
        return cir + sq;
    }
};