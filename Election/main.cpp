#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

struct Issue
{
	string name;
	bool isPro;
	int totalSupporters;
};

struct Candidate
{
	string name;
	Issue positions[10];
	int totalVotes;
};

struct Citizen
{
	Issue positions[10];

	void ChooseIssues(Issue issues[10])
	{
		for (int i = 0; i < 10; i++)
		{
			positions[i].isPro = rand() % 2;

			positions[i].name = issues[i].name;

			if (positions[i].isPro)
			{
				issues[i].totalSupporters++;
			}
		}
	}

	int CheckCandidiateAgreement(Candidate candidate)
	{
		int agreeCount = 0;
		for (int i = 0; i < 10; i++)
		{
			if (positions[i].isPro == candidate.positions[i].isPro)
			{
				agreeCount++;
			}
		}
		return agreeCount;
	}
};

void ElectionDay(Candidate candidates[3], Citizen citizens[1000])
{

	for (int i = 0; i < 1000; i++)
	{
		int maxAgreement = 0;
		int choiceIndex = -1;

		for (int c = 0; c < 3; c++)
		{
			int agree = citizens[i].CheckCandidiateAgreement(candidates[c]);

			if (agree > maxAgreement)
			{
				choiceIndex = c;
				maxAgreement = agree;
			}
		}

		if (choiceIndex != -1)
		{
			candidates[choiceIndex].totalVotes++;
		}

	}
}

string GetRandomTopic();
string GetRandomName();
string GetRandomState();

void CreateIssues(Issue issues[10]);
void CreateCandidates(Candidate candidates[3], Issue issues[10]);

int main()
{
	srand(time(NULL));

	Issue issues[10];
	CreateIssues(issues);

	Candidate candidates[3];
	CreateCandidates(candidates, issues);

	cout << "CANDIDATES" << endl;
	for (int c = 0; c < 3; c++)
	{
		cout << candidates[c].name << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << "* ";
			if (candidates[c].positions[i].isPro) { cout << "PRO-"; }
			else { cout << "ANTI-"; }
			cout << candidates[c].positions[i].name << endl;
		}

		cout << endl;
	}

	Citizen citizens[1000];
	for (int i = 0; i < 1000; i++)
	{
		citizens[i].ChooseIssues(issues);
	}

	cout << "TOTAL ISSUE SUPPORTERS";
	for (int i = 0; i < 10; i++)
	{
		cout << "* " << issues[i].totalSupporters << " - " << issues[i].name << endl;
	}

	ElectionDay(candidates, citizens);

	int winner = 0, mostVotes = 0;

	cout << endl << "ELECTION RESULTS" << endl;
	for (int c = 0; c < 3; c++)
	{
		cout << "* " << candidates[c].name << " with " << candidates[c].totalVotes << " votes" << endl;
		if (candidates[c].totalVotes > mostVotes)
		{
			winner = c;
			mostVotes = candidates[c].totalVotes;
		}
	}
	cout << endl << candidates[winner].name << " wins!" << endl;
	return 0;
}

void CreateIssues(Issue issues[10])
{
	for (int i = 0; i < 10; i++)
	{
		issues[i].name = GetRandomTopic();
		issues[i].totalSupporters = 0;
	}
}

void CreateCandidates(Candidate candidates[3], Issue issues[10])
{
	for (int c = 0; c < 3; c++)
	{
		candidates[c].name = GetRandomName();
		candidates[c].totalVotes = 0;

		for (int i = 0; i < 10; i++)
		{
			candidates[c].positions[i].name = issues[i].name;
			candidates[c].positions[i].isPro = rand() % 2;

			if (candidates[c].positions[i].isPro)
			{
				issues[i].totalSupporters++;
			}
		}
	}
}

string GetRandomTopic()
{
	string topicsA[10] = {
		"ROBOT",
		"TELEPORTATION",
		"JUPITER",
		"CYBORG",
		"TIME TRAVEL",
		"SPACESHIP",
		"WORMHOLE",
		"VIRTUAL REALITY",
		"3D PRINTER",
		"CYBER"
	};

	string topicsB[10] = {
		"COLONIES",
		"RIGHTS",
		"MARRIAGE",
		"CONTROL",
		"WAR",
		"RESTRICTION",
		"SUBSIDIES",
		"TAX BREAK",
		"TAX INCREASE",
		"INDUSTRIAL COMPLEX"
	};

	return topicsA[rand() % 10] + " " + topicsB[rand() % 10];
}

string GetRandomName()
{
	string namesA[15] = {
		"Janan", "Kalina", "Lei", "Sakke", "Denise",
		"Pradeep", "Takuya", "Salomao", "Sunan", "Angharad",
		"Teodor", "Paloma", "Varya", "Irenka", "Quan"
	};

	string namesB[15] = {
		"Katz", "Zietek", "Van Achthoven", "Chapman", "Szweda",
		"Leveque", "Liu", "Samuel", "Scotti", "Welch",
		"Pierno", "Shimizu", "Barnett", "Ruan", "Kwok"
	};

	return namesA[rand() % 15] + " " + namesB[rand() % 15];;
}

string GetRandomState()
{
	string states[50] = {
		"Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida", "Georgia",
		"Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", "Maryland", "Massachussets",
		"Michigan", "Minnesota", "Mississippi", "Missouri", "Montana", "Nebraska", "Nevada", "New Hampshire", "New Jersey",
		"New Mexico", "New York", "North Carolina", "North Dakota", "Ohio", "Oklahoma", "Oregon", "Pennsylvania",
		"Rhode Island", "South Carolina", "South Dakota", "Tennessee", "Texas", "Utah", "Vermont", "Virginia",
		"Washington", "West Virginia", "Wisconsin", "Wyoming"
	};

	return states[rand() % 50];
}