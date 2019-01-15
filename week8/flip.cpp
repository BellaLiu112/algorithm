#include<cstdio>  
#include<iostream>  
#include<cstring>  
#include<cmath>  
#include<queue>  
#include<algorithm>  
using namespace std;  
bool map[6][6],flag;  
int step;  
int dx[5]={0,0,0,1,-1};  
int dy[5]={1,-1,0,0,0};  
bool is()  
{  
    for(int i=1;i<=4;i++)  
    for(int j=1;j<=4;j++)  
    {  
        if(map[i][j]!=map[1][1])  
        return false;  
    }  
    return true;  
}  
void flip(int r,int c)  
{  
    for(int i=0;i<5;i++)  
    {  
        int x=r+dx[i];  
        int y=c+dy[i];  
        map[x][y]=!map[x][y];  
    }  
}  
void dfs(int r,int c,int s)  
{  
    if(s==step)  
    {  
        flag=is();  
        return ;  
    }  
    if(flag||r==5) return ;//一行一行进行枚举   
    flip(r,c);//如果r，c进行翻转，步数加一   
    if(c<4)  
        dfs(r,c+1,s+1);  
    else  
        dfs(r+1,1,s+1);  
    flip(r,c);//如果r，c处不翻转，就枚举下一个，flip要再用一次   
    if(c<4)  
        dfs(r,c+1,s);  
    else  
        dfs(r+1,1,s);  
}  
int main()  
{  
    char c;  
    memset(map,false,sizeof(map));  
    flag=false;  
    for(int i=1;i<=4;i++)  
    for(int j=1;j<=4;j++)  
    {  
        cin>>c;  
        if(c=='b')  
        map[i][j]=true;  
    }  
    for(step=0;step<=16;step++)  
    {  
        dfs(1,1,0);  
        if(flag) break;  
    }  
    if(flag) cout<<step<<endl;  
    else cout<<"Impossible"<<endl;  
    return 0;  
}  