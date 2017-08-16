#include<assert.h>
void InsertSort1(int arr[],int n)   //注意--操作的时候，实际上最后得到的那个数据是比你想象中的数据要小1的
{
	assert(arr);
	assert(n);
	int i = 1, j = 0, m = 0;
	for (; i < n; i++)
	{
		j = i - 1;
		for (; j>=0; j--)
		{
			if (arr[j] < arr[i])
			{
				break;
			}
		}
		//上面的循环完毕之后，j所标记的位置应该是放入的位置的前一个
		//此时需要考虑的一个问题就是，我们的j刚刚好就是i的前一个，这个时候是不需要移动的
		if (j != i - 1)
		{
			int temp = arr[i];
			for (m = i; m > j;m--)
			{
				arr[m] = arr[m - 1];
			}
			arr[j + 1] = temp;
		}
	}
}


//版本2：将查找位置，和移动位置合为一体
void InsertSort2(int arr[],int n)
{
	assert(arr);
	assert(n);
	int i = 1, j = 0, m = 0;
	for (i; i < n; i++)
	{
		int temp = arr[i];
		j = i - 1;
		for (j; j >= 0; j--)
		{
			
			if (arr[j] < temp)
			{
				break;
			}
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}


void ShellSort(int arr[],int n)
{
	int  grap = n;
	while (grap /= 2)
	{
		int i = 0, j = 0, m = 0;
		int k = 0;
		for (k; k < grap; k++)
		{
			for (i = grap + k; i < n; i += grap)
			{
				j = i - grap;
				int temp = arr[i];
				for (j; j>=k;j-=grap)
				{
					if (arr[j] < temp)
					{
						break;
					}
					arr[j+grap] = arr[j];
				}
				arr[j + grap] = temp;
			}
		}	
	}
}