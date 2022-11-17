#include <locale.h>
#include "graph.h"

int main() {
	setlocale(LC_ALL, "Rus");
	cout << "������������ ������ �6 - ����� ���\n";
	int switchNum, V, v, w, val;
	vector <int> c;
	Graph* g = new Graph(0);
	bool check = false;
	cout << "�������� ����� �������:\n"
		"1. �������� �����\n"
		"2. ����� �����\n"
		"3. ����������� ������ �����\n"
		"4. �������� ��������\n"
		"0. ��� ���������� ������\n"
		"��� �����: ";
	while (true) {
		cin >> switchNum;
		switch (switchNum) {
		case 1:
			cout << "������� ���������� ������ �����: ";
			cin >> V;
			delete(g);
			g = new Graph(V);
			cout << "������� � ������ ������ ���� ������ � ��� �����:\n"
				"(��� ��������� ������� 0 0 0)\n";
			cin >> v >> w >> val;
			while (v && w && val) {
				g->insert(v, w, val);
				cin >> v >> w >> val;
			}
			check = true;
			break;
		case 2:
			if (check) {
				g->print();
			}
			else
				cout << "��� ������ �������� ����!\n";
			break;
		case 3:
			if (check) {
				c = g->findCenter();
				for (int i = 0; i < c.size(); i++)
					cout << c[i] << " ";
				cout << "\n";
			}
			else
				cout << "��� ������ �������� ����!\n";
			break;
		case 4:
			if (check) {

			}
			else
				cout << "��� ������ �������� ����!\n";
			break;
		case 0:
			return 0;
		default:
			cout << "��� ������ ������!\n";
			break;
		}
		cout << "\n�������� ��������� �����: ";
	}
}


/*
1 2 1
1 5 10
1 3 2
2 5 6
2 4 11
3 5 7
3 4 4
4 5 11
0 0 0
*/