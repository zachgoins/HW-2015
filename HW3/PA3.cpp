
#include "min_tree.cpp"
#include "min_heap.cpp"

int main(int argc, char** argv)
{

    clock_t start;
    double duration;
	int num_elements, num_machine, x, schedule_time;

    /*

    cout << "Enter number of jobs\n";
    cin >> num_elements;
    cout << "Enter number of machines\n";
    cin >> num_machine;

    int priority_array[num_machine][num_elements];
    Min_heap<int> min_heap(num_elements);
    MinHBLT<int> leftist_tree;

    for (int i = 1; i <= num_elements; i++)
    {
        int input;
        cout << "Enter element " << (i) << endl;
        cin >> input;
        min_heap.push(input);
        leftist_tree.Insert(input);
    }
    */
    
    num_elements = 7;
    num_machine = 3;
    int priority_array[num_machine][num_elements];
    Min_heap<int> min_heap(num_elements);
    MinHBLT<int> leftist_tree;


    min_heap.push(2);
    min_heap.push(3);
    min_heap.push(5);
    min_heap.push(6);
    min_heap.push(7);
    min_heap.push(10);
    min_heap.push(14);
    leftist_tree.Insert(2);
    leftist_tree.Insert(3);
    leftist_tree.Insert(5);
    leftist_tree.Insert(6);
    leftist_tree.Insert(7);
    leftist_tree.Insert(10);
    leftist_tree.Insert(14);

    min_heap.build_minheap();
    schedule_time = min_heap.top_t() + min_heap.top_b();
    int leftover = num_elements % num_machine;

    // -------------------------------------------------------------------------------


    start = clock();
    int index = 0;
    int count = 0;
    while(min_heap.empty() != false)
    {
        if (min_heap.empty() == false){ break; };
        for (int i = 0; i < num_machine; i++)
        {
            if (min_heap.empty() == false)
            {
                priority_array[i][index] = 0;
            }else {
                priority_array[i][index] = min_heap.top_t();
                cout << min_heap.top_t();
                min_heap.pop_t();
                count++;
            }
        }
        index++;
    }

    cout << "Min Heap Finishing Time: " << schedule_time << endl;
    for (int i = 0; i < num_machine; i++)
    {
        cout << "Machine " << i + 1 << ": ";
        for (int j = 0; j < index; j++)
        {
            if (priority_array[i][j] != 0)
            {
                cout << priority_array[i][j] << ", ";
            }
        }
        cout << endl;
    }
    
    duration = (clock() - start ) / (double) CLOCKS_PER_SEC;

    cout<<"Time Elapsed: "<< duration << endl << endl;

    // -------------------------------------------------------------------------------

    start = clock();
    index = 0;
    while(leftist_tree.empty() != false)
    {
        if (leftist_tree.empty() == false){ break; };
        for (int i = 0; i < num_machine; i++)
        {
            if (leftist_tree.empty() == false)
            {
                priority_array[i][index] = 0;
            }else {
                priority_array[i][index] = leftist_tree.top();
                leftist_tree.pop();
            }
        }
        index++;
    }

    cout << "Height Biased Leftist Tree Finishing Time: " << schedule_time << endl;
    for (int i = 0; i < num_machine; i++)
    {
        cout << "Machine " << i + 1 << ": ";
        for (int j = 0; j < index; j++)
        {
            if (priority_array[i][j] != 0)
            {
                cout << priority_array[i][j] << ", ";
            }
        }
        cout << endl;
    }
    
    duration = (clock() - start ) / (double) CLOCKS_PER_SEC;

    cout<<"Time Elapsed: "<< duration << endl;

}



