#ifndef BST
#define BST

#include <iostream>
#include <algorithm>
#include "node.h"

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

    void insert(const data_type &d, size_t s = 1);
    void remove(const data_type &d, size_t s = 1);

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

    void copy (const bst<data_type> &other);
    node<data_type>* find_max (node<data_type>* r);
    node<data_type>* find_min (node<data_type>* r);
    node<data_type>* find_parent (const data_type &d);

    size_t sizeHELPER(node<data_type> *r);
    void clearHELPER(node<data_type> *&r);
    void insertHELPER(const data_type &d, size_t s, node<data_type>* &r);
    size_t findHELPER (const data_type &d, node<data_type>* r);
    bool removeHELPER(const data_type &d, size_t s, node<data_type>*& r);
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
    copy(other);
}

template <typename data_type>
bst<data_type> bst<data_type>::operator=(const bst<data_type> &other)
{
    if (this != &other)
        copy (other);
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
void bst<data_type>::insert(const data_type &d, size_t s)
{
    insertHELPER(d, s, theroot);
}

template <typename data_type>
void bst<data_type>::remove(const data_type &d, size_t s)
{
    removeHELPER(d, s, theroot);
}

template <typename data_type>
size_t bst<data_type>::find (const data_type &d)
{
    return findHELPER(d, theroot);
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
node<data_type>* bst<data_type>::find_max (node<data_type>* r)
{
    while(r->child(RIGHT))
        r = r->child(RIGHT);
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
                if (!r->child(LEFT))
                {
                    node<data_type> *delete_ptr = r;
                    r = r->child(RIGHT);
                    delete delete_ptr;
                    return 1;
                }
                else
                {
                    node<data_type> *swap_ptr = find_max(r->child(LEFT));
                    std::swap (r->data(), swap_ptr->data());
                    std::swap (r->count(), swap_ptr->count());
                    return removeHELPER (d, s, swap_ptr);
                }
    }
    else
        return 0;

}

#endif // BST
