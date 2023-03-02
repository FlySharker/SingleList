#ifndef __NODE_H__
#define __NODE_H__
#include<cstddef>

// �����
template <class ElemType>
struct Node
{
	// ���ݳ�Ա:
	ElemType data;				// ������
	Node<ElemType>* next;		// ָ����

// ���캯��:
	Node();						// �޲����Ĺ��캯��
	Node(ElemType e, Node<ElemType>* link = NULL);	// ��֪������Ԫ��ֵ��ָ�뽨���ṹ
};

// ������ʵ�ֲ���
template<class ElemType>
Node<ElemType>::Node()
// �������������ָ����Ϊ�յĽ��
{
	next = NULL;
}

template<class ElemType>
Node<ElemType>::Node(ElemType e, Node<ElemType>* link)
// �������������һ��������Ϊe��ָ����Ϊlink�Ľ��
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
	out << " ѧ�ţ�" << setw(8) << a.id << " ������" << setw(4) << a.name << " �Ա�" << setw(2) << a.gender << " �༶��" << setw(2) << a.sclass << " �绰��" << setw(11) << a.telephone << endl;
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

