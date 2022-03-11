#include <stdio.h>
#include <iostream>
#include <time.h>
#include <string>
#include "clui.h"
using namespace std;
struct games
{
    string name;
    int bombs;
    int given_row;
    int given_col;
    int flag_numbers;
    int correct_selected;
    int points;
    char** PlayGround;
    char** Player;       
};
games info[10];
games save[4];
int names;
int row;
int col;
void game();
void move();
void menu();
void Initialization() 
{
    info[names].PlayGround = new char*[info[names].given_row];
    info[names].Player = new char*[info[names].given_row];
    for(int i=0 ; i<info[names].given_row ; i++ )
    {
        info[names].PlayGround[i] = new char[info[names].given_col];
        info[names].Player[i] = new char[info[names].given_col];
       for(int j=0 ; j<info[names].given_col ; j++)
        {
            info[names].PlayGround[i][j]='X';
            info[names].Player[i][j]='X';
        }
    }
}
void init_with_load(int index)
{
    info[names].bombs = save[index].bombs;
    info[names].correct_selected = save[index].correct_selected;
    info[names].flag_numbers = save[index].flag_numbers;
    info[names].given_row = save[index].given_row;
    info[names].given_col = save[index].given_col;
    info[names].PlayGround = new char*[info[names].given_row];
    info[names].Player = new char*[info[names].given_row];    
    for(int i=0; i<save[index].given_row; i++)
    {
        info[names].PlayGround[i] = new char[info[names].given_col];
        info[names].Player[i] = new char[info[names].given_col];       
        for(int j=0; j<save[index].given_col; j++)
        {
            info[names].PlayGround[i][j] = save[index].PlayGround[i][j];
            info[names].Player[i][j] = save[index].Player[i][j];
        }
    }
    row = 1;col = 1;
    game();
}
void delete_playgrounds()
{
    for(int i=0; i<info[names].given_row; i++)
    {
        delete[] info[names].PlayGround[i];
        delete[] info[names].Player[i];
    }
    delete[] info[names].PlayGround;
    delete[] info[names].Player;
}
void save_game(int index)
{
    save[index].bombs = info[names].bombs;
    save[index].flag_numbers = info[names].flag_numbers;
    save[index].given_row = info[names].given_row;
    save[index].given_col = info[names].given_col;
    save[index].correct_selected = info[names].correct_selected;
    save[index].PlayGround = new char*[save[index].given_row];
    save[index].Player = new char*[save[index].given_row];
    for(int i=0; i<info[names].given_row; i++)
    {
        save[index].PlayGround[i] = new char[save[index].given_col];
        save[index].Player[i] = new char[save[index].given_col];
        for(int j=0; j<info[names].given_col; j++)
        {
            save[index].PlayGround[i][j] = info[names].PlayGround[i][j];
            save[index].Player[i][j] = info[names].Player[i][j];            
        }
    }
    delete_playgrounds();
}    
void save_and_menu()
{
    int r=1;
    clear_screen();
    printf("  Slot 1\n  Slot 2\n  Slot 3\n  Slot 4");
    cursor_to_pos(r,1);
    while (true)
    {
        char input = getch();
        if(input == 'w' || input == 'W')
        {
            if(r-1>=1)
            {
                r--;
                cursor_to_pos(r,1);
            }
        }
        if(input == 's' || input == 'S')
        {
            if(r+1<=4)
            {
                r++;
                cursor_to_pos(r,1);
            }
        }
        if(input == 32) 
        {
            save_game(r-1);
            break;
        }       
    }
    info[names].flag_numbers = 0;
    info[names].correct_selected = 0;
    menu();    
}
void Show_PlayGround()
{
    for(int i=0 ; i<info[names].given_row ; i++ )
    { 
       for(int j=0 ; j<info[names].given_col ; j++)
        {
            cout<<info[names].PlayGround[i][j]<<" ";
        }
        cout<<endl;
    } 
    cout<<endl;
}
void Show_PlayGround_of_player()
{
    for(int i=0 ; i<info[names].given_row ; i++ )
    {
       for(int j=0 ; j<info[names].given_col ; j++)
        {
            if(info[names].Player[i][j] == '1')
            {
                change_color_rgb(18, 52, 222);//blue for 1
                cout<<info[names].Player[i][j]<<" ";
                change_color_rgb(161,35,121);
            }
            else if(info[names].Player[i][j] == '2')
            {
                change_color_rgb(230, 207, 2);//yellow for 2
                cout<<info[names].Player[i][j]<<" ";
                change_color_rgb(161,35,121);              
            }
            else if(info[names].Player[i][j] == '3')
            {
                change_color_rgb(237, 24, 0);//red for 3
                cout<<info[names].Player[i][j]<<" ";
                change_color_rgb(161,35,121);               
            }
            else if(info[names].Player[i][j] == '4')
            {
                change_color_rgb(171, 3, 173);//purple for 4
                cout<<info[names].Player[i][j]<<" ";
                change_color_rgb(161,35,121);                
            }            
            else if(info[names].Player[i][j] == '5')
            {
                change_color_rgb(2, 212, 166);//IDK for 5 
                cout<<info[names].Player[i][j]<<" ";
                change_color_rgb(161,35,121);                
            }
            else if(info[names].Player[i][j] == '6')
            {
                change_color_rgb(245, 83, 2);//orange for 6
                cout<<info[names].Player[i][j]<<" ";
                change_color_rgb(161,35,121);                 
            }
            else if(info[names].Player[i][j] == '7')
            {
                change_color_rgb(224, 66, 245);//random but beautiful for 7
                cout<<info[names].Player[i][j]<<" ";
                change_color_rgb(161,35,121);                  
            }
            else if(info[names].Player[i][j] == '8')
            {
                change_color_rgb(244, 66, 170);//random but beautiful for 8
                cout<<info[names].Player[i][j]<<" ";
                change_color_rgb(161,35,121);                 
            }            
            else if(info[names].Player[i][j] == 'F')
            {
                change_color_rgb(255, 10, 100);//random but beautiful for F
                cout<<info[names].Player[i][j]<<" ";
                change_color_rgb(161,35,121);                 
            }
            else if(info[names].Player[i][j] == 'B')
            {
                change_color_rgb(0, 212, 227);//random but beautiful for B
                cout<<info[names].Player[i][j]<<" ";
                change_color_rgb(161,35,121);                  
            }            
            else 
            cout<<info[names].Player[i][j]<<" ";                        
        }
        cout<<endl;
    } 
    cout<<endl;  
}
void Bomb()
{
    int counter = 0;
    srand(time(0));
    while(counter<info[names].bombs)
    {
        int random_row = rand() % info[names].given_row;
        int random_col = rand() % info[names].given_col;
        if(info[names].PlayGround[random_row][random_col] == 'B')
        continue;
        else
        {
            info[names].PlayGround[random_row][random_col] = 'B';
            counter++;
        }
    }  
}
void setting()
{
    Initialization();
    Bomb();
    row = 1;col = 1;
    game();
}
void win()
{
    clear_screen();
    change_color_rgb(255,215,0); // gold 
    cout<<"YOU WON!"<<endl;
    play_beep();
    change_color_rgb(161,35,121);
    cout<<"the game was : "<<endl<<endl;
    Show_PlayGround();
    delay(5000);
    info[names].points += info[names].correct_selected * 10;
    info[names].flag_numbers = 0;
    info[names].correct_selected = 0;
    menu();
}
void lose()
{    
    clear_screen();
    change_color_rgb(194,8,8);
    cout<<"GAME OVER"<<endl;
    play_beep();
    change_color_rgb(161,35,121);
    cout<<"the game was : "<<endl<<endl;
    Show_PlayGround();
    delay(5000);
    info[names].flag_numbers = 0;
    info[names].correct_selected = 0;
    menu();    
}
char possibility(int row, int col)
{
    char bomb_posible = '0';     
    int test_row , test_col;
    test_row=row-1; test_col=col-1;
        if((test_row>=0 && test_row<info[names].given_row) && (test_col>=0 && test_col<info[names].given_col))
        {
            if(info[names].PlayGround[test_row][test_col] == 'B')
            bomb_posible++;
        }
    test_row=row-1; test_col=col;
        if((test_row>=0 && test_row<info[names].given_row) && (test_col>=0 && test_col<info[names].given_col))
        {
            if(info[names].PlayGround[test_row][test_col] == 'B')
            bomb_posible++;
        }
    test_row=row-1; test_col=col+1;
        if((test_row>=0 && test_row<info[names].given_row) && (test_col>=0 && test_col<info[names].given_col))
        {
            if(info[names].PlayGround[test_row][test_col] == 'B')
            bomb_posible++;
        }
    test_row=row; test_col=col-1;
        if((test_row>=0 && test_row<info[names].given_row) && (test_col>=0 && test_col<info[names].given_col))
        {
            if(info[names].PlayGround[test_row][test_col] == 'B')
            bomb_posible++;
        }
    test_row=row; test_col=col+1;
        if((test_row>=0 && test_row<info[names].given_row) && (test_col>=0 && test_col<info[names].given_col))
        {
            if(info[names].PlayGround[test_row][test_col] == 'B')
            bomb_posible++;
        }
    test_row=row+1; test_col=col-1;
        if((test_row>=0 && test_row<info[names].given_row) && (test_col>=0 && test_col<info[names].given_col))
        {
            if(info[names].PlayGround[test_row][test_col] == 'B')
            bomb_posible++;
        }
    test_row=row+1; test_col=col;
        if((test_row>=0 && test_row<info[names].given_row) && (test_col>=0 && test_col<info[names].given_col))
        {
            if(info[names].PlayGround[test_row][test_col] == 'B')
            bomb_posible++;
        }
    test_row=row+1; test_col=col+1;
        if((test_row>=0 && test_row<info[names].given_row) && (test_col>=0 && test_col<info[names].given_col))
        {
            if(info[names].PlayGround[test_row][test_col] == 'B')
            bomb_posible++;
        }  
    if(bomb_posible == '0')
    bomb_posible = ' ';

    return bomb_posible;         
}
void choose_home(int real_row, int real_col )
{
        if(info[names].Player[real_row - 1][real_col -1] == 'F')
        {
            move();
        }
        if(info[names].Player[real_row-1][real_col-1] == '1' || info[names].Player[real_row-1][real_col-1] == '2'
        || info[names].Player[real_row-1][real_col-1] == '3'||info[names].Player[real_row-1][real_col-1] == '4'
        || info[names].Player[real_row-1][real_col-1] == '5' || info[names].Player[real_row-1][real_col-1] == '6' 
        || info[names].Player[real_row-1][real_col-1] == '7' || info[names].Player[real_row-1][real_col-1] == '8'
        || info[names].Player[real_row-1][real_col-1] == ' ')
        {
            move();
        }
    if(info[names].PlayGround[real_row-1][real_col-1] == 'B')
    {
        lose();
    }    
    else if (info[names].PlayGround[real_row-1][real_col-1] != 'B')
    {
        info[names].Player[real_row-1][real_col-1] = possibility(real_row-1, real_col-1);
        info[names].correct_selected++;
    }
    if(info[names].correct_selected == ((info[names].given_row * info[names].given_col) - info[names].bombs))
    {
        win();
    }
    game();
}
void flag(int real_row, int real_col )
{   
    if(info[names].Player[real_row-1][real_col-1] == 'F')
    {
        info[names].Player[real_row-1][real_col-1] = 'X';
        info[names].flag_numbers--;
        game();
    } 
    else if(info[names].Player[real_row-1][real_col-1] == 'X' && info[names].flag_numbers<info[names].bombs)
    {
        info[names].Player[real_row-1][real_col-1] = 'F';
        info[names].flag_numbers++;
        game();
    }
    else
    {
        game();    
    }    
}
void move()
{
    cursor_to_pos(row,col);
    while (true)
    {
        char mov=getch();
        if(mov == 'w' || mov == 'W')
        {
            if(row-1 >= 1) // 1 is the edge
            {
                row--;
                cursor_to_pos(row,col); 
            }
        }
        else if(mov == 's' || mov == 'S')
        {
            if(row+1 <= info[names].given_row) // size_game is the edge
            {
                row++;
                cursor_to_pos(row,col);
            }
        }
        else if(mov == 'a' || mov == 'A')
        {
            if(col-2 >= 1) // 1 is the edge
            {
                col -= 2;
                cursor_to_pos(row,col); 
            }
        }
        else if(mov == 'd' || mov == 'D')
        {
            if(col+2 <= info[names].given_col+(info[names].given_col-1)) //  is the edge
            {
                col += 2;
                cursor_to_pos(row,col); 
            }
        }
        
        int real_row = row;
        int real_col = (col/2) + 1;

        if(mov == 32 ) choose_home(real_row, real_col); 
        else if( mov == 'f'|| mov == 'F') flag(real_row, real_col);
        else if(mov == 'o'|| mov == 'O') save_and_menu();
        else if(mov == 'q'|| mov == 'Q')
        {
            delete_playgrounds();
            menu();
        } 
    }    
}
void game()
{
    clear_screen();
    Show_PlayGround_of_player();
    move();
}
void load_game()
{
    int r=1;
    clear_screen();
    printf("  Slot 1\n  Slot 2\n  Slot 3\n  Slot 4\n  menu");
    cursor_to_pos(r,1);
    while (true)
    {
        char input = getch();
        if(input == 'w' || input == 'W')
        {
            if(r-1>=1)
            {
                r--;
                cursor_to_pos(r,1);
            }
        }
        if(input == 's' || input == 'S')
        {
            if(r+1<=5)
            {
                r++;
                cursor_to_pos(r,1);
            }
        }
        if(input == 32) 
        {
            if(r == 5)
            {
                menu();
            }
            else if(save[r-1].bombs != 0)
                init_with_load(r-1);
            else
            {
                clear_screen();
                cout<<"this slot is empty!";
                r = 1;
                delay(3000);
                load_game();
            }

        }       
    } 
}
void swap_num(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void swap_name(string &a,string &b)
{
    string temp = a;
    a = b;
    b = temp;
}
void bubble_sort(games name_point[], int size)
{
    for(int i=0; i<size-1 ; i++ )
    {
        for(int j=0; j<size - i - 1 ; j++)
        {
            if(name_point[j].points < name_point[j+1].points)
            {
                swap_num(name_point[j].points,name_point[j+1].points);
                swap_name(name_point[j].name,name_point[j+1].name);
            }
        }
    }
}
void leaderboard()
{
    clear_screen();
    cout<<"Leadeboard\nPress space to go back to menu\n";
    games name_point[10];
    for(int i=0; i<10; i++)
    {
        name_point[i].name = info[i].name;
        name_point[i].points = info[i].points;
    }
    cout<<endl;
    bubble_sort(name_point,10);
    int k=0;
    int number = 0;
    for( ;k<5; k++)
    {
        number = k+1;
        cout<<number<<" = "<<name_point[k].points<<" "<<name_point[k].name<<endl;
    }
    char input = getch();
    if(input == 32) menu();
}
void change_user()
{
    clear_screen();
    string user;
    bool condition = false;
    cout<<"please enter your name : ";
    getline (cin,user);
    int i=0;
    for(; i<10; i++)
    {
        if(user == info[i].name)
        {
            condition = true;  
            break;     
        }
    }
    if(condition)
    {
            names = i;
            cout<<"\nyou are backed to "<<user;
            delay(2000);
            menu();
    }
    else
    {
        if(names + 1 < 10)
        {
            for(int j=0; j<10; j++)
            {
                if(info[j].name[0] == '\0')
                {
                    names = j;
                    info[names].name = user;
                    cout<<"\nyou have changed your name(user)";
                    delay(2000);
                    menu();
                }
            }
        }
        else
        {
            clear_screen();
            cout<<"you can't add anymore player!";delay(2000);
            menu();
        }
    }
}
void new_game()
{
    clear_screen();
    char input;
    int r = 1;
    printf("  Easy\n  Normal\n  Hard\n  Custom");
    cursor_to_pos(r,1);
    while (true)
    {
        input = getch();
        if(input == 'w' || input == 'W')
        {
            if(r-1>=1)
            {
                r--;
                cursor_to_pos(r,1);
            }
        }
        else if(input == 's' || input == 'S')
        {
            if(r+1<=4)
            {
                r++;
                cursor_to_pos(r,1);
            }
        }
        else
            break;
    }    
        if(input == 32) // 32 is Space char ascii code   
        {
            if(r == 1)
            {
                info[names].given_row = 5;
                info[names].given_col = 5;
                info[names].bombs = 4;
                setting();
            }
            if(r == 2)
            {
                info[names].given_row = 12;
                info[names].given_col = 12;
                info[names].bombs = 28;
                setting();
            } 
            if(r == 3)
            {
                info[names].given_row = 20;
                info[names].given_col = 20;
                info[names].bombs = 96;
                setting();
            } 
            if(r == 4)
            {
                clear_screen();
                while (true)
                {
                    cout<<"please enter the numbers of rows : ";
                    cin>>info[names].given_row;
                    if(info[names].given_row>=5 && info[names].given_row<=20)
                        break;
                    else
                       clear_screen();
                }
                clear_screen();
                
                while (true)
                {
                    cout<<"please enter the numbers of cols : ";
                    cin>>info[names].given_col;
                    if(info[names].given_col>=5 && info[names].given_col<=20)
                        break;
                    else
                        clear_screen();
                }
                clear_screen();
                while (true)
                {
                    cout<<"please enter the numbers of bombs((row*col)/4 > bombs)( also don't enter 0 :) ) : ";
                    cin>>info[names].bombs;
                    if(((info[names].given_row * info[names].given_col) / 4 ) > info[names].bombs && info[names].bombs != 0)
                        break;
                    else
                        clear_screen();
                }
                setting();
            } 
        }
    
}
void menu()
{
    clear_screen();
    change_color_rgb(161,35,121);
    int r = 1;
    printf("  New Game\n  Load Game\n  Change User\n  Leaderboard\n  Quit");
    cursor_to_pos(r,1);
    while (true)
    {
        char input = getch();
        if(input == 'w' || input == 'W')
        {
            if(r-1>=1)
            {
                r--;
                cursor_to_pos(r,1);
            }
        }
        if(input == 's' || input == 'S')
        {
            if(r+1<=5)
            {
                r++;
                cursor_to_pos(r,1);
            }
        }
        if(input == 32) // 32 is Space char ascii code   
        {
            if(r == 1) new_game();
            if(r == 2) load_game();
            if(r == 3) change_user();
            if(r == 4) leaderboard();
            if(r == 5)
            {
                clear_screen();
                exit(0);
            } 
        }       
    }
}
int main()
{
    init_clui();
    change_color_rgb(161,35,121);
        cout<<"Please enter your name : ";
        getline (cin,info[names].name);
        menu();
}