/**
 * @FileName main.cpp
 */
#include <bits/stdc++.h>
#include <conio.h>
#include "User.h"
#include "log.h"
#include "input.h"
#include "student.h"
#define print_title printf("学号\t  姓名\t   班级\t      身份证号\t\t  语文成绩  数学成绩  英语成绩  总成绩\n")

#define debug printf("PASS IN LINE:%d\n",__LINE__)

using namespace std;

vector <student> _Stu;
int cnt;

void init(){//Get student information from file
	ifstream file("bin\\Student\\index.idx");
	file>>cnt;
	file.close();
	for(int i=0;i<cnt;i++){
		student st;
		st.FIlE_Get(i+1);
		_Stu.push_back(st);
		_Stu[i].score_tot=_Stu[i].score_c+_Stu[i].score_m+_Stu[i].score_e;
	}
}

void outit(){//Write student information to file
	ofstream file("bin\\Student\\index.idx");
	file<<cnt;
	file.close();
	sort(_Stu.begin(),_Stu.end(),cmp0);
	for(int i=0;i<cnt;i++){
		_Stu[i].write_stu(i+1);
	}
}

void print_stu_all(){//Print all student information
	printf("学号\t  姓名\t   班级\t      身份证号\t\t  语文成绩  数学成绩  英语成绩  总成绩\n");
	for(int i=0;i<cnt;i++){
		cout<<setw(10)<<setiosflags(ios::left)<<_Stu[i].school_ID<<setw(10)<<setiosflags(ios::left)<<_Stu[i].name<<setw(10)<<setiosflags(ios::left)<<_Stu[i].Class<<setw(20)<<setiosflags(ios::left)<<_Stu[i].ID<<setw(10)<<setiosflags(ios::left)<<_Stu[i].score_c<<setw(10)<<setiosflags(ios::left)<<_Stu[i].score_m<<setw(10)<<setiosflags(ios::left)<<_Stu[i].score_e<<setw(10)<<setiosflags(ios::left)<<_Stu[i].score_tot<<endl;
	}
}

void print_stu(int i){//Print i_th student information
	cout<<setw(10)<<setiosflags(ios::left)<<_Stu[i].school_ID<<setw(10)<<setiosflags(ios::left)<<_Stu[i].name<<setw(10)<<setiosflags(ios::left)<<_Stu[i].Class<<setw(20)<<setiosflags(ios::left)<<_Stu[i].ID<<setw(10)<<setiosflags(ios::left)<<_Stu[i].score_c<<setw(10)<<setiosflags(ios::left)<<_Stu[i].score_m<<setw(10)<<setiosflags(ios::left)<<_Stu[i].score_e<<setw(10)<<setiosflags(ios::left)<<_Stu[i].score_tot<<endl;
}

int darw_find_score(){//Darw find_score interface
	int x=40,y=0;
	while(1){
		system("cls");
		for(int i=1;i<=37;i++) printf(" ");
		for(int i=1;i<=20;i++) printf("*");
		printf("\n");
		for (int i=0;i<5;i++){
			for (int j=0;j<=40;j++){
				if (j==x&&i==y){
					printf(">");
				}
				else printf(" ");
			}
			if(i==0) printf(" 按总分查找 ");
			if(i==1) printf(" 按语文成绩查找 ");
			if(i==2) printf(" 按数学成绩查找 ");
			if(i==3) printf(" 按英语成绩查找 ");
			if(i==4) printf(" 返回 ");
			for(int k=1;k<5;k++) printf(" ");
			printf("\n");
	}
	for(int i=1;i<=37;i++) printf(" ");
	for(int i=1;i<=20;i++) printf("*");
	printf("\n");
		char input;
		input=getch();
		if(input==80&&y<4) y++;
		if(input==72&&y>0) y--;
		if(input==13) break;
	}
	return y;
}

void find_score(){//Search accroding user input range
	while(1){
		int flag=darw_find_score();
		int l,r;
		if(flag==0){
			printf("请输入查询下限:");
			l=input();
			printf("请输入查询上限:");
			r=input();
			print_title;
			if(l>r) swap(l,r);
			for(int i=0;i<cnt;i++){
				if(_Stu[i].score_tot>=l&&_Stu[i].score_tot<=r){
					print_stu(i);
				}
			}
			system("pause");
		} 
		if(flag==1){
			printf("请输入查询下限:");
			l=input();
			printf("请输入查询上限:");
			r=input();
			if(l>r) swap(l,r);
			print_title;
			for(int i=0;i<cnt;i++){
				if(_Stu[i].score_c>=l&&_Stu[i].score_c<=r){
					print_stu(i);
				}
			}
			system("pause");
		} 
		if(flag==2){
			printf("请输入查询下限:");
			l=input();
			printf("请输入查询上限:");
			r=input();
			print_title;
			if(l>r) swap(l,r);
			for(int i=0;i<cnt;i++){
				if(_Stu[i].score_m>=l&&_Stu[i].score_m<=r){
					print_stu(i);
				}
			}
			system("pause");
		}
		if(flag==3){
			printf("请输入查询下限:");
			l=input();
			printf("请输入查询上限:");
			r=input();
			print_title;
			if(l>r) swap(l,r);
			for(int i=0;i<cnt;i++){
				if(_Stu[i].score_e>=l&&_Stu[i].score_e<=r){
					print_stu(i);
				}
			}
			system("pause");
		}
		if(flag==4) break;
	}

}

void find_name(){//Search accroding user input name
	string s;
	printf("请输入要查找的姓名： ");
	cin>>s;
	print_title;
	for(int i=0;i<cnt;i++){
		if(_Stu[i].name==s){
			print_stu(i);
		}
	}
	system("pause");
}

void find_school_ID(){//Search accroding user input school ID
	string s;
	printf("请输入要查找的学号： ");
	cin>>s;
	print_title;
	for(int i=0;i<cnt;i++){
		if(_Stu[i].school_ID==s){
			print_stu(i);
		}
	}
	system("pause");
}

void find_ID(){//Search accroding user input ID
	string s;
	printf("请输入要查找的身份证号： ");
	cin>>s;
	print_title;
	for(int i=0;i<cnt;i++){
		if(_Stu[i].ID==s){
			print_stu(i);
		}
	}
	system("pause");
}

void find_Class(){//Search accroding user input class
	string s;
	printf("请输入要查找的班级： ");
	cin>>s;
	print_title;
	for(int i=0;i<cnt;i++){
		if(_Stu[i].Class==s){
			print_stu(i);
		}
	}
	system("pause");
}

void find_ac(){
	print_title;
	for(int i=0;i<cnt;i++){
		if(_Stu[i].AC==1){
			print_stu(i);
		}
	}
	system("pause");
}

void find_unac(){
	print_title;
	for(int i=0;i<cnt;i++){
		if(_Stu[i].AC==0){
			print_stu(i);
		}
	}
	system("pause");
}

void show_all(){
	printf("学号\t  姓名\t   班级\t      身份证号\t\t  语文成绩  数学成绩  英语成绩  总成绩\t\t报道状态\n");
	for(int i=0;i<cnt;i++){
		cout<<setw(10)<<setiosflags(ios::left)<<_Stu[i].school_ID<<setw(10)<<setiosflags(ios::left)<<_Stu[i].name<<setw(10)<<setiosflags(ios::left)<<_Stu[i].Class<<setw(20)<<setiosflags(ios::left)<<_Stu[i].ID<<setw(10)<<setiosflags(ios::left)<<_Stu[i].score_c<<setw(10)<<setiosflags(ios::left)<<_Stu[i].score_m<<setw(10)<<setiosflags(ios::left)<<_Stu[i].score_e<<setw(10)<<setiosflags(ios::left)<<_Stu[i].score_tot<<"\t";
		if(_Stu[i].AC==1)printf("已报道\n");
		else printf("未报到\n");
	}
	system("pause");
}

int darw_Find(){/*function darw is darw a function interface*/
		int x=40,y=0;
	while(1){
		system("cls");
		for(int i=1;i<=37;i++) printf(" ");
		for(int i=1;i<=20;i++) printf("*");
		printf("\n");
		for (int i=0;i<9;i++){
			for (int j=0;j<=40;j++){
				if (j==x&&i==y){
					printf(">");
				}
				else printf(" ");
			}
			if(i==0) printf(" 按名字查找 ");
			if(i==1) printf(" 按学号查找 ");
			if(i==2) printf(" 按身份证号查找 ");
			if(i==3) printf(" 按班级查找 ");
			if(i==4) printf(" 按分数段查找 ");
			if(i==5) printf(" 已报道 ");
			if(i==6) printf(" 未报道 ");
			if(i==7) printf(" 显示所有学生名单 ");
			if(i==8) printf(" 返回 ");
			for(int k=1;k<5;k++) printf(" ");
			printf("\n");
	}
	for(int i=1;i<=37;i++) printf(" ");
	for(int i=1;i<=20;i++) printf("*");
	printf("\n");
		char input;
		input=getch();
		if(input==80&&y<8) y++;
		if(input==72&&y>0) y--;
		if(input==13) break;
	}
	return y;
}

void _Find(){
	while(1){
		int flag=darw_Find();
		if(flag==0) find_name();
		if(flag==1) find_school_ID();
		if(flag==2) find_ID();
		if(flag==3) find_Class();
		if(flag==4) find_score();
		if(flag==5) find_ac();
		if(flag==6) find_unac();
		if(flag==7) show_all();
		if(flag==8) break;
	}
}

int darw_Ranking(){
	int x=40,y=0;
	while(1){
		system("cls");
		for(int i=1;i<=39;i++) printf(" ");
		for(int i=1;i<=20;i++) printf("*");
		printf("\n");
		for (int i=0;i<5;i++){
			for (int j=0;j<=40;j++){
				if (j==x&&i==y){
					printf(">");
				}
				else printf(" ");
			}
			if(i==0) printf(" 按总成绩排序 ");
			if(i==1) printf(" 按语文成绩排序 ");
			if(i==2) printf(" 按数学成绩排序 ");
			if(i==3) printf(" 按英语成绩排序 ");
			if(i==4) printf(" 返回 ");
			for(int k=1;k<5;k++) printf(" ");
			printf("\n");
	}
	for(int i=1;i<=39;i++) printf(" ");
	for(int i=1;i<=20;i++) printf("*");
	printf("\n");
		char input;
		input=getch();
		if(input==80&&y<4) y++;
		if(input==72&&y>0) y--;
		if(input==13) break;
	}
	return y;
}

int darw_sort_by(){
	int x=40,y=0;
	while(1){
		system("cls");
		for(int i=1;i<=35;i++) printf(" ");
		for(int i=1;i<=20;i++) printf("*");
		printf("\n");
		for (int i=0;i<2;i++){
			for (int j=0;j<=40;j++){
				if (j==x&&i==y){
					printf(">");
				}
				else printf(" ");
			}
			if(i==0) printf(" 降序 ");
			if(i==1) printf(" 升序 ");
			for(int k=1;k<5;k++) printf(" ");
			printf("\n");
	}
	for(int i=1;i<=35;i++) printf(" ");
	for(int i=1;i<=20;i++) printf("*");
	printf("\n");
		char input;
		input=getch();
		if(input==80&&y<2) y++;
		if(input==72&&y>0) y--;
		if(input==13) break;
	}
	return y;
}

void Ranking(){//sort
	while(1){
		int flag=darw_Ranking();
		if(flag==0){
			int f=darw_sort_by();
			if(f==1){
				sort(_Stu.begin(),_Stu.end(),cmp1_1);
			}else{
				sort(_Stu.begin(),_Stu.end(),cmp1_2);
			}
		}
		if(flag==1){
			int f=darw_sort_by();
			if(f==1){
				sort(_Stu.begin(),_Stu.end(),cmp2_1);
			}else{
				sort(_Stu.begin(),_Stu.end(),cmp2_2);
			}
		} 
		if(flag==2){
			int f=darw_sort_by();
			if(f==1){
				sort(_Stu.begin(),_Stu.end(),cmp3_1);
			}else{
				sort(_Stu.begin(),_Stu.end(),cmp3_2);
			}
		} 
		if(flag==3){
			int f=darw_sort_by();
			if(f==1){
				sort(_Stu.begin(),_Stu.end(),cmp4_1);
			}else{
				sort(_Stu.begin(),_Stu.end(),cmp4_2);
			}
		} 
		if(flag==4) break;
		print_stu_all();
		system("pause");
	}
}

int darw_find(){
		int x=40,y=0;
	while(1){
		system("cls");
		for(int i=1;i<=37;i++) printf(" ");
		for(int i=1;i<=20;i++) printf("*");
		printf("\n");
		for (int i=0;i<3;i++){
			for (int j=0;j<=40;j++){
				if (j==x&&i==y){
					printf(">");
				}
				else printf(" ");
			}
			if(i==0) printf(" 排序 ");
			if(i==1) printf(" 查找 ");
			if(i==2) printf(" 返回 ");
			for(int k=1;k<5;k++) printf(" ");
			printf("\n");
	}
	for(int i=1;i<=37;i++) printf(" ");
	for(int i=1;i<=20;i++) printf("*");
	printf("\n");
		char input;
		input=getch();
		if(input==80&&y<2) y++;
		if(input==72&&y>0) y--;
		if(input==13) break;
	}
	return y;
}

void inf_find(){
	while(1){
		int flag=darw_find();
		if(flag==0) Ranking();
		if(flag==1) _Find();
		if(flag==2) break;
	}
}

int darw_admin_ctl(){
	int x=40,y=0;
	while(1){
		system("cls");
		for(int i=1;i<=37;i++) printf(" ");
		for(int i=1;i<=20;i++) printf("*");
		printf("\n");
		for (int i=0;i<3;i++){
			for (int j=0;j<=40;j++){
				if (j==x&&i==y){
					printf(">");
				}
				else printf(" ");
			}
			if(i==0) printf(" 授权新的账户 ");
			if(i==1) printf(" 修改密码 ");
			if(i==2) printf(" 返回 ");
			for(int k=1;k<5;k++) printf(" ");
			printf("\n");
	}
	for(int i=1;i<=37;i++) printf(" ");
	for(int i=1;i<=20;i++) printf("*");
	printf("\n");
		char input;
		input=getch();
		if(input==80&&y<2) y++;
		if(input==72&&y>0) y--;
		if(input==13) break;
	}
	return y;
}

void admin_ctl(){
	int flag=darw_admin_ctl();
	if(flag==0) Register();
	else if(flag==1) now.change_key();
	else return;
}

int darw_change_stu(){
	int x=40,y=0;
	while(1){
		system("cls");
		printf("学号\t  姓名\t   班级\t      身份证号\t\t  语文成绩  数学成绩  英语成绩\n");
		for (int i=0;i<=cnt;i++){
			for (int j=0;j<=40;j++){
				if (j==x&&i==y){
					printf(">");
				}
				else printf("");
			}
			if(i!=cnt){
				cout<<setw(10)<<setiosflags(ios::left)<<_Stu[i].school_ID<<setw(10)<<setiosflags(ios::left)<<_Stu[i].name<<setw(10)<<setiosflags(ios::left)<<_Stu[i].Class<<setw(20)<<setiosflags(ios::left)<<_Stu[i].ID<<setw(10)<<setiosflags(ios::left)<<_Stu[i].score_c<<setw(10)<<setiosflags(ios::left)<<_Stu[i].score_m<<setw(10)<<setiosflags(ios::left)<<_Stu[i].score_e<<endl;
			}
			if(i==cnt) printf("返回 ");
			printf("\n");
		}
		char input;
		input=getch();
		if(input==80&&y<cnt) y++;
		if(input==72&&y>0) y--;
		if(input==13) break;
	}
	return y;
}

int darw_change(int flag){
	int x=40,y=0;
	while(1){
		system("cls");
		for (int i=0;i<8;i++){
			for (int j=0;j<=40;j++){
				if (j==x&&i==y){
					printf(">");
				}
				else printf("");
			}
			if(i==0) printf("学号： "),cout<<_Stu[flag].school_ID<<endl;
			if(i==1) printf("姓名： "),cout<<_Stu[flag].name<<endl;
			if(i==2) printf("班级： "),cout<<_Stu[flag].Class<<endl;
			if(i==3) printf("身份证号码： "),cout<<_Stu[flag].ID<<endl;
			if(i==4) printf("语文成绩： "),cout<<_Stu[flag].score_c<<endl;
			if(i==5) printf("数学成绩： "),cout<<_Stu[flag].score_m<<endl;
			if(i==6) printf("英语成绩： "),cout<<_Stu[flag].score_e<<endl;
			if(i==7) printf("返回 ");
			printf("\n");
	}
		char input;
		input=getch();
		if(input==80&&y<7) y++;
		if(input==72&&y>0) y--;
		if(input==13) break;
	}
	return y;
}

void change_stu(){//change student information
	while(1){
		int flag=darw_change_stu();
		if(flag==cnt) break;
		int f=darw_change(flag);
		string opr;
		if(f==0){
			printf(u8"请输入更正后的学号: ");
			opr="change school ID "+_Stu[flag].school_ID;
			cin>>_Stu[flag].school_ID;
			opr+=" into "+_Stu[flag].school_ID+" in file "+dig(_Stu[flag].FILE_ID);
			put_log(now.ID,opr);
		}
		if(f==1){
			printf(u8"请输入更正后的姓名: ");
			opr="change name "+_Stu[flag].name;
			cin>>_Stu[flag].name;
			opr+=" into "+_Stu[flag].name+" in file "+dig(_Stu[flag].FILE_ID);
			put_log(now.ID,opr);
		}
		if(f==2){
			printf(u8"请输入更正后的班级: ");
			opr="change class "+_Stu[flag].Class;
			cin>>_Stu[flag].Class;
			opr+=" into "+_Stu[flag].Class+" in file "+dig(_Stu[flag].FILE_ID);
			put_log(now.ID,opr);
		}
		if(f==3){
			printf(u8"请输入更正后的身份证号码: ");
			opr="change ID "+_Stu[flag].ID;
			cin>>_Stu[flag].ID;
			opr+=" into "+_Stu[flag].Class+" in file "+dig(_Stu[flag].FILE_ID);
			put_log(now.ID,opr);
		}
		if(f==4){
			printf(u8"请输入更正后的语文成绩: ");
			opr="change chinese score "+_Stu[flag].score_c;
			cin>>_Stu[flag].score_c;
			opr+=" into "+dig(_Stu[flag].score_c)+" in file "+dig(_Stu[flag].FILE_ID);
			put_log(now.ID,opr);
		}
		if(f==5){
			printf(u8"请输入更正后的数学成绩: ");
			opr="change math score "+_Stu[flag].score_m;
			cin>>_Stu[flag].score_m;
			opr+=" into "+dig(_Stu[flag].score_m)+" in file "+dig(_Stu[flag].FILE_ID);
			put_log(now.ID,opr);
		}
		if(f==6){
			printf(u8"请输入更正后的英语成绩: ");
			opr="change english score "+_Stu[flag].score_e;
			cin>>_Stu[flag].score_e;
			opr+=" into "+dig(_Stu[flag].score_e)+" in file "+dig(_Stu[flag].FILE_ID);
			put_log(now.ID,opr);
		}
		if(f==7) continue;
		_Stu[flag].score_tot=_Stu[flag].score_c+_Stu[flag].score_m+_Stu[flag].score_e;
		outit();
	}	
}

void del_stu(){//delete student
	system("cls");
	printf("编号\t  学号\t    姓名\n");
	for(int i=0;i<cnt;i++){
		cout<<setw(10)<<setiosflags(ios::left)<<i+1<<setw(10)<<setiosflags(ios::left)<<_Stu[i].school_ID<<setw(10)<<setiosflags(ios::left)<<_Stu[i].name<<endl;
	}
	printf("请输入要删除学生的编号(输入0退出)：");
	int del_ID=input();
	if(del_ID==0) return;
	string opr=" delete student "+_Stu[del_ID-1].school_ID+" in file "+dig(_Stu[del_ID-1].FILE_ID);
	_Stu.erase(_Stu.begin()+(del_ID-1));
	cnt--;
	put_log(now.ID,opr);
}

int darw_student_ctl(){
	int x=40,y=0;
	while(1){
		system("cls");
		for(int i=1;i<=37;i++) printf(" ");
		for(int i=1;i<=20;i++) printf("*");
		printf("\n");
		for (int i=0;i<4;i++){
			for (int j=0;j<=40;j++){
				if (j==x&&i==y){
					printf(">");
				}
				else printf(" ");
			}
			if(i==0) printf(" 添加学生 ");
			if(i==1) printf(" 删除学生 ");
			if(i==2) printf(" 修改学生信息");
			if(i==3) printf(" 返回 ");
			for(int k=1;k<5;k++) printf(" ");
			printf("\n");
	}
	for(int i=1;i<=37;i++) printf(" ");
	for(int i=1;i<=20;i++) printf("*");
	printf("\n");
		char input;
		input=getch();
		if(input==80&&y<3) y++;
		if(input==72&&y>0) y--;
		if(input==13) break;
	}
	return y;
}

void student_ctl(){
	while(1){
		int flag=darw_student_ctl();
		student st;
		if(flag==0){
			st.Ins_stu(++cnt);
			_Stu.push_back(st);
			outit();
			string opr="add student "+_Stu[cnt-1].school_ID+" in file "+dig(_Stu[cnt-1].FILE_ID);
			put_log(now.ID,opr);
		}
		if(flag==1) del_stu(),outit();
		if(flag==2) change_stu();
		if(flag==3) break;
	}
}

void student_report(){//student report
	system("cls");
	string ID;
	printf("请输入身份证号码： ");
	cin>>ID;
	for(int i=0;i<cnt;i++){
		if(_Stu[i].ID==ID){
			if(_Stu[i].AC==0){
				_Stu[i].AC=1;
				printf("报道到成功\n");
			}else{
				printf("您已报道\n");
			}
			_Stu[i].show_stu();
			system("pause");
			return;
		}
	}
	printf("信息未录入或未录取，请联系管理员\n");
	system("pause");
}

int darw_admin(){
	int x=40,y=0;
	while(1){
		system("cls");
		for(int i=1;i<=37;i++) printf(" ");
		for(int i=1;i<=20;i++) printf("*");
		printf("\n");
		for (int i=0;i<5;i++){
			for (int j=0;j<=40;j++){
				if (j==x&&i==y){
					printf(">");
				}
				else printf(" ");
			}
			if(i==0) printf(" 账户管理 ");
			if(i==1) printf(" 学生管理 ");
			if(i==2) printf(" 信息查询 ");
			if(i==3) printf(" 导入录取学生名单 ");
			if(i==4) printf(" 注销 ");
			for(int k=1;k<5;k++) printf(" ");
			printf("\n");
	}
	for(int i=1;i<=37;i++) printf(" ");
	for(int i=1;i<=20;i++) printf("*");
	printf("\n");
		char input;
		input=getch();
		if(input==80&&y<4) y++;
		if(input==72&&y>0) y--;
		if(input==13) break;
	}
	return y;
}

void ins_accepted(){
	ifstream file("bin\\accepted.txt");
	student iNs;
	int used=cnt;
	while(file>>iNs.school_ID>>iNs.name>>iNs.Class>>iNs.ID>>iNs.score_c>>iNs.score_m>>iNs.score_e){
		iNs.score_tot=iNs.score_c+iNs.score_m+iNs.score_e;
		iNs.AC=0;iNs.FILE_ID=cnt+1;
		_Stu.push_back(iNs);
		cnt++;
	}
	file.close();
	used-=cnt;
	system("cls");
	printf("导入%d名学生\n",-used);
	system("pause");
	string s=" add "+dig(-used)+" students";
	put_log(now.ID,s);
	outit();
}

void admin(){
	int flag=load();
	if(flag==0) return;
	else {
		while(1){
			flag=darw_admin();
			if(flag==0) admin_ctl();
			if(flag==1) student_ctl();
			if(flag==2) inf_find();
			if(flag==3) ins_accepted();
			if(flag==4) break;
		}	
	}
}

int darw_holle(){
	int x=40,y=0;
	while(1){
		system("cls");
		for(int i=1;i<=37;i++) printf(" ");
		for(int i=1;i<=20;i++) printf("*");
		printf("\n");
		for (int i=0;i<3;i++){
			for (int j=0;j<=40;j++){
				if (j==x&&i==y){
					printf(">");
				}
				else printf(" ");
			}
			if(i==0) printf(" 学生报道 ");
			if(i==1) printf(" 管理员登录 ");
			if(i==2) printf(" 退出 ");
			for(int k=1;k<5;k++) printf(" ");
			printf("\n");
	}
	for(int i=1;i<=37;i++) printf(" ");
	for(int i=1;i<=20;i++) printf("*");
	printf("\n");
		char input;
		input=getch();
		if(input==80&&y<2) y++;
		if(input==72&&y>0) y--;
		if(input==13) break;
	}
	return y;
}

void holle(){
	while(1){
		int flag=darw_holle();
		if(flag==0) student_report();
		if(flag==1) admin();
		if(flag==2) break;
	}
}

void Solve(){
	holle();
}

int main(){
	put_log("system","start");
	init();
	Solve();
	outit();
	put_log("system","kill");
}