class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) { //O(9*9)
        //bitmasks
        vector<int> rows(9);
        vector<int> cols(9);
        vector<vector<int>> subs(3, vector<int>(3)); //subboxes
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                int val = board[i][j] - '1';
                
                //check row
                if(rows[i] & (1 << val)) return false;
                else rows[i] |= (1 << val);
                
                //check col
                if(cols[j] & (1 << val)) return false;
                else cols[j] |= (1 << val);
                
                //check subbox
                if(subs[i/3][j/3] & (1 << val)) return false;
                else subs[i/3][j/3] |= (1 << val);
            }
        }
        
        return true;
    }
};
