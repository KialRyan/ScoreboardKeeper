#include <iostream>
#include <vector>

using namespace std;

const int MAX_PERIODS = 10;
const int MAX_TEAMS = 4;
const int MIN_PERIODS = 1;
const int MIN_TEAMS = 1;

int main()
{
  int periods;
  int teams;
  int players =1;
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
   //once created, display the scoreboard
  for(int r=0; r<Scoreboard.size();r++)
  {
    
    cout<<"Player "<<players<<": ";
    for(int c=0;c<Scoreboard[r].size();c++)
    {
        cout<<Scoreboard[r][c]<<"|";
    }
    cout<<endl;
    players++;
  }
  return 0;
  }
}
