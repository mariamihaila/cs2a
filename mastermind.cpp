#include <iostream>
#include <string>

using namespace std;

class Mastermind
{
public:
  Mastermind() {}
  void play();
  
private:
  void read_guess();
  void pick_name();
  string check() const;
  bool isValid(string name) const;
  
  string get_guess() const;
  string get_picked() const;

  bool set_guess(string a_gues);  
  bool set_picked(string a_pick);
  
  static const string names[];
  string guess;
  string picked;
  static const int WORD_LENGTH = 4;
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

string Mastermind::get_guess() const
{
  return guess;
}

string Mastermind::get_picked() const
{
  return picked;
}

bool Mastermind::set_guess(string a_guess)
{
  if (!isValid(a_guess))
    return false;
  guess = a_guess;
  return true;
}

bool Mastermind::set_picked(string a_pick)
{
  if (!isValid(a_pick))
    return false;
  picked = a_pick;
  return true;
}

void Mastermind::pick_name()
{
  const int namesSize = sizeof(names) / sizeof(names[0]);
  const int myRandom = rand() % namesSize;
  const string picked_name = names[myRandom];
  set_picked(picked_name);
}
  
bool Mastermind::isValid(string name) const
{
  return name.length() == WORD_LENGTH;
}

string Mastermind::check() const
{
  string response = "";
  int num_matched = 0;
  int num_found = 0;
  for (int i = 0; i < WORD_LENGTH; ++i)
  {
    const char curr = picked[i];
    if (guess[i] == curr)
    {
      ++num_matched;
      continue;
    }
    for (int j = 0; j < WORD_LENGTH; ++j)
    {
      if (guess[j] == curr)
	++num_found;
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
  cout << "Computer: I have a 4 letter name in mind. Can you guess it?" << endl;
  int tries = 0;
  pick_name();
  while (true)
  {
    tries++;
    read_guess();
    const string response = check();
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

void Mastermind::read_guess()
{
  string a_guess;
  while (true)
  {
    getline(cin, a_guess);
    if (set_guess(a_guess))
      return;
    cout << "Please enter a " << WORD_LENGTH << " letter name!" << endl;
  }	
}

int main()
{
  srand(time(0));
  Mastermind mastermind;
  mastermind.play();
}
