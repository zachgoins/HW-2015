#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>

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
    int top(){ return heap_array[1]; };
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
    //delete heap_array;
}

void Min_heap::build_minheap()
{

    for(int i = size/2; i >= 1; --i)
    {
        min_heapify(i);
    }
}

void Min_heap::min_heapify(int i)
{
    sort(heap_array, heap_array + size);
    
    
    int j, temp;
    temp = heap_array[i];
    j = 2 * i;
    while (j <= num_elm)
    {
        if (j < num_elm && heap_array[j] < heap_array[j+1])
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
    print heap_array[i/2]
    return;
    
}

void Min_heap::push(int element){
	heap_array[size] = element;
	size++;
}

void Min_heap::pop()
{
    for(int i = 1; i <= size; i++)
    {
        heap_array[i] = heap_array[i+1];
    }
    size--;
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
	if (size > 1)
	{
		return true;
	}else{
		return false;
	}
}

int main(int argc, char** argv)
{

    clock_t start;
    double duration;
    start = clock();

	

	int num_elements, num_machine, x;

    /*

    cout << "Enter number of jobs\n";
    cin >> num_elements;
    cout << "Enter number of machines\n";
    cin >> num_machine;

    Min_heap min_heap(num_elements);

    for (int i = 1; i <= num_elements; i++)
    {
        int input;
        cout << "Enter element " << (i) << endl;
        cin >> input;
        min_heap.push(input);
    }
    */
    
    num_elements = 7;
    num_machine = 3;
    Min_heap min_heap(num_elements);
    min_heap.push(3);
    min_heap.push(10);
    min_heap.push(1);
    min_heap.push(11);
    min_heap.push(13);
    min_heap.push(17);
    min_heap.push(6);
    

    min_heap.build_minheap();
    min_heap.print_heap();



    /*

    int index = 1;
    while(min_heap.empty() != false)
    {
        cout << "Machine " << index << ": ";
        for (int i = 1; i <= num_machine; i++)
        {
            if (min_heap.empty() == false){ break; };
            int temp = min_heap.top();
            cout << temp << ", ";
            min_heap.pop();
        }
        cout << endl;
        index++;
    }
    */



    

    duration = (clock() - start ) / (double) CLOCKS_PER_SEC;

    cout<<"Time Elapsed: "<< duration <<'\n';

}



