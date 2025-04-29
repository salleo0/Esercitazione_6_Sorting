#pragma once

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

namespace SortLibrary {
template<typename T>
concept Sortable = requires(T& t) {
	{t < t} -> convertible_to<bool>;
};

template<Sortable T>
void BubbleSort(vector<T>& v)
{
	const unsigned int n = v.size();
	
	for (unsigned int i = 0; i < n - 1; i++)
		for (unsigned int j = i + 1; j < n; j++)
			if (v[j] < v[i])
				swap(v[i], v[j]);
}

template<Sortable T>
void HeapSort(vector<T>& v)
{
	const unsigned int n = v.size();

	vector<T> heap;
	heap.reserve(n);
	
	// 	ENQUEUE
	for (const T& e : v)
	{
		heap.push_back(e);
		unsigned int current_knot = heap.size()-1;
		while(current_knot > 0)
		{
			unsigned int parent_knot = (current_knot - 1) / 2;
			
			if(heap[current_knot] > heap[parent_knot])
			{
				swap(heap[current_knot], heap[parent_knot]);
				current_knot = parent_knot;
			}
			else
				break;
		}
	}
	
	unsigned int heap_size = heap.size();
	
	// DEQUEUE
	while(heap_size > 0)
	{
		v[heap_size-1] = heap[0];
		swap(heap[0], heap[heap_size-1]);
		heap_size--;
		
		unsigned int current_knot = 0;
		while(true)
		{
			unsigned int right_knot = 2*current_knot + 2;
			unsigned int left_knot = 2*current_knot + 1;
			unsigned int largest_knot = current_knot;
			
			if(left_knot < heap_size && heap[left_knot] > heap[largest_knot])
				largest_knot = left_knot;
			
			if(right_knot < heap_size && heap[right_knot] > heap[largest_knot])
				largest_knot = right_knot;
			
			if (largest_knot != current_knot)
			{
				swap(heap[current_knot], heap[largest_knot]);
				current_knot = largest_knot;
			}
			else
				break;
		}
	}
}

}

template<typename T>
void swap(T& a, T& b) 
{
	T tmp = a;
	a = b;
	b = a;
}
