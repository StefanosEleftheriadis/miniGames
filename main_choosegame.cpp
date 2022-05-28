#include "classes.h"
#include <stdio.h> 

//functions prototypes
//************************
void puzzle_game();
void table_9game();
//************************

//main function
//************************
int main()
{
	int choice;
	
	do{
		cout<<"Press\n"
			<<"\t1 for puzzle_game\n"
			<<"\t2 for table_9game\n"
			<<"\t3 for Exit\n"
			<<"Choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				puzzle_game();
				system("pause");
				break;
			case 2:
				table_9game();
				system("pause");
				break;
			case 3:
				cout<<"Thanks for using this app!"<<endl;
				system("pause");
				break;
			default:
				cout<<"Wrong Input!"<<endl;
				system("pause");
				break;
		}
		
		system("CLS");
	}while(choice!=3);
	
	return 0;
}
//************************

//puzzle_game function
//************************
void puzzle_game()
{
	system("CLS");
	puzzle player;
	
	player.newgame();
	player.display();
	
	player.play();
}
//************************

//table_9game function
//************************
void table_9game()
{
	system("CLS");
	table_game player;
	
	player.newgame();
	player.display();
	
	player.play();
}
//************************
