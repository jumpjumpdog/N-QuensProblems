#include"iostream"
using std::cin;
using std::cout;
using std::endl;

void elimate(int,int);
bool isSafePlace(int x,int y);



int  queenMaze[8][8] = { 0 };
int count = 0;
int main() {




	for(int i=0;i<8;i++)
	elimate(0,i);

	return 0;
}



bool isSafePlace(int a,int b) {
	int x=a;
	int y=b;
	for (int i = 0; i < 8; i++) {       //对列进行分析；             
		x++;
		y++;
		x %= 8;
		y %= 8;
		if (1 == queenMaze[x][b])
		    	return false;	
	}

	x = a;
	y = b;

	while (y <= 7&&x<=7) {
		if (1 == queenMaze[x][y])
			return false;
		y++;
		x++;
	}

	x = a;
	y = b;
	while (y >= 0 && x >= 0) {
		if (1 == queenMaze[x][y])
			return false;
		y--;
		x--;
	}

	x = a;
	y = b;
	while (x>=0&&y<=7) {
		if (1 == queenMaze[x][y])
			return false;
		x--;
		y++;
	}

	x = a;
	y = b;
	while (x<=7&&y>=0) {
		if (1 == queenMaze[x][y])
			return false;
		x++;
		y--;
	}


	return true;
}

void elimate(int row,int col) {
	
	int a = row;
	int b = col;
	if (!isSafePlace(row, col)) {
		return;
	}
	 if (7==row)
	{
		count++;
		cout <<"第"<< count<<"种放置方法" << endl;
		queenMaze[row][col] = 1;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++)
				cout << queenMaze[i][j]<<' ';
			cout << endl;
		}
		queenMaze[row][col] = 0;
		cout << endl;
		return;
	}
	else {
		queenMaze[row][col]=1;
		for (int j = 0; j < 8; j++)
		{
			col++;
			col %= 8;
			elimate(row+1,col);
		}
		queenMaze[row][col]=0;
	}
	
}
