/*
描述：对一棵树采用采用层次遍历；
解决方案：1-采用队列依次把根节点压入，在弹出，在按顺序压入左右孩子；

*/

#include <iostream>
#include <queue>
using namespace std;
template <typename Comparable>

class BinarySearchTree
{
public:
    BinarySearchTree( ) :root( NULL )
    {}
    BinarySearchTree( const BinarySearchTree & rhs ) : root( NULL )
    {
        *this = rhs;
    }
    ~BinarySearchTree( )
    {
        makeEmpty( );
    }
    bool contains( const Comparable & x ) const
    {
        return contains( x, root );
    }
    bool isEmpty( ) const
    {
        return root == NULL;
    }
    void printTree( ostream & out = cout ) const
    {
        if( isEmpty( ) )
            out << "Empty tree" << endl;
        else
            printTree( root, out );
    }
    void makeEmpty( )
    {
        makeEmpty( root );
    }
    void insert( const Comparable & x )
    {
        insert( x, root );
    }
    void remove(const Comparable &x)
    {
        remove(x,root);
    }
    const BinarySearchTree & operator=( const BinarySearchTree & rhs )
    {
        if( this != &rhs )
        {
            makeEmpty( );
            root = clone( rhs.root );
        }
        return *this;
    }

private:
    struct BinaryNode
    {
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
            : element( theElement ), left( lt ), right( rt ) { }
    };
    BinaryNode *root;

    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( const Comparable & x, BinaryNode * & t )
    {
        if( t == NULL )
            t = new BinaryNode( x, NULL, NULL );
        else if( x < t->element )
            insert( x, t->left );
        else if( t->element < x )
            insert( x, t->right );
        else
            ;  // Duplicate; do nothing
    }


    /**
     * Internal method to test if an item is in a subtree.
     * x is item to search for.
     * t is the node that roots the subtree.
     */
    bool contains( const Comparable & x, BinaryNode *t ) const
    {
        if( t == NULL )
            return false;
        else if( x < t->element )
            return contains( x, t->left ) ;
        else if( t->element < x )
            return contains( x, t->right );
        else
            return true;    // Match
    }
    void makeEmpty( BinaryNode * & t )
    {
        if( t != NULL )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = NULL;
    }
    void printTree( BinaryNode *t, ostream & out ) const
    {
        queue<BinaryNode*> qu;
        qu.push(t);
        while(!qu.empty())
        {
            BinaryNode * Tmp = qu.front() ;
            qu.pop();
            out<<Tmp->element<<"\t";
            if (Tmp->left != nullptr)
                qu.push(Tmp->left);
            if (Tmp->right != nullptr)
                qu.push(Tmp->right);
        }
        cout<<endl;
    }
    BinaryNode* findMin(BinaryNode *t)
    {
        if (t == nullptr)
            return nullptr ;
        while(t->left != nullptr)
        {
            t = t->left;
        }
        return t ;
    }
    void remove( const Comparable & x, BinaryNode * & t )
    {
        if( t == NULL )
            return;   // Item not found; do nothing
        if( x < t->element )
            remove( x, t->left );
        else if( t->element < x )
            remove( x, t->right );
        else if( t->left != NULL && t->right != NULL ) // Two children
        {
            t->element = findMin( t->right )->element;
            remove( t->element, t->right );
        }
        else
        {
            BinaryNode *oldNode = t;
            t = ( t->left != NULL ) ? t->left : t->right;
            delete oldNode;
        }
    }

};
int main( )
{
    BinarySearchTree<int> t;
    int i;
    int a[] = {6,2,8,1,4,3};
    cout << "The original binary search tree---->" << endl;
    for( i = 0; i < sizeof(a)/sizeof(a[0]); i++ )
        t.insert( a[i] );
    t.printTree( );
    cout<<"Remove --"<<a[1]<<"---after--->"<<endl;
    t.remove(a[1]);
    t.printTree( );
    return 0;
}

/*
The answer as follow---->
The original binary search tree---->
6       2       8       1       4       3
Remove --2---after--->
6       3       8       1       4

Process returned 0 (0x0)   execution time : 0.061 s
Press any key to continue.
*/