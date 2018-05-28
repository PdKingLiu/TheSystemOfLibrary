#ifndef HEAD_H_
#define HEAD_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>

typedef struct book{
	char book_num[10];				//书号
	char book_name[20];				//书名
	char book_at_name[30];			//作者名
	char book_cp_name[30];			//出版社
	float book_price;				//价格
	int book_rest;					//库存
	struct book *next;				//下本书
}Book;

typedef struct stu{
	char stu_acc[10];				//学生账号
	char stu_passw[15];				//学生密码
	char stu_find_question[30];		//密保问题
	char stu_find_passw[15];		//密保问题密码	
	char stu_num[10];				//学生学号
	char stu_name[20];				//学生姓名
	char stu_tel[15];				//学生电话
	char stu_bor_book[10][20];		//所借书号
	struct stu *next;				//下位学生
}Student;

typedef struct manager{
	char man_name[15];				//管理员姓名
	char man_acc[10];				//管理员账号
	char man_passw[15];				//管理员密码
	struct manager *next;			//下个管理员
}Manager;

Book *Book_head;
Student *Student_head;
Manager *Manager_head;

void show_main(void);						
//主界面
void show_stu(void);						
//学生端
void show_stu_enter(void);					
//学生页
void show_manager(void);					
//管理员端
void show_manager_enter(void);				
//管理员页
Book *Book_load(void);						
//将书籍文件中的信息加载至书籍链表
Student *Student_load(void);				
//将学生文件中的信息加载至学生链表
Manager *Manager_load(void);				
//将管理员文件的信息加载至管理员链表
void RandStr(int l,char* ch);				
//随机获取一定长度字符串
void Student_Port(void);					
//学生端口
void Manager_Port(void);					
//管理员端口	
void Student_Login(void);					
//学生端登录
void Student_Register(void);				
//学生注册账号
void Find_Password(void);					
//学生找回密码
void Password_Input(char *Password);		
//输入密码函数
int Password_Text(char *Password_temp);		
//检测密码
Student *Find_Num(char *Stu_num);			
//按学号查找学生
int Password_Text_Find(char *Password);		
//密保问题密码验证
void Stu_Borrow(Student *Stu_num);			
//学生借书
void Stu_Back(Student *Stu_num);			
//学生还书
void Find_Book(void);						
//查找书
void Find_Theborrow(Student *Stu_num);		
//学生查看所借书
void Change_Stupassword(Student *Stu_num);	
//修改密码
Book *Find_BookofName(char *Book_num);		
//按书号查找书
void Print_Book(void);						
//打印书单
Book *Book_exit(char *Book_num);			
//寻找该书是否存在
int Ifborrow(Student *Stu_num,char *Book_num);
//查询学生是否结果此书
void Print_Borbook(Student *Stu_num);		
//打印所借书街
void Bake_Book(Student *Stu_num,char *Book_num);
//还书具体操作
void Manager_Login(void);					
//管理员登录
Manager *Manager_check(char *Manager_num);	
//核对管理员账号
void Manager_Add_Book(void);				
//管理员上架书籍
void Manager_Down_Book(void);				
//管理员下架书籍
void Manager_Look_Book(void);				
//管理员浏览书架
void Manager_Manager_Stu(void);			
//管理员管理学生
void Manager_Change_Password(Manager *Man_num);
//管理员修改密码
void Lookofnum(void);						
//编号升序查看书架
void Lookofrest(void);						
//库存升序查看书架
void Lookofprice(void);						
//价格升序查看
void Manager_Print_Book(void);				
//管理员打印书架
void Manager_Add_Book1(void);				
//增加库存
void Manager_Add_Book2(void);				
//上架新书
void Save_Book(void);						
//保存书籍链表至文件
void Save_Student(void);					
//保存学生链表至文件
void Save_Manger(void);						
//保存管理员链表至文件
void Massage_Save(void);					
//所有信息保存至文件
void Manager_Look_Stu(void);
//管理员查看学生名单
void Manager_Return_Stu(void);
// 管理员强制学生还书
void Manager_Del_Stu(void);
// 删除学生号码并归还所有书籍
Student *Find_Stu(char *Stu_Stuty);
//按学号查学生

#endif