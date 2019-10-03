
#include<iostream>
using std::cout;

#include<vector>
using std::vector;





vector<int> test(int quantity){

    vector<int> test;

    test.get_allocator().allocate(5);


    //cout << "\nV.size: " << test.size();
    //cout << "\nV.capacity: " << test.capacity();

    for(int i=0; i<quantity; ++i)
        test.push_back(i);


    return test;
}
/*



    - rezerwowanie pamiêci


    - nadawanie wartosci
    - zwracanie, przypisywanie, przesy³anie vectora


*/


void Show(vector<int>& V, bool elementy=0){


    if (elementy)
        for (int i : V)
            cout << V[i] << " ";

    std::cout << "\n\nParametry Vectora:"
         << "\nV.size: " << V.size()
         << "\nV.capacity: " << V.capacity();
}

void DoTheThing(vector<int>& V){

    V.reserve(500);


    for (int i=0; i<500; ++i){
        V[i] = i;
        cout << " " << V[i];
//        if (i<100)
//            V[i] = i;
//        else
//
//        if (i%2==0)
//            V[i] = i;
//        else
//            V[i] = 0;
    }

    std::cout << "\n\nParametry Vectora:"
         << "\nV.size: " << std::distance(V.begin(), V.end());
}



int main(){

    vector<int> V;

    Show(V,1);

    //DoTheThing(V);



        V.reserve(500);



    Show(V,1);


    cout << "\n\n\n";

/*
    vector<int> V = test(1000);


    int tmp = V[400];

    cout << "\n " <<  tmp;

    cout << "\nV.size: " << V.size();
    cout << "\nV.capacity: " << V.capacity();


    V.clear();
    V = test(200);

    cout << "\n " <<  tmp;
    cout << "\nV.size: " << V.size();
    cout << "\nV.capacity: " << V.capacity();


    V.get_allocator();
*/


    return 0;
}









