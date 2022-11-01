#include<stdio.h>

#define max 1000000
int a[max];
int b[max];

void merge(int a[], int low, int mid, int high) {
	int i = low;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= high) {
		if (a[i] <= a[j]) {
			b[k] = a[i];
			k++;
			i++;
		}
		else {
			b[k] = a[j];
			j++;
			k++;
		}
	}
	while (i <= mid) {
		b[k] = a[i];
		k++;
		i++;
	}
	while (j <= high) {
		b[k] = a[j];
		k++;
		j++;
	}
	k--;

	while (k >= 0) {
		a[low + k] = b[k];
		k--;
	}
}

void mergesort(int a[], int low, int high) {
	if (low < high) {
		int m = (low + high) / 2;

		mergesort(a, low, m); 
		mergesort(a, m + 1, high); 

		merge(a, low, m, high); 
	}
	else {
		return;
	}

}

int main()
{
	int n;
	int i;

	scanf_s("%d", &n);

	for (i = 0; i < n; i++)
		scanf_s("%d", a + i);


	mergesort(a, 0, n - 1);

	for (i = 0; i < n; i++)
		printf("%d\n", a[i]);
}