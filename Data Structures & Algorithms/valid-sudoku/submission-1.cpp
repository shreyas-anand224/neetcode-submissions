class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int row=0;row<9;row++)
        {
            unordered_set<char> seen={};//the set for rows
            for(int col=0;col<9;col++)
            {
                if(board[row][col]!='.'){
                   if (seen.count(board[row][col])) return false;
                seen.insert(board[row][col]);
                }
            }
        }
        for(int col=0;col<9;col++)
        {
            unordered_set<char>seen={};
           
            for(int row=0;row<9;row++){
                if(board[row][col]!='.')
                {
                   if (seen.count(board[row][col])) return false;
                seen.insert(board[row][col]);
                }
            }
        }
        for (int square = 0; square < 9; square++) {
            unordered_set<char> seen;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {//local for the current box
                    int row = (square / 3) * 3 + i;//global indices here
                    int col = (square % 3) * 3 + j;// global here for 9x9
                    if (board[row][col] == '.') continue;
                    if (seen.count(board[row][col])) return false;
                    seen.insert(board[row][col]);
                }
            }
        }
       
        return true;

    }
};

