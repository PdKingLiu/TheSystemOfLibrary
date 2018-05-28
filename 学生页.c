#include "head.h"
void Find_Book(void)
{
	Book *t=Book_head->next;
	char book_n[20];
	if(t==NULL){
		printf("\t\t抱歉，暂无书籍\n");
		printf("\t\t按任意键退出");
		getch();
		return;
	}
	printf("\t\t请输入你需要查找的书名：");
	gets(book_n);
	while(t){
		if(strcmp(book_n,t->book_name)==0)
			break;
		t=t->next;
	}
	if(t==NULL){
		printf("\t\t抱歉，无此书籍\n");
		printf("\t\t按任意键退出");
		getch();
		return;
	}
	t=Book_head->next;
	printf("\n\n\t**********************************");
	printf("********************************\n\n");
	printf("\t %-8s%-12s%-12s%-18s%-10s%-8s\n\n",
		"编号","书名","作者","出版社","价格","库存");
	while(t){
		if(strcmp(book_n,t->book_name)==0)
			printf("\t %-8s%-12s%-12s%-18s%-10.2f%-8d\n",
			t->book_num,t->book_name,t->book_at_name,
			t->book_cp_name,t->book_price,t->book_rest);
		t=t->next;
	}
	printf("\n\t**************************************");
	printf("****************************\n\n\n");
	printf("\n\t\t按任意键退出");
	getch();

}

Book *Find_BookofName(char *Book_num)
{
	Book *t=Book_head->next;
	while(t){
		if(strcmp(Book_num,t->book_num)==0)
			return t;
		t=t->next;
	}
}
void Change_Stupassword(Student *Stu_num)
{
	char password_tem[20];
	printf("\t\t加载中···\n");
	Sleep(500);
	printf("\t\t请输入原密码：");
	if(Password_Text_Find(Stu_num->stu_passw)==0){
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
		Sleep(3000);
		return;
	}
	Stu_num->stu_passw[0]='\0';
	strcat(Stu_num->stu_passw,password_tem);
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
void Find_Theborrow(Student *Stu_num)
{
	int tem=0;
	Book *t;
	printf("\t\t查找中···\n");
	Sleep(1000);
	for(int i=0;i<10;i++){
		if(strcmp(Stu_num->stu_bor_book[i],"0")!=0){
			tem=1;
			break;
		}
	}
	if(tem==0){
		printf("\t\t暂无借书记录\n");
		printf("\t\t按任意键退出");
		getch();
		return;
	}
	printf("\n\n\t*************************");
	printf("********************************\n\n");
	printf("\t %-8s%-12s%-12s%-18s%-10s\n\n",
		"编号","书名","作者","出版社","价格");
	for(int i=0;i<10;i++){
		if(strcmp(Stu_num->stu_bor_book[i],"0")!=0){
			t=Find_BookofName(Stu_num->stu_bor_book[i]);
			printf("\t %-8s%-12s%-12s%-18s%-10.2f\n",
			t->book_num,t->book_name,t->book_at_name,
			t->book_cp_name,t->book_price);
		}
	}
	printf("\n\t*****************************");
	printf("****************************\n\n\n");
	printf("\n\t\t按任意键退出");
	getch();
}

void Stu_Borrow(Student *Stu_num)
{
	int n=0;
	Book *t;
	char numb[10];
	for(int i=0;i<10;i++){
		if(strcmp(Stu_num->stu_bor_book[i],"0")!=0)
			n++;
	}
	printf("\n\t\t欢迎进入借书系统\n");
	printf("\n\t\t加载中···\n");
	Sleep(1000);
	if(n==10){
		printf("\t\t您好，您已借书10本，已到最大借书限额，");
		printf("\t\t请先归还已借书籍\n\n");
		printf("\t\t按任意键退出");
		getch();
		return;
	}
	printf("\t\t您已借书籍%d本，还可借%d本\n",n,10-n);
	printf("\t\t书单如下\n");
	Print_Book();
	printf("\n\t\t请选择你想借书的编号：");
	gets(numb);
	t=Book_exit(numb);
	printf("\t\t正在办理···\n");
	Sleep(1000);
	if(!t){
		printf("\t\t抱歉，无此书，借书失败\n");
		printf("\t\t按任意键退出");
		getch();
		return;
	}
	if(t->book_rest==0){
		printf("\t\t抱歉，库存不足，借书失败\n");
		printf("\t\t按任意键退出");
		getch();
		return;
	}
	if(Ifborrow(Stu_num,numb)){
		printf("\t\t抱歉，您已借过此书，请勿重复借书\n");
		printf("\t\t按任意键退出");
		getch();
		return;
	}
	for(int i=0;i<10;i++){
		if(strcmp(Stu_num->stu_bor_book[i],"0")==0){
			Stu_num->stu_bor_book[i][0]='\0';
			strcat(Stu_num->stu_bor_book[i],numb);
			t->book_rest--;
			break;
		}
	}
	printf("\t\t···\n");
	printf("\t\t恭喜您办理成功！\n");
	printf("\t\t按任意键退出");
	getch();
	return;
}

/*打印书单*/
void Print_Book(void)
{
	Book *t=Book_head->next;
	if(t==NULL){
		printf("\t\t抱歉，暂无上架书籍\n");
		Sleep(2000);
		return;
	}
	printf("\n\n\t**********************************");
	printf("********************************\n\n");
	printf("\t %-8s%-12s%-12s%-18s%-10s%-8s\n\n",
		"编号","书名","作者","出版社","价格","库存");
	while(t){
		printf("\t %-8s%-12s%-12s%-18s%-10.2f%-8d\n",
		t->book_num,t->book_name,t->book_at_name,
		t->book_cp_name,t->book_price,t->book_rest);
		t=t->next;
	}
	printf("\n\t**************************************");
	printf("****************************\n\n\n");
}
/*寻找该书是否存在*/
Book *Book_exit(char *Book_num)
{
	
	Book *t=Book_head->next;
	while(t){
		if(strcmp(t->book_num,Book_num)==0)
			break;
		t=t->next;
	}
	return t;
}
/*查询学生是否借过此书*/
int Ifborrow(Student *Stu_num,char *Book_num)
{
	int tem=0;
	for(int i=0;i<10;i++){
		if(strcmp(Stu_num->stu_bor_book[i],Book_num)==0){
			tem=1;
			break;
		}
	}
	return tem;
}
/*学生还书*/
void Stu_Back(Student *Stu_num)
{
	char book_num[15];
	int tem=0;
	printf("\n\t\t欢迎进入还书系统\n");
	printf("\n\t\t加载中···\n");
	Sleep(500);
	printf("\n\t\t正在查找已借书籍···\n");
	Sleep(500);
	for(int i=0;i<10;i++){
		if(strcmp(Stu_num->stu_bor_book[i],"0")!=0){
			tem=1;
			break;
		}
	}
	if(tem==0){
		printf("\n\t\t暂无借书记录\n");
		printf("\n\t\t按任意键退出");
		getch();
		return;
	}
	Print_Borbook(Stu_num);
	printf("\n\t\t请输入书的编号进行归还：");
	gets(book_num);
	tem=0;
	for(int i=0;i<10;i++){
		if(strcmp(Stu_num->stu_bor_book[i],book_num)==0){
			tem=1;
			break;
		}
	}
	if(!tem){
		printf("\t\t输入错误，您未借过此书\n");
		printf("\t\t按任意键退出");
		getch();
		return;
	}

	Sleep(500);
	printf("\t\t正在归还···\n");
	Sleep(500);
	Bake_Book(Stu_num,book_num);
	printf("\t\t归还成功！\n");
	printf("\t\t按任意键退出");
	getch();
}
/*打印所借书籍*/
void Print_Borbook(Student *Stu_num)
{

	int tem=0;
	Book *t;
	printf("\n\n\t*************************");
	printf("********************************\n\n");
	printf("\t %-8s%-12s%-12s%-18s%-10s\n\n",
		"编号","书名","作者","出版社","价格");
	for(int i=0;i<10;i++){
		if(strcmp(Stu_num->stu_bor_book[i],"0")!=0){
			t=Find_BookofName(Stu_num->stu_bor_book[i]);
			printf("\t %-8s%-12s%-12s%-18s%-10.2f\n",
			t->book_num,t->book_name,t->book_at_name,
			t->book_cp_name,t->book_price);
		}
	}
	printf("\n\t*****************************");
	printf("****************************\n\n\n");
}
/*还书具体操作*/
void Bake_Book(Student *Stu_num,char *Book_num)
{
	Book *t;
	for(int i=0;i<10;i++){
		if(strcmp(Stu_num->stu_bor_book[i],Book_num)==0){
			Stu_num->stu_bor_book[i][0]='0';
			Stu_num->stu_bor_book[i][1]='\0';
			break;
		}
	}
	t=Find_BookofName(Book_num);
	t->book_rest++;
}