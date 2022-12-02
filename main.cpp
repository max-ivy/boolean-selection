#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*******************************************************************************
 * This program will receive a series of candidates from the user. The user
 * will input the candidate's sex, height, and weight. The program will output
 * whether the candidate was accepted or rejected based on height, weight, or
 * height and weight. The user will input 'X' or 'x when they are finished
 * entering all candidates. The program will output the number of candidates
 * accepted, and the acceptance rate expressed as a percentage.
 * -----------------------------------------------------------------------------
 ******************************************************************************/

int main() {
	// FORMATTING CONSTANTS
	const int 	 INPUT_COL 		= 8;
	const int 	 PROMPT_COL 	= 63;
	const int    MAX_LINE_SIZE	= 24;

	// CLASS HEADER CONSTANTS
	const string AS_NAME		= "ASSIGNMENT";
	const int    AS_NUM			= 6;
	const char   AS_TYPE		= 'A';
	const string PROG_NAME		= "Max Ivy";

	// HEIGHT & WEIGHT CONSTANTS
	const int	 M_MIN_HEIGHT = 65;
	const int	 M_MAX_HEIGHT = 80;
	const int	 F_MIN_HEIGHT = 62;
	const int	 F_MAX_HEIGHT = 75;
	const int	 M_MIN_WEIGHT = 130;
	const int	 M_MAX_WEIGHT = 250;
	const int	 F_MIN_WEIGHT = 110;
	const int	 F_MAX_WEIGHT = 185;

	//VARIABLES
	char 	candidateGender;		// IN & CALC  : candidate gender
	int 	candidateHeight;		// IN & CALC  : candidate height
	int 	candidateWeight;		// IN & CALC  : candidate weight
	int		acceptedCandidates;		// CALC & OUT : # of accepted candidates
	int		totalCandidates;		// CALC		  : total # of candidates
	float	acceptanceRate;			// CALC & OUT : % of accepted candidates
	bool 	acceptableHeight;		// CALC		  : correct height conditions
	bool 	acceptableWeight;		// CALC		  : correct weight conditions
	bool	invalid;				// CALC		  : while loop conditions

	//	INITIALIZATIONS
	totalCandidates		= 0;
	acceptedCandidates	= 0;
	acceptanceRate		= 0;

	// INPUT SEX - Prompts user for single-char gender input
	cout << left
		 << setw(PROMPT_COL)
		 << "Please enter the candidate’s information (enter ‘X’ to exit)."
		 << endl;
	cout << left
		 << setw(INPUT_COL)
		 << "Sex: ";
	cin.get(candidateGender);
	cin.ignore(10000, '\n');

	// While loop condition initialization
	invalid = (candidateGender == 'X') ||
			  (candidateGender == 'x');

	// While loop while candidate gender input is not invalid
	while (!invalid)
	{
		//	INPUT HEIGHT - Prompts user for height input
		cout << left
			 << setw(INPUT_COL)
			 << "Height: ";
		cin  >> candidateHeight;
		cin.ignore(10000, '\n');

		// Boolean expression with acceptable height conditions
		acceptableHeight = (((candidateGender == 'M') ||
						   (candidateGender   == 'm'))  &&
						   (candidateHeight   >= M_MIN_HEIGHT  &&
						   candidateHeight    <= M_MAX_HEIGHT)) ||
						   (((candidateGender == 'F') ||
						   (candidateGender   == 'f'))  &&
						   (candidateHeight   >= F_MIN_HEIGHT &&
						   candidateHeight    <= F_MAX_HEIGHT));

		//	INPUT WEIGHT - Prompts user for weight input
		cout <<  left
			 << setw(INPUT_COL)
			 << "Weight: ";
		cin  >> candidateWeight;
		cin.ignore(10000, '\n');

		// Boolean expression with acceptable weight conditions
		acceptableWeight = (((candidateGender == 'M') ||
						   (candidateGender   == 'm'))  &&
						   (candidateWeight   >= M_MIN_WEIGHT  &&
						   candidateWeight    <= M_MAX_WEIGHT)) ||
						   (((candidateGender == 'F') ||
						   (candidateGender   == 'f'))  &&
						   (candidateWeight   >= F_MIN_WEIGHT &&
						   candidateWeight    <= F_MAX_WEIGHT));


		/*	Selection Section - evaluates whether candidate was
		 * accepted or rejected based on height, weight or both */

		// Checks if candidate height & weight is unacceptable
		if(!acceptableHeight && !acceptableWeight)
		{
			// Outputs message to user
			cout << endl
				 << "This candidate has been rejected based on the"
				 << " HEIGHT and WEIGHT requirements."
				 << endl
				 << endl;

			// Accumulates total candidates
			totalCandidates = totalCandidates + 1;
		}
		// Checks if candidate height is unacceptable
		else if(!acceptableHeight && acceptableWeight)
		{
			// Outputs message to user
			cout << endl
				 << "This candidate has been rejected based on"
				 << " the HEIGHT requirement."
				 << endl
				 << endl;

			// Accumulates total candidates
			totalCandidates = totalCandidates + 1;
		}
		// Checks if candidate height is unacceptable
		else if(!acceptableWeight && acceptableHeight)
		{
			// Outputs message to user
			cout << endl
				 << "This candidate has been rejected based on"
				 << " the WEIGHT requirement."
				 << endl
				 << endl;

			// Accumulates total candidates
			totalCandidates = totalCandidates + 1;
		}
		// Outputs acceptance message if conditions are met
		else
		{
			// Outputs message to user
			cout << endl
				 << "This candidate has been ACCEPTED!"
				 << endl
				 << endl
				 << endl;

			//PROCESSING - Accumulates accepted candidates
			acceptedCandidates = acceptedCandidates + 1;

			// PROCESSING - Accumulates total candidates
			totalCandidates = totalCandidates + 1;
		}

		// INPUT SEX - Prompts user for single-char gender input
		cout << left
			 << setw(PROMPT_COL)
			 << "Please enter the candidate’s information (enter ‘X’ to exit)."
			 << endl;
		cout << left
			 << setw(INPUT_COL)
			 << "Sex: ";
		cin.get(candidateGender);
		cin.ignore(10000, '\n');

		// While loop condition initialization
		invalid = (candidateGender == 'X') ||
				  (candidateGender == 'x');
	};

	// PROCESSING - Calculates acceptance rate as a percentage
	acceptanceRate = (float(acceptedCandidates) / float(totalCandidates)) * 100;

	// Checks if total candidates is greater than 0 to prevent divide error
	if (totalCandidates > 0)
	{
		// Outputs number and rate of accepted candidates to user
		cout << endl
			 << acceptedCandidates
			 << " candidate(s) accepted!"
			 << endl;
		cout << setprecision(0)
			 << fixed;
		cout << "That's "
			 << acceptanceRate
			 << "%!"
			 << endl;
	};

/* Error Checking */
//	cerr << totalCandidates << endl;
//	cerr << candidateGender << endl;
//	cerr << candidateHeight << endl;
//	cerr << candidateWeight << endl;

	return 0;
}

