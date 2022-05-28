#include <iostream>

using namespace std;

//table_game class
//************************
class table_game{
	public:
		void newgame();
		void resetTable();
		void display();
		void play();
		bool endgame();
		void Temp_table();
		void undo_redo();
	private:
		int table[3][3];
		int temp[3][3];
};
//************************

//puzzle class
//************************
class puzzle{
	public:
		void newgame();
		void display();
		void play();
		bool endgame();
		void Temp_table();
		void undo_redo();
	private:
		int table[3][3];
		int temp[3][3];
};
//************************
