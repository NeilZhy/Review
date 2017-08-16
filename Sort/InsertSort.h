#include<assert.h>
void InsertSort1(int arr[],int n)   //ע��--������ʱ��ʵ�������õ����Ǹ������Ǳ��������е�����ҪС1��
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
		//�����ѭ�����֮��j����ǵ�λ��Ӧ���Ƿ����λ�õ�ǰһ��
		//��ʱ��Ҫ���ǵ�һ��������ǣ����ǵ�j�ոպþ���i��ǰһ�������ʱ���ǲ���Ҫ�ƶ���
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


//�汾2��������λ�ã����ƶ�λ�ú�Ϊһ��
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