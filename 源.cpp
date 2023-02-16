#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define N 900  //�������ѧ����
struct student
{
	char ID[20];   //ѧ��
	char name[60];   //����
	int gs;   //�����ɼ�
	int dw;  //��ѧ����ɼ�
	int yy;   //Ӣ��ɼ�
	int hx;  //��ѧ�ɼ�
	int jsj;   //������ɼ�
	int sum;   //�ܳɼ�
}stu[N], stusort;
int M = 0;   //MΪȫ�ֱ��������ڴ�ŵ�ǰѧ������
int ad = 0;  
int choose_num;  //choose_numΪȫ�ֱ���
void welcome();//��ӭ���溯������
void menu();//�˵����溯������
void input_message();   //¼�뺯������
void add_message();   //��Ӻ�������
void del_message();   //ɾ����������
void change_message();   //�޸ĺ�������
int find_message();   //��ѯ��������
void display_message();  //��ʾȫ����������
void ID_order();   //��ѧ������������
void score_order();  //���ܳɼ�����������

int main()   //������
{
	welcome();  //���û�ӭ����
	do
	{
		menu();  //���ò˵�
		scanf("%d", &choose_num);
		if (choose_num == 1) input_message();  //����¼�뺯��
		else if (choose_num == 2) add_message();  //������Ӻ���
		else if (choose_num == 3) del_message();  //����ɾ������
		else if (choose_num == 4)change_message();  //�����޸ĺ���
		else if (choose_num == 5)find_message();  //���ò�ѯ����
		else if (choose_num == 6) display_message();  //������ʾȫ������
		else if (choose_num == 7)ID_order();  //���ð�ѧ��������
		else if (choose_num == 8)score_order();   //���ð��ܳɼ�������
		else if (choose_num == 0) break;   //����0���˳�����
		else printf("��������ȷ������\n");
	} while (1);
	printf("�˳�����");
	return 0;
}
///////////////////////////////////��ӭ���溯��/////////////////////////////////////////

void welcome()
{
	printf("        ********            ********\n");
	printf("    ****************    ****************\n");
	printf(" ******************************************\n");
	printf("********************************************\n");
	printf("****      ��ӭ����ѧ���ɼ�����ϵͳ      ****\n");
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

///////////////////////////////////ѡ��˵�����////////////////////////////////////////

void menu()
{
	printf("******************************************\n");
	printf("1.¼��\n");
	printf("2.���\n");
	printf("3.ɾ��\n");
	printf("4.�޸�\n");
	printf("5.��ѯ\n");
	printf("6.��ʾȫ��ѧ����Ϣ\n");
	printf("7.��ѧ������\n");
	printf("8.���ܳɼ�����\n");
	printf("0.�˳�\n");
	printf("******************************************\n");
}

////////////////////////////¼�뺯��///////////////////////////////////////////////
void input_message()
{
	int i;
	printf("����Ҫ���뼸λѧ������Ϣ��");
	scanf("%d", &M);
	
	for (i = 0; i < M; i++)
	{
		printf("�������ѧ��ѧ�ţ�");
		scanf("%s", &stu[i].ID);
		printf("�������ѧ��������");
		scanf("%s", &stu[i].name);
		printf("�������ѧ���ߵ���ѧ�ɼ���"); 
		scanf("%d", &stu[i].gs);
		printf("�������ѧ����ѧ����ɼ���");
		scanf("%d", &stu[i].dw);
		printf("�������ѧ��Ӣ��ɼ���");  scanf("%d", &stu[i].yy);
		printf("�������ѧ����ѧ�ɼ���");  scanf("%d", &stu[i].hx);
		printf("�������ѧ��������ɼ���");  scanf("%d", &stu[i].jsj);
		printf("\n");
	}


}
////////////////////////////��Ӻ���///////////////////////////////////////////////

void add_message() //�����ӹ��ܣ�ÿ�����һ��ѧ����Ϣ
{/*�ú�������ѧ���Լ����*/
	int i;
	printf("��Ҫ���ѧ������Ŀ��");
	scanf("%d", &ad);
	for (i = 0; i < ad; i++)
	{
		printf("�������ѧ��ѧ�ţ�");
		scanf("%s", &stu[M+i].ID);
		printf("�������ѧ��������");
		scanf("%s", &stu[M+i].name);
		printf("�������ѧ���ߵ���ѧ�ɼ���");
		scanf("%d", &stu[M+i].gs);
		printf("�������ѧ����ѧ����ɼ���");
		scanf("%d", &stu[M+i].dw);
		printf("�������ѧ��Ӣ��ɼ���");  scanf("%d", &stu[M+i].yy);
		printf("�������ѧ����ѧ�ɼ���");  scanf("%d", &stu[M+i].hx);
		printf("�������ѧ��������ɼ���");  scanf("%d", &stu[M+i].jsj);
		printf("\n");
	}
	M = M + ad;
}
////////////////////////////ɾ������///////////////////////////////////////////////
void del_message()  //ÿ��ɾ��һ��ѧ����Ϣ
{
	int n, i;
	n = find_message();  //�ȵ��ò�ѯ�������ҳ���Ҫɾ����ѧ��
	if (n >= 0 && n < M)
	{
		for (i = n; i < M; i++)
			stu[i] = stu[i + 1];
		M--; //ÿ��ɾ��һ��ѧ����Ϣ������ѧ��������Ҫ��1
		printf("��ͬѧ�����ѳɹ�ɾ��\n");
	}
	else
		printf("ϵͳ����");
}
////////////////////////////�޸ĺ���///////////////////////////////////////////////
void change_message()  //����޸Ĺ��ܣ�ÿ���޸�һ��ѧ����Ϣ
{/*�ú�������ѧ���Լ����*/
	char a[60]={0};
	int flag = 0;
	printf("������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
	scanf("%s", a);
	int i = 0;
	for (int i = 0; i < M; i++)
	{
		if (strcmp(a, stu[i].ID) == 0) { flag = 1; break; }
	}
		if(flag==1)
		{
			printf("�ߵ���ѧ�ɼ�Ϊ��%d  �޸ĺ�ɼ�Ϊ��", stu[i].gs);
			scanf("%d", &stu[i].gs);
			printf("��ѧ����ɼ�Ϊ��%d  �޸ĺ�ɼ�Ϊ��", stu[i].dw);
			scanf("%d", &stu[i].dw);
			printf("Ӣ��ɼ�Ϊ��%d  �޸ĺ�ɼ�Ϊ��", stu[i].yy);
			scanf("%d", &stu[i].yy);
			printf("��ѧ�ɼ�Ϊ��%d  �޸ĺ�ɼ�Ϊ��", stu[i].hx);
			scanf("%d", &stu[i].hx);
			printf("������ɼ�Ϊ��%d  �޸ĺ�ɼ�Ϊ��", stu[i].jsj);
			scanf("%d", &stu[i].jsj);
			
		}
		else printf("���޴�ͬѧ���޷��޸ĸ�ͬѧ�ĳɼ���\n");
	
}
////////////////////////////��ʾȫ������///////////////////////////////////////////////
void display_message()  //��ʾȫ��ѧ����Ϣ
{/*�ú�������ѧ���Լ����*/
	int i;
	for (i = 0; i < M; i++)
	{
		printf("��ѧ��ѧ�ţ�%s\n",*&stu[i].ID);
		printf("��ѧ��������%s\n", *&stu[i].name);
		printf("��ѧ���ߵ���ѧ�ɼ���%d\n", *&stu[i].gs);
		printf("��ѧ����ѧ����ɼ���%d\n", *&stu[i].dw);
		printf("��ѧ��Ӣ��ɼ���%d\n", *&stu[i].yy);
		printf("��ѧ����ѧ�ɼ���%d\n", *&stu[i].hx);
		printf("��ѧ��������ɼ���%d\n", *&stu[i].jsj);
	}
}
////////////////////////////��ѯ����///////////////////////////////////////////////
int find_message()
{
	char n[20];
	int i, flag = 0;
	if (choose_num == 3)	printf("������Ҫɾ����ͬѧѧ�ţ�");
	else if (choose_num == 4)	printf("������Ҫ�޸ĵ�ͬѧѧ�ţ�");
	else if (choose_num == 5)	printf("������Ҫ��ѯ��ͬѧѧ�ţ�");
	scanf("%s", &n);
	for (i = 0; i < M; i++)
		if (strcmp(stu[i].ID, n) == 0) { flag = 1; break; }
	if (flag == 1)
	{
		printf("��������ѧ����ѧ��Ϊ��%s;\n����Ϊ��%s;\n�����ɼ�Ϊ��%d;\n��ѧ����ɼ�Ϊ��%d;\nӢ��ɼ�Ϊ��%d;\n��ѧ�ɼ�Ϊ��%d;\n������ɼ�Ϊ��%d;\n", stu[i].ID, stu[i].name, stu[i].gs, stu[i].dw, stu[i].yy, stu[i].hx, stu[i].jsj);
		return(i);
	}
	else if (flag == 0) { printf("δ�ҵ���ͬѧ\n"); return(-1); }
}
////////////////////////////��ѧ��������///////////////////////////////////////////////
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
////////////////////////////���ܷ�������///////////////////////////////////////////////
void score_order()  //  ���ֶܷ�ѧ���ɼ��ɸߵ��ͽ�������
{/*�ú�������ѧ���Լ����*/
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