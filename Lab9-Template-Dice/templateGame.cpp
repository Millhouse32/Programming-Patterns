// Games, Template Method example
// Wayne Cheng
// 2/10/2018

#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;
using std::cout; using std::endl;

// template for any game where players take turns to make moves
// and there is a winner
class Game
{
	public:
		Game():playersCount_(0), movesCount_(0), playerWon_(noWinner){}

		// template method
		void playGame(const int playersCount = 0) 
		{
			playersCount_ = playersCount;
			movesCount_=0;

			initializeGame();

			for(int i=0; !endOfGame(); i = (i+1) % playersCount_ )
			{
				makeMove(i);
				if (i==playersCount_-1) 
					++movesCount_; 
			}
			printWinner();
		}

		virtual ~Game(){}

	protected:
		// primitive operations
		virtual void initializeGame() = 0;
		virtual void makeMove(int player) = 0;
		virtual void printWinner() = 0;
		virtual bool endOfGame() 
		{
			return playerWon_ != noWinner;
		} // this is a hook returns true if winner is decided
		
		static const int noWinner=-1;

		int playersCount_;
		int movesCount_;
		int playerWon_;
};

// Monopoly - a concrete game implementing primitive 
// operations for the template method
class Monopoly: public Game 
{
	public:  
		// implementing concrete methods
		void initializeGame()
		{
			playersCount_ = rand() % numPlayers_ + 1 ; // initialize players
		}

		void makeMove(int player) 
		{
			if (movesCount_ > minMoves_)
			{ 
				const int chance = minMoves_ + rand() % (maxMoves_ - minMoves_);
				if (chance < movesCount_) 
					playerWon_= player;
			}
		}

		void printWinner()
		{
			cout << "Monopoly, player "<< playerWon_<< " won in "
				 << movesCount_<< " moves." << endl;
		}

	private:
		static const int numPlayers_ = 8; // max number of players
		static const int minMoves_ = 20;  // nobody wins before minMoves_
		static const int maxMoves_ = 200; // somebody wins before maxMoves_
};

// Chess - another game implementing primitive operations
class Chess: public Game 
{
	public:
		void initializeGame()
		{
			playersCount_ = numPlayers_; // initalize players
			for(int i=0; i < numPlayers_; ++i) 
				experience_[i] = rand() % maxExperience_ + 1 ; 
		}

		void makeMove(int player)
		{
			if (movesCount_ > minMoves_)
			{
				const int chance = (rand() % maxMoves_) / experience_[player];
				if (chance < movesCount_) 
					playerWon_= player;
			}
		}

		void printWinner()
		{
			cout << "Chess, player " << playerWon_ 
				 << " with experience " << experience_[playerWon_]
				 << " won in "<< movesCount_ << " moves over"
				 << " player with experience " 
				 << experience_[playerWon_== 0 ? 1:0] << endl;
		}

	private:
		static const int numPlayers_ = 2;
		static const int minMoves_ = 2; // nobody wins before minMoves_
		static const int maxMoves_ = 100; // somebody wins before maxMoves_
		static const int maxExperience_ = 3; // player's experience
											 // the higher, the greater probability of winning
		int experience_[numPlayers_]; 
};

class Dice: public Game {

    public:
        void initializeGame() {
            playersCount_ = numPlayers_; // inaitalize players
            humanScore = 0;
            computerScore = 0;
            computerPassed = false;
            humanPassed = false;
        }

        void makeMove(int player) {
            int computerChoice;

            char humanChoice;
            int compCurrScore;
            int humanCurrScore;
            if (movesCount_ > 0) {
                if (!computerPassed) {
                    computerChoice=rand()%2;
                    if (!computerChoice) {
                        computerPassed = true;
                    }
                }
                if (!humanPassed) {
                    cout << "Do you want to roll again? [y/n] :: ";
                    std::cin >> humanChoice;
                    if (humanChoice == 'n') {
                        humanPassed = true;
                    }
                    else if (humanChoice != 'y') {
                        cout << "Invalid choice auto rerolling" << endl;
                    }
                }
            }

            cout << "Computer rolled :: ";
            if (!computerPassed) {
                compCurrScore = 0;
                for (int i = 0; i < 5; i++) {
                    int number=rand()%6+1;
                    cout<<number<<" ";
                    compCurrScore+=number;
                }
                cout <<" = "<<compCurrScore;

                computerScore=computerScore>compCurrScore?computerScore:compCurrScore;

                cout <<", computer's highest score = " << computerScore << endl;
            }
            else {
                cout << "passed, computer's highest score = " << computerScore << endl;
            }
            cout << "You rolled: ";

            if (!humanPassed) {
                humanCurrScore = 0;
                for (int i = 0; i < 5; i++) {
                    int number=rand()%6+1;
                    cout <<number<<" ";
                    humanCurrScore += number;
                }
                cout << " = " << humanCurrScore;
                humanScore=humanScore>humanCurrScore?humanScore:humanCurrScore;
                cout <<", your highest score =" << humanScore << endl;
            }
            else {
                cout << "passed, your highest score = "<<humanScore << endl;
            }
        }

        void printWinner() {
            if (computerScore >= humanScore) {
                cout << "you lose" << endl;
            }
            else {
                cout << "you win" << endl;
            }
        }

        virtual bool endOfGame() {
            if (movesCount_ == 3 || humanPassed && computerPassed) {
                return true;
            }
            return false;
        }



    private:
        int humanScore;
        int computerScore;
        static const int numPlayers_ = 1;
        bool computerPassed;
        bool humanPassed;
};

int main() 
{
	srand(time(nullptr));

	Game* gp = nullptr;

	// play dice
    gp= new Dice;
    gp->playGame();
    delete gp;

	return 0;
}
