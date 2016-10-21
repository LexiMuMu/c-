
#include "stdio.h"
#define BIG 9999 //无穷大

//Dijkstra算法函数，求给定顶 点到其余各点的最短路径
//参数：邻接矩阵、顶点数、出发点的下标、结果数组
void Dijkstra(int Cost[] [6],int n,int v0,int Distance[])
{
     int s[6];
     int mindis,dis;
     int i,j,u;
     //初始化
     for(i=0;i<n;i++) {
           Distance[i]=Cost[v0][i];
           s[i]=0;
     }
     s[v0] =1; /*标记v0*/
     //在当前还未找到最短路径的顶点中，
     //寻找具有最短距离的顶点
     for(i=1;i<n;i++) {//每循环一次，求得一个最短路径
           mindis=BIG;
           for (j=0;j<n;j++) //求离出发点最近的顶点
                 if(s [j]==0&&Distance[j]<mindis) {
                       mindis=Distance [j];
                       u=j;
                 } // if语句体结束，j循环结束
           for(j=0;j<n;j++) //修改递增路径序列（集合）
                 if(s[j]==0) { //对还未求得最短路径的顶点
                       //求出由最近的顶点 直达各顶点的距离
                       dis=Distance[u] +Cost[u][j];
                       // 如果新的路径更短，就替换掉原路径
                       Distance[j]= (Distance[j]<dis)?
                          & nbsp;  Distance[j]:dis;
                 } // if 语句体结束，，j循环结束
           s[u]=1; /* 标记最短路径已经求得*/
     } // i循环结束
}


//主函数
void main()
{
     //给出有向网的顶点数组 
     char *Vertex[6]={"V1","V2","V3","V4","V5","V6"};
     //给出有向网的邻接矩阵
     int Cost[6][6]={{0,BIG,5,30,BIG,BIG},
                          & nbsp;  {2,0,BIG,BIG,8,BIG},
                          & nbsp;  {BIG,15,0,BIG,BIG,7},
                          & nbsp;  {BIG,BIG,BIG,0,BIG,BIG},
                          & nbsp;  {BIG,BIG,BIG,4,0,BIG},
                          & nbsp;  {BIG,BIG,BIG,10,18,0},
           };
     int Distance[6]; //存放求得的最短路径
     int i;
     //调用Dijkstra算法函数，求顶点V1到其余各点的最短路径
     //参数：邻接矩阵、顶点数、出发点的下标、 结果数组
     Dijkstra(Cost,6,0,Distance);
     for(i=0;i<6;i++)
           printf("%s---->%s   %d\n",
                 Vertex[0],Vertex[i],Distance[i]);
}


