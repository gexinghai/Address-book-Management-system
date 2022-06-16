#include <iostream>
#include <string>
//��ϵ������
#define MAX 100

using namespace std;
//�˵�
void showMenu()
{
	cout << "**********************" << endl;
	cout << "*****1.�����ϵ��*****" << endl;
	cout << "*****2.��ʾ��ϵ��*****" << endl;
	cout << "*****3.ɾ����ϵ��*****" << endl;
	cout << "*****4.������ϵ��*****" << endl;
	cout << "*****5.�޸���ϵ��*****" << endl;
	cout << "*****6.�����ϵ��*****" << endl;
	cout << "*****0.�˳�ͨѶ¼*****" << endl;
	cout << "**********************" << endl;
}
//��ϵ�˽ṹ��
struct Person
{
	//����
	string m_Name;
	//�Ա� 1 �� 2 Ů
	int m_Sex;
	//����
	int m_Age;
	//�绰
	string m_Phone;
	//��ַ
	string m_Addr;
};
//ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼�б������ϵ�˵�����
	struct Person personArray[MAX];
	//ͨѶ¼�е�ǰ��¼����ϵ�˵ĸ���
	int m_Size;
};
//1.�����ϵ��
void addPerson(struct Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		cout << "����������:";
		cin >> abs->personArray[abs->m_Size].m_Name;
		cout << "�������Ա�:(1-�� 2-Ů):";
		cin >> abs->personArray[abs->m_Size].m_Sex;
		cout << "����������:";
		cin >> abs->personArray[abs->m_Size].m_Age;
		cout << "������绰:";
		cin >> abs->personArray[abs->m_Size].m_Phone;
		cout << "�������ַ:";
		cin >> abs->personArray[abs->m_Size].m_Addr;
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;
	}
}
//2.��ʾ��ϵ��
void showPerson(struct Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "ͨѶ¼Ϊ�գ�" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; ++i)
		{
			cout << "����:" << abs->personArray[i].m_Name
				<< "\t�Ա�:" << abs->personArray[i].m_Sex
				<< "\t����:" << abs->personArray[i].m_Age
				<< "\t�绰:" << abs->personArray[i].m_Phone
				<< "\tסַ:" << abs->personArray[i].m_Addr
				<< endl;
		}
	}
}
//3.ɾ����ϵ��
void delPerson(struct Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "ͨѶ¼Ϊ�գ�" << endl;
		return;
	}
	else
	{
		cout << "������Ҫɾ������ϵ��:";
		string name;
		cin >> name;
		int flag = 0;
		for (int i = 0; i < abs->m_Size; ++i)
		{
			if (abs->personArray[i].m_Name == name)
			{
				flag = 1;
				cout << "�ҵ�����" << endl;
				for (int j = i; j < abs->m_Size - 1; ++j)
				{
					abs->personArray[j] = abs->personArray[j + 1];
				}
				abs->m_Size--;
			}
		}
		if (flag == 0)
		{
			cout << "���޴��ˣ�" << endl;
		}
	}
}
//4.������ϵ��
void findPerson(struct Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "ͨѶ¼Ϊ�գ�" << endl;
		return;
	}
	else
	{
		cout << "������Ҫ���ҵ���ϵ��:";
		string name;
		cin >> name;
		for (int i = 0; i < abs->m_Size; ++i)
		{
			if (abs->personArray[i].m_Name == name)
			{
				cout << "�ҵ�����" << endl;
				cout << "����:" << abs->personArray[i].m_Name
					<< "\t�Ա�:" << abs->personArray[i].m_Sex
					<< "\t����:" << abs->personArray[i].m_Age
					<< "\t�绰:" << abs->personArray[i].m_Phone
					<< "\tסַ:" << abs->personArray[i].m_Addr
					<< endl;
			}
			else
			{
				cout << "���޴���!" << endl;
				break;
			}
		}
	}
}
//5.�޸���ϵ��
void modifyPreson(struct Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "ͨѶ¼Ϊ�գ�" << endl;
		return;
	}
	else
	{
		cout << "������Ҫ�޸ĵ���ϵ��:";
		string name;
		cin >> name;
		int flag = 0;
		for (int i = 0; i < abs->m_Size; ++i)
		{
			if (abs->personArray[i].m_Name == name)
			{
				flag = 1;
				cout << "�ҵ����ˣ��������޸ĺ����Ϣ" << endl;
				cout << "����������:";
				cin >> abs->personArray[i].m_Name;
				cout << "�������Ա�:(1-�� 2-Ů):";
				cin >> abs->personArray[i].m_Sex;
				cout << "����������:";
				cin >> abs->personArray[i].m_Age;
				cout << "������绰:";
				cin >> abs->personArray[i].m_Phone;
				cout << "�������ַ:";
				cin >> abs->personArray[i].m_Addr;
				cout << "�޸ĳɹ�" << endl;
			}

		}
		if(flag == 0)
		{
			cout << "���޴���!" << endl;
		}
	}
}
//6.�����ϵ��
void cleanPerson(struct Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "��ճɹ�" << endl;
}

int main()
{
	//����ͨѶ¼�ṹ�����
	struct Addressbooks abs;
	//��ʼ����ǰ��ϵ����
	abs.m_Size = 0;

	while (true)
	{
		//�û������ѡ��
		int select = 0;
		//��ʾ�˵�
		showMenu();
		cout << "��ѡ��:";
		cin >> select;
		switch (select)
		{
		case 1://1.�����ϵ��
			addPerson(&abs);
			break;
		case 2://2.��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://3.ɾ����ϵ��
			delPerson(&abs);
			break;
		case 4://4.������ϵ��
			findPerson(&abs);
			break;
		case 5://5.�޸���ϵ��
			modifyPreson(&abs);
			break;
		case 6://6.�����ϵ��
			cleanPerson(&abs);
			break;
		case 0://0.�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			return 0;
			break;
		default:
			cout << "����������������룡" << endl;
			break;
		}
	};

	return 0;
}
