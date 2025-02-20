#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
using namespace std;


class cnode {
public:

	int info;
	string letter;
	cnode* pnext = NULL;
	cnode* pleft = NULL;
	cnode* pright = NULL;
};
class Hnode {
public:

	char info;
	string code;
	Hnode* pnext = NULL;
	Hnode* pleft = NULL;
	Hnode* pright = NULL;
};


class sortedlist
{
public:
	cnode* phead;
	sortedlist() {
		phead = NULL;
	}
	~sortedlist() {
		cnode* ptrav = phead;
		while (ptrav != NULL)
		{
			phead = ptrav->pnext;
			delete ptrav;
			ptrav = phead;
		}
	}

	void insert(cnode* pnn) {

		if (!phead) {
			phead = pnn;
			return;
		}
		if (pnn->info <= phead->info) {
			pnn->pnext = phead;
			phead = pnn;
			return;
		}
		cnode* ptrav = phead;
		while (ptrav->pnext && ptrav->pnext->info < pnn->info) {
			ptrav = ptrav->pnext;
		}

		pnn->pnext = ptrav->pnext;
		ptrav->pnext = pnn;

	}
	void dispall() {
		cnode* ptrav = phead;
		cout << endl;
		
		while (ptrav != NULL)
		{
			cout << ptrav->info << "   ";
			cout << ptrav->letter << endl;
			ptrav = ptrav->pnext;
			cout << "Doneeee" << endl;

		}
	}
};
class Cstack {
public:
	cnode* phead;
	cnode* ptail;
	Cstack() {
		phead = NULL;
		ptail = NULL;
	}
	void push(cnode* pnn) {

		pnn->pnext = phead;
		phead = pnn;


	}
	cnode* pop() {
		if (phead == NULL)
		{
			return NULL;
		}
		cnode* ptrav = phead;
		phead = phead->pnext;
		ptrav->pnext = NULL;
		return ptrav;
	}
	void disp() {
		cnode* ptrav = phead;
		while (ptrav != NULL)
		{

		}
		cout << endl;
	}
	~Cstack() {

	}
};
class clist {
public:
	Hnode* phead;
	Hnode* ptail;

	clist()
	{
		phead = NULL;
		ptail = NULL;
	}

	~clist() {
		Hnode* ptrav;
		ptrav = phead;
		while (ptrav != NULL)
		{
			phead = phead->pnext;
			delete ptrav;
			ptrav = phead;

		}

	};

	void attach(Hnode* hnn)
	{
		if (phead == NULL)
		{
			phead = hnn;
			ptail = hnn;
		}
		else
		{
			ptail->pnext = hnn;
			ptail = hnn;
		}
	}
	void dispall() {
		Hnode* ptrav = phead;
		cout << endl;
		cout << "Huffman Tree : " << endl;
		cout << "Character  ,    Code  " << endl << endl;
		while (ptrav != NULL)
		{
			cout << "   "<<ptrav->info << "             ";
			cout << ptrav->code << endl;
			ptrav = ptrav->pnext;

		}
	}




};
class CbTree
{
public:
	cnode* Root;
	CbTree() {
		Root = NULL;
	};
	~CbTree() {

	};
	void insert(cnode* pnn) {
		if (Root == NULL)
			Root = pnn;

		else
		{
			cnode* pb = NULL;
			cnode* ptrav = Root;
			while (ptrav != NULL)
			{
				pb = ptrav;
				if (pnn->info > ptrav->info)
				{
					ptrav = ptrav->pright;
				}
				else
				{
					ptrav = ptrav->pleft;
				}
			}
			if (pnn->info > pb->info)
				pb->pright = pnn;
			else
				pb->pleft = pnn;

		}
	}

	void display(cnode* ptrav) {
		if (ptrav == NULL)
		{
			return;
		}
		display(ptrav->pleft);

		cout << ptrav->info << "   ";
		cout << ptrav->letter << endl;
		cout << "Doneeee" << endl;

		display(ptrav->pright);

	}
	void search(cnode* ptrav, string x[1000], int& i, string value) {

		if (ptrav == NULL)
		{
			return;

		}

		if (ptrav->letter.length() == 1) {
			x[i] = ptrav->letter + ':' + value;
			i++;
		}

		search(ptrav->pleft, x, i, value + '0');
		search(ptrav->pright, x, i, value + '1');


	}

	void last(cnode* ptrav, string x[7], string& s, int& i, char e) {

		if (ptrav == NULL)
		{
			return;

		}


		if (ptrav->pleft == NULL && ptrav->pright == NULL && ptrav->letter.length() == 1)
		{
			cout << s;
			//x[i] = s;
			cout << "length" << s.length() << endl;;
			i++;
		}

		last(ptrav->pleft, x, s, i, '0');
		last(ptrav->pright, x, s, i, '1');

	}


};
void display(cnode* pnn)
{

	cout << pnn->info;
	cout << pnn->letter;

}
int to_number(char value)
{

	int result = 0;

	for (int i = 0; i < 8; i++)
	{
		if (value & (1 << i))
		{
			result += 1 << i;
		}
	}

	return result;
}



void main() {

	ifstream resultout;
	//write
	ofstream resultin;
	resultin.open("result.txt");
	resultout.open("result.txt");
	CbTree MyTree;
	clist  Hcode;
	sortedlist MySortedList;
	cnode* pnn;
	int ctnodes = 0;
	pnn = new cnode;
	char Line[10000];
	int HowMany[256];
	char Character[256];
	char compressed[1000];
	int intcompressed[1000];
	int ctcompressed = 0;
	string input;
	string output[10000];
	for (int i = 0; i < 256; i++)
	{
		HowMany[i] = 0;
		Character[i] = i;
	}
	cout << "Please Write a string to Compress" << endl;
	getline(cin, input);



	for (int i = 0; i < input.length(); i++)
	{
		Line[i] = input[i];
	}
	int counter = 0;
	for (int i = 0; i < input.length(); i++)
	{
		for (int b = 0; b < 256; b++)
		{
			if (Line[i] == Character[b])
			{
				HowMany[b]++;
			}
		}


	}
	for (int i = 0; i < 256; i++)
	{
		if (HowMany[i] != 0)
		{
			counter++;
		}
	}


	for (int i = 0; i < 256; i++)
	{
		if (HowMany[i] >= 1)
		{
			pnn = new cnode;
			pnn->info = HowMany[i];
			pnn->letter = Character[i];
			pnn->pleft = NULL;
			pnn->pnext = NULL;
			pnn->pright = NULL;
			MySortedList.insert(pnn);
			ctnodes++;

		}

	}
	//	MySortedList.dispall();


	cnode* ptrav = MySortedList.phead;
	while (ptrav->pnext != NULL)
	{
		pnn = new cnode;
		pnn->info = ptrav->info + ptrav->pnext->info;
		pnn->letter = ptrav->letter + ptrav->pnext->letter;
		pnn->pleft = ptrav;
		pnn->pright = ptrav->pnext;
		pnn->pnext = NULL;
		MyTree.Root = pnn;
		MySortedList.phead = MySortedList.phead->pnext;

		if (MySortedList.phead->pnext != NULL)
		{

			MySortedList.phead = MySortedList.phead->pnext;
		}
		else
		{
			break;
		}
		MySortedList.insert(pnn);
		ptrav = MySortedList.phead;
		//	_getch();
		//MySortedList.dispall();
		//cout << "ttreeeeeeeeeeeeeeeeeeeeee" << endl;
		//MyTree.display(MyTree.Root);
	}
	//	MySortedList.dispall();
	//cout << "Treeeeeeeeeeeeeeeeeeeeeeeeee" << endl;
	//MyTree.display(MyTree.Root);


	string r;
	int qw = 0;
	MyTree.search(MyTree.Root, output, qw, r);



	string g;
	Hnode* hnn;
	int hcodect = 0;
	for (int i = 0; i < counter; i++)
	{
		resultin << output[i] << endl;
		hnn = new Hnode;
		hnn->info = output[i][0];
		for (int c = 2; c < output[i].length(); c++)
		{
			g += output[i][c];
		}
		//cout << g;
		hnn->code = g;
		g.clear();
		Hcode.attach(hnn);

	}
	Hcode.dispall();
	char tmp = 0;
	int tmpct = 8;
	char mask = 1;
	for (int i = 0; i < input.length(); i++)
	{
		Hnode* ptrav = Hcode.phead;
		int v = 0;
		while (ptrav != NULL)
		{
			if (Line[i] == ptrav->info)
			{

				for (; v < ptrav->code.length(); v++)
				{
					//cout << ptrav->code.length();
					for (tmpct--; tmpct >= 0; )
					{

						if (ptrav->code[v] == '0')
						{
							char reo = tmp & (mask << tmpct);
							if (reo != 0)
							{
								tmp = tmp | (mask << tmpct);

							}
							int y = tmp;
							//cout << y,',';
							//cout << tmpct;
							int Y = to_number(tmp);

							tmp = Y;
							break;
						}
						else
						{

							tmp = tmp | (1 << tmpct);
							//cout << tmp;
							int y = tmp;
							//cout << y, ',';
							//cout << tmpct;
							int Y = to_number(tmp);
							tmp = Y;
							break;
						}
					}
					if (tmpct == 0)
					{
						//compressed[ctcompressed] = tmp;
						int Y = to_number(tmp);
						tmp = Y;
						compressed[ctcompressed] = tmp;
						intcompressed[ctcompressed] = Y;
						//cout << "Y" << Y<< compressed[ctcompressed] << endl;
						compressed[ctcompressed] = Y;
						//cout <<"ana u" << Y << endl;
						ctcompressed++;
						tmp = 0;
						tmpct = 8;
					}

				}
				break;

			}
			ptrav = ptrav->pnext;
		}



	}
	cout << "Your compressed message : " << endl;
	for (int i = 0; i < ctcompressed; i++)
	{

		resultin << compressed[i];
		cout << compressed[i];

	}
	resultin << endl;
	string decompresed;
	int po;
	int ty;
	string f;
	char reo;
	for (int i = 0; i < ctcompressed; i++)
	{
		tmp = compressed[i];
		int tmpct = 8;
		char mask = 1;
		for (tmpct--; tmpct >= 0; tmpct--)
		{
			reo = tmp & (1 << tmpct);
			if (reo != 0)
			{
				f += '1';

			}
			else
			{
				f += '0';
			}
		}
		resultin << f << compressed[i] << endl;;
		decompresed = decompresed + f;
		f.clear();


	}

	string op;
	string finallycom;
	Hnode* ptraav = Hcode.phead;
	Hnode* ptrave;
	int opct = 0;
	for (int i = 0; i < decompresed.length(); i++)
	{
		op += decompresed[i];
		ptrave = Hcode.phead;

		while (ptrave != NULL)
		{

			if (op == ptrave->code)
			{
				finallycom = finallycom + ptrave->info;

				op.clear();
			}
			ptrave = ptrave->pnext;
		}

	}

	cout << endl;
	cout << "Your Decompressed message : " << endl;
	cout << finallycom << endl;









	resultin.close();
	resultout.close();
	system("pause");
}