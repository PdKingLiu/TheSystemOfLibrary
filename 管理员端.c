#include "head.h"
/*管理员端*/
void Manager_Port(void)
{
	char mp='1';

	while(mp!='0')
	{
		show_manager();
		printf("\t\t：");
		scanf("%c",&mp);
		while(getchar()!='\n');
		switch(mp)
		{
			case '1':Manager_Login();break;
			case '0':break;
			default:printf("\t\t输入错误，请重新输入\n");Sleep(3000);break;
		}
	}
}
/*管理员登录*/
void Manager_Login(void)
{
	char Manager_num[20];
	char ml='1';
	Manager *t;
	printf("\n\t\t账号：");
	gets(Manager_num);
	t=Manager_check(Manager_num);
	if(!t){
		printf("\t\t抱歉，账号不存在\n");
		printf("\t\t按任意键退出");
		getch();
		return;
	}
	printf("\t\t密码：");
	if(Password_Text_Find(t->man_passw)==0){
		printf("\n\t\t已经错误输入密码三次，将退出登录系统···\n");
		Sleep(5000);
		return;
	}
	Sleep(500);
	printf("\n\t\t登录中···\n");
	Sleep(500);
	printf("\t\t登录成功···\n");
	Sleep(500);
	printf("\t\t正在加载···\n");
	Sleep(1000);


	while(ml!='0')
	{
		show_manager_enter();
		printf("\t\t：");
		scanf("%c",&ml);
		while(getchar()!='\n');
		switch(ml)
		{
			case '1':Manager_Add_Book();break;
			case '2':Manager_Down_Book();break;
			case '3':Manager_Look_Book();break;
			case '4':Manager_Manager_Stu();break;
			case '5':Manager_Change_Password(t);break;
			case '0':break;
			default:printf("\t\t输入错误，请重新输入\n");Sleep(3000);break;
		}
	}



}
/*核对管理员账号*/
Manager *Manager_check(char *Manager_num)
{

	Manager *t=Manager_head->next;
	while(t){
		if(strcmp(Manager_num,t->man_acc)==0)
			break;
		t=t->next;
	}
	return t;
}
/*管理员查看书架*/
void Manager_Look_Book(void)
{
	char ml;
	printf("\n\t\t管理员，你好！\n");
	printf("\t\t请选择浏览的方式\n\n");
	printf("\t\t\t1)按编号升序浏览书架\n");
	printf("\t\t\t2)按库存升序浏览书架\n");
	printf("\t\t\t3)按价格升序浏览书架\n\n");

	printf("\t\t：");
	scanf("%c",&ml);
	while(getchar()!='\n');
	switch(ml)
	{
		case '1': Lookofnum();break;
		case '2': Lookofrest();break;
		case '3': Lookofprice();break;
		default:printf("\t\t输入错误\n");break;
	}
	printf("\t\t按任意键退出");
	getch();
	return;
}
//编号升序查看书架
void Lookofnum(void)
{
	if(Book_head->next==NULL)
	{
		printf("\t\t暂无书籍\n");
		return;
	}
	if(Book_head->next->next==NULL)
	{
		return;
	}
	Book *p1,*p2,*p3,*end,*tem;
	Book *head=Book_head;
	end=NULL;
	while(head->next!=end){
		for(p1=head,p2=p1->next,p3=p2->next;p3!=end;p1=p1->next,p2=p2->next,p3=p3->next){
			if((strcmp(p2->book_num,p3->book_num))>0){
				p1->next=p2->next;
				p2->next=p3->next;
				p3->next=p2;
				tem=p2;
				p2=p3;
				p3=tem;
			}
			
		}
		end=p2;
	}
	Manager_Print_Book();
}
//库存升序查看书架
void Lookofrest(void)
{
	if(Book_head->next==NULL)
	{
		printf("\t\t暂无书籍\n");
		return;
	}
	if(Book_head->next->next==NULL)
	{
		return;
	}
	Book *p1,*p2,*p3,*end,*tem;
	Book *head=Book_head;
	end=NULL;
	while(head->next!=end){
		for(p1=head,p2=p1->next,p3=p2->next;p3!=end;p1=p1->next,p2=p2->next,p3=p3->next){
			if(p2->book_rest > p3->book_rest){
				p1->next=p2->next;
				p2->next=p3->next;
				p3->next=p2;
				tem=p2;
				p2=p3;
				p3=tem;
			}
			
		}
		end=p2;
	}
	Manager_Print_Book();
}
//价格升序查看书架
void Lookofprice(void)
{
	if(Book_head->next==NULL)
	{
		printf("\t\t暂无书籍\n");
		return;
	}
	if(Book_head->next->next==NULL)
	{
		return;
	}
	Book *p1,*p2,*p3,*end,*tem;
	Book *head=Book_head;
	end=NULL;
	while(head->next!=end){
		for(p1=head,p2=p1->next,p3=p2->next;p3!=end;p1=p1->next,p2=p2->next,p3=p3->next){
			if(p2->book_price > p3->book_price){
				p1->next=p2->next;
				p2->next=p3->next;
				p3->next=p2;
				tem=p2;
				p2=p3;
				p3=tem;
			}
			
		}
		end=p2;
	}
	Manager_Print_Book();
}
void Manager_Print_Book(void)
{
	Book *t=Book_head->next;;
	if(t==NULL){
		printf("\t\t没有任何书籍信息\n");
		return;
	}
	printf("\n\n\t**********************************");
	printf("********************************\n\n");
	printf("\t %-8s%-12s%-12s%-18s%-10s%-8s\n\n",
		"编号","书名","作者","出版社","价格","库存");
	while(t)
	{
		printf("\t %-8s%-12s%-12s%-18s%-10.2f%-8d\n",
		t->book_num,t->book_name,t->book_at_name,
		t->book_cp_name,t->book_price,t->book_rest);
		t=t->next;
	}
	printf("\n\t**************************************");
	printf("****************************\n\n\n");
}
/*管理员修改密码*/
void Manager_Change_Password(Manager *Man_num)
{
	char password_tem[20];
	printf("\t\t加载中···\n");
	Sleep(500);
	printf("\t\t请输入原密码：");
	if(Password_Text_Find(Man_num->man_passw)==0){
		printf("\n\t\t已经错误输入密码三次，将退出修改密码系统···\n");
		Sleep(1500);
		return;
	}
	printf("\n\t\t验证中···\n");
	Sleep(1000);
	printf("\t\t验证成功！\n");
	Sleep(500);
	printf("\t\t请输入新密码(6~10位)：");
	Password_Input(password_tem);
	printf("\n\t\t请再次输入新密码：");
	if(Password_Text(password_tem)==0){
		printf("\t\t已经错误输入密码三次，将退出修改密码系统···\n");
		Sleep(1500);
		return;
	}
	Man_num->man_passw[0]='\0';
	strcat(Man_num->man_passw,password_tem);
	Sleep(500);
	printf("\n\t\t请稍等，正在修改···\n");
	Sleep(1000);
	printf("\t\t···\n");
	Sleep(1000);
	printf("\t\t···\n");
	Sleep(1000);
	printf("\t\t恭喜！修改成功！\n");
	printf("\t\t按任意键退出");
	getch();
}
/*上架书籍*/
void Manager_Add_Book(void)
{


	char mab='1';

	while(mab!='0')
	{
		system("CLS");
		printf("\n\n\n\n\t\t\t请选择上架的种类\n\n");
		printf("\t\t\t1)增加库存\n");
		printf("\t\t\t2)上架新书\n");
		printf("\t\t\t0)退出\n");
		printf("\n\t\t\t：");
		scanf("%c",&mab);
		while(getchar()!='\n');
		switch(mab)
		{
			case '1':Manager_Add_Book1();break;
			case '2':Manager_Add_Book2();break;
			case '0':break;
			default:printf("\t\t输入错误，请重新输入\n");Sleep(3000);break;
		}
	}
}
void Manager_Add_Book1(void)
{
	Book *t;
	int n;
	char ch[20];
	Lookofnum();
	if(!Book_head->next){
		printf("\t\t无法增加库存\n");
		printf("\t\t按任意键退出");
		getch();
		return;
	}
	printf("\t\t输入新增书的编号:");
	gets(ch);
	t=Find_BookofName(ch);
	if(!t){
		printf("\t\t抱歉，无此书\n");
		printf("\t\t按任意键退出");
		getch();
		return;
	}
	printf("\t\t输入新增的数量：");
	scanf("%d",&n);
	getchar();
	t->book_rest+=n;
	Sleep(500);
	printf("\t\t正在增加···\n");
	Sleep(500);
	printf("\t\t成功增加%d本书籍\n",n);
	printf("\t\t按任意键退出");
	getch();
}
void Manager_Add_Book2(void)
{
	
	printf("\t\t请输入以下信息：\n");
	Book *new=(Book *)malloc(sizeof(Book));
	new->next=NULL;
	Book *t=Book_head;
	printf("\t\t书籍编号：");
	gets(new->book_num);
	if(Find_BookofName(new->book_num)){
		free(new);
		printf("\t\t该书已上架过，请选择增加库存\n");
		printf("\t\t按任意键退出");
		getch();
		return;
	}
	printf("\t\t书名：");
	gets(new->book_name);
	printf("\t\t作者：");
	gets(new->book_at_name);
	printf("\t\t出版社：");
	gets(new->book_cp_name);
	printf("\t\t价格：");
	scanf("%f",&new->book_price);
	getchar();
	printf("\t\t库存：");
	scanf("%d",&new->book_rest);
	getchar();
	Sleep(500);
	printf("\t\t正在上架···\n");
	Sleep(500);
	printf("\t\t···\n");
	Sleep(500);
	printf("\t\t···\n");
	Sleep(500);
	printf("\t\t上架成功！\n");
	while(t->next){
		t=t->next;
	}
	t->next=new;
	printf("\t\t按任意键退出");
	getch();
}
/*管理员下架书籍*/
void Manager_Down_Book(void)
{
	char book_num[20];
	Book *t=Book_head->next;
	Lookofnum();
	if(!t){
		printf("\t\t按任意键退出");
		getch();
		return;
	}
	printf("\t\t请输入需下架的书籍编号：");
	gets(book_num);
	t=Find_BookofName(book_num);
	if(!t){
		printf("\t\t抱歉，无此书籍\n");
		printf("\t\t按任意键退出");
		getch();
		return;
	}
	t->book_rest=0;
	Sleep(500);
	printf("\t\t正在下架···\n");
	Sleep(500);
	printf("\t\t下架成功！\n");
	printf("\t\t按任意键退出");
	getch();

}

/*管理员管理学生*/
void Manager_Manager_Stu(void)
{

	char mms='1';

	while(mms!='0')
	{
		system("CLS");
		printf("\n\n\n\n\t\t\t请选择\n\n");
		printf("\t\t\t1)查看学生名单\n");
		printf("\t\t\t2)强制学生还书\n");
		printf("\t\t\t3)删除学生号码并归还所有书籍\n");
		printf("\t\t\t0)退出\n");
		printf("\n\t\t：");
		scanf("%c",&mms);
		while(getchar()!='\n');
		switch(mms)
		{
			case '1':Manager_Look_Stu();break;
			case '2':Manager_Return_Stu();break;
			case '3':Manager_Del_Stu();;break;
			case '0':break;
			default:printf("\t\t输入错误，请重新输入\n");Sleep(3000);break;
		}
	}
}
/*管理员查看学生名单*/
void Manager_Look_Stu(void)
{
	Student *t=Student_head->next;
	printf("\t\t正在打印学生名单···\n");
	Sleep(1000);
	if(!t){
		printf("\n\t\t抱歉，暂无学生\n");
		printf("\t\t按任意键退出");
		getch();
		return;
	}
	printf("\n\n     *************************************");
	printf("********************************\n\n");
	printf("      %-10s%-12s%-15s%-10s%-12s%-10s\n\n",
		"姓名","学号","电话","账号","密码","借书数量");
	while(t)
	{
		int n=0;
		for(int i=0;i<10;i++){
			if(strcmp(t->stu_bor_book[i],"0")!=0)
				n++;
		}
		printf("      %-10s%-12s%-15s%-10s%-12s%-10d\n",
		t->stu_name,t->stu_num,t->stu_tel,
		t->stu_acc,t->stu_passw,n);
		t=t->next;
	}
	printf("\n     *****************************************");
	printf("****************************\n\n\n");
	printf("\t\t按任意键退出");
	getch();

}
/*强制还书*/
void Manager_Return_Stu(void)
{
	char ch[20];
	Book *a;
	Student *t=Student_head->next;
	
	if(!t){
		printf("\n\t\t抱歉，暂无学生\n");
		printf("\t\t按任意键退出");
		getch();
		return;
	}
	printf("\n\n\t**********************");
	printf("**********************\n\n");
	printf("\t %-10s%-12s%-10s%-8s\n\n",
		"姓名","学号","账号","借书数量");
	while(t)
	{
		int n=0;
		for(int i=0;i<10;i++){
			if(strcmp(t->stu_bor_book[i],"0")!=0)
				n++;
		}
		printf("\t %-10s%-12s%-10s%-10d\n",
		t->stu_name,t->stu_num,t->stu_acc,n);
		t=t->next;
	}
	printf("\n\t**************************");
	printf("******************\n\n\n");
	printf("\t\t请输入你想强制还书的学号：");
	gets(ch);
	t=Find_Stu(ch);
	if(!t){
		printf("\t\t抱歉，无该学生\n");
		printf("\t\t按任意键退出");
		getch();
		return;
	}
	int n=0;
	for(int i=0;i<10;i++){
		if(strcmp(t->stu_bor_book[i],"0")!=0)
			n++;
	}
	if(!n){
		printf("\t\t抱歉，该学生借书数量为0，无法强制还书\n");
		printf("\t\t按任意键退出");
		getch();
		return;
	}
	for(int i=0;i<10;i++){
		if(strcmp(t->stu_bor_book[i],"0")!=0){
			a=Find_BookofName(t->stu_bor_book[i]);
			a->book_rest+=1;
			t->stu_bor_book[i][0]='0';
			t->stu_bor_book[i][1]='\0';
		}
	}
	printf("\t\t增在强制还书···\n");
	Sleep(500);
	printf("\t\t···\n");
	Sleep(500);
	printf("\t\t强制还书成功！\n");
	printf("\t\t按任意键退出");
	getch();
	return;
}

Student *Find_Stu(char *Stu_Stuty)
{
	Student *t=Student_head->next;
	while(t){
		if(strcmp(t->stu_num,Stu_Stuty)==0)
			break;
		t=t->next;
	}
	return t;
}
void Manager_Del_Stu(void)
{
	char bh[20];
	Book *a;
	Student *head=Student_head;
	Student *t=Student_head->next;
	printf("\t\t正在打印学生名单···\n");
	Sleep(1000);
	if(!t){
		printf("\n\t\t抱歉，暂无学生\n");
		printf("\t\t按任意键退出");
		getch();
		return;
	}
	printf("\n\n     *************************************");
	printf("********************************\n\n");
	printf("      %-10s%-12s%-15s%-10s%-12s%-10s\n\n",
		"姓名","学号","电话","账号","密码","借书数量");
	while(t)
	{
		int n=0;
		for(int i=0;i<10;i++){
			if(strcmp(t->stu_bor_book[i],"0")!=0)
				n++;
		}
		printf("      %-10s%-12s%-15s%-10s%-12s%-10d\n",
		t->stu_name,t->stu_num,t->stu_tel,
		t->stu_acc,t->stu_passw,n);
		t=t->next;
	}
	printf("\n     *****************************************");
	printf("****************************\n\n\n");

	printf("\t\t请输入你想删除学生的账号：");
	gets(bh);
	t=Find_Stu(bh);
	if(!t){
		printf("\t\t抱歉，无该学生\n");
		printf("\t\t按任意键退出");
		getch();
		return;
	}
	Sleep(500);
	printf("\t\t正在删除···\n");
	Sleep(500);
	printf("\t\t删除成功！\n");
	for(int i=0;i<10;i++){
		if(strcmp(t->stu_bor_book[i],"0")!=0){
			a=Find_BookofName(t->stu_bor_book[i]);
			a->book_rest+=1;
		}
	}
	t=Student_head->next;
	while(t){
		if(strcmp(bh,t->stu_num)==0){
			head->next=t->next;

			free(t);
			break;
		}
		head=t;
		t=t->next;
	}
	printf("\t\t按任意键退出\n");
	getch();
	return;
}