#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//unsigned int reverse_bit(unsigned int value)
//{
//	unsigned int num = 0;
//	int i = 0;
//	for(i=0; i<32; i++)
//	{
//		num = num << 1;//��num���Ʒ���ǰ����Ϊ�˽���λ��Ľ������һ�Σ���Ϊ��1λ�Ƶ���32λֻ��Ҫ��λ31��
//		num |= (value >> i) & 1;
//	}
//	return num;
//}
//int main()
//{
//	int ret = 0;
//	int n = 0;
//	printf("������һ��������\n");
//	scanf("%d",&n);
//	ret = reverse_bit(n); 
//	printf("��ת���ֵΪ��%u\n",ret);//�ǵ�����޷�����ʱһ��Ҫ��%u
//	return 0;
//}

//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ� 
//���ҳ�������֡���ʹ��λ���㣩 
//#include<stdio.h>
//int main()
//{
//	int arr[] = {1,3,1,4,4,3,6,7,7};
//	int i = 0;
//	int len = sizeof(arr)/sizeof(arr[0]);
//	for(i=1; i<len; i++)
//	{
//		arr[0] = arr[0]^arr[i];//�Լ�����Լ������Լ�
//	}
//	printf("%d\n",arr[0]);
//	return 0;
//}

//��һ���ַ����������Ϊ:"student a am i", 
//���㽫��������ݸ�Ϊ"i am a student". 
//Ҫ�� 
//����ʹ�ÿ⺯���� 
//ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
//#include<stdio.h>
//#include<assert.h>
//int my_strlen(const char *arr)
//{
//	const char *p = arr;
//	assert(arr != NULL);
//	assert(p != NULL);
//	while(*arr != '\0')
//	{
//		arr++;
//	}
//	return arr-p;
//}
//void overthrow(char *left,char *right)
//{
//	assert(left != NULL);
//	assert(right != NULL);
//	while(left<right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//void all_overthrow(char *str)
//{
//	int len = 0;
//	assert(str != NULL);
//	len = my_strlen(str);
//	overthrow(str,str+len-1);
//	while(*str != '\0')
//	{
//		char *p = str;
//		while((*str != ' ') && (*str != '\0'))
//		{
//			str++;
//		}
//		overthrow(p,str-1);
//		if(*str != '\0')
//		{
//			str++;
//		}
//	}
//}
//int main()
//{
//	char str[999] = {0};
//	printf("������һ���ַ�:>");
//	gets(str);
//	all_overthrow(str);
//	puts(str);
//	return 0;
//}

////���������λ��1�ĸ���
//#include<stdio.h>
//int count_one_bits(unsigned int value)
//{
//	int sum = 0;
//	while(value)
//	{
//		value = value & (value-1);
//		sum++;
//	}
//	return sum;
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	printf("������һ��������>");
//	scanf("%d",&n);
//	ret = count_one_bits(n);
//	printf("��%dλ1\n",ret);
//	return 0;
//}

#include<stdio.h>
int count_one_bits(unsigned int value)
{
	int count = 0;
	while(value)
	{
		if((value&1) == 1)//ģ1ȡ���λ����
		{
			count++;
		}
		value >>=1;
	}
	return count;
}
int main()
{
	int n = 0;
	int ret = 0;
	printf("������һ��������>");
	scanf("%d",&n);
	ret = count_one_bits(n);
	printf("��%dλ1\n",ret);
	return 0;
}