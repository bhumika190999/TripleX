#include <iostream>
#include <ctime>

  void Introduction(int Level)
{
    std::cout<<"\n\nYou have been abducted some deserted place and there are several doors to unlock to reach home."<< std::endl;
    std::cout<<"You're at door "<< Level <<"."<< std::endl;
    std::cout<< "You need to enter correct codes to proceed..."<< std::endl;

}
bool PlayGame(int Level)
{   
    Introduction(Level);
    const int CodeA = rand() % Level + Level ,CodeB=rand() % Level + Level ,CodeC=rand() % Level + Level;
    const int CodeSum=CodeA+CodeB+CodeC;
    const int CodeProduct =  CodeA*CodeB*CodeC;

    std::cout << "There are three numbers in the code."<< std::endl;
    std::cout << "The codes add-up to: "<< CodeSum<< std::endl;
    std::cout << "The codes multiply to give: " <<CodeProduct << std::endl;

  
    int GuessA, GuessB, GuessC;

    std::cin>>GuessA;
    std::cin>>GuessB;
    std::cin>>GuessC;
  //  std::cout<<"You entered: "<<GuessA << GuessB << GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    std::cout<<std::endl;
    
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout<<"\nYou win!!.The door is opening..";
        return true;
    }
    else
    {
        std::cout<<"\nOops... Looks like you're liking it here. Enter the code again to open the door.\n";
        return false;
    }
  } 
int main()
{   srand(time(NULL));
    int LevelDifficulty = 1;
    int const MaxLevel =5;

    while (LevelDifficulty <= MaxLevel)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty); 
        std::cin.clear();//clear errors
        std::cin.ignore();//ignores buffer

        if (bLevelComplete)
        {    
            ++LevelDifficulty;
        }
        
    } 
    std::cout<<"\n\nYou are now free. Never get lost again. Tell your mumma I said hi.~_^";
    return 0;
}