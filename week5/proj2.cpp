/*
 描述
 Bessie has gone to the mall's jewelry store and spies a charm bracelet. Of course, she'd like to fill it with the best charms possible from the N(1 ≤ N≤ 3,402) available charms. Each charm iin the supplied list has a weight Wi(1 ≤ Wi≤ 400), a 'desirability' factor Di(1 ≤ Di≤ 100), and can be used at most once. Bessie can only support a charm bracelet whose weight is no more than M(1 ≤ M≤ 12,880).
 
 Given that weight limit as a constraint and a list of the charms with their weights and desirability rating, deduce the maximum possible sum of ratings.
 
 输入
 Line 1: Two space-separated integers: N and M
 
 Lines 2..N+1: Line i+1 describes charm i with two space-separated integers: Wi and Di
 
 输出
 Line 1: A single integer that is the greatest sum of charm desirabilities that can be achieved given the weight constraints
 */

/*
 背包问题
 v为背包容量，c[i]为每个物品的重量，v[i]为每个物品的价值。f[i][v]为背包容量为v,装前i个物品的最大价值，每个物品只能用一次
 状态转移方程： f[i][v] = max{f[i-1][v], f[i-1][v-c[i]] + v[i]}
 */

#include<iostream>
using namespace std;

int n,m,w[3600],d[3600];
int dp[3600][13100];
void f(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(w[i]<=j){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+d[i]);
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>d[i];
    }
    f();
}


