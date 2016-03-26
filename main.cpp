#include <iostream>
#include <cstdlib>
#include <ctime>
#include "node.h"
#include "bst.h"

using namespace std;

int main()
{
    bst<int> mybst(PREORDER);
    srand (time(NULL));

    for (size_t i = 0; i < 15; ++i)
    {
        mybst.insert(rand()%10);
        cout<<"Insertion Round "<<i<<": "<<endl<<mybst<<endl;
    }

    cout<<"Successfully inserted, beginning removal!"<<endl
       <<"Full bst = "<<endl<<mybst<<endl<<"Size = "<<mybst.size()<<endl;
    for (int i = 0; i < 10; ++i)
    {
        mybst.remove(i, mybst.find(i));
        cout<<"Round "<<i<<": "<<endl<<mybst<<endl<<"Size = "<<mybst.size()<<endl;
    }

    mybst.clear();
    cout<<"Cleared: "<<mybst<<endl<<"Size = "<<mybst.size()<<endl;


    return 0;
}
