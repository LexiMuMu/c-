/*
	Bubble Sort from the lectures
	with the comparisons counted
*/

int sort(int arr[], int n, int& nc)
{
	int temp, j, LastUnsorted = n-1, LastSwapIndex;
	
	nc = 0;
	while (LastUnsorted > 0)
	{
		LastSwapIndex = 0;
		for (j=0;j<LastUnsorted;j++)
		{
			nc++;
			if (arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				LastSwapIndex = j;
			}
		}
		LastUnsorted = LastSwapIndex;
	}
}
