#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int mat[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    int sr=0, er=n-1,sc=0,ec=m-1;
    while(sr<=er && sc<=ec){
        //top
        for(int j=sc;j<=ec;j++){
            cout<<mat[sr][j]<<" ";
        }
        //right
        for(int i=sr+1;i<=er;i++){
            cout<<mat[i][ec]<<" ";
        }
        //bottom
        for(int j=ec-1;j>=sc;j--){
            if(sr==er){
                break;
            }
            cout<<mat[er][j]<<" ";
        }
        //left
        for(int i=er-1;i>=sr+1;i--){
            if(sc==ec){
                break;
            }
            cout<<mat[i][sc]<<" ";
        }
        sc++; sr++; ec--; er--;
    }
    cout<<endl;
    return 0;
}

// link for question:
// https://leetcode.com/problems/spiral-matrix/description/