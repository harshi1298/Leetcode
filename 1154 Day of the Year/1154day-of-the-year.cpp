class Solution {
public:
    int dayOfYear(string date) {
        int y = stoi(date.substr(0, 4));
        int m = stoi(date.substr(5, 2));
        int d = stoi(date.substr(8, 2));

        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        for (int i = 0; i < m - 1; ++i)
            d += daysInMonth[i];

        if (m > 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)))
            ++d;

        return d;
    }
};