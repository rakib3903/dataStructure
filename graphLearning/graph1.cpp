#include<bits/stdc++.h>
using namespace std;

int main() {

    int m;
    cin >> m;
    int arr[m][m];
    int Am[m][m];

     for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int cut = 0;
    cout<<"Adjacency list of v1,v2 ... are : "<<endl;
    for(int i = 0; i < m; i++) {
    cout<<"The adjacence of V"<<i+1<<" is : ";
        for(int j = 0; j < m; j++) {
            if(arr[i][j] !=0){
            cout<<"v"<<j+1<<" ";
            }
        }
        cout<<endl;
        cut = 0;
    }

    cout << endl << endl;
    int grph[m][m][m];

    for(int i = 0; i < m; i++) {
        if(i == 0) {
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < m; k++) {
                    grph[i][j][k] = arr[j][k];
                    Am[j][k] = arr[j][k];
                }
            }
        } else {
            int sum = 0;
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < m; k++) {
                    for(int p = 0; p < m; p++) {
                        sum += grph[i-1][j][p] * arr[p][k];
                    }
                    grph[i][j][k] = sum;
                    Am[j][k] += sum;
                    sum = 0;
                }
            }

        }

    }

    for(int i=1;i<m;i++){
    cout<<"The matrix for the number of path of length "<<i + 1<<" is : "<<endl;
     for(int j =0; j < m; j++) {
            for(int k = 0; k < m; k++) {

                if(grph[i][j][k]>0) {
                if(grph[i][j][k]==1){
                cout<<"there is a path of length "<<i+1<<" from v"<<j+1<<" to v"<<k+1<<endl;
                }else{
                cout<<"there are "<<grph[i][j][k]<<"path of length "<<i +1<<" from v"<<j+1<<" to v"<<k+1<<endl;
                }

            }
        }
    }
    }


    return 0;

}
