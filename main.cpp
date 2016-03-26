#include <iostream>
#include <cstdlib>
#include <ctime>
#include "node.h"
#include "bst.h"

using namespace std;

int main()
{
    srand(time(NULL));
    bst<int> mybst;

    for (size_t i = 0; i < 100; ++i)
    {
        int toinsert = rand() % 40;
        cout<<"Inserting: "<<toinsert<<endl;
        mybst.insert(toinsert);
        cout<<mybst<<endl;
        cout<<"Size = "<<mybst.size()<<", Balanced = "<<( mybst.balanced() ? "True" : "False" )<<endl;
    }

    cout<<"Balancing!"<<endl;

    mybst.balance();

    cout<<mybst<<endl;
    cout<<"Size = "<<mybst.size()<<", Balanced = "<<( mybst.balanced() ? "True" : "False" )<<endl;

    return 0;
}
