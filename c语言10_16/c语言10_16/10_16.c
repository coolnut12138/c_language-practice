#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int x = ++a;//�ȶ�a����������Ȼ��ʹ��a��ֵ����x��xΪ11
//	//printf("x = %d,a = %d",x,a);
//	int y = --a;//�ȶ�a�����Լ���Ȼ��ʹ��a��ֵ����y��yΪ10
//	//printf("y = %d,a = %d",y,a);
//	int w = a--;//��ʹ��a��ֵ���ٸ�a�Լ�������w��ֵΪ10��֮��a��Ϊ9
//		//printf("w = %d,a = %d",w,a);
//	int z = a++;//��ʹ��a��ֵ���ٸ�a����������z��ֵΪ9��֮���Ϊ10
//		//printf("z = %d,a = %d",z,a);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int *p = NULL;
//	p = &a;
//	printf("%d\n",sizeof(a));//���4
//	printf("%d\n",sizeof(int));//���4
//	printf("%d\n",sizeof a);//���4
//	//printf("%d\n",sizeof int);//�﷨����
//	return 0;
//}


//ָ��������
//#include<stdio.h>
//void test1(int arr[])
//{
//	printf("%d\n",sizeof(arr));//40  ������������С
//}
//void test2(char ch[])
//{
//	printf("%d\n",sizeof(ch));//10   ͬ��
//}
//int main()
//{
//	int arr[10] = {0};
//	char ch[10] = {0};
//	printf("%d\n",sizeof(arr));//4  �������ָ��
//	printf("%d\n",sizeof(ch));//4   ͬ��
//	test1(arr);
//	test2(ch);
//	return 0;
//}


//360������
//#include<stdio.h>
//int main()
//{
//	int i = 0,a = 0,b = 2,c = 3,d = 4;
//	//i = a++ && ++b && d++;      //ִ����a=1,b=2,c=3,d=4;&&ǰΪ�ٺ���Ͳ�������
//	i = a++ || ++b || d++;        //ִ����a=1,b=3,c=3,d=4;||ǰΪ�����Ͳ�������
//	printf("a = %d\n b = %d\n c = %d\n d = %d\n",a,b,c,d);
//	return 0;
//}


//����һ���ṹ��ĳ�Ա
#include<stdio.h>
struct Stu//����һ���ṹ��
{
	char name[10];
	int age;
	char sex[5];
};
void set_age1(struct Stu stu)//stuΪ�ṹ�����
{
	stu.age = 18;
}
void set_age2(struct Stu *pStu)
{
	pStu->age = 18;//�ṹ��Ա����
}
int main()
{
	struct Stu stu;//�����ṹ�����
	struct Stu *pStu = &stu;//�ṹ��Ա����
	stu.age = 20;//�ṹ��Ա����
	set_age1(stu);
	pStu->age = 20;//�ṹ��Ա����
	set_age2(pStu);
	return 0;
}

