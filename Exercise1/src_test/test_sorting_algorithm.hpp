#pragma once

#include <iostream>
#include <vector>

#include <gtest/gtest.h>
#include "SortingAlgorithm.hpp"

// https://google.github.io/googletest/

namespace SortLibrary {

TEST(TestSorting, TestSelectionSort)
{
    std::vector<int> v = {9, 13, 5, 10, 2, 7, 9, 4, 6, 12};
    SelectionSort<int>(v);
    std::vector<int> sortedV = {2, 4, 5, 6, 7, 9, 9, 10, 12 ,13};
    ASSERT_EQ(v, sortedV); // prova con EXPECT_EQ: cosa cambia?
}

TEST(TestSorting, TestInsertionSort)
{
    std::vector<int> v = {9, 13, 5, 10, 2, 7, 9, 4, 6, 12};
    InsertionSort<int>(v);
    std::vector<int> sortedV = {2, 4, 5, 6, 7, 9, 9, 10, 12 ,13};
    ASSERT_EQ(v, sortedV);
}

}
