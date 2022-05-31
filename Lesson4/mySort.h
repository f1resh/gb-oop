#pragma once
class mySort
{
private:
	static void swapInt(int* a, int* b) {
		int t = *a;
		*a = *b;
		*b = t;
	}

	static void insertSort(int* arr, const int left, const int right) {
		int tmp, pos;
		for (int i = left; i <= right; ++i) {
			tmp = arr[i];
			pos = i - 1;

			while (pos >= 0 && arr[pos] > tmp) {
				arr[pos + 1] = arr[pos];
				--pos;
			}
			arr[pos + 1] = tmp;
		}
	}

	static int getMedian(int* arr, const int left, const int right) {
		int mid = (right + left) / 2;
		if (arr[left] > arr[mid]) {
			if (arr[left] > arr[right]) return left;
			else return right;
		}
		else {
			if (arr[mid] > arr[right]) return mid;
			else return right;
		}
	}

public:
	
	static void advancedQSort(int* arr, const int left, const int right) {
		int mid = (right + left) / 2;
		if (right - left + 1 <= 10) insertSort(arr, left, right);
		else
		{
			int medianIndex = getMedian(arr, left, right);
			swapInt(&arr[medianIndex], &arr[mid]);

			int i = left;
			int j = right;
			int x = arr[mid];
			do {
				while (arr[i] < x) ++i;
				while (arr[j] > x) --j;

				if (i <= j) {
					swapInt(&arr[i], &arr[j]);
					++i;
					--j;
				}
			} while (i <= j);

			if (i < right) advancedQSort(arr, i, right);
			if (left < j) advancedQSort(arr, left, j);

		}
	}
};

