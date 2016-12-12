#include<iostream>
#include<stdio.h>

void print_array(int *a, int s) {
	for(int i = 0; i < s; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

int remove_duplicates(int* arr, int asize) {
	int index = 0;
	for(int i = 1; i < asize; i++) {
		if(arr[i] != arr[index]) {
			arr[++index] = arr[i];
		}
	}

	return index + 1;
}

int remove_duplicates_allow_2_max(int* arr, int asize) {
	int index = 2;
	for(int i = 2; i < asize; i++) {
		if(arr[i] != arr[index - 2]) {
			arr[index++] = arr[i];
		}
	}

	return index;
}


int main() {
	int a[10] = {1, 2, 3, 3, 4, 5, 6, 6, 6, 6};
	int length = 10;
	print_array(a, length);
	printf("after remove duplicates\n");
	int r = remove_duplicates(a, length);
	print_array(a, r);

	printf("\n");

	int b[10] = {1, 2, 3, 3, 4, 5, 6, 6, 6, 6};
	print_array(b, length);
	printf("after remove duplicates(allow 2 consecutive same digits at most)\n");
	r = remove_duplicates_allow_2_max(b, length);
	print_array(b, r);

	return 0;
}
