#include <iomanip>
#include <time.h>
#include <stdio.h> 
#include <stdlib.h> 
#include "classes.h"

//Functions of table_game class
//*************************************************************************************
void table_game::newgame()
{
	
	srand (time(NULL));
 	
 	for(int row_count=0; row_count<3;row_count++)
 	{
 		for(int col_count=0; col_count<3;col_count++)
 		{
 			table[row_count][col_count]=rand()%9+1;
		}
	}	
	
}

void table_game::display()
{
	cout<<"Table 9 game:"<<endl<<"-------------"<<endl;
	
	for(int counterout=0;counterout<3;counterout++)
 	{
 		for(int counterin=0;counterin<3;counterin++)
 		{
 			cout<<setw(5)<<table[counterout][counterin];
		}
		cout<<endl;
	}
}

void table_game::play()
{
	int row_pos,col_pos,choice,loop_count=0;
	bool wrong_input=false, tfundo=false,exit=false;
			
	
	do{
		wrong_input=false;
		table_game::Temp_table();
		
		cout<<"Enter\n\t1 for Undo\n\t2 for Redo\n\t3 for nothing\n\t4 Exit the game\nchoice->";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				if(!tfundo)
				{
					table_game::undo_redo();
				}
				else
					cout<<"Only one time can undo!"<<endl;
				
				system("pause");	
				break;
			case 2:
				if(tfundo)
				{
					table_game::undo_redo();
				}
				else
					cout<<"Only one time can redo!"<<endl;
				
				system("pause");	
				break;
			case 3:
				break;
			case 4:
				exit=true;
				cout<<"Thanks for playing this game!"<<endl;
				system("pause");
				break;
			default:
				cout<<"Invalid input!"<<endl;
				system("pause");
				break;
		}
		
		system("CLS");
		table_game::display();
		
		if(!exit)
		{
			cout<<"Enter position: ";
			cin>>row_pos>>col_pos;
		
			for(int row_count=0; row_count<3;row_count++)
 			{
 				for(int col_count=0; col_count<3;col_count++)
 				{
 					if(row_count+1==row_pos || col_count+1==col_pos)
 					{
 						if(table[row_count][col_count]!=9)
 						{
 							table[row_count][col_count]++;
				 		}	
 						else
 						{
 							cout<<"Invalid input!"<<endl;
 							wrong_input=true;
 							break;
						}	
					}
 					
				}
				if(wrong_input)
				{
					table_game::resetTable();
					break;
				}
			}	
		
		
			system("pause");
		
			system("CLS");
			table_game::display();
			if(!wrong_input)
				loop_count++;
		}
		
		
	}while(!table_game::endgame()&& !exit);		
		
}

void table_game::resetTable()
{
	for(int counterout=0;counterout<3;counterout++)
	{
		for(int counterin=0;counterin<3;counterin++)
		{
			table[counterout][counterin]=temp[counterout][counterin];
		}
	}
}

bool table_game::endgame()
{
	int counter=0;
	
	for(int counterout=0; counterout<3; counterout++)
	{
		for(int counterin=0; counterin<3; counterin++)
		{
			if(table[counterout][counterin]!=9)
			{
				return false;
			}
			counter++;
			
		}
	}
	
	return true;
}

void table_game::Temp_table()
{
	for(int counterout=0;counterout<3;counterout++)
	{
		for(int counterin=0;counterin<3;counterin++)
		{
			temp[counterout][counterin]=table[counterout][counterin];
		}
	}
}

void table_game::undo_redo()
{
	int tmp=0;
	
	for(int counterout=0;counterout<3;counterout++)
	{
		for(int counterin=0;counterin<3;counterin++)
		{
			tmp=table[counterout][counterin];
			table[counterout][counterin]=temp[counterout][counterin];
			temp[counterout][counterin]=tmp;
		}
	}
}
//*************************************************************************************

//Functions of puzzle class
//*************************************************************************************
void puzzle::newgame()
{
	int row=0,col=0;
	bool tfarr[3][3]={false};//true/false array
	
	srand (time(NULL));
 	
    for(int counter=0; counter<=8; counter++)
    {
    	do{
    		row=rand()%3;
    		col=rand()%3;
    		if(!tfarr[row][col])
    		{
    			tfarr[row][col]=true;
    			table[row][col]=counter;
    			break;
			}
		}while(1);
    
	}
 
	
	
}

void puzzle::display()
{
	cout<<"Puzzle game:"<<endl<<"------------"<<endl;
	
	for(int counterout=0;counterout<3;counterout++)
 	{
 		for(int counterin=0;counterin<3;counterin++)
 		{
 			cout<<setw(5)<<table[counterout][counterin];
		}
		cout<<endl;
	}
}

void puzzle::play()
{
	int hold1,hold2,count_play=0;
	char position;
	bool exit=false, tfundo=false;
			
	
			
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(table[i][j]==0)
			{
				hold1=i;
				hold2=j;
			}
	do{
		
		cout<<"move(u-up, r-right, l-left, d-down, e-exit, U-undo, R-redo)>";
		cin>>position;
		
		switch(position)
		{
			case 'u':
				if(hold1-1>=0)
				{
					Temp_table();
					table[hold1][hold2]=table[hold1-1][hold2];
					table[hold1-1][hold2]=0;
					hold1--;
				}
				else{
					cout<<"Invalid input"<<endl;
				}
				system("pause");
				break;
			case 'd':
				if(hold1+1<=2)
				{
					Temp_table();
					table[hold1][hold2]=table[hold1+1][hold2];
					table[hold1+1][hold2]=0;
					hold1++;
				}
				else{
					cout<<"Invalid input"<<endl;
				}
				system("pause");
				break;
			case 'l':
				if(hold2-1>=0)
				{
					Temp_table();
					table[hold1][hold2]=table[hold1][hold2-1];
					table[hold1][hold2-1]=0;
					hold2--;
				}
				else{
					cout<<"Invalid input"<<endl;
				}
				system("pause");
				break;
			case 'r':
				if(hold2+1<=2)
				{
					Temp_table();
					table[hold1][hold2]=table[hold1][hold2+1];
					table[hold1][hold2+1]=0;
					hold2++;
				}
				else{
					cout<<"Invalid input"<<endl;
				}
				system("pause");
				break;
			case 'U':
				if(!tfundo && count_play>0)
				{
					puzzle::undo_redo();
					tfundo=true;
				}
				else{
					cout<<"Can't undo more than one time"<<endl;
				}
				system("pause");
				break;
			case 'R':
				if(tfundo && count_play>0)
				{
					puzzle::undo_redo();
					tfundo=false;
				}
				else{
					cout<<"Can't redo more than one time"<<endl;
				}
				system("pause");
				break;
			case 'e':
				exit=true;
				cout<<"Exit!"<<endl;
				system("pause");
				break;
			default:
				cout<<"Invalid input"<<endl;
				system("pause");
		}
		system("CLS");
		puzzle::display();
		count_play++;
		
	}while(!puzzle::endgame() && !exit);		
		
}

bool puzzle::endgame()
{
	int counter=0;
	
	for(int counterout=0; counterout<3; counterout++)
	{
		for(int counterin=0; counterin<3; counterin++)
		{
			if(!(table[counterout][counterin]==counter))
			{
				return false;
			}
			counter++;
			
		}
	}
	
	return true;
}

void puzzle::Temp_table()
{
	for(int counterout=0;counterout<3;counterout++)
	{
		for(int counterin=0;counterin<3;counterin++)
		{
			temp[counterout][counterin]=table[counterout][counterin];
		}
	}
}

void puzzle::undo_redo()
{
	int tmp=0;
	
	for(int counterout=0;counterout<3;counterout++)
	{
		for(int counterin=0;counterin<3;counterin++)
		{
			tmp=table[counterout][counterin];
			table[counterout][counterin]=temp[counterout][counterin];
			temp[counterout][counterin]=tmp;
		}
	}
}
//*************************************************************************************
