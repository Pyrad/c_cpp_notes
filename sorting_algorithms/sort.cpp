//============================================================================
// Name        : SortingAlgorithms.cpp
// Author      : Pyrad
// Time		   : Jan. 18 PM, 2016
// Version     : Ver 1.0
// Copyright   : Copyright reserved by Pyrad
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <utility>
#include <stdio.h>
#include <mem.h>
#include <malloc.h>
#include <math.h>
using namespace std;


// Some auxiliary functions
bool findMaxInArray(int* pArray, int size, int& res) {
	if(!pArray || size <= 0)
		return false;
	res = pArray[0];
	for(int i = 0; i < size; i++) {
		if(pArray[i] > res)
			res = pArray[i];
	}
	return true;
}
int getTotalDigits(int num) {
	int i = 1;
	while(num /= 10)
		i++;
	return i;
}

// C Style
void print_array(int* pArray, int size, bool newLineEnd = true) {
	if(!pArray || size <= 0)
		return ;
	for(int i = 0; i < size; i++)
		printf("%d ", pArray[i]);
	if(newLineEnd)
		printf("\n");
	else
		printf("\t");

	return ;
}

// C++ Style
template < unsigned int N >
void print_array(int(& pArray)[N], bool newLineEnd = true) {

	if(!pArray) {
		printf("Empty array! Can't print!\n");
		return ;
	}

	// Calculate array length
	// int aLen = sizeof(pArray) / sizeof(pArray[0]);
	for(unsigned int i = 0; i < N; i++) {
		printf("%d ", pArray[i]);
	}
	if(newLineEnd)
		printf("\n");
	else
		printf("\t");

	return ;
}


//----------------------------------------------------------------------------
// Various Functions of Sorting Algorithms --> Ascending Order for Example
//----------------------------------------------------------------------------

/**************************/
/***** 1. Bubble Sort *****/
/**************************/
void BubbleSort(int* pArray, int size) {

	int temp;

	for(int i = 1; i < size; i++) {
		for(int j = size - 1; j >= i; j--) {
			if( pArray[j] < pArray[j-1] ) {
				temp = pArray[j - 1];
				pArray[j - 1] = pArray[j];
				pArray[j] = temp;
			}
		}
	}

	return ;
}

/****************************/
/***** 2. Exchange Sort *****/
/****************************/
// Nearly same as 'Bubble Sort'
void ExchangeSort(int* pArray, int size) {
	int temp;
	for(int i = 0; i < size -1; i++) {
		for(int j = i + 1; j < size; j++) {
			if( pArray[j] < pArray[i] ) {
				temp = pArray[i];
				pArray[i] = pArray[j];
				pArray[j] = temp;
			}
		}
	}

	return ;
}

/*****************************/
/***** 3. Selection Sort *****/
/*****************************/
void SelectionSort(int* pArray, int size) {

	int temp;
	int pos;
	for(int i = 0; i < size - 1; i++) {
		temp = pArray[i];
		pos = i;
		for(int j = i + 1; j < size; j++) {
			if(pArray[j] < temp) {
				temp = pArray[j];
				pos = j;
			}
		}
		pArray[pos] = pArray[i];
		pArray[i] = temp;
	}

	return ;
}

/*****************************/
/***** 4. Insertion Sort *****/
/*****************************/
void InsertionSort(int* pArray, int size) {
	int temp;
	int pos;
	for(int i = 1; i < size; i++) {
		temp = pArray[i];
		pos = i - 1;
		while( (pos >= 0) && (temp < pArray[pos]) ) {
			pArray[pos+1] = pArray[pos];
			pos--;
		}
		pArray[pos+1] = temp;
	}

	return ;
}

/*************************/
/***** 5. Merge Sort *****/
/*************************/
void Merge(int* pArray, int first, int mid, int last, int* pTemp) {

	int pos1 = first;
	int pos2 = mid + 1;

	int i = 0;
	for(i = 0; pos1 <= mid && pos2 <= last; i++) {
		if(pArray[pos1] < pArray[pos2]) {
			pTemp[i] = pArray[pos1];
			pos1++;
		} else {
			pTemp[i] = pArray[pos2];
			pos2++;
		}
	}

#if 1
	// Use memcpy instead of while loop
	if(pos1 <= mid ) {
		memcpy(pTemp + i, pArray + pos1, (mid - pos1 + 1)*sizeof(pArray[pos1]));
	}
	if(pos2 <= last) {
		memcpy(pTemp + i, pArray + pos2, (last - pos2 + 1)*sizeof(pArray[pos2]));
	}
	memcpy(pArray + first, pTemp, (last - first + 1)*sizeof(pTemp[0]));
#else
	while(pos1 <= mid) {
		pTemp[i++] = pArray[pos1++];
	}
	while(pos2 <= last) {
		pTemp[i++] = pArray[pos2++];
	}
	for(i = 0; i < last - first + 1; i++) {
		pArray[first + i] = pTemp[i];
	}
#endif

	return ;
}

void MergeSort(int* pArray, int first, int last, int* pTemp) {
	int mid;

	if(first < last) {
		mid = (first + last) / 2;
		MergeSort(pArray, first, mid, pTemp);
		MergeSort(pArray, mid+1, last, pTemp);
		Merge(pArray, first, mid, last, pTemp);
	}

	return ;
}

/*************************/
/***** 6. Quick Sort *****/
/*************************/

void QuickSort(int* pArray, int left, int right) {

	if(left < right) {
		int i = left;
		int j = right;
		int pivot = pArray[left]; //Also could use pArray[(left+right)/2] as pivot

		while(i < j) {
			while( i < j && pArray[j] >= pivot)
				j--;
			if(i < j)
				pArray[i++] = pArray[j];
			while( i < j && pArray[i] < pivot)
				i++;
			if(i < j)
				pArray[j--] = pArray[i];
		}
		pArray[i] = pivot; // Actually now i == j, so could also use pArray[j] = pivot instead
		QuickSort(pArray, left, i - 1);
		QuickSort(pArray, i + 1, right);
	}

	return ;
}

/************************/
/***** 7. Heap Sort *****/
/************************/

// For min heap, aka for ascending order use in heap sort
void shift_down(int* pArray, int left, int right) {
	int jOld = left;
	int a = pArray[left];
	int j = 2 * left + 1;

	while(j <= right) {
		if( j < right && pArray[j] < pArray[j+1])
			j++;
		if( a >= pArray[j])
			break;
		pArray[jOld] = pArray[j];
		jOld = j;
		j = 2 * j + 1;
	}
	pArray[jOld] = a;
}

void shift_up(int* pArray, int left, int right) {
	int jOld = left;
	int a = pArray[left];
	int j = 2 * left + 1;
	while(j <= right) {
		if( j < right && pArray[j] > pArray[j+1])
			j++;
		if( a <= pArray[j])
			break;
		pArray[jOld] = pArray[j];
		jOld = j;
		j = 2 * j + 1;
	}
	pArray[jOld] = a;
}

void HeapSort(int* pArray, int size) {
	//int temp;
	// Create min heap
	for(int i = size/2 - 1; i >= 0; i--) // Make heap, reverse order from 0 <= i <= size/2 -1
		shift_down(pArray, i, size - 1);
	// Then shift down many times
	for(int i = size - 1; i > 0; i--) { // Adjust, reverse order from 1 <= i <= size - 1
		std::swap(pArray[0], pArray[i]);
		shift_down(pArray, 0, i - 1);
	}
}

/*************************/
/***** 8. Shell Sort *****/
/*************************/

// Concise version while hard to understand at first glance
void ShellSort(int* pArray, int size) {
	int i, j, gap;
	for(gap = size / 2; gap > 0; gap /= 2)
		for(i = gap; i < size; i++)
			for(j = i - gap; j >= 0 && pArray[j] > pArray[j + gap]; j -= gap)
				std::swap(pArray[j], pArray[j + gap]);
}

// According to concept strictly, easy to understand
void ShellSortSimple(int* pArray, int size) {
	int i, j, gap, temp, k;
	for( gap = size / 2; gap > 0; gap /= 2)
		for( i = 0; i < gap; i++) {
			for( j = i + gap; j < size; j += gap)
				if( pArray[j] < pArray[j - gap]) {
					temp = pArray[j];
					k = j - gap;
					while( k >= 0 && pArray[k] > temp) {
						pArray[k + gap] = pArray[k];
						k -= gap;
					}
					pArray[k + gap] = temp;
				}
		}
}
#if 0
// Simplified shell sort according to concept, derived from ShellSortSimple
void ShellSortSimple2(int* pArray, int size) {
	int j, gap, temp, k;
	for(gap = size / 2; gap > 0; gap /= 2)
		for(j = gap; j < size; j++)
			if(pArray[j] < pArray[j - gap]) {
				temp = pArray[j];
				k = j - gap;
				while(k >= 0 && pArray[k] > temp) {
					pArray[k + temp] = pArray[k];
					k -= gap;
				}
				pArray[k + gap] = temp;
			}
}
#endif

/****************************/
/***** 9. Cocktail Sort *****/
/****************************/
void CocktailSort(int* pArray, int size) {
	int i;
	int left = 1;
	int right = size - 1;
	int t = 0;

	do {
		for(i = right; i >= left; i--) {
			if(pArray[i] < pArray[i-1]) {
				std::swap(pArray[i], pArray[i-1]);
				t = i;
			}
		}
		left = t + 1;
		for(i = left; i <= right; i++) {
			if(pArray[i] < pArray[i-1]) {
				std::swap(pArray[i], pArray[i-1]);
				t = i;
			}
		}
		right = t - 1;
	} while(left <= right);

	return ;
}

/**************************/
/***** 10. Count Sort *****/
/**************************/
void CountSort(int* pArray, int size) {
	int i, j;
	int min = pArray[0];
	int max = pArray[0];
	for(i = 1; i < size; i++) {
		if(pArray[i] < min)
			min = pArray[i];
		else if(pArray[i] > max)
			max = pArray[i];
	}
	int range = max - min + 1;
	int* pTemp = new int[range];
	memset(pTemp, 0, range * sizeof(int));
	for(i = 0; i < size; i++)
		pTemp[pArray[i] - min]++;
	int k = 0;
	for(i = min; i <= max; i++)
		for(j = 0; j < pTemp[i - min]; j++)
			pArray[k++] = i;
	delete pTemp;

	return ;
}

/*********************************/
/***** 11. Bucket/Radix Sort *****/
/*********************************/
int GetDigit(int x,int d) {
    int a[] = {1, 1, 10, 100, 1000, 10000};
    return (x/a[d]) % 10;
}

void RadixSortLSD(int* pArray, int begin, int end, int maxDigits) {
    const int radix = 10;
    int count[radix], i, j;

    int* bucket = new int[end - begin + 1]; //int *bucket = (int*)malloc((end-begin+1)*sizeof(int));

    for(int k = 1; k <= maxDigits; ++k) {
        memset(count, 0, radix * sizeof(int));
        for(i = begin; i <= end; i++)
        	count[GetDigit(pArray[i], k)]++;
        for(i = 1; i < radix; i++)
        	count[i] = count[i] + count[i-1];
        for(i = end;i >= begin; --i) {
            j = GetDigit(pArray[i], k);
            bucket[count[j]-1] = pArray[i];
            --count[j];
        }
        memcpy(pArray, bucket, (end - begin + 1) * sizeof(int));
    }
    delete bucket; //free(bucket);
}

void RadixSortLSD2(int* pArray, int size, int maxDigits) {
    const int base = 10;
    int arCountSort[base];
    int* pTemp = new int[size];
    int i, j;
    int t = 1;
    for(i = 0; i < maxDigits; ++i)
    {
        memset(arCountSort, 0, sizeof(int) * base);
        for(j = 0; j < size; ++j)
            arCountSort[pArray[j] / t % base]++;
        for(j = 1; j < 10; ++j)
            arCountSort[j] += arCountSort[j - 1];
        for(j = size-1; j >= 0; --j) {
            int splitDigit = pArray[j]/t%base;
            pTemp[ arCountSort[splitDigit] - 1 ] = pArray[j];
            arCountSort[splitDigit]--;
        }
        memcpy_s(pArray, sizeof(int) * size, pTemp, sizeof(int) * size);
        t *= base;
    }
}

// MSD
void RadixSortMSDGut(int* pArray, int index, int size, int maxDigits) {
    if(size <= 1 || maxDigits <= 0)
        return;
    const int base = 10;
    int arCountSort[base];
    int arCountSortTemp[base];
    int* pTemp = new int[size];
    int i;
    int t = (int)pow((float)base, maxDigits-1);

    memset(arCountSort, 0, sizeof(int) * base);
    for(i = index; i < index + size; ++i)
        arCountSort[ pArray[i] / t % base ]++;
    memcpy_s(arCountSortTemp, sizeof(int)*base, arCountSort, sizeof(int)*base);
    for(i = 1; i < base; ++i)
        arCountSort[i] += arCountSort[i-1];
    for(i = 0; i < base; ++i)
        arCountSort[i] -= arCountSortTemp[i];
    for(i = index; i < index + size; ++i) {
        int splitDigit = pArray[i] / t % base;
        pTemp[ arCountSort[splitDigit] ] = pArray[i];
        arCountSort[splitDigit]++;
    }
    memcpy_s(pArray + index, sizeof(int) * size, pTemp, sizeof(int) * size);
    RadixSortMSDGut(pArray, index, arCountSort[0], maxDigits-1);
    for(i = 1; i < base; ++i)
        RadixSortMSDGut(pArray, index + arCountSort[i-1], arCountSort[i] - arCountSort[i-1], maxDigits-1);
    delete pTemp;
}

void RadixSortMSD(int* pArray, int size, int maxDigits) {
	RadixSortMSDGut(pArray, 0, size, maxDigits);

	return ;
}

#if 0
// MSD solution has some issue so comment it out
void RadixSortMSD(int arr[],int begin,int end,int maxDigits)
{
	printf("[DIGITS NOW] %d\n", maxDigits);
    const int radix = 10;
    int count[radix], i, j;
    for(i = 0; i < radix; ++i)
        count[i] = 0;
    int *bucket = (int *) malloc((end-begin+1) * sizeof(int));
    for(i = begin;i <= end; ++i)
        count[GetDigit(arr[i], maxDigits)]++;
    for(i = 1; i < radix; ++i)
        count[i] = count[i] + count[i-1];
    for(i = end;i >= begin; --i) {
        j = GetDigit(arr[i], maxDigits);
        bucket[count[j]-1] = arr[i];
        --count[j];
    }
    for(i = begin, j = 0;i <= end; ++i, ++j)
        arr[i] = bucket[j];
    free(bucket);
    for(i = 0; i < radix; i++) {
        int p1 = begin + count[i];
        int p2 = begin + count[i+1]-1;
        if(p1 < p2 && maxDigits > 1)
        	RadixSortMSD(arr, p1, p2, maxDigits-1);
    }
}
#endif // 0


//----------------------------------------------------------------------------
//----------------------------------------------------------------------------



//int array[]= {8, 4, 6, 5, 2, 1, 2, 3, 9, 7, 8, 0, 9, 2, 6};
int array[] = {432, 456, 11, 96, 120, 121, 11, 90, 589, 998, 20, 80, 965, 852, 123, 456, 789};

int main() {

	const unsigned int len = sizeof(array) / sizeof(array[0]);

	int counter = 0; // Just a counter for how many algorithms here
	int* testarray = new int[len];

	printf("---Start of sorting---\n\n");
	//--------------------------------------------------------------------

	memcpy(testarray, array, sizeof(array));
	printf("[%2d]Bubble Sort:\t", ++counter);
	print_array(testarray, len, false/*No new line at the end*/);
	BubbleSort(testarray, len);
	printf("After sorting:\t");
	print_array(testarray, len);

	memcpy(testarray, array, sizeof(array));
	printf("[%2d]Exchange Sort:\t", ++counter);
	print_array(testarray, len, false/*No new line at the end*/);
	ExchangeSort(testarray, len);
	printf("After sorting:\t");
	print_array(testarray, len);

	memcpy(testarray, array, sizeof(array));
	printf("[%2d]Selection Sort:\t", ++counter);
	print_array(testarray, len, false/*No new line at the end*/);
	SelectionSort(testarray, len);
	printf("After sorting:\t");
	print_array(testarray, len);

	memcpy(testarray, array, sizeof(array));
	printf("[%2d]Insertion Sort:\t", ++counter);
	print_array(testarray, len, false/*No new line at the end*/);
	InsertionSort(testarray, len);
	printf("After sorting:\t");
	print_array(testarray, len);

	memcpy(testarray, array, sizeof(array));
	printf("[%2d]Merge Sort:\t\t", ++counter);
	print_array(testarray, len, false/*No new line at the end*/);
	int* pArrayTemp = new int[len];
	MergeSort(testarray, 0, len - 1, pArrayTemp);
	printf("After sorting:\t");
	print_array(testarray, len);
	delete pArrayTemp;

	memcpy(testarray, array, sizeof(array));
	printf("[%2d]Quick Sort:\t\t", ++counter);
	print_array(testarray, len, false/*No new line at the end*/);
	QuickSort(testarray, 0, len - 1);
	printf("After sorting:\t");
	print_array(testarray, len);

	memcpy(testarray, array, sizeof(array));
	printf("[%2d]Heap Sort:\t\t", ++counter);
	print_array(testarray, len, false/*No new line at the end*/);
	HeapSort(testarray, len);
	printf("After sorting:\t");
	print_array(testarray, len);

	memcpy(testarray, array, sizeof(array));
	printf("[%2d]Shell Sort:\t\t", ++counter);
	print_array(testarray, len, false/*No new line at the end*/);
	ShellSort(testarray, len);
	printf("After sorting:\t");
	print_array(testarray, len);

	memcpy(testarray, array, sizeof(array));
	printf("[%2d]Cocktail Sort:\t", ++counter);
	print_array(testarray, len, false/*No new line at the end*/);
	CocktailSort(testarray, len);
	printf("After sorting:\t");
	print_array(testarray, len);

	memcpy(testarray, array, sizeof(array));
	printf("[%2d]Count Sort:\t\t", ++counter);
	print_array(testarray, len, false/*No new line at the end*/);
	CountSort(testarray, len);
	printf("After sorting:\t");
	print_array(testarray, len);

	memcpy(testarray, array, sizeof(array));
	printf("[%2d]RadixSortLSD:\t", ++counter);
	print_array(testarray, len, false/*No new line at the end*/);
	int res_lsd = 0;
	if(findMaxInArray(testarray, len, res_lsd)) {
		int d = getTotalDigits(res_lsd);
		RadixSortLSD(testarray, 0, len - 1, d);
		// RadixSortLSD2(testarray, len, d);
		printf("After sorting:\t");
		print_array(testarray, len, false);
		printf("(Got max result: %d", res_lsd);
		printf(", Total digits is: %d)\n", d);
	} else {
		printf("\n");
	}

	memcpy(testarray, array, sizeof(array));
	printf("[%2d]RadixSortLSD2:\t", ++counter);
	print_array(testarray, len, false/*No new line at the end*/);
	int res_lsd2 = 0;
	if(findMaxInArray(testarray, len, res_lsd2)) {
		int d = getTotalDigits(res_lsd2);
		RadixSortLSD2(testarray, len, d);
		printf("After sorting:\t");
		print_array(testarray, len, false);
		printf("(Got max result: %d", res_lsd2);
		printf(", Total digits is: %d)\n", d);
	} else {
		printf("\n");
	}

	memcpy(testarray, array, sizeof(array));
	printf("[%2d]RadixSortMSD:\t", ++counter);
	print_array(testarray, len, false/*No new line at the end*/);
	int res_msd = 0;
	if(findMaxInArray(testarray, len, res_msd)) {
		int d = getTotalDigits(res_msd);
		RadixSortMSD(testarray, len, d);
		printf("After sorting:\t");
		print_array(testarray, len, false);
		printf("(Got max result: %d", res_msd);
		printf(", Total digits is: %d)\n", d);
	} else {
		printf("\n");
	}

#if 0
	// MSD solution has some issue so comment it out
	memcpy(testarray, array, sizeof(array));
	printf("RadixSortMSD:\t");
	print_array(testarray, len, false/*No new line at the end*/);
	int res_msd = 0;
	if(findMaxInArray(testarray, len, res_msd)) {
		int d = getTotalDigits(res_msd);
		RadixSortMSD(testarray, 0, len - 1, d);
		printf("After sorting:\t");
		print_array(testarray, len, false);
		printf("(Got max result: %d", res_msd);
		printf(", Total digits is: %d)\n", d);
	} else {
		printf("\n");
	}
#endif // 0


	//--------------------------------------------------------------------
	delete testarray;

	printf("\n---End of sorting---\n");

	return 0;
}

