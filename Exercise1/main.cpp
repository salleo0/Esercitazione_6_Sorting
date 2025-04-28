#include <cmath> // contiene floor
#include <iostream>
#include <numeric> // contiene iota
#include <iostream>
#include <sstream>
#include <chrono> // https://en.cppreference.com/w/cpp/chrono

#include "SortingAlgorithm.hpp"
using namespace std;

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

    // bool operator< (const ClassObj& rhs) { return value < rhs.value; }
};

inline bool operator< (const ClassObj& lhs, const ClassObj& rhs) { return lhs.value < rhs.value; }

int main(int argc, char *argv[])
{
	
	cout << "argc: " << argc << endl;
	for (int a = 0; a < argc; a++) 
		cout << argv[a] << " ";
	cout << endl;
	
    size_t m = 10;
	if (argc > 1)
	{
		istringstream convert(argv[1]);
		convert >> m;
		cout << "use value: " << m << endl;
	}
	else 
		cerr << "use default value: " << m << endl;
	
	// GENERAZIONE DI VETTORI
	vector<int> v1(m);
	iota(v1.begin(), v1.end(), -4);	// vettore che parte da -4 e aumenta di 1 fino a riempire tutti gli m posti
    cout << "v1: " << ArrayToString(v1) << endl;
	
	srand(2);
    vector<double> v2(m);
	for (size_t i = 0; i < m; i++)
		v2[i] = rand() / ((double)RAND_MAX);
    cout << "v2: " << ArrayToString(v2) << endl;

    vector<int> v3(m, 0);
	for (size_t i = floor(m*0.5) + 1; i < m; i++)
		v3[i] = rand()%1000;
	copy(v1.begin(), v1.begin() + floor(m * 0.5) + 1, v3.begin());
    cout << "v3: " << ArrayToString(v3) << endl;
	
	// https://www.epochconverter.com/
	const auto today_time = chrono::system_clock::now();
	cout << "Tempo trascorso dal 1 gennaio 1970: "	
		 << chrono::duration_cast<chrono::milliseconds>(today_time.time_since_epoch()).count() << endl;


    unsigned int num_experiment = 100;
	
	// Try commenting out the overloading of the "<" operator and uncommenting the two lines below:
    // an error will be reported because ClassObj is not "Sortable"

    // vector<ClassObj> v;
    // SortLibrary::SelectionSort<ClassObj>(v); // ATTENZIONE: il vettore è non inizializzato -> non eseguire

    double time_elapsed_selection_v1 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v1);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::SelectionSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_selection_v1 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_selection_v1 /= num_experiment;

    cout << "Selection Sort - v1: " << time_elapsed_selection_v1 << endl;

    double time_elapsed_selection_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<double> v(v2);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::SelectionSort<double>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_selection_v2 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_selection_v2 /= num_experiment;

    cout << "Selection Sort - v2: " << time_elapsed_selection_v2 << endl;


    double time_elapsed_selection_v3 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v3);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::SelectionSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_selection_v3 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_selection_v3 /= num_experiment;

    cout << "Selection Sort - v3: " << time_elapsed_selection_v3 << endl;

    double time_elapsed_insertion_v1 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v1);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::InsertionSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_insertion_v1 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_insertion_v1 /= num_experiment;

    cout << "Insertion Sort - v1: " << time_elapsed_insertion_v1 << endl;

    double time_elapsed_insertion_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<double> v(v2);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::InsertionSort<double>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_insertion_v2 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_insertion_v2 /= num_experiment;

    cout << "Insertion Sort - v2: " << time_elapsed_insertion_v2 << endl;


    double time_elapsed_insertion_v3 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v3);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::InsertionSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_insertion_v3 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_insertion_v3 /= num_experiment;

    cout << "Insertion Sort - v3: " << time_elapsed_insertion_v3 << endl;


    return 0;
}

