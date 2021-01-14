class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()){
            return false;
        }
        int row=0,column=matrix[0].size()-1;
        while (row<matrix.size()&&column>=0){
            if(matrix[row][column]>target){
                column--;
            }
            else if(matrix[row][column]<target){
                row++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};