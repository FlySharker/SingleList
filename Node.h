#ifndef __NODE_H__
#define __NODE_H__
#include<cstddef>

// 结点类
template <class ElemType>
struct Node
{
	// 数据成员:
	ElemType data;				// 数据域
	Node<ElemType>* next;		// 指针域

// 构造函数:
	Node();						// 无参数的构造函数
	Node(ElemType e, Node<ElemType>* link = NULL);	// 已知数数据元素值和指针建立结构
};

// 结点类的实现部分
template<class ElemType>
Node<ElemType>::Node()
// 操作结果：构造指针域为空的结点
{
	next = NULL;
}

template<class ElemType>
Node<ElemType>::Node(ElemType e, Node<ElemType>* link)
// 操作结果：构造一个数据域为e和指针域为link的结点
{
	data = e;
	next = link;
}

struct Student
{
	string id;
	string name;
	char gender;
	int sclass;
	long telephone;
	Student(string Id = "21122867", string Name = "human", char Gender = 'M', int Sclass = 10, long Telephone = 12345678912);
	friend ostream& operator<<(ostream& out, const Student& a);
	friend istream& operator>>(istream& in, Student& a);
	bool operator<(const Student& b);
	bool operator!=(const Student& b);
};

Student::Student(string Id, string Name, char Gender, int Sclass, long Telephone) :id(Id), name(Name), gender(Gender), sclass(Sclass), telephone(Telephone)
{

}

ostream& operator<<(ostream& out, const Student& a)
{
	out << " 学号：" << setw(8) << a.id << " 姓名：" << setw(4) << a.name << " 性别：" << setw(2) << a.gender << " 班级：" << setw(2) << a.sclass << " 电话：" << setw(11) << a.telephone << endl;
	return out;
}

istream& operator>>(istream& in, Student& a)
{
	in >> a.id >> a.name >> a.gender >> a.sclass >> a.telephone;
	return in;
}

bool Student::operator<(const Student& b)
{
	return id < b.id;
}

bool Student::operator!=(const Student& b)
{
	return id != b.id;
}

#endif

