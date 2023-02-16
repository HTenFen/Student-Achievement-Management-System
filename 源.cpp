#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define N 900  //最大输入学生数
struct student
{
	char ID[20];   //学号
	char name[60];   //姓名
	int gs;   //高数成绩
	int dw;  //大学物理成绩
	int yy;   //英语成绩
	int hx;  //化学成绩
	int jsj;   //计算机成绩
	int sum;   //总成绩
}stu[N], stusort;
int M = 0;   //M为全局变量，用于存放当前学生人数
int ad = 0;  
int choose_num;  //choose_num为全局变量
void welcome();//欢迎界面函数声明
void menu();//菜单界面函数声明
void input_message();   //录入函数声明
void add_message();   //添加函数声明
void del_message();   //删除函数声明
void change_message();   //修改函数声明
int find_message();   //查询函数声明
void display_message();  //显示全部函数声明
void ID_order();   //按学号排序函数声明
void score_order();  //按总成绩排序函数声明

int main()   //主函数
{
	welcome();  //调用欢迎界面
	do
	{
		menu();  //调用菜单
		scanf("%d", &choose_num);
		if (choose_num == 1) input_message();  //调用录入函数
		else if (choose_num == 2) add_message();  //调用添加函数
		else if (choose_num == 3) del_message();  //调用删除函数
		else if (choose_num == 4)change_message();  //调用修改函数
		else if (choose_num == 5)find_message();  //调用查询函数
		else if (choose_num == 6) display_message();  //调用显示全部函数
		else if (choose_num == 7)ID_order();  //调用按学号排序函数
		else if (choose_num == 8)score_order();   //调用按总成绩排序函数
		else if (choose_num == 0) break;   //输入0，退出程序
		else printf("请输入正确的数字\n");
	} while (1);
	printf("退出程序");
	return 0;
}
///////////////////////////////////欢迎界面函数/////////////////////////////////////////

void welcome()
{
	printf("        ********            ********\n");
	printf("    ****************    ****************\n");
	printf(" ******************************************\n");
	printf("********************************************\n");
	printf("****      欢迎进入学生成绩管理系统      ****\n");
	printf("  ****************************************\n");
	printf("    ************************************\n");
	printf("      ********************************\n");
	printf("        ****************************\n");
	printf("          ************************\n");
	printf("            ********************\n");
	printf("              ****************\n");
	printf("                ************\n");
	printf("                  ********\n");
	printf("                    ****\n");
}

///////////////////////////////////选择菜单函数////////////////////////////////////////

void menu()
{
	printf("******************************************\n");
	printf("1.录入\n");
	printf("2.添加\n");
	printf("3.删除\n");
	printf("4.修改\n");
	printf("5.查询\n");
	printf("6.显示全部学生信息\n");
	printf("7.按学号排序\n");
	printf("8.按总成绩排序\n");
	printf("0.退出\n");
	printf("******************************************\n");
}

////////////////////////////录入函数///////////////////////////////////////////////
void input_message()
{
	int i;
	printf("请问要输入几位学生的信息？");
	scanf("%d", &M);
	
	for (i = 0; i < M; i++)
	{
		printf("请输入该学生学号：");
		scanf("%s", &stu[i].ID);
		printf("请输入该学生姓名：");
		scanf("%s", &stu[i].name);
		printf("请输入该学生高等数学成绩："); 
		scanf("%d", &stu[i].gs);
		printf("请输入该学生大学物理成绩：");
		scanf("%d", &stu[i].dw);
		printf("请输入该学生英语成绩：");  scanf("%d", &stu[i].yy);
		printf("请输入该学生化学成绩：");  scanf("%d", &stu[i].hx);
		printf("请输入该学生计算机成绩：");  scanf("%d", &stu[i].jsj);
		printf("\n");
	}


}
////////////////////////////添加函数///////////////////////////////////////////////

void add_message() //完成添加功能，每次添加一个学生信息
{/*该函数留给学生自己完成*/
	int i;
	printf("想要添加学生的数目：");
	scanf("%d", &ad);
	for (i = 0; i < ad; i++)
	{
		printf("请输入该学生学号：");
		scanf("%s", &stu[M+i].ID);
		printf("请输入该学生姓名：");
		scanf("%s", &stu[M+i].name);
		printf("请输入该学生高等数学成绩：");
		scanf("%d", &stu[M+i].gs);
		printf("请输入该学生大学物理成绩：");
		scanf("%d", &stu[M+i].dw);
		printf("请输入该学生英语成绩：");  scanf("%d", &stu[M+i].yy);
		printf("请输入该学生化学成绩：");  scanf("%d", &stu[M+i].hx);
		printf("请输入该学生计算机成绩：");  scanf("%d", &stu[M+i].jsj);
		printf("\n");
	}
	M = M + ad;
}
////////////////////////////删除函数///////////////////////////////////////////////
void del_message()  //每次删除一个学生信息
{
	int n, i;
	n = find_message();  //先调用查询函数，找出需要删除的学生
	if (n >= 0 && n < M)
	{
		for (i = n; i < M; i++)
			stu[i] = stu[i + 1];
		M--; //每次删除一个学生信息后，总体学生人数需要减1
		printf("该同学数据已成功删除\n");
	}
	else
		printf("系统错误");
}
////////////////////////////修改函数///////////////////////////////////////////////
void change_message()  //完成修改功能，每次修改一个学生信息
{/*该函数留给学生自己完成*/
	char a[60]={0};
	int flag = 0;
	printf("请输入要修改的学生学号：");
	scanf("%s", a);
	int i = 0;
	for (int i = 0; i < M; i++)
	{
		if (strcmp(a, stu[i].ID) == 0) { flag = 1; break; }
	}
		if(flag==1)
		{
			printf("高等数学成绩为：%d  修改后成绩为：", stu[i].gs);
			scanf("%d", &stu[i].gs);
			printf("大学物理成绩为：%d  修改后成绩为：", stu[i].dw);
			scanf("%d", &stu[i].dw);
			printf("英语成绩为：%d  修改后成绩为：", stu[i].yy);
			scanf("%d", &stu[i].yy);
			printf("化学成绩为：%d  修改后成绩为：", stu[i].hx);
			scanf("%d", &stu[i].hx);
			printf("计算机成绩为：%d  修改后成绩为：", stu[i].jsj);
			scanf("%d", &stu[i].jsj);
			
		}
		else printf("查无此同学，无法修改该同学的成绩！\n");
	
}
////////////////////////////显示全部函数///////////////////////////////////////////////
void display_message()  //显示全部学生信息
{/*该函数留给学生自己完成*/
	int i;
	for (i = 0; i < M; i++)
	{
		printf("该学生学号：%s\n",*&stu[i].ID);
		printf("该学生姓名：%s\n", *&stu[i].name);
		printf("该学生高等数学成绩：%d\n", *&stu[i].gs);
		printf("该学生大学物理成绩：%d\n", *&stu[i].dw);
		printf("该学生英语成绩：%d\n", *&stu[i].yy);
		printf("该学生化学成绩：%d\n", *&stu[i].hx);
		printf("该学生计算机成绩：%d\n", *&stu[i].jsj);
	}
}
////////////////////////////查询函数///////////////////////////////////////////////
int find_message()
{
	char n[20];
	int i, flag = 0;
	if (choose_num == 3)	printf("请输入要删除的同学学号：");
	else if (choose_num == 4)	printf("请输入要修改的同学学号：");
	else if (choose_num == 5)	printf("请输入要查询的同学学号：");
	scanf("%s", &n);
	for (i = 0; i < M; i++)
		if (strcmp(stu[i].ID, n) == 0) { flag = 1; break; }
	if (flag == 1)
	{
		printf("您搜索的学生的学号为：%s;\n姓名为：%s;\n高数成绩为：%d;\n大学物理成绩为：%d;\n英语成绩为：%d;\n化学成绩为：%d;\n计算机成绩为：%d;\n", stu[i].ID, stu[i].name, stu[i].gs, stu[i].dw, stu[i].yy, stu[i].hx, stu[i].jsj);
		return(i);
	}
	else if (flag == 0) { printf("未找到该同学\n"); return(-1); }
}
////////////////////////////按学号排序函数///////////////////////////////////////////////
void ID_order()
{
	int i, j;
	for (i = 0; i < M - 1; i++)
		for (j = 0; j < M - 1 - i; j++)
		{
			if (stu[j].ID > stu[j + 1].ID)
			{
				stusort = stu[j]; stu[j] = stu[j + 1]; stu[j + 1] = stusort;
			}
		}
	display_message();
}
////////////////////////////按总分排序函数///////////////////////////////////////////////
void score_order()  //  按总分对学生成绩由高到低进行排序
{/*该函数留给学生自己完成*/
	int i, j;
	for (i = 0; i < M; i++)
	{
		stu[i].sum = stu[i].gs + stu[i].dw + stu[i].yy + stu[i].hx + stu[i].jsj;
	}
	for (i = 0; i < M - 1; i++)
		for (j = 0; j < M - 1 - i; j++)
		{
			if (stu[j].sum < stu[j + 1].sum)
			{
				stusort = stu[j]; stu[j] = stu[j + 1]; stu[j + 1] = stusort;
			}
		}
	display_message();
}