/**
 * @FileName User.h
 * @Function administrator's operate
 */
#ifndef User_h
#define User_h

#include <bits/stdc++.h>
#include "input.h"
#include "log.h"
#include "dig.h"
#define debug printf("PASS IN LINE:%d\n",__LINE__)

using namespace std;

class User{
	public:
		string ID,key;
		int key_ID;
		
		void Get_Information(int x){//Get information in file
			string _path="bin\\User\\";
			_path+=dig(x)+".json";
			ifstream file(_path.c_str());
			file>>ID;
			file>>key;
			file>>key_ID;
			file.close();
		}
		
		void change_key(){//Change administrator password
			string key1,key2;
			printf(u8"请输入原密码：");
			cin>>key1;
			if(key1!=key){
				printf("密码错误\n");
				return;
			}
			else{
				printf("请输入密码：");
				cin>>key1;
				printf("请重新输入密码：");
				cin>>key2;
				int cnt=0;
				while(key1!=key2){
					printf("请重新输入密码：");
					cin>>key2;
					cnt++;
					if(cnt>=3){
						printf("修改失败\n");
						put_log(ID,"change key fail");
						system("pause");
						return;
					}
				}
				string _path="bin\\User\\";
				_path+=dig(key_ID)+".json";
				ofstream file(_path.c_str());
				file<<ID<<endl;
				file<<key2<<endl;
				file<<key_ID<<endl;
				file.close();
				printf("修改成功\n");
				put_log(ID,"change key");
				system("pause");
				return;
			}
		}
};

User now;

bool load(){//administrator load
	string ID,key;
	int cnt;
	printf("请输入用户名：");
	cin>>ID;
	printf("请输入密码：");
	cin>>key;
	ifstream file("bin\\User\\index.idx");
	file>>cnt;
	file.close();
	for(int i=1;i<=cnt;i++){
		User ur;
		ur.Get_Information(i);
		if(ur.ID==ID&&key==ur.key){
			now=ur;
			printf("登录成功\n");
			put_log(ID,"load");
			system("pause");
			return 1;
		}
	}
	printf("账户或密码错误\n");
	system("pause");
	return 0;
}

void Register(){//administrator register
	int cnt;
	string ID,key;
	printf("请输入用户名\n");
	cin>>ID;
	printf("请输入密码\n");
	cin>>key;
	ifstream file("bin\\User\\index.idx");
	file>>cnt;
	file.close();
	ofstream _file("bin\\User\\index.idx");
	_file<<cnt+1;
	_file.close();
	string path="bin\\User\\"+dig(cnt+1)+".json";
	ofstream File(path.c_str());
	File<<ID<<endl;
	File<<key<<endl;
	File<<cnt+1<<endl;
	File.close();
	put_log(ID,"was Register");
}

#endif