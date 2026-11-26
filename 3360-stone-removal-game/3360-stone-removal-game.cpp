class Solution {
public:
    bool canAliceWin(int n) {
        int rm = 10;
        bool turn = true;
        while (n >= rm) {
            n -= rm;
            rm--;
            turn = !turn;
        }
        return !turn;
    }
};