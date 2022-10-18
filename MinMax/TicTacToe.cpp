#include<iostream>

using namespace std;

class AI {
public:

	int board[9] = {
		1,  0, -1,
	   -1,  1, -1,
	   -1, -1, 0
	};

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
					}
				}
				
			}
			return value;
		}
		return 0;
	}


	void Play()
	{
		cout<<Process(board, 1, 1);
	}
};

int main() {
	AI ai = AI();
	ai.Play();
	return 0;
}
