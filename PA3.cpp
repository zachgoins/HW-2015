#include <iostream>
#include <cmath>

using namespace std;

class Min_heap
{

private:

public:
	Min_heap(int num_elements);
	~Min_heap();
	void build_minheap();
	void push(int element);
	void min_heapify(int i);
	void pop();
	void print_heap();
	int get_size(){ return size; };
	bool empty();
	int size;
	int *heap_array;
	int num_elm;
};

Min_heap::Min_heap(int num_elements)
{
	heap_array = new int[num_elements];
	num_elm = num_elements;
	size = 1;
}

Min_heap::~Min_heap(){

}

void Min_heap::build_minheap()
{

    for(int i = num_elm/2; i >= 1; i--)
    {
        min_heapify(i);
    }
}

void Min_heap::min_heapify(int i)
{
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


    cout << i << endl;
    }
    heap_array[j/2] = temp;
    return;
}

void Min_heap::push(int element){
	heap_array[size] = element;
	size++;
}

void Min_heap::pop()
{
    for(int i = 0; i <= size; i++)
    {
        heap_array[i] = heap_array[i+1];
    }

    size--;

    for(int i = size/2; i > 1; i--)
    {
        min_heapify(i);
    }
}

void Min_heap::print_heap(){

	cout<<"Min Heap\n";
	for (int i = 1; i < size; i++)
    {
        cout << heap_array[i] << endl;
    }

}

bool Min_heap::empty()
{
	if (size > 0)
	{
		return true;
	}else{
		return false;
	}
}

int main(int argc, char** argv)
{
	

	int num_elements, num_machine, x;

    cout << "enter number of jobs\n";
    cin >> num_elements;
    cout << "enter number of machines\n";
    cin >> num_machine;

    Min_heap min_heap(num_elements);

    /*

    for (int i = 1; i <= num_elements; i++)
    {
    	int input;
        cout << "Enter element " << (i) << endl;
        cin >> input;
        min_heap.push(input);
    }

    */

    min_heap.push(14);
    min_heap.push(7);
    min_heap.push(10);
    min_heap.push(6);
    min_heap.push(2);
    min_heap.push(3);
    min_heap.push(5);




    min_heap.build_minheap();
    min_heap.print_heap();


    


}



