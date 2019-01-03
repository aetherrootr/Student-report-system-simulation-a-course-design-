/**
 * @FileName student.h
 * @Function student information operate
 */
#ifndef student_h
#define student_h

#include <bits/stdc++.h>
#include "input.h"
#include "dig.h"
#define debug printf("PASS IN LINE:%d\n",__LINE__)

using namespace std;

class student{
	public:
		string school_ID;
		string name;
		string Class;
		string ID;
		int score_c,score_m,score_e;
		int score_tot;
		bool AC;
		int FILE_ID;

		void Ins_stu(int x){//add student
			system("CLS");
			printf(u8"请输入学号: ");
			cin>>school_ID;
			printf(u8"请输入姓名: ");
			cin>>name; 
			printf(u8"请输入班级: ");
			cin>>Class;
			printf(u8"请输入身份证号码: ");
			cin>>ID;
			printf(u8"请输入语文成绩: ");
			score_c=input();
			printf(u8"请输入数学成绩: ");
			score_m=input();
			printf(u8"请输入英语成绩: ");
			score_e=input();
			score_tot=score_c+score_m+score_e;
			printf(u8"总成绩为: %d\n",score_tot);
			AC=0;FILE_ID=x;
			system("pause");
		}

		void FIlE_Get(int x){//Get information from file
			string path="bin\\Student\\"+dig(x)+".json";
			ifstream file(path.c_str());
			file>>school_ID;
			file>>name;
			file>>Class;
			file>>ID;
			file>>score_c;
			file>>score_m;
			file>>score_e;
			file>>score_tot;
			file>>AC;
			file>>FILE_ID;
			file.close();
		}

		void write_stu(int x){//write student information to file
			string path="bin\\Student\\"+dig(x)+".json";
			ofstream file(path.c_str());
			file<<school_ID<<endl;
			file<<name<<endl;
			file<<Class<<endl;
			file<<ID<<endl;
			file<<score_c<<endl;
			file<<score_m<<endl;
			file<<score_e<<endl;
			file<<score_tot<<endl;
			file<<AC<<endl;
			file<<FILE_ID<<endl;
			file.close();
		}

		void show_stu(){//show student information
			printf("学号：");
			cout<<school_ID<<endl;
			printf("姓名：");
			cout<<name<<endl;
			printf("班级：");
			cout<<Class<<endl;
			printf("身份证号码：");
			cout<<ID<<endl;
			printf("语文成绩：");
			cout<<score_c<<endl;
			printf("数学成绩：");
			cout<<score_m<<endl;
			printf("英语成绩：");
			cout<<score_e<<endl;
			printf("总分：");
			cout<<score_tot<<endl;
		}

};

/*
 *sort way 
 */

bool cmp1_1(student a,student b){
	return a.score_tot<b.score_tot;
}

bool cmp1_2(student a,student b){
	return a.score_tot>b.score_tot;
}

bool cmp2_1(student a,student b){
	return a.score_c<b.score_c;
}

bool cmp2_2(student a,student b){
	return a.score_c>b.score_c;
}

bool cmp3_1(student a,student b){
	return a.score_m<b.score_m;
}

bool cmp3_2(student a,student b){
	return a.score_m>b.score_m;
}

bool cmp4_1(student a,student b){
	return a.score_e<b.score_e;
}

bool cmp4_2(student a,student b){
	return a.score_e>b.score_e;
}

bool cmp0(student a,student b){
	return a.FILE_ID<b.FILE_ID;
}

#endif