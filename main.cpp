#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_PERIODS = 10;
const int MAX_TEAMS = 4;
const int MIN_PERIODS = 1;
const int MIN_TEAMS = 1;

void printScoreboard(vector < vector <int> >);
int randomBetween(int, int); 
int main()
{
  srand((int) time(0));
  int periods;
  int teams;
  
  cout<<"How many competitors? ";
  cin>>teams;
  cout<<"How many scoring periods? ";
  cin>>periods;

  if( teams < MIN_TEAMS || periods < MIN_PERIODS || 
      teams > MAX_TEAMS || periods > MAX_PERIODS )
  {
    cout<<"Must have between "<<MIN_TEAMS<<" and "<<MAX_TEAMS<<" competitors.\n";
    cout<<"and between "<<MIN_PERIODS<<" and "<<MAX_PERIODS<<" periods.\n";
    return 0;
  }
  else
  {
   //make scoreboard and fill it with zeros
  vector<vector<int> >Scoreboard;
  Scoreboard.resize(teams);

  for(int row=0; row<Scoreboard.size();row++)
  {
    Scoreboard[row].resize(periods);
  }
  
  for(int r=0; r<Scoreboard.size();r++)
  {
    for(int c=0;c<Scoreboard[r].size();c++)
    {
      Scoreboard[r][c]=0;
    }
  }
  printScoreboard(Scoreboard);
  for(int r=0; r<Scoreboard.size();r++)
  {
    for(int c=0;c<Scoreboard[r].size();c++)
    {
        Scoreboard[r][c] = randomBetween(5,5);
    }

  }
  printScoreboard(Scoreboard);  
  }
  return 0;
}  
  //once created, display the scoreboard
void printScoreboard(vector<vector<int> > grid)
{
  int players=1;
  cout<<"SCOREBOARD\n"; 
  for(int r=0; r<grid.size();r++)
  {
    
      cout<<"Player "<<players<<": ";
      for(int c=0;c<grid[r].size();c++)
      {
          cout<<grid[r][c]<<"|";
      }
      cout<<endl;
      players++;
  }
}
int randomBetween(int first,int second)
{
  if(first >= second)
  {
    return second + rand()%(first-second+1);
  }
  else if (second > first)
  {
    return first + rand()%(second-first+1);
  }
}

  

