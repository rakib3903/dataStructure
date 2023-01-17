#include<bits/stdc++.h>
using namespace std;
int main() {

    int m;
    cin >> m;
    int arr[m][m];


    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }


    int grph[m+1][m][m];

    for(int i = 0; i <= m; i++) {
        if(i == 0) {
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < m; k++) {
                    if(arr[j][k] > 0)
                        grph[i][j][k] = 1;
                    else
                        grph[i][j][k] = 0;
                }
            }
        } else {
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < m; k++) {
                   grph[i][j][k] = grph[i-1][j][k] | (grph[i-1][j][i-1] & grph[i-1][i-1][k]);
                }
            }

        }

    }
    int cot = 0;
    cout<<"The Path matrix using warshall's algorithms is : "<<endl;
   for(int i = m; i <= m; i++) {
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < m; k++) {
                if(grph[i][j][k] == 1){
                cot++;
                }
                   cout<<grph[i][j][k]<<" ";
                }
                cout<<endl;
            }
        }
        if(cot == m * m){
        cout<<"The graph is strongly connected graph"<<endl;
        }else{
         cout<<"The graph is not strongly connected graph"<<endl;
        }

        return 0;

}
