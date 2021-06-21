#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
  //Game intro
  std::cout << "\n\nYou've broken into a level " << Difficulty;
  std::cout << " Dognapper's room with the task of saving all the cute doggos.\n";
  std::cout << "The rarer the doggo, the harder it is to crack its lock. Try to save all the doggos!\n\n";
}

bool PlayGame(int Difficulty)
{
  PrintIntroduction(Difficulty);

  //vars of lock
  const int CodeA = rand() % Difficulty + Difficulty;
  const int CodeB = rand() % Difficulty + Difficulty;
  const int CodeC = rand() % Difficulty + Difficulty;

  //operation
  const int CodeSum = CodeA + CodeB + CodeC;
  const int CodeProduct = CodeA * CodeB * CodeC;

  //printing hints to console
  std::cout << std::endl;
  std::cout << "+ There are 3 numbers for the lock's code...\n";
  std::cout << "+ The three numbers add to: " << CodeSum << std::endl;
  std::cout << "+ They also multiply to give: " << CodeProduct << std::endl;

  //takes player's guess input
  int GuessA, GuessB, GuessC;
  std::cout << "  Enter code: ";
  std::cin >> GuessA >> GuessB >> GuessC;

  //calculates the player's guess
  int GuessSum = GuessA + GuessB + GuessC;
  int GuessProduct = GuessA * GuessB * GuessC;

  //checks to see if player's guess matches lock code
  if (CodeSum == GuessSum && CodeProduct == GuessProduct)
  {
    std::cout << " \n *** Great job! Moving on to the next Dog's lock... ***";
    return true;
  }
  else 
  { 
    std::cout << "\n *** Oh no! Some of the dogs were shipped and sold for medical research. Keep trying! ***"; 
    return false;
  }
}

int main()
{
  srand(time(NULL)); //creates new random sequence based on the time of day

  int LevelDifficulty = 1;
  const int MaxLevel = 5;

  while (LevelDifficulty <= MaxLevel) //Loops game until all levels are cleared
  {
    bool bLevelComplete = PlayGame(LevelDifficulty);
    std::cin.clear(); //clears errors
    std::cin.ignore();  //discards buffer
    
    if (bLevelComplete)
    {
      ++LevelDifficulty; //increases level difficulty by 1
    }
  }

  std::cout << "\n *** Congratulations! You are now the proud owner of cute doggos who love you! UwU ***";
  return 0;
}