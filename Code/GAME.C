#include "unity.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include "main1.h"

void setUp(void){
}
void tearDown(void){
	
}
/// Start of the program 
int main(void)
{
  UnityBegin("test");
  /// Variables to hold the input from user and computer and their result
  int player, comp, result;
  srand((unsigned)time(NULL));

  for(;;)
  {
	int c=0;
	int p=0;
	int d=0;
	int i=0;
	/// Start of the MENU
	printf("\n\n ..WELCOME!!..");
	printf("\n\nTHIS GAME WILL BE PLAYED FOR 5 ROUNDS AND THE PLAYER WITH MAXIMUM WINS WILL WIN THE ROUND!!..");
	/// The game is played for 5 times to finish one round and the one with maximum wins wins the round.
	for(i=0;i<5;i++)
	{
	player = get_player_choice();
	if (player == QUIT)
	 return 0;
	comp = get_computer_choice();
	result = get_result(player, comp);
	
	if(result==4){ c++;}
	else if(result==5){ p++;}
	else if(result==6){ d++;}
	
	show_result(player, comp, result);
	 /// Test cases to check the inputs.
	void test_cases(){
		 
	TEST_ASSERT_GREATER_OR_EQUAL(0,player);
	TEST_ASSERT_LESS_OR_EQUAL(2,player);
    TEST_ASSERT_GREATER_OR_EQUAL(0,comp);
	TEST_ASSERT_LESS_OR_EQUAL(2,comp);
    TEST_ASSERT_GREATER_OR_EQUAL(4,result);
    TEST_ASSERT_LESS_OR_EQUAL(6,result);
	
	}
	
	RUN_TEST(test_cases);
	}
	/// After being played for five times the result for the round is computed.
	if(p>c && p>d){
		
	
		printf("\n\n...YOU WON THIS ROUND!!...");
	}
	else if(c>d){
		printf("\n\n...COMPUTER WON THIS ROUND!!...");
		}
	else{
		printf("\n\n...ROUND DRAWN!!..");
	}
  }
  return (UnityEnd()) ;
}
/// The funtion askes the user to enter the option to play.
int get_player_choice()
{
  int c;
  for(;;)
  {
    printf("\n\n.....MENU..... ");
	printf("\n Enter 1 for choosing rock.");
	printf("\n Enter 2 for choosing paper.");
	printf("\n Enter 3 for choosing scissors.");
	printf("\n Enter 4 for choosing quit.");
    scanf("%d",&c);

    if (c==1){

	  return ROCK;
	}
    else if (c== 2)
      return SCISSOR;
    else if (c==3)
      return PAPER;
    else if (c==4)
      return QUIT;
  }
  return 0;
}
/// The function selects an option randomly for the computer. 
int get_computer_choice()
{
  return rand() % 3;
}
/// The function computes the result based computer and user's input.
int get_result(int player, int computer)
{
  int idx;

  for (idx = 0; idx < NUM_RESULTS; ++idx)
  {
    if (results[idx].player == player && results[idx].computer == computer)
      break;
  }

  return results[idx].result;
}
/// The function shows the result.
void show_result(int player, int comp, int result)
{

  const char *result_names[] = {"Computer won", "Player won", "Draw"};
  const char *choises[] = {"Paper", "Rock", "Scissor"};
  printf("\nYou chose: %s", choises[player]);
  printf("\nComputer choose: %s", choises[comp]);
  printf("\nResult: %s", result_names[result - 4]);

}