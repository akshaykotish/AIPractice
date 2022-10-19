#include<iostream>

using namespace std;

class AI {
public:
	char AIChar = 'X';
	char PlChar = 'O';

	int turn = -1;

	int reqMoves[9];
	int board[9] = {
		-1, 0, -1,
	     1, 1, 0,
	     0, -1, 0
	};

	int nextMove = 0;

	int Check(int temp[], int turn) {
		for (int i = 0; i < 9; i+=3)
		{
			
			if (temp[i] == temp[i + 1] && temp[i + 1] == temp[i + 2] && temp[i + 2] == turn)
			{
				return turn;
			}

			//cout << i<<" ";
			int b = i / 3;
			//cout <<b <<endl;
			if (temp[b] == temp[b + 3] && temp[b + 3] == temp[b + 6] && temp[b + 6] == turn)
			{
				return turn;
			}
		}

		if (((temp[0] == temp[4] && temp[4] == temp[8]) || (temp[2] == temp[4] && temp[4] == temp[6])) && temp[4] == turn)
		{
			return turn;
		}

		return 0;
	}

	int Max(int a, int b)
	{
		return a > b ? a : b;
	}

	int Min(int a, int b)
	{
		return a < b ? a : b;
	}	

	int Process(int temp[], int depth, int turn) {
		int value = 0;

		bool isend = false;

		int max = -5;
		int min = -5;

		if (Check(temp, 1) == 1)
		{
			return 1;
		}
		else if (Check(temp, -1) == -1)
		{
			return -1;
		}
		else {
			for (int i = 0; i < 9; i++)
			{
				if (temp[i] == 0)
				{
					isend = true;
					int tt[9];
					for (int j = 0; j < 9; j++)
					{
						tt[j] = temp[j];
					}
					tt[i] = turn;
					int t = turn == 1 ? -1 : 1;
					int p = Process(tt, depth + 1, t);
					if (max == -5 || min == -5)
					{
						max = p;
						min = p;
						value = p;
						//cout << " ZERO: " << depth << " " << i << " " << p << " " << value << endl;

					}
					else {
						if (turn == 1)
						{
							max = Max(max, p);
							value = max;
						}
						else {
							min = Min(min, p);
							value = min;
						}
					}

					if (depth == 1) {
						cout << depth << " " << i << " " << p << " " << value << endl;
						//reqMoves[i] = value;

						if (p == 1)
						{
							nextMove = i;
						}
					}
				}
				
			}
			return value;
		}
		return 0;
	}

	void WhatsNext() {
		for (int i = 0; i < 9; i++)
		{

		}
	}

	void Display(int tboard[])
	{
		for (int i = 0; i < 9; i++)
		{
			if(tboard[i] == 1){
				cout << AIChar;
			}
			else if(tboard[i] == -1) {
				cout << "O";
			}
			else {
				cout << " ";
			}
			
			if ((i + 1) % 3 == 0)
			{
				cout << endl;
			}
			else {
				cout << " | ";
			}
		}
		cout << endl;
	}

	void GamePlay()
	{
		int i = 0;
		while (Check(board, 1) != 1 && Check(board, -1) != -1 && i < 9)
		{
			system("CLS");
			if (turn == -1)
			{
				int a;
				cout <<"Turn: " << PlChar << endl;
				Display(board);
				cin >> a;
				board[a] = -1;
				turn = 1;
			}
			else {
				int a;
				cout << "Turn: " << AIChar << endl;
				Display(board);
				Process(board, 1, 1);
				board[nextMove] = 1;
				turn = -1;
			}
			i++;
		}
		system("CLS");
		Display(board);
	}

	void Play()
	{
		/*Display(board);
		cout<<Process(board, 1, 1);
		cout << "NextMove: " << nextMove << endl;
		board[nextMove] = 1;
		Display(board);*/
		GamePlay();
	}
};

int main() {
	AI ai = AI();
	ai.Play();
	return 0;
}
