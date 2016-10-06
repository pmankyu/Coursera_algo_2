#include <stdio.h>

int size = 10;
int count = 0;

//int quickSort(int numbers[], int array_size);
//int q_sort(int numbers[], int left, int right);

int quickSort(int numbers[], int array_size);
int q_sort(int numbers[], int left, int right);

int main(void)
{
	FILE *fp = fopen("IntegerArray100.txt","r");
	int i=0;
	//int test_arr[100];
	int test_arr[10] = { 3,9,8,4,6,10,2,5,7,1} ;
	int result =0;
	if (fp == NULL) {
     printf("������ ����\n");
	}
	else
	{
		for(i = 0;i<size;i++)
		{
			//fscanf(fp,"%d\n",&test_arr[i]);
		}
	}
	printf("Start\n");

	for(i=0;i<size;i++)
	{
		printf("%d," ,test_arr[i]);
	}
	printf("\n\n\n");

	result = quickSort(test_arr,size);

	for(i=0;i<size;i++)
	{
		printf("%d," ,test_arr[i]);
	}
	printf("\nresult: %d\n" ,result);

	printf("Test!!!\n");
	return 0;
}

/*

int quickSort(int* numbers, int array_size)
{
    return q_sort(numbers, 0, array_size -1);
}



int q_sort(int* numbers, int left, int right)
{
	int pivot, low, high, temp, length;
	int left_result=0; 
	int right_result=0;
	int middle = 0;
	low = left;
	high = right;
	
	if((right-left)%2 == 1)
	{
		middle = left + (right-left)/2 + 1;
	}
	else
	{
		middle = left + (right-left)/2;
	}
	
	temp = numbers[left];
	numbers[left] = numbers[middle];
	numbers[middle] = temp;
	

	pivot = numbers[left];
	
	length = right-left;

	while(left<right)
	{
		while((numbers[right] >= pivot)&&(right!=low))
		{
			right--;
		}

		while((numbers[left] <= pivot)&&(left!=high))
		{
			left++;
		}

		if((left != right) && (left<right))
		{
			temp = numbers[left];
			numbers[left] = numbers[right];
			numbers[right] = temp;
		}
	}

	numbers[low] = numbers[right];
	numbers[right] = pivot;

	if(low < right)  left_result = q_sort(numbers,low,right-1); // ���� �� ���� ������� sorting
	if(right < high)  right_result = q_sort(numbers,right+1,high); // ������ �� ���� ������� sorting

	return left_result + right_result + length;
}
*/



int quickSort(int numbers[], int array_size)
{
    return q_sort(numbers, 0, array_size -1);
}

int q_sort(int numbers[], int left, int right)
{
    int pivot, l_hold, r_hold;
	int left_result = 0;
	int right_result = 0;
	int length = 0;

    l_hold  = left;
    r_hold  = right;

	length = right - left;

    pivot   = numbers[left];  // 0��° ���Ҹ� �Ǻ����� ����

    while (left < right)
    {
        // ���� ������ �Ǻ��� ���ų� ũ�ٸ�, �̵��� �ʿ䰡 ����
        while ((numbers[right] >= pivot) && (left < right))
          right --;

          // �׷��� �ʰ� ���� �Ǻ����� �۴ٸ�,
          // �Ǻ��� ��ġ�� ���� ���� �ִ´�.
        if (left != right)
        {
             numbers[left] = numbers[right];
        }
        // ���ʺ��� ���� ��ġ���� ���� �о���̸鼭
        // �Ǻ����� ū ���� �ִٸ�, ���� �̵��Ѵ�.
        while ((numbers[left] <= pivot) && (left < right))
          left ++;
        
        if (left != right)
        {
           numbers[right] = numbers[left];
           right --;
        }
    }

    // ��� ��ĵ�� �����ٸ�, �Ǻ����� ���� ��ġ�� �Է��Ѵ�.
    // ���� �Ǻ��� �������� ���ʿ��� �Ǻ����� �۰ų� ���� ���� ���Ҵ�.
    numbers[left] = pivot;
    pivot         = left;
    left          = l_hold;
    right         = r_hold;

    // ���ȣ���� �����Ѵ�.
    if (left < pivot)
        left_result = q_sort(numbers, left, pivot - 1);
    if (right > pivot)
        right_result = q_sort(numbers, pivot+1, right);

	return left_result + right_result + length;
}