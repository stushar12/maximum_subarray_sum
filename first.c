#include<stdio.h>

  int kadane(int a[] , int n)
  {
  int sum=0,sum1=0;
    for(int i=0;i<n;i++)
      {
         sum=sum+a[i];
            if(sum<0)
               sum=0;
            if(sum1<sum)
              sum1=sum;   
      }
  return sum1;
  }
  
int circular_sum(int a[],int n)
  {
    int total=0;
    int a1=kadane(a,n);
  for (int i=0;i<n;i++)
  {
    total=total+a[i];
    a[i]=-a[i];
  }
  int circular_total=kadane(a,n);
  total=total+circular_total;
  return (total>a1) ? total:a1;
  }

int main()
{      
  int total=0,x=0,sum1=0;
  int arr[]={2,1,-5,4,-3,1,-3,1,-3,4,-1};
  int n=sizeof(arr)/sizeof(arr[0]);
  total=circular_sum(arr,n);
  printf("Maximum sum is %d ",total);
}
