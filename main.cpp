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

    for (int i = 99; i >= 0; --i)
        mybst.insert(rand()%20);

    cout<<mybst<<endl;
    cout<<"Size = "<<mybst.size()<<", Balanced = "<<mybst.balanced()<<endl;

    mybst.balance();
    cout<<mybst<<endl;

    cout<<"Size = "<<mybst.size()<<", Balanced = "<<mybst.balanced()<<endl;

    while (!mybst.empty())
    {
        int toremove = rand()%20;
        cout<<"Removing "<<toremove<<endl;
        mybst.remove(toremove, mybst.find(toremove));
        cout<<mybst<<endl;

        cout<<"Size = "<<mybst.size()<<", Balanced = "<<mybst.balanced()<<endl;

    }

    cout<<"SUCCESS!"<<endl;
    return 0;
}
