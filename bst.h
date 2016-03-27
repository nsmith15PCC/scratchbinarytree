#ifndef BST
#define BST

#include <iostream>
#include <algorithm>
#include "node.h"

using std::cout;
using std::swap;
using std::max;

enum TRAVERSAL_TYPE {PREORDER, INORDER, POSTORDER};
enum BSTERRORS {EMPTY};

template <typename data_type>
class bst
{
public:
    bst(TRAVERSAL_TYPE t = INORDER);
    ~bst();

    bst(const bst<data_type> &other);
    bst<data_type> operator=(const bst<data_type> &other);

    node<data_type>* root ();
    const node<data_type>* root () const;

    TRAVERSAL_TYPE& traversal();
    const TRAVERSAL_TYPE& traversal() const;

    bool empty();
    size_t size();

    void clear();

    bool balanced() const;
    void balance();


    void insert(const data_type &d, size_t s = 1);
    bool remove(const data_type &d, size_t s = 1);

    size_t find (const data_type &d);

    template <typename D>
    friend
    istream& operator>>(istream& ins, bst<D> &b);

    template <typename D>
    friend
    ostream& operator<<(ostream& outs, const bst<D> &b);

private:
    node<data_type>* theroot;
    TRAVERSAL_TYPE thetraversal;

    void copy (const node<data_type>* r);
    node<data_type> *find_max(node<data_type>* r);

    size_t sizeHELPER(node<data_type> *r);
    void clearHELPER(node<data_type> *&r);
    void insertHELPER(const data_type &d, size_t s, node<data_type>* &r);
    size_t findHELPER (const data_type &d, node<data_type>* r);
    bool removeHELPER(const data_type &d, size_t s, node<data_type>*& r);
    bool removeMAX(node<data_type> *&r, data_type &d, size_t &c);

    int depth(const node<data_type>* r) const;

    void tree_to_vine (node<data_type> *&root, int &size );
    void vine_to_tree ( node<data_type>* &root, int size );
    int FullSize ( int size );
    void compression ( node<data_type>* &root, int count );

};

template <typename data_type>
bst<data_type>::bst(TRAVERSAL_TYPE t)
{
    theroot = NULL;
    thetraversal = t;
}

template <typename data_type>
bst<data_type>::~bst()
{
    clearHELPER(theroot);
}

template <typename data_type>
bst<data_type>::bst(const bst<data_type> &other)
{
    copy(other.theroot);
}

template <typename data_type>
bst<data_type> bst<data_type>::operator=(const bst<data_type> &other)
{
    if (this != &other)
        copy (other.theroot);
    return *this;
}

template <typename data_type>
node<data_type>* bst<data_type>::root ()
{
    return theroot;
}

template <typename data_type>
const node<data_type>* bst<data_type>::root () const
{
    return theroot;
}

template <typename data_type>
TRAVERSAL_TYPE& bst<data_type>::traversal()
{
    return thetraversal;
}

template <typename data_type>
const TRAVERSAL_TYPE& bst<data_type>::traversal() const
{
    return thetraversal;
}

template <typename data_type>
bool bst<data_type>::empty()
{
    return !theroot;
}

template <typename data_type>
size_t bst<data_type>::size()
{
    return sizeHELPER(theroot);
}

template <typename data_type>
void bst<data_type>::clear()
{
    clearHELPER(theroot);
}

template <typename data_type>
bool bst<data_type>::balanced() const
{
    if (theroot)
        return (abs(depth(theroot->child(LEFT)) - depth (theroot->child(RIGHT))) <= 1);
    else return 1;
}

template <typename data_type>
void bst<data_type>::balance()
{
    int size = 0;
    node<data_type>* dummy = new node<data_type>();
    dummy->child(RIGHT) = theroot;
    tree_to_vine(dummy, size);
    vine_to_tree(dummy, size);
    theroot = dummy->child(RIGHT);
    delete dummy;
}


template <typename data_type>
void bst<data_type>::insert(const data_type &d, size_t s)
{
    insertHELPER(d, s, theroot);
}

template <typename data_type>
bool bst<data_type>::remove(const data_type &d, size_t s)
{
    if (find(d))
        return removeHELPER(d, s, theroot);
}

template <typename data_type>
size_t bst<data_type>::find (const data_type &d)
{
    return findHELPER(d, theroot);
}

template <typename data_type>
void bst<data_type>::copy(const node<data_type> *r)
{
    if (r)
    {
    insert(r->data(), r->count());
    copy(r->child(LEFT));
    copy(r->child(RIGHT));
    }
}

template <typename D>
istream& operator>>(istream& ins, bst<D> &b)
{
    D temp;
    ins >> temp;
    b.insert(temp);
}

template <typename D>
ostream& operator<<(ostream& outs, const bst<D> &b)
{
    node<D>::trav_ptr[b.thetraversal](outs, b.theroot,0);
    return outs;
}

template <typename data_type>
node<data_type> *bst<data_type>::find_max(node<data_type>* r)
{
    while(r->child(RIGHT)->child(RIGHT))
        r = r->child(RIGHT);
    return r;
}

template <typename data_type>
size_t bst<data_type>::sizeHELPER(node<data_type> *r)
{
    size_t counter(0);
    if (r)
    {
        counter += r->count();
        counter += sizeHELPER(r->child(LEFT));
        counter += sizeHELPER(r->child(RIGHT));
    }
    return counter;
}

template <typename data_type>
void bst<data_type>::clearHELPER(node<data_type> *&r)
{
    if (r)
    {
        clearHELPER(r->child(LEFT));
        clearHELPER(r->child(RIGHT));
        delete r;
        r = NULL;
    }
}

template <typename data_type>
void bst<data_type>::insertHELPER(const data_type &d, size_t s, node<data_type>* &r)
{
    if (r)
        if (*r == d)
            *r += s;
        else
            insertHELPER (d, s, r->child((DIRECTION)(*r < d)));
    else
        r = new node<data_type>(d, s);
}

template <typename data_type>
size_t bst<data_type>::findHELPER (const data_type &d, node<data_type>* r)
{
    if (r)
    {
        if (*r == d)
            return r->count();
        else
            return findHELPER(d, r->child((DIRECTION)(*r < d)));
    }
    else
        return 0;
}

template<typename data_type>
bool bst<data_type>::removeHELPER(const data_type &d, size_t s, node<data_type>*& r)
{
    if (r)
    {
        if (d != *r)
            return removeHELPER(d,s, r->child((DIRECTION)(*r < d)));
        else
            if (s < r->count())
            {
                *r -= s;
                return 1;
            }
            else
                if (!(r->child(LEFT)))
                {
                    node<data_type> *delete_ptr = r;
                    r = r->child(RIGHT);
                    delete delete_ptr;
                    return 1;
                }
                else
                    return removeMAX(r->child(LEFT), r->data(), r->count());

    }
    else
        return 0;
}

template <typename data_type>
bool bst<data_type>::removeMAX(node<data_type>*& r, data_type& d, size_t &c)
{
    if (r->child(RIGHT))
    {
        return removeMAX(r->child(RIGHT), d, c);
    }
    else
    {
        d = r->data();
        c = r->count();
        node<data_type> *delete_ptr = r;
        r = r->child(LEFT);
        delete delete_ptr;
        return 1;
    }
}


template <typename data_type>
int bst<data_type>::depth(const node<data_type>* r) const
{
    if (r)
        return (1 + std::max(depth(r->child(LEFT)), depth(r->child(RIGHT) ) ) ) ;
    else
        return 0;
}

template <typename data_type>
void bst<data_type>::tree_to_vine ( node<data_type> *&root, int &size )
{
    node<data_type> *vineTail, *remainder, *tempPtr;

    vineTail = root;
    remainder = vineTail->child(RIGHT);
    size = 0;
    while ( remainder != NULL )
    {
        if ( remainder->child(LEFT) == NULL )
        {  vineTail = remainder;
            remainder = remainder->child(RIGHT);
            size++;
        }
        else
        {  tempPtr = remainder->child(LEFT);
            remainder->child(LEFT) = tempPtr->child(RIGHT);
            tempPtr->child(RIGHT) = remainder;
            remainder = tempPtr;
            vineTail->child(RIGHT) = tempPtr;
        }
    }
}

template<typename data_type>
int bst<data_type>::FullSize (int size)
{
    int Rtn = 1;
    while ( Rtn <= size )
        Rtn = Rtn + Rtn + 1;
    return Rtn/2;
}

template <typename data_type>
void bst<data_type>::vine_to_tree ( node<data_type>* &root, int size )
{
    int full_count = FullSize (size);
    compression(root, size - full_count);
    for ( size = full_count ; size > 1 ; size /= 2 )
        compression ( root, size / 2 );
}

template <typename data_type>
void bst<data_type>::compression ( node<data_type>* &root, int count )
{
    node<data_type>* scanner = root;

    for ( int j = 0; j < count; j++ )
    {
        node<data_type>* child = scanner->child(RIGHT);
        scanner->child(RIGHT) = child->child(RIGHT);
        scanner = scanner->child(RIGHT);
        child->child(RIGHT) = scanner->child(LEFT);
        scanner->child(LEFT) = child;
    }
}

#endif // BST
