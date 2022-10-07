#include "ECSort.h"
void mergeSortedHalves(int listInts[], int start, int middle, int end);
void SortHalves(int listInts[], int start, int end);
void ECSort(int listInts[], int size)
{
	SortHalves(listInts, 0, size);
}

void SortHalves(int listInts[], int start, int end){
	if(end - start == 1) return;
	if(end - start == 2){
		mergeSortedHalves(listInts, start, 0, end);
		return;
	}
	else{
		int left_start = start;
		int left_end = (end + start) / 2;
		int right_start = left_end;
		int right_end = end;
		SortHalves(listInts, left_start, left_end);
		SortHalves(listInts, right_start, right_end);
		mergeSortedHalves(listInts, start, left_end, end);
	}
}

void mergeSortedHalves(int listInts[], int start, int middle, int end){
	if(end - start <= 1){
	       	return;
	}
	else if(end - start == 2){
		int end_v = listInts[end-1];
		int start_v = listInts[start];
		if(start_v > end_v){
			listInts[end-1] = start_v;
			listInts[start] = end_v;
		}
		return;
	}
	else{
		int i = start;
		int j = middle;
		int index = 0;
		int buf[end - start];
		while(i < middle && j < end){
			int val1 = listInts[i];
			int val2 = listInts[j];
			if(val1 < val2){
				buf[index] = val1;
				i++;
			}
			else{
				buf[index] = val2;
				j++;
			}
			index++;
		}
		while(i < middle){
			buf[index] = listInts[i];
			i++;
			index++;
		}
		while(j < end){
			buf[index] = listInts[j];
			j++;
			index++;
		}
		for(int k = 0; k < (end - start); k++){
			listInts[k + start] = buf[k];
		}
		return;
	}
}

/*int main(){
	int arr[] = {-1, 2, 5, 6, 4, 3, 7, 8, 1};
	//int arr[] = {4,5,6,1,2,3};
	int size = 9;
	//mergeSortedHalves(arr, 0,3,6);
	//SortHalves(arr, 3, 6);
	ECSort(arr, size);
	for(int i = 0; i < size; i++){
		cout << arr[i] << ' ';
	}
	cout << endl;
	return 0;
}*/
