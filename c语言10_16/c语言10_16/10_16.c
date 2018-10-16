#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int x = ++a;//先对a进行自增，然后使用a的值赋给x，x为11
//	//printf("x = %d,a = %d",x,a);
//	int y = --a;//先对a进行自减，然后使用a的值赋给y，y为10
//	//printf("y = %d,a = %d",y,a);
//	int w = a--;//先使用a的值，再给a自减，这样w的值为10，之后a变为9
//		//printf("w = %d,a = %d",w,a);
//	int z = a++;//先使用a的值，再给a自增，这样z的值为9，之后变为10
//		//printf("z = %d,a = %d",z,a);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int *p = NULL;
//	p = &a;
//	printf("%d\n",sizeof(a));//输出4
//	printf("%d\n",sizeof(int));//输出4
//	printf("%d\n",sizeof a);//输出4
//	//printf("%d\n",sizeof int);//语法错误
//	return 0;
//}


//指针与数组
//#include<stdio.h>
//void test1(int arr[])
//{
//	printf("%d\n",sizeof(arr));//40  计算的是数组大小
//}
//void test2(char ch[])
//{
//	printf("%d\n",sizeof(ch));//10   同上
//}
//int main()
//{
//	int arr[10] = {0};
//	char ch[10] = {0};
//	printf("%d\n",sizeof(arr));//4  计算的是指针
//	printf("%d\n",sizeof(ch));//4   同上
//	test1(arr);
//	test2(ch);
//	return 0;
//}


//360笔试题
//#include<stdio.h>
//int main()
//{
//	int i = 0,a = 0,b = 2,c = 3,d = 4;
//	//i = a++ && ++b && d++;      //执行完a=1,b=2,c=3,d=4;&&前为假后面就不用算了
//	i = a++ || ++b || d++;        //执行完a=1,b=3,c=3,d=4;||前为真后面就不用算了
//	printf("a = %d\n b = %d\n c = %d\n d = %d\n",a,b,c,d);
//	return 0;
//}


//访问一个结构体的成员
#include<stdio.h>
struct Stu//定义一个结构体
{
	char name[10];
	int age;
	char sex[5];
};
void set_age1(struct Stu stu)//stu为结构体变量
{
	stu.age = 18;
}
void set_age2(struct Stu *pStu)
{
	pStu->age = 18;//结构成员访问
}
int main()
{
	struct Stu stu;//创建结构体变量
	struct Stu *pStu = &stu;//结构成员访问
	stu.age = 20;//结构成员访问
	set_age1(stu);
	pStu->age = 20;//结构成员访问
	set_age2(pStu);
	return 0;
}

