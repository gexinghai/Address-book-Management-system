#include <iostream>
#include <string>
//联系人上限
#define MAX 100

using namespace std;
//菜单
void showMenu()
{
	cout << "**********************" << endl;
	cout << "*****1.添加联系人*****" << endl;
	cout << "*****2.显示联系人*****" << endl;
	cout << "*****3.删除联系人*****" << endl;
	cout << "*****4.查找联系人*****" << endl;
	cout << "*****5.修改联系人*****" << endl;
	cout << "*****6.清空联系人*****" << endl;
	cout << "*****0.退出通讯录*****" << endl;
	cout << "**********************" << endl;
}
//联系人结构体
struct Person
{
	//姓名
	string m_Name;
	//性别 1 男 2 女
	int m_Sex;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
	//地址
	string m_Addr;
};
//通讯录结构体
struct Addressbooks
{
	//通讯录中保存的联系人的数组
	struct Person personArray[MAX];
	//通讯录中当前记录的联系人的个数
	int m_Size;
};
//1.添加联系人
void addPerson(struct Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		cout << "请输入姓名:";
		cin >> abs->personArray[abs->m_Size].m_Name;
		cout << "请输入性别:(1-男 2-女):";
		cin >> abs->personArray[abs->m_Size].m_Sex;
		cout << "请输入年龄:";
		cin >> abs->personArray[abs->m_Size].m_Age;
		cout << "请输入电话:";
		cin >> abs->personArray[abs->m_Size].m_Phone;
		cout << "请输入地址:";
		cin >> abs->personArray[abs->m_Size].m_Addr;
		abs->m_Size++;
		cout << "添加成功" << endl;
	}
}
//2.显示联系人
void showPerson(struct Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "通讯录为空！" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; ++i)
		{
			cout << "姓名:" << abs->personArray[i].m_Name
				<< "\t性别:" << abs->personArray[i].m_Sex
				<< "\t年龄:" << abs->personArray[i].m_Age
				<< "\t电话:" << abs->personArray[i].m_Phone
				<< "\t住址:" << abs->personArray[i].m_Addr
				<< endl;
		}
	}
}
//3.删除联系人
void delPerson(struct Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "通讯录为空！" << endl;
		return;
	}
	else
	{
		cout << "请输入要删除的联系人:";
		string name;
		cin >> name;
		int flag = 0;
		for (int i = 0; i < abs->m_Size; ++i)
		{
			if (abs->personArray[i].m_Name == name)
			{
				flag = 1;
				cout << "找到此人" << endl;
				for (int j = i; j < abs->m_Size - 1; ++j)
				{
					abs->personArray[j] = abs->personArray[j + 1];
				}
				abs->m_Size--;
			}
		}
		if (flag == 0)
		{
			cout << "查无此人！" << endl;
		}
	}
}
//4.查找联系人
void findPerson(struct Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "通讯录为空！" << endl;
		return;
	}
	else
	{
		cout << "请输入要查找的联系人:";
		string name;
		cin >> name;
		for (int i = 0; i < abs->m_Size; ++i)
		{
			if (abs->personArray[i].m_Name == name)
			{
				cout << "找到此人" << endl;
				cout << "姓名:" << abs->personArray[i].m_Name
					<< "\t性别:" << abs->personArray[i].m_Sex
					<< "\t年龄:" << abs->personArray[i].m_Age
					<< "\t电话:" << abs->personArray[i].m_Phone
					<< "\t住址:" << abs->personArray[i].m_Addr
					<< endl;
			}
			else
			{
				cout << "查无此人!" << endl;
				break;
			}
		}
	}
}
//5.修改联系人
void modifyPreson(struct Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "通讯录为空！" << endl;
		return;
	}
	else
	{
		cout << "请输入要修改的联系人:";
		string name;
		cin >> name;
		int flag = 0;
		for (int i = 0; i < abs->m_Size; ++i)
		{
			if (abs->personArray[i].m_Name == name)
			{
				flag = 1;
				cout << "找到此人，请输入修改后的信息" << endl;
				cout << "请输入姓名:";
				cin >> abs->personArray[i].m_Name;
				cout << "请输入性别:(1-男 2-女):";
				cin >> abs->personArray[i].m_Sex;
				cout << "请输入年龄:";
				cin >> abs->personArray[i].m_Age;
				cout << "请输入电话:";
				cin >> abs->personArray[i].m_Phone;
				cout << "请输入地址:";
				cin >> abs->personArray[i].m_Addr;
				cout << "修改成功" << endl;
			}

		}
		if(flag == 0)
		{
			cout << "查无此人!" << endl;
		}
	}
}
//6.清空联系人
void cleanPerson(struct Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "清空成功" << endl;
}

int main()
{
	//创建通讯录结构体变量
	struct Addressbooks abs;
	//初始化当前联系人数
	abs.m_Size = 0;

	while (true)
	{
		//用户输入的选择
		int select = 0;
		//显示菜单
		showMenu();
		cout << "请选择:";
		cin >> select;
		switch (select)
		{
		case 1://1.添加联系人
			addPerson(&abs);
			break;
		case 2://2.显示联系人
			showPerson(&abs);
			break;
		case 3://3.删除联系人
			delPerson(&abs);
			break;
		case 4://4.查找联系人
			findPerson(&abs);
			break;
		case 5://5.修改联系人
			modifyPreson(&abs);
			break;
		case 6://6.清空联系人
			cleanPerson(&abs);
			break;
		case 0://0.退出通讯录
			cout << "欢迎下次使用" << endl;
			return 0;
			break;
		default:
			cout << "输入错误，请重新输入！" << endl;
			break;
		}
	};

	return 0;
}
