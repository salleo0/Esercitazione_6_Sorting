#pragma once

#include <iostream>
#include <vector>

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
			{
				// swap 
				T tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}			
}

}


