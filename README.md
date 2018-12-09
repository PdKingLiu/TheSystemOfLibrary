##图书馆管理系统 （C语言）


----------


功能框架如下
![这里写图片描述](https://img-blog.csdn.net/20180506222329528?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0NvZGVGYXJtZXJfXw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)


#####管理系统主要使用了以下操作

- 单向链表的创建、增添、删除、遍历、查找、排序。
- 链表写入文件、从文件读取数据至链表。
- 密码的隐式输入、输入检测。
- 注册生成随机账号
- 账号登录检测
- 账号找回密码
- 密码简单加密存储至文件，解密加载至链表

主函数
```
#include "head.h"

int main(void)
{
	Book_head=(Book *)malloc(sizeof(Book));
	Student_head=(Student *)malloc(sizeof(Student));
	Manager_head=(Manager *)malloc(sizeof(Manager));

	Book_head->next=Book_load();
	Student_head->next=Student_load();
	Manager_head->next=Manager_load();

	char ma='1';

	while(ma!='0')
	{
		show_main();
		printf("\t\t\t：");
		scanf("%c",&ma);
		while(getchar()!='\n');
		switch(ma)
		{
			case '1':Student_Port();break;	//学生端
			case '2':Manager_Port();break;	//管理员端
			case '0':Massage_Save();break;	//退出程序，保存链表数据至文件中
			default:printf("\t\t输入错误，请重新输入\n");Sleep(3000);break;
		}
	}
	system("PAUSE");
	return 0;
}
```

头文件里面得事先声明三个链表（分别是学生链表、书籍链表、管理员链表）的头结点，在main函数里面首先三行是为三个变量分配内存，然后三行是从文件里面加载信息至链表（相当于创建链表）把创建的链表赋值给每个节点的next，若文件为空，说明无信息，加载信息的函数返回NULL，next赋值为NULL，具体函数请下载源代码查看。

**以下为各个功能的具体注意事项**

###学生端
1. 登录
登录端口先进行账号输入，然后输入密码，密码输入长度确定在一定范围内，密码格式不正确提示重新输入，输入密码时应注意，密码不能显示（显示为*），第二就是要实现删除错误输入的功能，其次先检测账号是否存在，若不存在，直接提示账号不存在，返回上一层，否则，检测密码的正确性，如果不正确，记录错误次数，错误三次将退出系统。
2. 注册
注册需要这注意的也是密码的问题，密码的长度，错误次数检测，相关密码的操作可以写一个函数，多次调用。
3. 找回密码
先检测账号是否存在，不存在提示无此账号，退出上一层，否则根据密码输入的要求输入密码检测即可。

###管理员端
登录和学生的登录一样，密码的验证都类似，只不过管理员账号是固定的，直接在文件里面写着，每次进入程序时，就从文件里面读到链表。

###文件写入和读取
这个就是可以根据自己的想法对密码加密后存入文件，读取的时候再以自己的规则解密就行，可以参考我的简单的加密。

#### 链表



######1. 学生链表

```
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
```
  
#####2.书籍链表
```
typedef struct book{
	char book_num[10];				//书号
	char book_name[20];				//书名
	char book_at_name[30];			//作者名
	char book_cp_name[30];			//出版社
	float book_price;				//价格
	int book_rest;					//库存
	struct book *next;				//下本书
}Book;
```

#####3.管理员链表

```
typedef struct manager{
	char man_name[15];				//管理员姓名
	char man_acc[10];				//管理员账号
	char man_passw[15];				//管理员密码
	struct manager *next;			//下个管理员
}Manager;
```
####函数
```
void show_main(void);							//主界面
void show_stu(void);							//学生端
void show_stu_enter(void);						//学生页
void show_manager(void);						//管理员端
void show_manager_enter(void);					//管理员页
Book *Book_load(void);							//将书籍文件中的信息加载至书籍链表
Student *Student_load(void);					//将学生文件中的信息加载至学生链表
Manager *Manager_load(void);					//将管理员文件的信息加载至管理员链表
void RandStr(int l,char* ch);					//随机获取一定长度字符串
void Student_Port(void);						//学生端口
void Manager_Port(void);						//管理员端口	
void Student_Login(void);						//学生端登录
void Student_Register(void);					//学生注册账号
void Find_Password(void);						//学生找回密码
void Password_Input(char *Password);			//输入密码函数
int Password_Text(char *Password_temp);			//检测密码
Student *Find_Num(char *Stu_num);				//按学号查找学生
int Password_Text_Find(char *Password);			//密保问题密码验证
void Stu_Borrow(Student *Stu_num);				//学生借书
void Stu_Back(Student *Stu_num);				//学生还书
void Find_Book(void);							//查找书
void Find_Theborrow(Student *Stu_num);			//学生查看所借书
void Change_Stupassword(Student *Stu_num);		//修改密码
Book *Find_BookofName(char *Book_num);			//按书号查找书
void Print_Book(void);							//打印书单
Book *Book_exit(char *Book_num);				//寻找该书是否存在
int Ifborrow(Student *Stu_num,char *Book_num);	//查询学生是否结果此书
void Print_Borbook(Student *Stu_num);			//打印所借书街
void Bake_Book(Student *Stu_num,char *Book_num);//还书具体操作
void Manager_Login(void);						//管理员登录
Manager *Manager_check(char *Manager_num);		//核对管理员账号
void Manager_Add_Book(void);					//管理员上架书籍
void Manager_Down_Book(void);					//管理员下架书籍
void Manager_Look_Book(void);					//管理员浏览书架
void Manager_Manager_Stu(void);					//管理员管理学生
void Manager_Change_Password(Manager *Man_num);//管理员修改密码
void Lookofnum(void);							//编号升序查看书架
void Lookofrest(void);							//库存升序查看书架
void Lookofprice(void);							//价格升序查看
void Manager_Print_Book(void);					//管理员打印书架
void Manager_Add_Book1(void);					//增加库存
void Manager_Add_Book2(void);					//上架新书
void Save_Book(void);							//保存书籍链表至文件
void Save_Student(void);						//保存学生链表至文件
void Save_Manger(void);							//保存管理员链表至文件
void Massage_Save(void);						//所有信息保存至文件
void Manager_Look_Stu(void);					//管理员查看学生名单
void Manager_Return_Stu(void);					// 管理员强制学生还书
void Manager_Del_Stu(void);						// 删除学生号码并归还所有书籍
Student *Find_Stu(char *Stu_Stuty);				//按学号查学生
```

##文件目录##
![这里写图片描述](https://img-blog.csdn.net/20180513130151447?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0NvZGVGYXJtZXJfXw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

##源代码##
[源代码下载](https://pan.baidu.com/s/1qgxCP3lZj89Sk4yHnmbRiA)
> 注：管理员账号只有两个
> 账号：931942280  密码123456
> 账号：10861646  密码123456


##主页面##
![这里写图片描述](https://img-blog.csdn.net/20180513130211132?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0NvZGVGYXJtZXJfXw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)
##学生端##
![这里写图片描述](https://img-blog.csdn.net/20180513130223480?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0NvZGVGYXJtZXJfXw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)
##登录成功进入学生页##
![这里写图片描述](https://img-blog.csdn.net/20180513130234268?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0NvZGVGYXJtZXJfXw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)
##管理员端##
![这里写图片描述](https://img-blog.csdn.net/20180513130244246?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0NvZGVGYXJtZXJfXw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)
##管理员页##
![这里写图片描述](https://img-blog.csdn.net/20180513130251667?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0NvZGVGYXJtZXJfXw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)
