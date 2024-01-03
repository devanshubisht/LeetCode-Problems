class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int first {0};
        int second {0};
        int total {0};
        for (int i = 0 ; i < bank.size() ; ++i) {
            if (first == 0) {
                first = numberInRow(bank[i]);
            } else if (second == 0) {
               second = numberInRow(bank[i]);
            }
            if (first != 0 && second != 0) {
                total += first * second;
                first = second;
                second = 0;
            }
        }
        return total;
    }

    int numberInRow(string& row) {
        int result = 0;
        for (int i = 0 ; i < row.size() ; ++i) {
            if (row[i] == '1') {
                result++;
            }
        }
        return result;
    }
};