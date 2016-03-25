#ifndef NODE
#define NODE

#include <iostream>

enum DIRECTION {LEFT, RIGHT};

using std::ostream;
using std::istream;

template <typename data_type>
class node
{
public:
    node(const data_type &D = data_type(), size_t C = 1);
    ~node();

    node(const node<T> &other);
    node<data_type>& operator=(const node<T> &other);

    data_type& data();
    const data_type& data() const;

    size_t& count();
    const size_t& count() const;

    node<data_type>*& child (DIRECTION which);
    const node<data_type>* child (DIRECTION which) const;

    node<data_type>& operator+=(size_t v);

    node<data_type>& operator-=(size_t v);

    int operator++();
    int operator++(int);

    int operator--();
    int operator--(int);


    // Node to Node comparisons

    template <typename D>
    friend
    bool operator==(const node<D>& x, const node<D>& y);

    template <typename D>
    friend
    bool operator!=(const node<D>& x, const node<D>& y);

    template <typename D>
    friend
    bool operator<(const node<D>& x, const node<D>& y);

    template <typename D>
    friend
    bool operator>(const node<D>& x, const node<D>& y);

    template <typename D>
    friend
    bool operator<=(const node<D>& x, const node<D>& y);

    template <typename D>
    friend
    bool operator>=(const node<D>& x, const node<D>& y);


    // Node to Data Comparisons

    template <typename D>
    friend
    bool operator==(const node<D>& x, const D& y);

    template <typename D>
    friend
    bool operator!=(const node<D>& x, const D& y);

    template <typename D>
    friend
    bool operator<(const node<D>& x, const D& y);

    template <typename D>
    friend
    bool operator>(const node<D>& x, const D& y);

    template <typename D>
    friend
    bool operator<=(const node<D>& x, const D& y);

    template <typename D>
    friend
    bool operator>=(const node<D>& x, const D& y);


    // Data to Node Comparisons

    template <typename D>
    friend
    bool operator==(const D& x, const node<D>& y);

    template <typename D>
    friend
    bool operator!=(const D& x, const node<D>& y);

    template <typename D>
    friend
    bool operator<(const D& x, const node<D>& y);

    template <typename D>
    friend
    bool operator>(const D& x, const node<D>& y);

    template <typename D>
    friend
    bool operator<=(const D& x, const node<D>& y);

    template <typename D>
    friend
    bool operator>=(const D& x, const node<D>& y);


    // iostream

    template <typename D>
    friend
    istream& operator>>(istream& ins, node<D>& n);

    template <typename D>
    friend
    ostream& operator<<(ostream& outs, const node<D>& n);

private:
    data_type thedata;
    size_t thecount;
    node<data_type>* children[2];
};

template <typename data_type>
node<data_type>::node(const data_type &D = data_type(), size_t C = 1)
{
    thedata = D;
    thecount = C;
    children[] = {NULL};
}

template <typename data_type>
node<data_type>::~node()
{
    thedata = data_type();
    thecount = 0;
    children[0] = children[1] = NULL;
}

template <typename data_type>
node<data_type>::node(const node<T> &other)
{
    thedata = other.thedata;
    thecount = other.thecount;
    children[0] = children[1] = NULL;
}

template <typename data_type>
node<data_type>& node<data_type>::operator=(const node<T> &other)
{
    if (this != &other)
    {
        thedata = other.thedata;
        thecount = other.thecount;
        children[0] = children[1] = NULL;
    }
    return *this;
}

template <typename data_type>
data_type& node<data_type>::data()
{
    return thedata;
}

template <typename data_type>
const data_type& node<data_type>::data() const
{
    return thecount;
}

template <typename data_type>
size_t& node<data_type>::count()
{
    return thecount;
}

template <typename data_type>
const size_t& node<data_type>::count() const
{
    return thecount;
}

template <typename data_type>
node<data_type>*& node<data_type>::child (DIRECTION which)
{
    return children[which];
}

template <typename data_type>
const node<data_type>* node<data_type>::child (DIRECTION which) const
{
    return children[which];
}

template <typename data_type>
node<data_type>& node<data_type>::operator+=(size_t v)
{
    thecount += v;
    return *this;
}

template <typename data_type>
node<data_type>& node<data_type>::operator-=(size_t v)
{
    thecount -= v;
    return *this;
}

template <typename data_type>
int node<data_type>::operator++()
{
    thecount++;
    return thecount;
}

template <typename data_type>
int node<data_type>::operator++(int)
{
    int temp = thecount;
    thecount++;
    return temp;
}

template <typename data_type>
int node<data_type>::operator--()
{
    thecount--;
    return thecount;
}

template <typename data_type>
int node<data_type>::operator--(int)
{
    int temp = thecount;
    thecount--;
    return temp;
}

// Node to Node comparisons

template <typename D>
bool operator==(const node<D>& x, const node<D>& y)
{
    return x.thedata == y.thedata;
}

template <typename D>
bool operator!=(const node<D>& x, const node<D>& y)
{
    return x.thedata != y.thedata;
}

template <typename D>
bool operator<(const node<D>& x, const node<D>& y)
{
    return x.thedata < y.thedata;
}

template <typename D>
bool operator>(const node<D>& x, const node<D>& y)
{
    return x.thedata > y.thedata;
}

template <typename D>
bool operator<=(const node<D>& x, const node<D>& y)
{
    return x.thedata <= y.thedata;
}

template <typename D>
bool operator>=(const node<D>& x, const node<D>& y)
{
    return x.thedata >= y.thedata;
}


// Node to Data Comparisons

template <typename D>
bool operator==(const node<D>& x, const D& y)
{
    return x.thedata == y;
}

template <typename D>
bool operator!=(const node<D>& x, const D& y)
{
    return x.thedata != y;
}

template <typename D>
bool operator<(const node<D>& x, const D& y)
{
    return x.thedata < y;
}

template <typename D>
bool operator>(const node<D>& x, const D& y)
{
    return x.thedata > y;
}

template <typename D>
bool operator<=(const node<D>& x, const D& y)
{
    return x.thedata <= y;
}

template <typename D>
bool operator>=(const node<D>& x, const D& y)
{
    return x.thedata >= y;
}


// Data to Node Comparisons

template <typename D>
bool operator==(const D& x, const node<D>& y)
{
    return x == y.thedata;
}

template <typename D>
bool operator!=(const D& x, const node<D>& y)
{
    return x != y.thedata;
}

template <typename D>
bool operator<(const D& x, const node<D>& y)
{
    return x < y.thedata;
}

template <typename D>
bool operator>(const D& x, const node<D>& y)
{
    return x > y.thedata;
}

template <typename D>
bool operator<=(const D& x, const node<D>& y)
{
    return x <= y.thedata;
}

template <typename D>
bool operator>=(const D& x, const node<D>& y)
{
    return x >= y.thedata;
}


// iostream

template <typename D>
istream& operator>>(istream& ins, node<D>& n)
{
    D temp;
    ins >> temp;
    n = node(temp);
    return ins;
}

template <typename D>
ostream& operator<<(ostream& outs, const node<D>& n)
{
    outs<<n.thedata;
    return outs;
}

#endif // NODE
