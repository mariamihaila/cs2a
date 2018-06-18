#include <iostream>
#include <string>

using namespace std;

class Mastermind
{
public:
  Mastermind() {}
  void play();
  
private:
  string read_guess() const;
  string check(string guess) const;
  
  static const string names[];
  string picked;
};

const string Mastermind::names[] =
  {
    "ADAM", "ALAN", "ALEX", "AMIR", "AMOS", "ANDY", "ANNA", "ANNE",
    "ARNE", "AXEL", "BART", "BERT", "BETH", "BILL", "BOYD", "BRAD",
    "BRET", "CARL", "CARY", "CASE", "CHET", "CHIP", "CLAY", "CLEM",
    "COLE", "CORY", "CRIS", "CURT", "DALE", "DANA", "DANI", "DAVE",
    "DAWN", "DEAN", "DEBI", "DICK", "DION", "DIRK", "DONN", "DORI",
    "DORY", "DOUG", "DREW", "DUKE", "EARL", "EDDY", "ELSA", "EMIL",
    "EMMA", "ERIC", "ERIK", "EVAN", "FRED", "GAIL", "GALE", "GARY",
    "GENE", "GIGI", "GILL", "GLEN", "GREG", "HANK", "HANS", "HARV",
    "HEIN", "HERB", "HOHN", "HUEY", "HUGH", "HUME", "HURF", "ILYA",
    "IZZY", "JACK", "JANE", "JARL", "JEAN", "JEFF", "JESS", "JILL",
    "JIRI", "JOCK", "JOEL", "JOHN", "JONG", "JONI", "JOON", "JOSE",
    "JOSH", "JUAN", "JUDY", "JUHA", "JUNE", "JURI", "KARI", "KARL",
    "KATE", "KEES", "KENN", "KENT", "KIKI", "KING", "KIRK", "KNUT",
    "KORY", "KRIS", "KURT", "KYLE", "KYLO", "LANA", "LARS", "LEIF",
    "LEON", "LILA", "LISA", "LIST", "LIZA", "LOIS", "LORD", "LORI",
    "LOYD", "LUIS", "LUKE", "LYNN", "MANN", "MARA", "MARC", "MARK",
    "MARY", "MATS", "MATT", "MAYO", "MICK", "MIEK", "MIKE", "MIKI",
    "MILO", "MOTT", "NAIM", "NATE", "NEAL", "NEIL", "NHAN", "NICI",
    "NICK", "NILS", "NING", "NOAM", "NORA", "NORM", "NOVO", "OFER",
    "OLAF", "OLEG", "OLOF", "OMAR", "OWEN", "OZAN", "PAGE", "PART",
    "PAUL", "PETE", "PETR", "PHIL", "PIET", "PING", "PRIA", "RAIF",
    "RAJA", "RALF", "RAND", "RAUL", "RAVI", "REAL", "REES", "REID",
    "RENU", "RICH", "RICK", "ROLF", "ROOT", "ROSS", "RUDY", "RUSS",
    "RUTH", "SAAD", "SAUL", "SCOT", "SEAN", "SETH", "SHAI", "SHAW",
    "SHEL", "SKEF", "SKIP", "STAN", "SYED", "SYUN", "TAIT", "TERI",
    "THAD", "THEO", "TIMO", "TOBY", "TODD", "TOFT", "TONY", "TRAN",
    "TREY", "TROY", "TUAN", "TUNA", "VERN", "VICE", "VICK", "WADE",
    "WALT", "WILL", "WOLF"
  };

string Mastermind::check(string guess) const
{
  string response = "";
  int num_matched = 0;
  int num_found = 0;
  for (int i = 0; i < picked.length(); ++i)
  {
    const char curr = picked[i];
    if (guess[i] == curr)
      ++num_matched;
    else
    {
      for (int j = 0; j < guess.length(); ++j)
      {
	if (guess[j] == curr)
	  ++num_found;
      }
    }
  }
  for (int i = 0; i < num_matched; ++i)
    response += "*";
  for (int i = 0; i < num_found; ++i)
    response += "-";
  return response;
}

void Mastermind::play()
{
  cout << "Computer: I have a 4 letter word in mind. Can you guess it?" << endl;
  const int namesSize = sizeof(names) / sizeof(names[0]);
  const int myRandom = rand() % namesSize;
  cout << myRandom << endl;
  picked = names[myRandom];
  
  string guess;
  int tries = 0;
  while (true)
  {
    tries++;
    guess = read_guess();
    const string response = check(guess);
    if (response == "****")
    {
      cout << "Computer: You got it! " << tries << " tries." << endl;
      break;
    }
    if (response == "") 
      cout << "Sorry, you got nothing." << endl;
    else 
      cout << response << endl;
  }
}

string Mastermind::read_guess() const
{
  string guess;
  getline(cin, guess);
  return guess;
}

int main()
{
  srand(time(0));
  
  Mastermind mastermind;

  mastermind.play();
}
