class NumMatrix {
private:
    vector<vector<int>> prefixSum2d;
    int result = 0;
    
public:
    
    NumMatrix(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size() + 1;
        const int COLS = matrix[0].size() + 1;
        prefixSum2d = vector<vector<int>>(ROWS, vector<int> (COLS));
        for (int row = 0; row < ROWS-1; row++) {
            for (int column = 0; column<COLS-1; column++) {
                prefixSum2d[row + 1][column + 1] = matrix[row][column] + prefixSum2d[row + 1][column] + prefixSum2d[row][column + 1] - prefixSum2d[row][column];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        result = prefixSum2d[row2+1][col2+1] - prefixSum2d[row2+1][col1] - prefixSum2d[row1][col2+1] + prefixSum2d[row1][col1];

        return result;
    }

};


// TODO
/**
1. In the constructor, create a prefix sum. 
    a. Initialize ROWS and COLS
    b. Find an equation to find a 2D prefix sum in one step (2nd approach)
        prefixSum2d[i + 1][j + 1] = matrix[i][j] + prefixSum2d[i - 1][j] + prefixSum2d[i][j - 1] - prefixSum2d[i - 1][j - 1]
    c. Iterate through prefixSum2d and initialize element based on b.
2. Function definition for sumRegion
    a. Query prefixSum2d to calculate sumRegion based on indices of upper left and bottom right corner
    b. result = prefixSum2d[r2+1][c2+1] - prefixSum2d[r2+1][c1] - prefixSum2d[r1][c2+1] + prefixSum2d[r1][c1]
    c. return the result to the constructor

 */

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
 


// Cursor parking lot  
