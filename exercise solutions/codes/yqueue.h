// header file dqueue.h

#ifndef LinkedQueue_
#define LinkedQueue_

template <class type>
class Node {
public:
   type data;
   Node<type> *link;
};

template<class type>
class LinkedQueue
{// FIFO objects
public:
   LinkedQueue() {front = rear = 0;} // constructor
   ~LinkedQueue(); // destructor
   int IsEmpty()
      {return ((front) ? 0 : 1);}
   int IsFull();
   int First(type& x); // return first element of queue in x
   int Last(type& x); // return last element of queue in x
   int Add(const type& x); // add x to queue
   int Delete(type& x); // delete x from queue
   int Size();
   int Input();
   void Output();
protected:
   Node<type> *front, *rear;
};

template<class type>
LinkedQueue<type>::~LinkedQueue()
{
Node<type> *i;
while (front) {i = front->link; delete front; front = i;}
}

template<class type>
int LinkedQueue<type>::IsFull()
{
Node<type> *i;
i = new Node<type>;
if (i) {delete i; return 0;};
return 1;
}

template<class type>
int LinkedQueue<type>::First(type& x)
{//set x to first element
if (IsEmpty()) return 0; //First fails
x = front->data;
return 1;
}

template<class type>
int LinkedQueue<type>::Last(type& x)
{//set x to last element
if (IsEmpty()) return 0; //Last fails
x = rear->data;
return 1;
}

template<class type>
int LinkedQueue<type>::Add(const type& x)
{//add x to queue
Node<type> *i;
i = new Node<type>;
if (i) {
     i->data = x; i->link = 0;
     if (front) rear->link = i;
     else front = i;
     rear = i; return 1;
        };
return 0; // add fails 
}

template<class type>
int LinkedQueue<type>::Delete(type& x)
{//delete first element and put it in x
if (IsEmpty()) return 0; //delete fails
x = front->data;
Node<type> *i = front;
front = front->link;
delete i;
return 1;
}

template<class type>
int LinkedQueue<type>::Size()
{int i = 0;
Node<type> *x = front;
while (x) {x = x->link; i++;}
return i;
}


template<class type>
int LinkedQueue<type>::Input()
{
//empty out the queue
type x;
while (!IsEmpty()) Delete(x);
int length;
cout << "Enter size of queue" << endl;
cin >> length;
cout << "Enter the elements front-to-rear" << endl;
for (int i = 0; i < length ; i++) {
   cin >> x;
   if (!Add(x)) return 0;
   }
return 1;
}

template<class type>
void LinkedQueue<type>::Output()
{
cout << "The queue has " << Size() << " element(s)" << endl;
cout << "The element(s) front-to-rear are" << endl;
for (Node<type> *i = front; i ; i = i->link)
   cout << i->data << ' ';
cout << endl;
}

#endif
