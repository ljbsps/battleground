class Solution {
public:
    int num[16] = { 0, };
    bool visit[16] = { false };
    int cache[16][16] = { 0, };
    int cnt = 0;
    
    void  make_arr(int now, int n) {
	if (now == n + 1) {
		bool beautiful = true;
		for (int i = 1; i <= n; i++) {
			if (num[i] % i != 0 && i % num[i] != 0) {
				cache[i][num[i]] = -1;
				cache[num[i]][i] - -1;
				beautiful = false;
			}
		}
		if (beautiful) cnt++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (cache[now][i] == -1)  // 이미 안되는 수
			continue;
		if (!visit[i]) {
			visit[i] = true;
			num[now] = i;
			make_arr(now + 1, n);			
			visit[i] = false;
		}
	}
}
    
    int countArrangement(int n) {
        	// arr 순열 만들기
        make_arr(1, n);
        return cnt;
    }
};