class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size(),column=board[0].size();
        if(!row||!column||!word.size()){
            return false;
        }
        bool *visited=new bool[row*column];
        memset(visited,0,row*column);
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(hasPath(board,row,column,word,i,j,0,visited)){
                    return true;
                }
            }
        }
        return false;
    }
    bool hasPath(vector<vector<char>>& board,int row,int column,string& word,int x,int y,int plen,bool* visited){
        if(x<0||x>=row||y<0||y>=column){
            return false;
        }
        if(visited[x*column+y]){
            return false;
        }
        if(board[x][y]!=word[plen]){
            return false;
        }
        if(plen==word.size()-1){
            return true;
        }
        visited[x*column+y]=true;
        bool hp=hasPath(board,row,column,word,x-1,y,plen+1,visited)
                ||hasPath(board,row,column,word,x,y-1,plen+1,visited)
                ||hasPath(board,row,column,word,x+1,y,plen+1,visited)
                ||hasPath(board,row,column,word,x,y+1,plen+1,visited);
        if(hp){
            return true;
        }
        visited[x*column+y]=false;
        return false;
    }
};