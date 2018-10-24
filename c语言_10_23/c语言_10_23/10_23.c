#define _CRT_SECURE_NO_WARNINGS 1
////1.编写函数： 
////unsigned int reverse_bit(unsigned int value); 
////这个函数的返回值value的二进制位模式从左到右翻转后的值。 
//#include<stdio.h>
//#include<math.h>
//unsigned int reverse_bit(unsigned int value)
//{
//	int arr1[] = {0};
//	int i = 0;
//	unsigned int sum = 0;
//	for(i=0; i<32; i++)
//	{
//		sum = sum<<1;
//		sum |= (value >> i) & 1;
//	}
//	return sum;
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	printf("请输入一个数字:>");
//	scanf("%d",&n);
//	ret = reverse_bit(n);
//	printf("%u\n",ret);
//	return 0;
//}

////2.不使用（a+b）/2这种方式，求两个数的平均值。 
//#include<stdio.h>
//void ave(float a,float b)
//{
//	if(a>=b)
//	{
//		printf("平均值为：%f",(a-b)/2+b);
//	}
//	else
//	{
//		printf("平均值为：%f",(b-a)/2+a);
//	}
//}
//int main()
//{
//	float a = 0;
//	float b = 0;
//	printf("请输入两个整数：\n");
//	scanf("%f%f",&a,&b);
//	ave(a,b);
//	return 0;
//}

//3.编程实现： 
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。 
//请找出这个数字。（使用位运算） 
//#include<stdio.h>
//int main()
//{     
//	int arr[]={2,2,3,5,5,3,6,7,6};     
//	int i=0;     
//	int len=sizeof(arr)/sizeof(arr[0]);          
//	/*找出单独的数，就将数组中的每个数全都取异或运算，     
//	如：arr[1]={1,3,3,1,4}     
//	01^11=10，再用这个结果10^11=01,01^01=00,000^100=100=4    
//	独的数结果就为1     
//	（1）a=a^b    c^a相当于c^(a^b)     
//	（2）自己异或自己两次相当于没有异或，还是自己。*/          
//	for(i=1;i<len;i++)     
//	{          
//		arr[0]=arr[0]^arr[i];      
//	}     
//	printf("the single number is:%d",arr[0]);    
//	return 0; 
//}

//4. 有一个字符数组的内容为:"student a am i", 
//请你将数组的内容改为"i am a student". 
//要求： 
//不能使用库函数。 
//只能开辟有限个空间（空间个数和字符串的长度无关）
//#include<stdio.h>
//#include<assert.h>
//char *overthrow(char *arr)
//{
//	char arr1[] = {0};
//}
//int my_strlen(const char *s)//求字符数组的长度
//{
//	assert(s != NULL);
//	const char *p = s;
//	while(*p != '\0')
//	{
//		p++;
//	}
//	return p-s; 
//}
//int main()
//{
//	char arr[] = "student a am i";
//	overthrow(arr);
//	return 0;
//}
#include <stdio.h>
#include <assert.h> 
int my_strlen(const char *str)
{	
	int len = 0;
	assert(str != NULL);	
	while (*str++)	
	{		
		len++;	
	}	
	return len;
}
void reverse(char *start, char *end)
{	
	assert(start != NULL);	
	assert(end != NULL);	
	while (start < end)	
	{		
		char tmp = *start;		
		*start = *end;		
		*end = tmp;		
		start++;		
		end--;	
	}
}
void str_reverse(char *str)
{	
	int len = 0;
	assert(str != NULL);	
	len = my_strlen(str);	
	reverse(str, str + len - 1);	
	while (*str != '\0')	
	{		
		char *p = str;		
		while ((*str != ' ') && (*str != '\0'))		
		{			
			str++;		
		}		
		reverse(p, str - 1);		
		if (*str != '\0')		
		{			
			str++;		
		}	
	}
}
int main()
{	
	char str[] = "student a am i";	
	str_reverse(str);	
	printf("%s\n", str);		
	return 0;
}
