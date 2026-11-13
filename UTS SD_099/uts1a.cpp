#include <iostream>
using namespace std;
main(){
    system("cls");
    int arr1 [2] [3] [4];
    int klpt1 = 3;
    int klpt2 = 6;

     for (int i = 0 ; i < 2 ; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 4; k++){
                arr1[i][j][k] = klpt1 + klpt2;
                klpt1 += 3;
                klpt2 += 6;
            }
        }
    }
        for (int i = 0; i < 2; i++){
         for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                cout << arr1[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}