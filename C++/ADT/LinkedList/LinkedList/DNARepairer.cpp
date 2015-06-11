#include "stdafx.h"

#include <fstream>
#include <sstream>
#include <string>
#include "DNARepairer.h"

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//  ����� �����!!
//  ���� ���� �������� ���� ��������-����������, �������
//  ���������� ��� ���������� �� ������� ���� ������ ����
//  � pPreHead.
//  �� ������ �������� �� ��� ����������� ���� ���������� �������.
//  �������� � ������ readFile �� ����������� ������ � ��
//  ������������ ����������, � repairDNA ������ ������
//  ���������� ���!!!
//  ����� ���� ���� ������ ����� �������� ������ ���� � ���
//  ��������� ���������� LinkedList.h

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



typedef LinkedList<DNAElement> DNA;
// ����� DNA ������������ ������ �����, ������� �������� DNAElement �������
// ���� �� �� �� �����, ��� ��������!

typedef Node<DNAElement> NodeDNA;
// ����� NodeDNA ������������ ���� ����, ������� �������� DNAElement
// ������ DNA ������� �� NodeDNA

void DNARepairer::repairDNA()
{
	// ������ �������
	// �����! ��� ���������� ����� ������ ����� ���� ������.
	// ������� ��� � ���������� ������� repairDNA ������.

	Node<DNA> * it = DNAStorage.getPreHead();
	Node<DNA> * it1, *it2;

	//��������� ��������� �� ������ ���� � ��� � it1
	it = it->next;
	it1 = it;

	//��������� ��������� �� ������ ���� � ��� � it2
	it = it->next;
	it2 = it;

	//���� ������� � id="a" �� ������ ���
	Node<DNAElement> * it3 = it2->value.getPreHead();
	while (it3->next != 0 &&
		it3->next->value.id != "a")
	{
		it3 = it3->next;
	}

	//����������� ������ �������� �� ������� ������ � ������
	it1->value.moveNodeAfter(
		it1->value.getPreHead(),
		it3
		);
	// ����� �������

	//Write your code here...
}

void DNARepairer::printDNAStorage()
{
	Node<DNA> * it1 = DNAStorage.getPreHead();
	while (it1->next != 0)
	{
		it1 = it1->next;
		//�������� �� ������ ���������

		NodeDNA * it2 = it1->value.getPreHead();
		while (it2->next != 0)
		{
			it2 = it2->next;
			//�������� �� ������ ���

			cout << it2->value.id << "" << it2->value.number << ":";
			cout << it2->value.base << "  ";
		}
		cout << endl;
	}
}

void DNARepairer::readFile(string filename)
{
	ifstream fin(filename);

	if (!fin)
	{
		cout << "File couldn't be opened :" << filename << endl;
		return;
	}

	string line;
	getline(fin, line); // ��� ������� ������ ������� � ������ �����

	Node<DNA> * it = DNAStorage.getPreHead();
	while (getline(fin, line))
	{
		Node<DNA> * pNewNode = new Node<DNA>;
		// ������� ���� ��� �� ����

		istringstream istr(line);
		//������� ��������� ����� ��� �������

		string strTmp;

		while (istr >> strTmp) // ��������� ����� �� �����
		{
			DNAElement tmpDNAElement;

			tmpDNAElement.readString(strTmp); // ������ ����� ������ � DNAElement

			pNewNode->value.addElementToEnd(tmpDNAElement);
			// ��������� ���������� DNAElement � ���
		}
		it->next = pNewNode;
		it = it->next;
		//��������� ��� � ���������
	}
}
