#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>

using namespace std;


template <class T>
class Min_heap
{

private:

public:
	Min_heap(int num_elements);
	~Min_heap();
	void build_minheap();
	void push(int element);
	void min_heapify(int i);
	void pop_t();
    void pop_b();
	void print_heap();
	int get_size(){ return size; };
    int top_t(){ return heap_array[1]; };
    int top_b(){ return heap_array[size-1]; };
	bool empty();
	int size;
	int *heap_array;
	int num_elm;
};

template <class T>
Min_heap<T>::Min_heap(int num_elements)
{
	heap_array = new int[num_elements];
	num_elm = num_elements;
	size = 1;
}

template <class T>
Min_heap<T>::~Min_heap(){
    //delete heap_array;
}

template <class T>
void Min_heap<T>::build_minheap()
{

    for(int i = size/2; i >= 1; i--)
    {
        min_heapify(i);
    }
}

template <class T>
void Min_heap<T>::min_heapify(int i)
{
    sort(heap_array, heap_array + size);
    
    /*
    int j, temp;
    temp = heap_array[i];
    j = 2 * i;
    while (j <= num_elm)
    {
        if (j < num_elm && heap_array[j+1] < heap_array[j])
            j = j + 1;
        if (temp < heap_array[j])
            break;
        else if (temp >= heap_array[j])
        {
            heap_array[j/2] = heap_array[j];
            j = 2 * j;
        }
    }
    heap_array[j/2] = temp;
    return;
    */
    
    
}

template <class T>
void Min_heap<T>::push(int element){
	heap_array[size] = element;
	size++;
}

template <class T>
void Min_heap<T>::pop_t()
{
    for(int i = 1; i <= size; i++)
    {
        heap_array[i] = heap_array[i+1];
    }
    size--;
}

template <class T>
void Min_heap<T>::pop_b()
{
    size--;
}

template <class T>
void Min_heap<T>::print_heap(){

	cout<<"Min Heap\n";
	for (int i = 1; i < size; i++)
    {
        cout << heap_array[i] << endl;
    }

}

template <class T>
bool Min_heap<T>::empty()
{
	if (size > 1)
	{
		return true;
	}else{
		return false;
	}
}
