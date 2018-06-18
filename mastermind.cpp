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
  int common_letters(string guess) const;
  int matched_letters(string guess) const;
  
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
  
  return "";
}

int Mastermind::common_letters(string guess) const
{
  int num_common_letters = 0;
  for (int i = 0; i < guess.length(); ++i)
  {
    for (int j = 0; j < picked.length(); ++j)
    {
      if (j == i)
	continue;
      if (guess[i] == picked[j])
	++num_common_letters;
    }
  }
  return num_common_letters;
}

void Mastermind::play()
{
  cout << "Computer: I have a 4 letter word in mind. Can you guess it?" << endl;
  const int namesSize = sizeof(names) / sizeof(names[0]);
  const int myRandom = rand() % namesSize;
  picked = names[myRandom];
  
  string guess;
  int tries = 0;
  while (true)
  {
    tries++;
    guess = read_guess();
    if (check(guess) == "++++") {
      cout << "Computer: You got it! " << tries << " tries." << endl;
      break;
    }
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
  Mastermind mastermind;

 
    
}
