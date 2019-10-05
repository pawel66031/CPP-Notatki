
#include<iostream>
using std::cout;

#include<vector>
using std::vector;






/*
    - rezerwowanie pamiêci

    - nadawanie wartosci
    - zwracanie, przypisywanie, przesy³anie vectora
*/


void Show(vector<int>& V, bool elementy=0){


    if (elementy)
        for (int i=0; i<V.size(); ++i)
            cout << V[i] << " ";

    std::cout << "\n\nParametry Vectora:"
         << "\nV.size: " << V.size()
         << "\nV.capacity: " << V.capacity();
}





int main(){

    vector<int> V(112,1);
//    V.reserve(800);

    Show(V,1);
    cout << "\n\n\n";

    V.shrink_to_fit();

    Show(V);
//    V.resize(500);
//    for (int i=0; i<V.size(); ++i){
//        V[i] = 1+i;
//    }

//    V.reserve(500);
//    for (int i=0; i<V.capacity(); ++i)
//       V.push_back(i+1);
//
//
//    V.reserve(600);
//    V.reserve(100);

//    Show(V,1);
//    cout << "\n\n\n";



    return 0;
}









