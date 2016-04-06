#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int print_int(int * p,int n);


//冒泡排序
int bubble_sort(int *p,int n)
{
	int i =0,j=0;
	for (i = 0;i < n; i++)
	{
		for(j = 0;j < n - i; j++)
		{
			if(p[j-1] > p[j] )
			{
				int temp = p[j-1];
				p[j-1] = p[j];
				p[j] = temp;
			}
		}
	}
	return 0;
}

//选择排序
int select_sort(int *p,int n)
{
	int i = 0, j = 0, temp = 0; 
	for(i = 0;i < n; i++)
	{
		temp = p[i];
		for(j = i + 1;j < n;j++)
		{
			if (p[j] < temp)
			{
				p[i] = p[j];
				p[j] = temp;
				temp = p[i];
			}	
		}
	}
	return 0;
}

//插入排序
int insert_sort(int *p,int n)
{
	int i = 0, j = 0, k = 0,temp = 0; 
	for(i = 0;i < n; i++)
	{
		for(j = i + 1;j < n;j++)
		{
			if (p[j] < p[i])
			{
				temp = p[j];
				k = j;
				while(k > i)
				{
					p[k]=p[k - 1];
					k--;
				}
				p[i] = temp;
			}	
		}
	}
	return 0;
}

//快速排序
int quick_sort(int *p,int start,int end)
{
	int i = start;
	int j = end;
	int temp = p[i];
	if (start < end)
	{
		while(i < j)
		{
			while((i < j) && (p[j] >= temp))	
				j--;
			p[i] = p[j];
			while((i < j) && (p[i] <= temp))
				i++;
			p[j] = p[i];
		}
	
		p[i] = temp;
		quick_sort( p,start,i-1);
		quick_sort( p,j+1,end);
	}
	else
	{	
		return 0;
	}
}

//希尔排序
int shell_sort(int *A,int n)
{
	int i=0,j=0,k=0,t=0;
	k = (n/2)%2==0? (n/2 + 1):(n/2);
	while(k)
	{
		for(i = k;i < n; i++ )
		{
			j = i - k;
			t = A[i];
			while((j>=0) && (A[j] > t)) 
			{
				 A[j + k] = A[j];
				j-=k;
			}
			A[j + k] = t; 
		}
		if(k == 1) break;
		k = (k/2)%2==0? (k/2 + 1):(k/2);
	}
}

//归并非递归
int merge_sort(int * list, int length)
{
	int i, left_min, left_max, right_min, right_max, next;
	int *tmp = (int*)malloc(sizeof(int) * length);

	if (tmp == NULL)
		return -1;

	for (i = 1; i < length; i *= 2) // i为步长，1,2,4,8……
	{
		for (left_min = 0; left_min < length - i; left_min = right_max)
		{
			right_min = left_max = left_min + i;
			right_max = left_max + i;

			if (right_max > length)
				right_max = length;

			next = 0;
			while (left_min < left_max && right_min < right_max)
				tmp[next++] = list[left_min] > list[right_min] ? list[right_min++] : list[left_min++];

			while (left_min < left_max)
				list[--right_min] = list[--left_max];

			while (next > 0)
				list[--right_min] = tmp[--next];
		}
	}

	free(tmp);
	return 0;
}

//归并
void merge(int a[], int start, int mid, int end)
{
		int n1 = mid - start + 1;
		int n2 = end - mid;
		int left[n1], right[n2];
		int i, j, k;
		
		for (i = 0; i < n1; i++) /* left holds a[start..mid] */
		    left[i] = a[start+i];
		for (j = 0; j < n2; j++) /* right holds a[mid+1..end] */
		    right[j] = a[mid+1+j];
		
		i = j = 0;
		k = start;
		while (i < n1 && j < n2)
			if (left[i] < right[j])
			a[k++] = left[i++];
			else
			a[k++] = right[j++];
		
		while (i < n1) /* left[] is not exhausted */
		    a[k++] = left[i++];
		while (j < n2) /* right[] is not exhausted */
		    a[k++] = right[j++];
}

//归并递归
void merge_sort_1(int a[], int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        merge_sort_1(a, start, mid); 
        merge_sort_1(a, mid+1, end); 
        merge(a, start, mid, end); 
    }
} 

//堆
void Heapfy(int A[],int idx,int max)      //建立最大堆  
{  
	int left=idx*2;  
	int right=left+1;  
	int largest=idx;  
  
	if(left<max&&A[largest]<A[left])
		largest=left; 
	
	if(right<max&&A[largest]<A[right])
		largest=right;  
  
	if(largest!=idx)  
	{  
		int temp=A[largest];   //较大的节点值将交换到其所在节点的父节点  
		A[largest]=A[idx];  
		A[idx]=temp;  
		Heapfy(A,largest,max); //递归遍历  
	}  
}  
  
void buildHeap(int A[],int n)  
{  
	int len=n;  
	int i;
	for( i=len/2;i>=0;--i)   
		Heapfy(A,i,len);     //建立最大堆，将堆中最大的值交换到根节点    

	for( i=len-1;i>=1;--i)  
	{  
		int temp=A[0];   //将当前堆的根节点交换到堆尾的指定位置  
		A[0]=A[i];  
		A[i]=temp;  
		Heapfy(A,0,i);  //建立下一次的最大堆  
	}  
}  

int print_int(int * p,int n)
{
	int i = 0;
	for(i = 0;i < n; i++)
	{
		printf("p[%d] = %d\n", i, p[i]);
	}
	return 0;
}

int main()
{
	int a[10]={80,23,4312,5,64,45,2,76,35,43};
	int res[10];
	memcpy(res,a,sizeof(a));
	//bubble_sort((int *)res,10);
	//select_sort((int *)res,10);
	//insert_sort((int *)res,10);
	//quick_sort((int *)res,0,9);
	shell_sort((int *)res,10);
	print_int(res,10);
	return 0;
}
