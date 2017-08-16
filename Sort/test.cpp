#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"InsertSort.h"
using namespace std;
int main()
{
	int arr[9] = {5,3,9,7,8,1,2,6,4};
	ShellSort(arr, 9);
	int i = 0;
	for (; i < 9;i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
}