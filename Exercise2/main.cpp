#include <cmath>
#include <iostream>
#include <numeric> 
#include <iostream>
#include <sstream>
#include <chrono> 

#include "SortingAlgorithm.hpp"
using namespace std;
using namespace SortLibrary;

template<typename T>
string ArrayToString(const vector<T>& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (const T& e: v)
        toString << e << " ";
    toString << "]";

    return toString.str();
}

struct ClassObj{
    double value;
};

inline bool operator< (const ClassObj& lhs, const ClassObj& rhs) { return lhs.value < rhs.value; }


int main(int argc, char *argv[])
{
	size_t m = 5;
	cout << endl << "size of vectors: ";
	if (argc > 1)
	{
		istringstream convert(argv[1]);
		convert >> m;
		cout << m << endl;
	}
	else 
		cerr << m << "(default value)" << endl;
	
	// GENERAZIONE DI VETTORI
	//1° - vettore che parte da -5 e poi riempito con funzione iota
	vector<int> v1(m);
	iota(v1.begin(), v1.end(), -5);
	cout << "v1: " << ArrayToString(v1) << endl;
	
	// 2° - vettore di numeri casuali tra 0 e 10
	srand(2);
    vector<double> v2(m);
	for (size_t i = 0; i < m; i++)
		v2[i] = (rand() / ((double)RAND_MAX))*10.0;
    cout << "v2: " << ArrayToString(v2) << endl;
	
	// 3° - vettore la cui prima metà è uguale a v1, la seconda metà sono numeri interi 
	// 		casuali tra 0 w 1000
	vector<int> v3(m, 0);
	for (size_t i = floor(m*0.5) + 1; i < m; i++)
		v3[i] = rand()%1000;
	copy(v1.begin(), v1.begin() + floor(m * 0.5) + 1, v3.begin());
    cout << "v3: " << ArrayToString(v3) << endl;
	
	unsigned int num_experiment = 100;
	
	//BUBBLE SORT
	double time_elapsed_bubble_v1 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v1);

        chrono::steady_clock::time_point start_time = chrono::steady_clock::now();
        BubbleSort<int>(v);
        chrono::steady_clock::time_point end_time = chrono::steady_clock::now();
        time_elapsed_bubble_v1 += chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_bubble_v1 /= num_experiment;

    cout << "Bubble Sort - v1: " << time_elapsed_bubble_v1 << endl;

    double time_elapsed_bubble_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<double> v(v2);

        chrono::steady_clock::time_point start_time = chrono::steady_clock::now();
        BubbleSort<double>(v);
        chrono::steady_clock::time_point end_time = chrono::steady_clock::now();
        time_elapsed_bubble_v2 += chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_bubble_v2 /= num_experiment;

    cout << "Bubble Sort - v2: " << time_elapsed_bubble_v2 << endl;


    double time_elapsed_bubble_v3 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v3);

        chrono::steady_clock::time_point start_time = chrono::steady_clock::now();
        SortLibrary::BubbleSort<int>(v);
        chrono::steady_clock::time_point end_time = chrono::steady_clock::now();
        time_elapsed_bubble_v3 += chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_bubble_v3 /= num_experiment;

    cout << "Bubble Sort - v3: " << time_elapsed_bubble_v3 << endl;

    double time_elapsed_heap_v1 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v1);

        chrono::steady_clock::time_point start_time = chrono::steady_clock::now();
        SortLibrary::HeapSort<int>(v);
        chrono::steady_clock::time_point end_time = chrono::steady_clock::now();
        time_elapsed_heap_v1 += chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_heap_v1 /= num_experiment;

    cout << "Heap Sort - v1: " << time_elapsed_heap_v1 << endl;

    double time_elapsed_heap_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<double> v(v2);

        chrono::steady_clock::time_point start_time = chrono::steady_clock::now();
        SortLibrary::HeapSort<double>(v);
        chrono::steady_clock::time_point end_time = chrono::steady_clock::now();
        time_elapsed_heap_v2 += chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_heap_v2 /= num_experiment;

    cout << "Heap Sort - v2: " << time_elapsed_heap_v2 << endl;


    double time_elapsed_heap_v3 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v3);

        chrono::steady_clock::time_point start_time = chrono::steady_clock::now();
        SortLibrary::HeapSort<int>(v);
        chrono::steady_clock::time_point end_time = chrono::steady_clock::now();
        time_elapsed_heap_v3 += chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_heap_v3 /= num_experiment;

    cout << "Heap Sort - v3: " << time_elapsed_heap_v3 << endl;
    return 0;
}

