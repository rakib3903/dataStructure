#include<bits/stdc++.h>
using namespace std;
int main() {

    int m;
    cin >> m;
    int arr[m][m];
    int infinite = 99999999;

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
                        grph[i][j][k] = arr[j][k];
                    else
                        grph[i][j][k] = infinite;
                }
            }
        } else {
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < m; k++) {
                   grph[i][j][k] = min(grph[i-1][j][k] , (grph[i-1][j][i-1] + grph[i-1][i-1][k]));
                }
            }

        }

    }
     cout<<"The shortest path of the graph is : "<<endl;
   for(int i = m; i <= m; i++) {
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < m; k++) {
                   cout<<grph[i][j][k]<<" ";
                }
                cout<<endl;
            }
        }

        return 0;

}
