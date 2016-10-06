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
     printf("파일이 없음\n");
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

	if(low < right)  left_result = q_sort(numbers,low,right-1); // 왼쪽 편 같은 방법으로 sorting
	if(right < high)  right_result = q_sort(numbers,right+1,high); // 오른쪽 편 같은 방법으로 sorting

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

    pivot   = numbers[left];  // 0번째 원소를 피봇으로 선택

    while (left < right)
    {
        // 값이 선택한 피봇과 같거나 크다면, 이동할 필요가 없다
        while ((numbers[right] >= pivot) && (left < right))
          right --;

          // 그렇지 않고 값이 피봇보다 작다면,
          // 피봇의 위치에 현재 값을 넣는다.
        if (left != right)
        {
             numbers[left] = numbers[right];
        }
        // 왼쪽부터 현재 위치까지 값을 읽어들이면서
        // 피봇보다 큰 값이 있다면, 값을 이동한다.
        while ((numbers[left] <= pivot) && (left < right))
          left ++;
        
        if (left != right)
        {
           numbers[right] = numbers[left];
           right --;
        }
    }

    // 모든 스캔이 끝났다면, 피봇값을 현재 위치에 입력한다.
    // 이제 피봇을 기준으로 왼쪽에는 피봇보다 작거나 같은 값만 남았다.
    numbers[left] = pivot;
    pivot         = left;
    left          = l_hold;
    right         = r_hold;

    // 재귀호출을 수행한다.
    if (left < pivot)
        left_result = q_sort(numbers, left, pivot - 1);
    if (right > pivot)
        right_result = q_sort(numbers, pivot+1, right);

	return left_result + right_result + length;
}