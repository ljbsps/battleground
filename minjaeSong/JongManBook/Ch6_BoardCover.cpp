#include <iostream>
#include <vector>
using namespace std;

int shape[4][6]={
        {0,0,1,0,0,1},
        {0,0,1,0,1,1},
        {0,0,0,1,1,1},
        {0,0,1,0,1,-1}
};

bool can_put(vector<vector<int>>& board, int idx, int r, int c, int height, int width){
    for(int i=0;i<3;i++){
        int nr = r + shape[idx][2*i];
        int nc = c + shape[idx][2*i+1];
        if(nr<0 || nc<0 || nr>height-1 || nc>width-1 || board[nr][nc]==1)
            return false;
    }
    return true;
}

void color(vector<vector<int>>& board, int idx, int r, int c, int delta){
    for(int i=0;i<3;i++){
        int nr = r + shape[idx][2*i];
        int nc = c + shape[idx][2*i+1];
        board[nr][nc] = delta;
    }
}

int board_cover(vector<vector<int>>& board, int height, int width, int blank){
    int ret = 0, r = -1, c = -1;
    bool found = false;
    if(blank==0){
        return 1;
    }
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(board[i][j]==0){
                found = true;
                r=i;
                c=j;
                break;
            }
        }
        if(found) break;
    }
    for(int idx=0;idx<4;idx++){
        if(can_put(board,idx,r,c,height,width)){
            color(board, idx, r, c, 1);
            ret += board_cover(board,height,width,blank-3);
            color(board, idx, r, c, 0);
        }
    }
    return ret;
}

int main()
{
    int C, H, W, blank=0;
    vector<vector<int>> board;
    cin >> C;

    for(int tc=0;tc<C;tc++){
        // 입력
        cin>>H>>W;
        for (int i = 0; i < H; i++){
            vector<int> tmp_vec;
            for (int j = 0; j < W; j++){
                char tmp;
                cin >> tmp;
                if(tmp=='#')
                    tmp_vec.push_back(1);
                else{
                    tmp_vec.push_back(0);
                    blank++;
                }
            }
            board.push_back(tmp_vec);
        }
        if(blank==0 || blank%3!=0)
            cout << 0 << '\n';
        else
            cout << board_cover(board, H, W, blank) << '\n';

    }
    return 0;
}