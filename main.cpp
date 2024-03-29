#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define num 300



struct information
{
	char name[100];//姓名
	char tel[20];//电话号码
	char email[30];//电子邮箱
	char kind;//所属类别
};


void add();
void browse();
void sort();
void search();
void summary();
void del();
void change();
void save();
void read();
int j = 3;//j为全局变量，代表通讯录中所包含信息的条数

struct information info[num] = {{"zyh","19825300946","758088924@qq.com",'b'},
							    {"asd","11111111111","1111111111111111",'B'},
								{"bad","22222222222","2222222222222222",'C'},
									};/*预先存入数据*/

int main()
{
	int q = 1;//q为标志，代表是否继续进行菜单操作
	while (q)
	{
		int choice;
		printf("———欢迎使用通讯录系统 ————    produced by zyh\n\n");  /*菜单界面*/
		printf("———增加新的联系人，请按1———\n\n");
		printf("———浏览所有联系人，请按2———\n\n");
		printf("———排序所有联系人，请按3———\n\n");
		printf("———查询一个联系人，请按4———\n\n");
		printf("———显示某类联系人，请按5———\n\n");
		printf("———删除一个联系人，请按6———\n\n");
		printf("———修改一个联系人，请按7———\n\n");
		printf("———  存盘联系人  ，请按8———\n\n");
		printf("———  读取联系人  ，请按9———\n\n");
		printf("———    退出系统  ，请按0———\n");
		printf("请输入你的选择");
		scanf("%d",&choice);
		switch(choice)
			{case 1:add();break;
			 case 2:browse();break;
			 case 3:sort();break;
			 case 4:search();break;
			 case 5:summary();break;
			 case 6:del();break;
			 case 7:change();break;
			 case 8:save();break;
			 case 9:read();break;
			}
			
		if (choice == 0)
			break ;
		printf("需要继续使用本系统吗？继续请按1，停止请按0");
		scanf("%d",&q);

	}
return 0;
}





/*添加联系人*/

void add()
{
	int a=1;//一个标志，当a==1时，运行添加程序，a==0时停止运行
	int b;
	char mz[10];
	char needs_go_on = 'y';//一个标志，如果联系人名字重复，不进行录入联系人操作
	int check = 1;//检查第一次与第二次输入的名字是否一样
	while(a==1)
		{	
			printf("请输入名字");
			scanf("%s",&mz);
			for(b=0;b<j;b++)
				{
					if(strcmp(mz,info[b].name ) == 0)
						{
							printf("\n该联系人已存在！\n\n");
							needs_go_on = 'n';
							break;
						}
				}
			if(needs_go_on == 'y')
				{	
					printf("该联系人可以添加，请再次输入姓名！\n");
					while(check)//检查第一次与第二次输入的名字是否一样
						{
							scanf("%s",&info[j].name );
							if(strcmp(mz,info[j].name ) != 0)
								{
									printf("两次姓名输入不一样！\n");
									printf("请重新输入！");
								}
							else
								check = 0;
						}

					printf("\n请输入手机号码");         //输入信息
					scanf("%s",&info[j].tel );getchar();
					printf("\n请输入电子邮箱");
					scanf("%s",&info[j].email );getchar();
					printf("\n请输入所属类别（A为办公类 B为个人类 C为商务类）");
					scanf("%s",&info[j].kind );getchar();
					j += 1;
				}
			printf("需要继续录入吗？继续按1，停止按0\n\n");
			scanf("%d",&a);
			if(a==1)
				{check = 1;
				 needs_go_on = 'y';}
		}
}



/*遍历联系人*/

void browse()
{
	int a;
	for(a=0 ; a<j ; a++)//对通讯录中的信息进行输出
	{	printf("姓名\t电子邮箱\t电话\t类别");
		printf("\n %s %s %s %c",info[a].name,info[a].email ,info[a].tel ,info[a].kind);
		printf("\n\n\n");
	}
	
	if(j==0)//判断通讯录中是否有信息
		printf("当前无联系人信息\n\n\n");
}


/*排序联系人*/
void sort()
{
	int i;
	int k;
	information temp;//创建一个temp来临时储存要进行交换的信息
	for(i=0;i<j-1;i++)
		{
			for(k=0;k<j-i-1;k++)    //冒泡排序法
				{
					if(strcmp(info[k].name ,info[k+1].name )<0)   //判断一趟排序中，前后两个名字
						{
							temp =info[k];
							info[k]= info[k+1];
							info[k+1]= temp;
						}
				}
		}
	printf("排序成功!\n");

	browse();//再输出一遍，看是否成功
}

/*查询联系人*/

void search()
{
	int a;
	char temp[100];//用来存放要查找的名字
	printf("输入查找的姓名\n");
	scanf("%s",temp);
	for(a = 0;a <=j ; a++)//遍历通讯录
		{
			if(strcmp(temp,info[a].name) == 0)//看是否有与mz中存放的名字相符合
				{
					printf("已找到该联系人！\n");
					printf("姓名\t  电话\t  电子邮箱\t  类别\n\n");
					printf("%s   %s  %s   %c",info[a].name , info[a].tel , info[a].email ,info[a].kind );
					printf("\n\n\n\n\n");
					break;
				}
			if(a==j)
				printf("\n未找到联系人！！\n");
		}
}


/*统计联系人*/
void summary()
{

    int target;//存放想要统计的类别
	int a;
	int sign = 0;
	printf("有以下几类。A为办公类 B为个人类 C为商务类");
	printf("\nA类请按1,B类请按2，C类请按3");
	scanf("%d",&target);

	if(target == 1)
	{
		for(a=0;a<j;a++)
			{
				if( info[a].kind == 'A'||info[a].kind == 'a')//只要是a类别，不论大小写都输出
					{
						printf("姓名\t电话\t电子邮箱\t类别\n\n");
						printf("%s  %s  %s  %c",info[a].name , info[a].tel , info[a].email ,info[a].kind );
						
						printf("\n\n\n\n");
						sign = 1;
					}
			}
			
	}

	if(target == 2)
	{
		for(a=0;a<j;a++)
			{
				if( info[a].kind == 'B'||info[a].kind == 'b')//只要是b类别，不论大小写都输出
					{
						printf("姓名\t电话\t电子邮箱\t类别\n\n");
						printf("%s  %s  %s  %c",info[a].name , info[a].tel , info[a].email ,info[a].kind );
					
						printf("\n\n\n\n");
						sign = 1;						
					}
			}
			
	}

	if(target == 3)
	{
		for(a=0;a<j;a++)
			{
				if( info[a].kind == 'C'||info[a].kind == 'c')//只要是c类别，不论大小写都输出
					{
						printf("姓名\t电话\t电子邮箱\t类别\n\n");
						printf("%s  %s  %s  %c",info[a].name , info[a].tel , info[a].email ,info[a].kind );
						printf("\n\n\n\n");
						sign = 1;
					}
			}
	}

	if(sign == 0)
		printf("\n当前类别无联系人信息！！\n");

	if(sign == 1)
		printf("\n\n————已全部显示！！————\n\n");
}

/*删除联系人*/

void del()
{
	int a;
	int b;
	int sign = 1;
	char temp[100];
	printf("当前通讯录中有以下信息\n");
	browse();
	printf("请输入你要删除的人名");
	scanf("%s",&temp);
	for(a=0;a<j;a++)
		{	
			if (strcmp(temp,info[a].name)==0)//查询是否有该名字
				{
					for(b=a;b<num;b++)
						{
							info[b]=info[b+1];//将要删除的数据后面一条复制到要删除的位置
							
						}
					j -= 1;//全局变量减一，代表所拥有的数据减一条
					printf("\n\n");
					browse();//看是否删除完成
					printf("删除完成！！\n\n");
					sign = 0;
					break;
					
				}
			else
				continue;
		}
	if(sign == 1)
		printf("未找到该联系人！！\n");

}

/*修改联系人*/
void change()
{
	int a;
	int sign=1;//一个标志，看是否修改成功，成功为0.失败或未找到为1
	int target ;
	int q = 1;
	char temp[100];//存放要修改的人名
	printf("以下是当前通讯录中包含的信息\n\n");
	browse();
	printf("请输入要修改人的姓名");
	scanf("%s",&temp);
	getchar();
	for (a=0;a<j;a++)
		{
			if(strcmp(temp,info[a].name )==0)
				{
					sign=0;//已找到
					printf("已找到联系人！\n");
					printf("原信息如下：\n");
					printf("姓名\t电话\t电子邮箱\t类别\n\n");
					
					while(q)
						{
							printf("%s  %s  %s  %c",info[a].name , info[a].tel , info[a].email ,info[a].kind );
							printf("请输入你要修改的项\n");
							printf("修改名字请按1  修改电话请按2  修改电子邮箱请按3  修改类别请按4\n");
							scanf("%d",&target);
						
							if(target == 1)
							{printf("\n请输入修改过后的姓名");
							scanf("%s",&info[a].name);getchar();}					

							if(target == 2)
							{printf("请输入修改过后的电话");
							scanf("%s",&info[a].tel);getchar();}

							if(target == 3)
							{printf("请输入修改过后的电子邮箱");
							scanf("%s",&info[a].email);getchar();}
						
							if(target == 4)
							{printf("请输入修改过后的类别");
							scanf("%c",&info[a].kind);getchar();}
							printf("修改成功！！！\n\n");	
							printf("你还想继续修改该联系人信息吗？继续请按1,中止请按0");
							scanf("%d",&q);
						}
			}
					break;
				}
		
			if(sign)
				printf("通讯录查无此人！！\n\n");
}


//联系人信息存盘
void save()
{
	FILE *fp;//定义一个文件指针
	int i;
	int sign = 0;//判断是否完成数据存盘
	if((fp = fopen("stu.dat","wb"))==NULL) //打开输出文件
	{
		printf("文件无法打开！\n");
		return;
	}
	for(i=0;i<j;i++)
		{
			if(fwrite(&info[i],sizeof(struct information),1,fp)!=1)
				{printf("数据写入失败！\n");
			sign = 1;}
		}
	fclose(fp);//关闭文件
	if(sign == 1) // 判断是否存盘成功
		printf("数据存盘失败！！\n");
	else
		printf("数据存盘成功！");

	
}


//联系人信息读取
void read()
{
	FILE *fp;
	int i,k;
	int c = 0;
	int sign = 1;
	int check = 1;
	int m = 0;
	struct information temp[300];
	if((fp = fopen("stu.dat","rb"))==NULL)
	{
		printf("无法打开文件\n");
		exit(0);
	}
	for(i = 0;i<300;i++)
	{
		fread(&temp[i],sizeof(struct information),1,fp);
		sign = 0;
	}
	for(i=0;i<300;i++)
	{
		if(strlen(temp[i].name) != 0)
			c++;
	}
	for(i=0;i<c;i++)//判断是否加入的联系人有重复的
	{
		for(k=0;k<300;k++)
		{
			if(strcmp(temp[i].name ,info[k].name )!=0)
				check = 1;
			else
				{
					check = 0;
					break;
				}
		}
		if(check == 1)//如果没有重复的，则把它加入
			{
				info[j] = temp[i];
				j += 1;
				m++;
			}

	}
	fclose(fp);
	if(sign == 1)
		printf("数据读取失败！\n");
	else
		printf("数据读取成功！\n");
	printf("已录入%d条信息\n",m);
}