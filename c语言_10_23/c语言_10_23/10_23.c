#define _CRT_SECURE_NO_WARNINGS 1
////1.��д������ 
////unsigned int reverse_bit(unsigned int value); 
////��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ�� 
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
//	printf("������һ������:>");
//	scanf("%d",&n);
//	ret = reverse_bit(n);
//	printf("%u\n",ret);
//	return 0;
//}

////2.��ʹ�ã�a+b��/2���ַ�ʽ������������ƽ��ֵ�� 
//#include<stdio.h>
//void ave(float a,float b)
//{
//	if(a>=b)
//	{
//		printf("ƽ��ֵΪ��%f",(a-b)/2+b);
//	}
//	else
//	{
//		printf("ƽ��ֵΪ��%f",(b-a)/2+a);
//	}
//}
//int main()
//{
//	float a = 0;
//	float b = 0;
//	printf("����������������\n");
//	scanf("%f%f",&a,&b);
//	ave(a,b);
//	return 0;
//}

//3.���ʵ�֣� 
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ� 
//���ҳ�������֡���ʹ��λ���㣩 
//#include<stdio.h>
//int main()
//{     
//	int arr[]={2,2,3,5,5,3,6,7,6};     
//	int i=0;     
//	int len=sizeof(arr)/sizeof(arr[0]);          
//	/*�ҳ������������ͽ������е�ÿ����ȫ��ȡ������㣬     
//	�磺arr[1]={1,3,3,1,4}     
//	01^11=10������������10^11=01,01^01=00,000^100=100=4    
//	�����������Ϊ1     
//	��1��a=a^b    c^a�൱��c^(a^b)     
//	��2���Լ�����Լ������൱��û����򣬻����Լ���*/          
//	for(i=1;i<len;i++)     
//	{          
//		arr[0]=arr[0]^arr[i];      
//	}     
//	printf("the single number is:%d",arr[0]);    
//	return 0; 
//}

//4. ��һ���ַ����������Ϊ:"student a am i", 
//���㽫��������ݸ�Ϊ"i am a student". 
//Ҫ�� 
//����ʹ�ÿ⺯���� 
//ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ�
//#include<stdio.h>
//#include<assert.h>
//char *overthrow(char *arr)
//{
//	char arr1[] = {0};
//}
//int my_strlen(const char *s)//���ַ�����ĳ���
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
