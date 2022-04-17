// from my solution of leetcode : https://leetcode.com/problems/set-matrix-zeroes/
class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        bool RowZ=0,ColZ=0;
        int row=v.size();
        if(row==0)return;
        int col=v[0].size();
        for(int i=0;i<col;i++){
            if(v[0][i]==0){
                RowZ=1;break;
            }
        }

        for(int i=0;i<row;i++){
            if(v[i][0]==0){
                ColZ=1;break;
            }
        }

        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++){
                if(v[i][j]==0){
                    v[i][0]=0;
                    v[0][j]=0;
                }
            }
        }

        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                if(v[i][0]==0 || v[0][j]==0)v[i][j]=0;
            }
        }

        if(RowZ){
            for(int i=0;i<col;i++)v[0][i]=0;
        }
        if(ColZ){
            for(int i=0;i<row;i++)v[i][0]=0;
        }


    }
};
