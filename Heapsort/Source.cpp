///
/// A heroic attempt to sort strings using heapsort.
///
#include<iostream>
#include<ctime>
#define ROWS 5100
#define COLS 200


void heapify(char (&arr)[ROWS][COLS], unsigned short rows, unsigned short root) {
	unsigned short largest = root;
	unsigned short left = root * 2 + 1;
	unsigned short right = root * 2 + 2;

	if (left < rows)
		if (strcmp(arr[left], arr[largest]) > 0)
			std::swap(left, largest);

	if (right < rows)
		if (strcmp(arr[right], arr[largest]) > 0)
			std::swap(right, largest);

	if (root != largest) {
		std::swap(arr[root], arr[largest]);
		heapify(arr, rows, largest);
	}
}


void heapsort(char(&arr)[ROWS][COLS], unsigned short rows) {
	for (int i = rows / 2 - 1; i >= 0; --i)
		heapify(arr, rows, i);

	for (int i = rows - 1; i >= 0; --i) {
		std::swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}


int main() {
	srand(time(NULL));
	clock_t begin = clock();

	//
	// Generate a random set of strings with lengths of 100 to 200.
	//
	char arrays[ROWS][COLS];
	for (int i = 0; i < ROWS; ++i) {
		int size = (rand() % (COLS));
		size = size < COLS /2 ? size + COLS /2 : size;

		for (int j = 0; j < size; ++j) {
			bool type = rand() % 2;
			if (type)
				arrays[i][j] = (rand() % 10) + 48;
			else
				arrays[i][j] = (rand() % 26) + 97;
		}
		arrays[i][size] = '\0';
	}

	//
	// Heroically attempt to sort them with heapsort, thinking that is O(nlg(n)v)
	//
	heapsort(arrays, ROWS);
	clock_t end = clock();

	// To print the sorted strings uncomment the following line:
	// for (int i = 0; i < ROWS; ++i) std::cout << arrays[i] << "\n";

	printf("Sorted %d strings with length from %d to %d\n", ROWS,COLS/2,COLS);
	printf("Elapsed time: %f\n",double(end-begin)/CLOCKS_PER_SEC);

	system("pause");
	return 0;
}