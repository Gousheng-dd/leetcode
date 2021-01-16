class Solution {
public:
    int movingCount(int m, int n, int k) {
        if(m<=0||n<=0||k<0){
            return -1;
        }
        bool* visited = new bool[m*n];
        memset(visited,0,m*n);
        int res=0;
        movingCountCore(m,n,k,0,0,res,visited);
        delete[] visited;
        return res;
    }
private:
    void movingCountCore(int m,int n,int k,int x,int y,int &cnt,bool* visited){
        if(x<0||x>=m||y<0||y>=n||visited[x*n+y]){
            return;
        }
        if(!avichk(m,n,k,x,y)){
            return;
        }
        cnt++;
        visited[x*n+y]=true;
        movingCountCore(m,n,k,x-1,y,cnt,visited);
        movingCountCore(m,n,k,x,y-1,cnt,visited);
        movingCountCore(m,n,k,x+1,y,cnt,visited);
        movingCountCore(m,n,k,x,y+1,cnt,visited);
        return;
    }
    bool avichk(int m,int n,int k,int x,int y){
        int sum=0;
        while(x>0){
            sum+=x%10;
            x/=10;
        }
        while(y>0){
            sum+=y%10;
            y/=10;
        }
        if(sum<=k){
            return true;
        }
        return false;
    }
};