#include <iostream>
#include <List>
using namespace std;

struct student
{
    string sid;
    string name;
    string age;
    string address;
};

list<student> students;

//注册信息
void addInfo()
{
    student s1;
    cout << "学生学号 : ";
    cin >> s1.sid;
    cout << "学生姓名 : ";
    cin >> s1.name;
    cout << "学生年龄 : ";
    cin >> s1.age;
    cout << "学生住址 : ";
    cin >> s1.address;
    for (auto it = students.begin(); it != students.end(); it++)
    {
        if (it->sid == s1.sid)
        {
            cout << "已有相同学号学生身份信息，请勿重复注册!" << endl;
            return;
        }
    }
    students.push_back(s1);
    cout << "信息添加成功!" << endl;
}

//注销信息
void deleteInfo()
{
    if (students.empty())
    {
        cout << "无信息，请添加信息再注销!" << endl;
    }
    else
    {
        student s1;
        cout << "请输入待删除学生学号" << endl;
        cin >> s1.sid;
        for (auto it = students.begin(); it != students.end(); it++)
        {
            if (it->sid == s1.sid)
            {
                students.erase(it);
                cout << "注销成功!" << endl;
                return;
            }
        }
        cout << "未找到相关人员信息，请检查后输入后重试!" << endl;
    }
}

//修改信息
//先注销，再注册
void alterInfo()
{
    if (students.empty())
    {
        cout << "无信息，请添加信息再修改!" << endl;
    }
    else
    {
        student s1;
        cout << "请输入待修改信息学生学号" << endl;
        cin >> s1.sid;
        for (auto it = students.begin(); it != students.end(); it++)
        {
            if (it->sid == s1.sid)
            {
                students.erase(it);
                cout << "学生新姓名 : ";
                cin >> s1.name;
                cout << "学生新年龄 : ";
                cin >> s1.age;
                cout << "学生新住址 : ";
                cin >> s1.address;
                students.push_back(s1);
                return;
            }
        }
        cout << "未找到相关人员信息，请检查后输入后重试!" << endl;
    }
}

//显示所有信息
//遍历链表，通过迭代器
void Traverse()
{
    bool judge = students.empty();
    if (judge)
    {
        cout << "无信息，请添加信息再查询!" << endl;
    }
    else
    {
        cout << "已注册的所有学生信息如下" << endl;
        //打印表头
        cout << "学号\t\t"
             << "姓名\t\t\t"
             << endl;
        for (list<student>::iterator iterator = students.begin(); iterator != students.end(); iterator++)
        {
            cout << iterator->sid << "\t\t" << iterator->name << "\t\t\t" << endl;
        }
    }
}

//菜单
void menu()
{
    cout << "-------欢迎使用学生信息管理系统-------" << endl;
    cout << "1.注册信息" << endl;
    cout << "2.注销信息" << endl;
    cout << "3.修改信息" << endl;
    cout << "4.显示所有信息" << endl;
    cout << "5.查询信息" << endl;
    cout << "0.退出系统" << endl;
    cout << "请输入您的选择 : ";
}

//按键反馈
void keyDown()
{
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "注册信息" << endl;
        addInfo();
        break;
    case 2:
        cout << "注销信息" << endl;
        deleteInfo();
        break;
    case 3:
        cout << "修改信息" << endl;
        alterInfo();
        break;
    case 4:
        Traverse();
        break;
    case 5:
        cout << "查询信息" << endl; //TODO
        break;
    case 0:
        cout << "谢谢使用！" << endl;
        students.clear();
        exit(0);
        break;
    default:
        cout << "您的输入有误，请重新输入!" << endl;
        break;
    }
}

int main(int argc, char const *argv[])
{
    system("title StudentManager"); //修改窗口标题
    while (1)
    {
        menu();
        keyDown();
        system("pause"); //防止直接刷屏
        system("cls");   //清屏
    }
    return 0;
}
