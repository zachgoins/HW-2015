#include <queue>

template <class T>
class HBLTNode {

public:
    HBLTNode(const T& e, const int sh)
    {
        data = e;
        s = sh;
        LeftChild = RightChild = 0;
    }
    int s;
    T data;
    HBLTNode<T> *LeftChild, *RightChild;
};

template<class T>
class MinHBLT {

   public:

      MinHBLT() {root = 0;}
      ~MinHBLT() {Free(root);}
      bool empty();
      T top() {if (!root);
               return root->data;}
      MinHBLT<T>& Insert(const T& x);
      MinHBLT<T>& pop();
      MinHBLT<T>& Meld(MinHBLT<T>& x) {
                Meld(root,x.root);
                x.root = 0;
                return *this;}
      void Initialize(T a[], int n);
      int get_size(){ return size; };
      void Free(HBLTNode<T> *t);
      void Meld(HBLTNode<T>* &x, HBLTNode<T>* y);
      int size = 0;
      HBLTNode<T> *root;  // pointer to tree root

};



template<class T>
void MinHBLT<T>::Free(HBLTNode<T> *t)
{ // Delete all nodes in tree rooted at t.
 //Use a postorder traversal.
   if (t) {Free(t->LeftChild);
           Free(t->RightChild);
           delete t;}

}



template<class T>
void MinHBLT<T>::Meld(HBLTNode<T>* &x, HBLTNode<T>* y)
{// Meld leftist trees with roots *x and *y.
 // Return pointer to new root in x.
   if (!y) return; // y is empty
   if (!x) // x is empty
      {x = y;
       return;}

   // neither is empty
   if (x->data > y->data) std::swap(x,y);
   // now x->data <= y->data
   Meld(x->RightChild,y);
   if (!x->LeftChild) {// left subtree empty
         // swap subtrees
         x->LeftChild = x->RightChild;
         x->RightChild = 0;
         x->s = 1;}
   else {// see if subtrees to be swapped
         if (x->LeftChild->s < x->RightChild->s)
            std::swap(x->LeftChild,x->RightChild);
         x->s = x->RightChild->s + 1;}

}


template<class T>
MinHBLT<T>& MinHBLT<T>::Insert(const T& x)
{// Insert x into the leftist tree.
 // Create tree with one node.
   HBLTNode<T> *q = new HBLTNode<T> (x,1);
   // meld q and original tree
   Meld(root,q);
   size++;
   return *this;


}

template<class T>
MinHBLT<T>& MinHBLT<T>::pop()
{// Delete min element and put it in x.
   if (!root);
   // tree not empty
   HBLTNode<T> *L = root->LeftChild;
   HBLTNode<T> *R = root->RightChild;
   delete root;
   root = L;
   Meld(root,R);
   size--;
   return *this;


}


template<class T>
void MinHBLT<T>::Initialize(T a[], int n)

{// Initialize hblt with n elements.
   std::queue<HBLTNode<T> *> Q(n);
   Free(root);  // delete old nodes
   // initialize queue of trees
   for (int i = 1; i <= n; i++) {
      // create trees with one node each
      HBLTNode<T> *q = new HBLTNode<T> (a[i],1);
      Q.Add(q);
      }
   // repeatedly meld from queue
   HBLTNode<T> *b, *c;
   for (int i = 1; i <= n - 1; i++) {
      // delete and meld two trees
      Q.Delete(b).Delete(c);
      Meld(b,c);
      // put melded tree on queue
      Q.Add(b);
      }
   if (n) Q.Delete(root);

}

template <class T>
bool MinHBLT<T>::empty()
{
   if (size > 0)
   {
      return true;
   }else{
      return false;
   }
}