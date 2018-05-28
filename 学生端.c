#include "head.h"
/*学生端口*/
void Student_Port(void)
{
	char sp='1';

	while(sp!='0')
	{
		show_stu();
		printf("\t\t\t：");

		scanf("%c",&sp);
		while(getchar()!='\n');
		switch(sp)
		{
			case '1':Student_Login();break;
			case '2':Student_Register();break;
			case '3':Find_Password();break;
			case '0':break;
			default:printf("\t\t输入错误，请重新输入：\n");Sleep(1500);break;
		}
	}
}
/*学生注册账号*/
void Student_Register(void)
{
	char password[20];
	Student *t;
	Student *new=(Student *)malloc(sizeof(Student));
	new->next=NULL;
	for(int i=0;i<10;i++){
		new->stu_bor_book[i][0]='0';
		new->stu_bor_book[i][1]='\0';
	}
	printf("\n\t\t欢迎来到注册系统！\n");
	Sleep(500);
	printf("\t\t正在加载···\n");
	Sleep(500);
	printf("\t\t请输入以下信息\n");
	printf("\t\t学号：");
	scanf("%s",new->stu_num);
	printf("\t\t姓名：");
	scanf("%s",new->stu_name);
	printf("\t\t电话：");
	scanf("%s",new->stu_tel);
	printf("\t\t密码：");
	Password_Input(new->stu_passw);
	printf("\n\t\t再次输入密码：");
	if(Password_Text(new->stu_passw)==0){
		printf("\n\t\t您已连续输错3次，将退出注册系统···");
		Sleep(5000);
		free(new);
		return;
	}
	printf("\n\n\t\t密保问题用于找回密码\n");
	printf("\t\t如：\n");
	printf("\t\t    我母亲的生日是？\n");
	printf("\t\t    我父亲的生日是？\n");
	printf("\t\t    我的生日是？\n");
	printf("\n\t\t密保问题：");
	scanf("%s",new->stu_find_question);
	printf("\t\t密保问题密码：");
	Password_Input(new->stu_find_passw);
	printf("\n\t\t再次输入密保问题密码：");
	if(Password_Text(new->stu_find_passw)==0){
		printf("\n\t\t您已连续输错3次，将退出注册系统···");
		Sleep(5000);
		free(new);
		return;
	}
	Sleep(500);
	printf("\n\t\t正在注册···\n");
	Sleep(1000);
	printf("\t\t···\n");
	Sleep(1000);
	printf("\t\t···\n");
	Sleep(1000);
	printf("\t\t注册成功！\n");
	RandStr(6,new->stu_acc);
	printf("\t\t您的账号是: %s\n",new->stu_acc);
	printf("\t\t请务必牢记账号密码！\n");
	while(getchar()!='\n');
	t=Student_head;
	while(t->next){
		t=t->next;
	}
	t->next=new;
	printf("\t\t按任意键退出");
	getch();
}
void Find_Password(void)
{
	Student *find_tem;
	char num_tem[50];
	char password_find[20];
	printf("\t\t欢迎来到找回密码系统\n");
	Sleep(500);
	printf("\t\t···\n");
	Sleep(500);
	int l=1;
	while(l!=6){
		printf("\t\t请输入六位账号：");
		gets(num_tem);
		l=strlen(num_tem);
		if(l!=6)
			printf("\t\t账号有误，请输入正确长度的账号\n");
	}
	num_tem[6]='\0';
	find_tem=Find_Num(num_tem);
	printf("\t\t您输入的账号：");
	puts(num_tem);
	Sleep(500);
	printf("\t\t正在为您查找\n");
	Sleep(500);
	printf("\t\t···\n");
	Sleep(500);
	if(find_tem==NULL){
		printf("\t\t抱歉，无此账号，即将退出注册系统\n");
		Sleep(1000);
		printf("\t\t···\n");
		Sleep(3000);
		return;
	}
	printf("\t\t%s，您好！\n",find_tem->stu_name);
	Sleep(300);
	printf("\t\t你设置的密保问题是： %s\n",find_tem->stu_find_question);
	Sleep(300);
	printf("\t\t请输入你的密保问题密码：");
	if(Password_Text_Find(find_tem->stu_find_passw)==0){
		printf("\n\t\t您已连续输错3次，将退出找回密码系统···\n");
		Sleep(1500);
		return;
	}
	Sleep(500);
	printf("\n\t\t正在查找\n");
	Sleep(500);
	printf("\t\t···\n");
	Sleep(500);
	printf("\t\t···\n");
	Sleep(500);
	printf("\t\t%s 您好，您的密码是 ：%s",find_tem->stu_name,find_tem->stu_passw);
	printf("\n\t\t请牢记您的密码\n");
	printf("\t\t按任意键退出");
	getch();


}
Student *Find_Num(char *Stu_num)
{
	Student *t=Student_head->next;
	while(t){
		if(strcmp(t->stu_acc,Stu_num)==0)
			break;
		t=t->next;
	}
	return t;
}
/*学生端登录*/
void Student_Login(void)
{
	char sl='1';
	char enter_num[50];
	char enter_passw[20];
	int l=1;
	Student *enter_stu;
	while(l!=6){
		printf("\n\t\t请输入你的账号：");
		gets(enter_num);
		l=strlen(enter_num);
		if(l!=6)
			printf("\t\t账号有误，请输入正确长度的账号\n");
	}
	enter_num[6]='\0';
	enter_stu=Find_Num(enter_num);
	if(enter_stu==NULL){
		printf("\n\t\t抱歉，无此账号");
		Sleep(500);
		printf("\n\t\t按任意键退出");
		getch();
		return;
	}
	printf("\t\t请输入密码：");
	if(Password_Text_Find(enter_stu->stu_passw)==0){
		printf("\n\t\t您已连续输错3次，将退出登录系统···");
		Sleep(2000);
		return;
	}
	Sleep(500);
	printf("\n\t\t正在登录");
	Sleep(500);
	printf("\n\t\t···\n");
	Sleep(500);
	printf("\n\t\t登录成功！\n");
	Sleep(1000);


	while(sl!='0')
	{
		show_stu_enter();
		printf("\t\t：");
		scanf("%c",&sl);
		while(getchar()!='\n');
		switch(sl)
		{
			case '1':Stu_Borrow(enter_stu);break;
			case '2':Stu_Back(enter_stu);break;
			case '3':Find_Book();break;
			case '4':Find_Theborrow(enter_stu);break;
			case '5':Change_Stupassword(enter_stu);break;
			case '0':break;
			default:printf("\t\t输入错误，请重新输入\n");Sleep(3000);break;
		}
	}
}