//Name: Jose Villanueva Vigil
//Course: COSC 2436
//Program set 2, Required Program (CrewScheduling)
//References: I used the PDF covering program set 2
//=================================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>
#include <random>

using namespace std;

//the NFL_List class is a linked list that is used to store a crew's season schedule data
//(the amount of times a team has played and the weeks those teams have played)
class NFL_List
{
private:

	//a structure called NFL_List_Node is decalred (this will create the linked list)
	struct NFL_List_Node
	{
		//a pointer with the data type of NFL_List_Node (next) is set to nullptr
		//a string called NFL_Team is created
		//the following integers are initalized to zero 
		//Home, Away, weePlayed, priorWeek, and amountPlayed
		NFL_List_Node* next = nullptr;
		string NFL_Team;
		int Home = 0;
		int Away = 0;
		int weekPlayed = 0;
		int priorWeek = 0;
		int amountPlayed = 0;
	};

	//a pointer with the data type of NFL_List_Node (head) is set to nullptr
	NFL_List_Node* head = nullptr;

public:
	//the default constructor sets head to nullptr
	NFL_List()
	{
		head = nullptr;
	}

	//the member functions (below) are defined as out-of-line member functions, 
	//each of their descriptions can be found below the NFlCrewStats class
	//(their code can also be found there)
	~NFL_List();
	void insertValues(string, string, int);
	void removeValues(string, string);
	void insertTeams(string);
	void resetValues();
	void displayValues();
	string freeTeams(int);
	int returnHomeStatus(string);
	int returnAwayStatus(string);
	int returnWeekPlayed(string);
	int returnAmountPlayed(string);
};

//the NFlcrewStats class is used to gather the information (schedules) for a crew
class NFlCrewStats
{
private:
	//a string called Name is defined as private
	//a string pointer called SeasonSchedule is set to nullptr and defined as private
	//an integer called offWeeks is defined as private 
	string Name;
	string* SeasonSchedule = nullptr;
	int offWeeks;

public:
	//an instance of the NFL_List class is created (object named crewScheduleSeason)
	NFL_List crewScheduleSeason;

	//the default constructor is used to initalize all of the private 
	//member varaibles to a default value, the seasonSchedule pointer is used to create 
	//an array of strings, and the intializeSeasonSchedule member function is called
	NFlCrewStats()
	{
		Name = " ";
		offWeeks = 0;
		SeasonSchedule = new string[18];
		initalizeSeasonSchedule();
	}

	//the overloaded constructor is used to initalize all of the private 
	//member varaibles to a default value(apart from Name, the Name is set to equal string N)
	//the seasonSchedule pointer is used to create an array of strings, 
	// and the intializeSeasonSchedule member function is called
	NFlCrewStats(string N)
	{
		Name = N;
		offWeeks = 0;
		SeasonSchedule = new string[18];
		initalizeSeasonSchedule();
	}

	//the setCrewName function is used to set the Name variable, Name is set to N (passed in the parameter list)
	void setCrewName(string N)
	{
		Name = N;
	}

	//the setSeasonSchedule function is used to set a crew's schedule, string n, and int i are passed through 
	//the parameter list. string n is saved in SeasonSchedule (n-1) 
	void setSeasonSchedule(string n, int i)
	{
		SeasonSchedule[i - 1] = n;

		//if the value of n is "OFF", then offWeeks is incremented by one (+1)
		if (n == "OFF")
		{
			offWeeks++;
		}
	}

	//the intializeSeasonSchedule function is used to initalize all of a crew's schedule to "Empty"
	void initalizeSeasonSchedule()const
	{
		for (int index = 0; index < 18; index++)
		{
			SeasonSchedule[index] = "Empty";
		}
	}

	//the resetOffWeeks function is used to set the off weeks to for a crew (set to zero)
	void resetOffWeeks()
	{
		offWeeks = 0;
	}

	//the getSeasonSchedule function returns a crew's current game (using int i)
	string getSeasonSchedule(int i) const
	{
		return SeasonSchedule[i];
	}

	//the getCrewName function is used to return the Name variable 
	string getCrewName() const
	{
		return Name;
	}

	//the getOffWeeks function is used to return the offWeeks variable 
	int getOffWeeks() const
	{
		return offWeeks;
	}
};

//the returnAmountPlayed out-of-line member function is used to return the amount of games that a team has
//played during the season, for a specific crew(is string a passed through the parameter list, AnyTeam)
int NFL_List::returnAmountPlayed(string AnyTeam)
{
	//a pointer with the data type if NFL_List_Node is created (tempNode)
	//and is set to equal the front of the list (head)
	NFL_List_Node* tempNode;
	tempNode = head;

	//while the tempNode is pointing to something, the loop will continue to iterate 
	while (tempNode)
	{
		//if the value of the NFL-Team is equal to AnyTeam, then the amountPlayed value is returned 
		if (tempNode->NFL_Team == AnyTeam)
		{
			return tempNode->amountPlayed;
		}

		//tempNode points to the next node in the linked list
		tempNode = tempNode->next;
	}

	return 0;
}

//the returnWeekPlayed out-of-line member function is used to return the week a team had played for a crew
//during the season(a string is passed through the parameter list, AnyTeam)
int NFL_List::returnWeekPlayed(string AnyTeam)
{
	//a pointer with the data type if NFL_List_Node is created (tempNode)
	//and is set to equal the front of the list (head)
	NFL_List_Node* tempNode;
	tempNode = head;

	//while the tempNode is pointing to something, the loop will continue to iterate 
	while (tempNode)
	{
		//if the value of the NFL-Team is equal to AnyTeam, then the weekPlayed value is returned 
		if (tempNode->NFL_Team == AnyTeam)
		{
			return tempNode->weekPlayed;
		}

		//tempNode points to the next node in the linked list
		tempNode = tempNode->next;
	}
	return 0;
}

//the returnAwayStatus out-of-line member function is used to return the amount of away games
//a team had played for a crew during the season(a string is passed through the parameter list, teamOne)
int NFL_List::returnAwayStatus(string teamOne)
{
	//a pointer with the data type if NFL_List_Node is created (tempNode)
	//and is set to equal the front of the list (head)
	NFL_List_Node* tempNode;
	tempNode = head;

	//while the tempNode is pointing to something, the loop will continue to iterate 
	while (tempNode)
	{
		//if the value of the NFL-Team is equal to teamOne, then the Away value is returned 
		if (tempNode->NFL_Team == teamOne)
		{
			return tempNode->Away;
		}

		//tempNode points to the next node in the linked list
		tempNode = tempNode->next;
	}
	return 0;
}

//the returnHomeStatus out-of-line member function is used to return the amount of home games
//a team had played for a crew during the season(a string is passed through the parameter list, teamTwo)
int NFL_List::returnHomeStatus(string teamTwo)
{
	//a pointer with the data type if NFL_List_Node is created (tempNode)
	//and is set to equal the front of the list (head)
	NFL_List_Node* tempNode;
	tempNode = head;

	//while the tempNode is pointing to something, the loop will continue to iterate 
	while (tempNode)
	{
		//if the value of the NFL-Team is equal to teamTwo, then the Home value is returned 
		if (tempNode->NFL_Team == teamTwo)
		{
			return tempNode->Home;
		}

		//tempNode points to the next node in the linked list
		tempNode = tempNode->next;
	}
	return 0;
}

//the insertValues out-of-line member function is used to increment the values of two teams for a crew,
//this indicates that the crew is play that match(two strings are passed through the parameter list,
// TeamOne and TeamTwo, and an integer is passed through the parameter list, week)
void NFL_List::insertValues(string TeamOne, string TeamTwo, int week)
{
	//a pointer with the data type if NFL_List_Node is created (tempNode)
	//and is set to equal the front of the list (head)
	NFL_List_Node* tempNode;
	tempNode = head;

	//while the tempNode is pointing to something, the loop will continue to iterate 
	while (tempNode)
	{
		//if the value of the NFL-Team is equal to TeamOne, then the values of TeamOne are incremented
		if (tempNode->NFL_Team == TeamOne)
		{
			tempNode->Away++;
			tempNode->amountPlayed++;
			tempNode->priorWeek = tempNode->weekPlayed;
			tempNode->weekPlayed = week;
		}
		//else if the value of the NFL-Team is equal to TeamTwo, then the values of TeamTwo are incremented
		else if (tempNode->NFL_Team == TeamTwo)
		{
			tempNode->Home++;
			tempNode->amountPlayed++;
			tempNode->priorWeek = tempNode->weekPlayed;
			tempNode->weekPlayed = week;
		}

		//tempNode points to the next node in the linked list
		tempNode = tempNode->next;
	}
}

//the removeValues out-of-line member function is used to decrement the values of two teams for a crew,
//this indicates that a crew has swapped matches(two strings are passed through the parameter list,
// TeamOne and TeamTwo)
void NFL_List::removeValues(string teamOne, string teamTwo)
{
	//a pointer with the data type if NFL_List_Node is created (tempNode)
	//and is set to equal the front of the list (head)
	NFL_List_Node* tempNode;
	tempNode = head;

	//while the tempNode is pointing to something, the loop will continue to iterate 
	while (tempNode)
	{
		//if the value of the NFL-Team is equal to TeamOne, then the values of TeamOne are decremented
		//(and weekPlayed is set to equal priorWeek)
		if (tempNode->NFL_Team == teamOne)
		{
			tempNode->Away--;
			tempNode->amountPlayed--;
			tempNode->weekPlayed = tempNode->priorWeek;
		}
		//else if the value of the NFL-Team is equal to TeamTwo, then the values of TeamTwo are decremented
		//(and weekPlayed is set to equal priorWeek)
		else if (tempNode->NFL_Team == teamTwo)
		{
			tempNode->Home--;
			tempNode->amountPlayed--;
			tempNode->weekPlayed = tempNode->priorWeek;
		}

		//tempNode points to the next node in the linked list
		tempNode = tempNode->next;
	}
}

//the insertTeams out-of-line member function is used to insert a list of NFL teams into the linked list
//(a string is passed through the parameter list, teamName)
void NFL_List::insertTeams(string teamName)
{
	//two pointers with the data type of NFL_List_Node are created (nodePtr and newNode)
	NFL_List_Node* newNode;
	NFL_List_Node* nodePtr;

	//memory is allocated to create a new NFL_List_Node using newNode
	//newNode is the initalized (its NFL_Team is set to teamName and next is set to nullptr)
	newNode = new NFL_List_Node;
	newNode->NFL_Team = teamName;
	newNode->next = nullptr;

	//if the value of head is nullptr, the head is set to equal the address of the newNode
	if (!head)
	{
		head = newNode;
	}

	//otherwise the following statement is executed
	else
	{
		//nodePtr is set to the address of head
		nodePtr = head;

		//while nodePtr is pointing to next, the loop will contiue to iterate
		while (nodePtr->next)
		{
			//nodePtr is set to equal the next node in the linked list
			nodePtr = nodePtr->next;
		}

		//the current address of the last node in the linked list is set to equal 
		//the address of the newNode
		nodePtr->next = newNode;
	}
}

//the resetValues out-of-line member function is used to rest all of the teams values to zero
void NFL_List::resetValues()
{
	//a pointer with the data type if NFL_List_Node is created (nodePtr)
	//and is set to equal the front of the list (head)
	NFL_List_Node* nodePtr;
	nodePtr = head;

	//while the nodePtr is pointing to something, the loop will continue to iterate 
	while (nodePtr)
	{
		//all of the values for a team are set to zero
		nodePtr->amountPlayed = 0;
		nodePtr->Away = 0;
		nodePtr->Home = 0;
		nodePtr->weekPlayed = 0;
		nodePtr->priorWeek = 0;

		//nodePtr points to the next node in the linked list
		nodePtr = nodePtr->next;
	}
}

//the displayValues out-of-line member function is a function that was used to test the 
//NFL_List class, it displays the values of a team
void NFL_List::displayValues()
{
	//a pointer with the data type if NFL_List_Node is created (nodePtr)
	//and is set to equal the front of the list (head)
	NFL_List_Node* nodePtr;
	nodePtr = head;

	//while the nodePtr is pointing to something, the loop will continue to iterate 
	while (nodePtr)
	{
		//all of a teams variables are disaplyed (for testing purposes to determine if
		//the values are being incremented/decremented)
		cout << "Name: " << nodePtr->NFL_Team << endl;
		cout << "Week Played: " << nodePtr->weekPlayed << endl;
		cout << "Home Games Player: " << nodePtr->Home << endl;
		cout << "Away Games Played: " << nodePtr->Away << endl;
		cout << "Total Games Played: " << nodePtr->amountPlayed << endl;

		//nodePtr points to the next node in the linked list
		nodePtr = nodePtr->next;
	}
}

//the freeTeams out-of-line member function is used to retrieve any teams that a crew had not played 
//with/for during the season (an integer is passed through the paraeter list, val)
string NFL_List::freeTeams(int val)
{
	//a pointer with the data type if NFL_List_Node is created (nodePtr)
	//and is set to equal the front of the list (head)
	NFL_List_Node* nodePtr;

	string teamName;

	nodePtr = head;

	//a for loop is used to move through the linked list
	for(int twoVal = 0; twoVal < val; twoVal++)
	{
		//if the amountPlayed value for the curret node is zero, then teamName is set to NFl_Team
		if (nodePtr->amountPlayed == 0)
		{
			teamName = nodePtr->NFL_Team;
		}

		//nodePtr points to the next node in the linked list
		nodePtr = nodePtr->next;
	}

	//if the amountPlayed value for the curret node is zero, then teamName + " " is returned 
	if (nodePtr->amountPlayed == 0)
	{
		return (teamName + (" "));
	}

	//if the if statment above is false, the "" is returned 
	return ("");
}

//the NFL_List out-of-line destructor is used to deallocate the memory used to create the linked list
NFL_List::~NFL_List()
{
	//two pointers with the data type of NFL_List_Node are created (nodePtr and nextNode)
	//and nodePtr is set to equal the front of the list (head)
	NFL_List_Node* nodePtr;
	NFL_List_Node* nextNode;

	nodePtr = head;

	//while nodePtr is not nullptr, the loop will continue to iterate
	while (nodePtr != nullptr)
	{
		//nextNode points to the next node in the linked list
		//nodePtr is deleted (current node)
		//nodePtr is set to the next node in the linked list (nextNode)
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

//the following constant integers are used to create arrays 
//that will be used to hold the data from the data file 
const int CrewSize = 17;
const int ScheduleDuration = 18;
const int TeamTableColumns = 19;
const int TeamTableRows = 32;
const int minTeam = 0;

//a new instance of a map (empty) is created, its key is a string 
//and its value is an instance of the "NFlCrewStats" class
map<string, NFlCrewStats> NFL_Schedule_Info;

//the Scheduleweeks string array is used to hold the number of weeks within a season
//the TeamSchedule string array is used to hold the season of the schedule 
//the TeamCrewNames string array is used to hold all of the crew names 
string ScheduleWeeks[ScheduleDuration];
string TeamSchedule[TeamTableRows][TeamTableColumns];
string TeamCrewNames[CrewSize];

//the following strings below will be used to gather the information from the data file
string CrewNameInfo;
string SeasonSchedule;
string TempHolder;

//a random number generator is created, this will be used (later in the program) to generate the 
//crews schedules 
random_device CrewRandomizer;
uniform_int_distribution<int> RandomCrewNumber(minTeam, 16);


//the following functions below will be used throughout the duration of the program 
//their descriptions can be found towards the bottom of the program(along with their code)
bool repeatMatch(map<string, class NFlCrewStats>&, string, string, string);
bool canPlayTeamOne(map<string, class NFlCrewStats>&, string, string, int);
bool canPlayTeamTwo(map<string, class NFlCrewStats>&, string, string, int);
bool matchSwap(map<string, class NFlCrewStats>&, string[], string, string, string, int);

int main()
{
	int RanCrewNum = 0;
	int validNum = 0;
	char OptionCheck = 'Y';

	string FileName;
	ifstream InputFile;

	string SecondFileName;
	ofstream OutputFile;

	cout << "===================================================================================" << endl;
	cout << "IMPORTANT NOTICE" << endl << endl;
	cout << "-DO NOT USE ANY OTHER DATA FILE, BESIDES THE DATA FILE THAT WAS PROVIDED FOR THIS PROGRAM" << endl;
	cout << "-ONLY USE THE football23 DATA FILE" << endl;
	cout << "===================================================================================" << endl << endl;


	//the user is prompted to enter the name of the data file
	cout << "Enter File Name: ";
	getline(cin, FileName);

	//the data file is opened
	InputFile.open(FileName);

	//if the data file can not be found, an error message is sent and the program closes
	if (InputFile.fail())
	{
		cout << "File can not be found...\n";
		cout << "Now terminating program...\n";
		return 0;
	}
	//otherwise, the following is executed
	else
	{
		cout << "The file was found, now processing the information...\n\n";

		//the for loop is used to gather the information for the crew Names and inserts them 
		//into the NFL_Schedule_Info map
		for (int index = 0; index < CrewSize; index++)
		{
			InputFile >> CrewNameInfo;
			NFL_Schedule_Info.insert(make_pair(CrewNameInfo, NFlCrewStats(CrewNameInfo)));
			TeamCrewNames[index] = CrewNameInfo;
		}

		//the for loop is used to collect the week (numbers) from the data file
		for (int index = 0; index < ScheduleDuration; index++)
		{
			InputFile >> TempHolder;
			ScheduleWeeks[index] = TempHolder;
		}

		//the for loop is used to gather the season schedule from the data file (places it into an array)
		for (int index = 0; index < TeamTableRows; index++)
		{
			for (int index2 = 0; index2 < TeamTableColumns; index2++)
			{
				InputFile >> TempHolder;
				TeamSchedule[index][index2] = TempHolder;
			}
		}

		//the range based for loop is used to move through the elements within the NFL_Schedule_Info map
		//the for loop is used to insert the NFL teams into the map through a linked list
		for (auto& element : NFL_Schedule_Info)
		{
			for (int index = 0; index < 32; index++)
			{
				element.second.crewScheduleSeason.insertTeams(TeamSchedule[index][0]);
			}
		}

		//the data file (input file) is closes)
		InputFile.close();

		//the user is promted to enter the name of the output file
		cout << "Enter the name of the output file: ";
		getline(cin, SecondFileName);

		//the output file is open
		OutputFile.open(SecondFileName);

		//while validNum is not equal to two, the loop will continue to iterate
		while (validNum != 2)
		{

			int LoopTracker = 0;
			bool LoopTrackerReset = false;

			//the while loop is placed here to track an invalid schedule's off weeks
			//if an off week schedule can not be made, the entire schedule is rest and rebuilt 
			//from stratch, the process will continue to occur until a proper schedule has been 
			//made, that will not cause the LoopTrakcerReset value to trigger
			while (LoopTrackerReset != true)
			{
				LoopTracker = 0;

				//the for loop is used to move through a crew's season schedule 
				for (int index = 1; index < 19; index++)
				{
					int byeCounter = 0;
					int weekCounter = 0;

					//the for loop is used to move through the NFL season schedule (each week)
					for (int index2 = 0; index2 < 32; index2++)
					{
						//if the current position of the TeamSchedule array is equal to "BYE"
						//the byecounter is incremented by one (+1)
						if (TeamSchedule[index2][index] == "BYE")
						{
							byeCounter++;
						}

						//if the byeCounter is equal to two
						//the weekCounter is incremented by one (+1) and the byeCounter is set to zero
						if (byeCounter == 2)
						{
							weekCounter++;
							byeCounter = 0;
						}
					}

					//the for loop is used to assign off games
					for (int index2 = 1 + weekCounter; index2 > 0; index2--)
					{
						bool weekCondition = false;
						LoopTracker = 0;

						//the while loop will contiue to iterate until weekCondition is true
						while (weekCondition == false)
						{
							LoopTracker++;
							int ranNum = RandomCrewNumber(CrewRandomizer);
							string ranCrew = TeamCrewNames[ranNum];

							//if the current schedule's week is the first week, then an off week
							//is automatically assigned wihtout any checks
							if (index - 1 == 0)
							{
								NFL_Schedule_Info.at(ranCrew).setSeasonSchedule("OFF", index);
								weekCondition = true;
							}

							//otherwise, the following statement is executed
							else
							{
								//if the current crew's last week is not an off week and their amount of off weeks
								//is less than two, the following statement is executed
								if (NFL_Schedule_Info.at(ranCrew).getSeasonSchedule(index - 2) != "OFF" &&
									NFL_Schedule_Info.at(ranCrew).getOffWeeks() < 2)
								{
									//if the current position of the crew's schedule is an empty week, they are assigned
									//the off week and week condition is set to true, loopTracker is also set to zero
									if (NFL_Schedule_Info.at(ranCrew).getSeasonSchedule(index - 1) == "Empty")
									{
										NFL_Schedule_Info.at(ranCrew).setSeasonSchedule("OFF", index);
										weekCondition = true;
										LoopTracker = 0;
									}
								}
							}

							//if the value of LoopTracker is greater than twenty, the all of the schedules are reset
							if (LoopTracker > 20)
							{
								//the for loop is used to set all crew schedules to empty and reset their off weeks to zero
								//index and index2 are also incremented and decremented to end the for loops above
								//and weekCondition is set to true
								for (int index3 = 1; index3 < 19; index3++)
								{
									for (auto& element : NFL_Schedule_Info)
									{
										element.second.setSeasonSchedule("Empty", index3);
										element.second.resetOffWeeks();
									}
								}
								index = index + 50;
								index2 = index2 - 50;
								weekCondition = true;
							}
						}
					}

					//if the value of the index is equal to eight-teen, then LoopTracker is set to true
					//and the while loop will end.
					if (index == 18)
					{
						LoopTrackerReset = true;
					}
				}
			}

			LoopTrackerReset = false;
			LoopTracker = 0;

			//the while loop is placed here to track an invalid schedule's games
			//if a schedule (of valid games) can not be made, the entire schedule is rest and rebuilt 
			//from stratch, the process will continue to occur until a proper schedule has been 
			//made, that will not cause the LoopTrakcerReset value to trigger
			while (LoopTrackerReset != true)
			{
				LoopTracker = 0;

				//the for loop is used to move through the weeks within the season
				for (int index = 1; index < 19; index++)
				{
					LoopTracker = 0;

					//the for loop is used to move through the games within a week
					for (int index2 = 0; index2 < 32; index2++)
					{
						LoopTracker = 0;
						bool ConditionOne = false;
						bool ConditionTwo = false;

						//the while loop will continue to iterate until ConditionOne or ConditionTwo are true
						while (ConditionOne != true && ConditionTwo != true)
						{
							LoopTracker++;

							bool tempFlag = false;
							bool tempTwoFlag = false;
							bool tempThreeFlag = false;

							string placeHolder;
							string placeHolderTwo;
							string temp;
							string match;

							//the values for a randomly selected crew are created below
							//as well as gathering the information need for a match
							int RandomNumber = RandomCrewNumber(CrewRandomizer);
							CrewNameInfo = TeamCrewNames[RandomNumber];
							temp = TeamSchedule[index2][0];
							placeHolder = TeamSchedule[index2][index];
							placeHolderTwo = placeHolder;
							placeHolderTwo = placeHolderTwo.erase(0, 1);

							//if the current position of place holder is "@", the following statement is executed
							if (placeHolder[0] == '@')
							{
								//if the current position of the Crew's schedule is "Empty" the following statment is executed
								if (NFL_Schedule_Info.at(CrewNameInfo).getSeasonSchedule(index - 1) == "Empty")
								{
									//the canPlayTeamOne function is called, passing NFL_Schedule_Info, CrewNameInfo, temp, and index as arguments
									//the canPlayTeamTwo function is called, passing NFL_Schedule_Info, CrewNameInfo, placeHolderTwo, and index as arguments
									//the repeatMatch function is called, passing NFL_Schedule_Info, CrewNameInfo, temp, and placeHolderTwo as arguments
									tempFlag = canPlayTeamOne(NFL_Schedule_Info, CrewNameInfo, temp, index);
									tempTwoFlag = canPlayTeamTwo(NFL_Schedule_Info, CrewNameInfo, placeHolderTwo, index);
									tempThreeFlag = repeatMatch(NFL_Schedule_Info, CrewNameInfo, temp, placeHolderTwo);

									//if tempFlag, tempTwoFlag, and TempThreeFlag are all true, the following statement is executed
									if (tempFlag == true && tempTwoFlag == true && tempThreeFlag)
									{
										//the crew is assigned the match, its values are incremented, and ConditonOne is set to true
										match = TeamSchedule[index2][0] + TeamSchedule[index2][index];
										NFL_Schedule_Info.at(CrewNameInfo).setSeasonSchedule(match, index);
										NFL_Schedule_Info.at(CrewNameInfo).crewScheduleSeason.insertValues(temp, placeHolderTwo, index);
										ConditionOne = true;
									}
									//otherwise, the following statement is executed
									else
									{
										//ConditionOne equals the value returned by the matchSwap function
										//the matchSwap function is called, passing NFL_Schedule_Info, CrewNameInfo, temp, placeHolderTwo, and index as arguments
										ConditionOne = matchSwap(NFL_Schedule_Info, TeamCrewNames, CrewNameInfo, temp, placeHolderTwo, index);
									}
								}
							}

							//otherwise, ConditionTwo is set to true
							else
							{
								ConditionTwo = true;
							}

							//if the value of LoopTracker is greater than 500, the following statement is executed
							if (LoopTracker > 500)
							{

								//the nested for loops are used to reset all of the crews schedules to "Empty"
								//and their values are also reset to zero, and a new schedule will be generated
								//(this implies that a new schedule must be generate as the prior one could not be 
								//completed)
								for (int index3 = 1; index3 < 19; index3++)
								{
									for (auto& element : NFL_Schedule_Info)
									{
										if (element.second.getSeasonSchedule(index3 - 1) != "OFF")
										{
											element.second.setSeasonSchedule("Empty", index3);
											element.second.crewScheduleSeason.resetValues();
										}
									}
								}

								//ConditionOne and ConditionTwo are set to true
								//index and index2 are incremented/decremented to end the for loops
								ConditionOne = true;
								ConditionTwo = true;
								index += 50;
								index2 += 50;
							}
						}
					}

					//if the value of the index is equal to eight-teen, then LoopTrackerReset is set to true
					if (index == 18)
					{
						LoopTrackerReset = true;
					}
				}
			}

			//the following code below is used to write and format the schedules out to a data file
			OutputFile << "==============================================" << endl;

			//if validNum is equal to zero, the following message is printed
			if (validNum == 0)
			{
				OutputFile << "Here is the " << validNum + 1 << "st set of Schedules" << endl;
			}
			//otherwise, this message is printed
			else
			{
				OutputFile << "Here is the " << validNum + 1 << "nd set of Schedules" << endl;
			}

			OutputFile << "==============================================" << endl << endl;

			//the nested for loop (within the range based for loop) is used to print out the 
			//schedule for a crew for the NFL season 
			for (auto& element : NFL_Schedule_Info)
			{
				OutputFile << "Schedule for : " << element.second.getCrewName() << endl;
				OutputFile << "============================" << endl;

				//the for loop is used to print the schedule of a crew
				for (int index = 0; index < 18; index++)
				{
					OutputFile << "Week " << index + 1 << " : " << element.second.getSeasonSchedule(index) << endl;
				}

				OutputFile << " " << endl;
				OutputFile << "Teams that were not played: ";

				//the following for loop is used to print any teams that a crew
				//had not played throughout the season
				for (int index = 0; index < 32; index++)
				{
					OutputFile << element.second.crewScheduleSeason.freeTeams(index);	
				}

				OutputFile << " " << endl << endl;
				OutputFile << "============================" << endl << endl;
			}

			OutputFile << "==============================================" << endl << endl;

			//the stats of each NFL team and a crews schedule are reset so the program can create another
			//set of valid schedules, this is done by the nested range based for loop within the for loop
			for (int index = 1; index < 19; index++) 
			{
				for (auto& element : NFL_Schedule_Info) 
				{
					element.second.setSeasonSchedule("Empty", index);
					element.second.crewScheduleSeason.resetValues();
					element.second.resetOffWeeks();
				}
			}

			//validNum is incremented by one (+1)
			validNum++;
		}
	}

	//the OutputFile is closed and a message is displayed to indicate 
	//that the schedules have been created and the program is closed
	OutputFile.close();
	cout << "Schedules have been generated....\n";
	cout << "Now terminating program....\n";

	return 0;
}

/*-------------------------------------------------------------------------------------------

Description:the repeatMatch function is used to inspect a match up, and check if a crew
has already played that match before, the value(boolean) returns false is the teams share the same week,
otherwise the value(boolean) returns true

-Within the parameter list, a map is being passed by reference (passedMap)
-Within the parameter list, three strings are passed (currentCrew, teamOne, and teamTwo)

--------------------------------------------------------------------------------------------*/
bool repeatMatch(map<string, class NFlCrewStats>& passedMap, string currentCrew, string teamOne, string teamTwo )
{
	bool flagOne = false;
	bool flagTwo = false;

	//if value of the first team's week is not equal to zero, then flagOne is set to true
	if (passedMap.at(currentCrew).crewScheduleSeason.returnWeekPlayed(teamOne) != 0)
	{
		flagOne = true;
	}

	//if value of the second team's week is not equal to zero, then flagTwo is set to true
	if (passedMap.at(currentCrew).crewScheduleSeason.returnWeekPlayed(teamTwo) != 0)
	{
		flagTwo = true;
	}

	//if flagOne and flagTwo are true, the following statement is executed
	if (flagOne == true && flagTwo == true)
	{
		//if the week's of the first and second team are the same, the function returns false
		if(passedMap.at(currentCrew).crewScheduleSeason.returnWeekPlayed(teamOne) ==
			passedMap.at(currentCrew).crewScheduleSeason.returnWeekPlayed(teamTwo))
		{
			return false;
		}
	}

	//if one of the flags was false, then the if statement above is skipped
	//and the function returns true.
	return true;
}

/*-------------------------------------------------------------------------------------------

Description:the canPlayTeamOne function is used to determine if a certain team can play 
for a crew's schedule, this will always check the first teams Away status, the function returns 
true is the team can play, otherwise the function returns false

-Within the parameter list, a map is being passed by reference (passedMap)
-Within the parameter list, two strings are passed (currentCrew, and teamOne)
-Within the parameter list, an integer is passed (currentWeek)

--------------------------------------------------------------------------------------------*/
bool canPlayTeamOne(map<string, class NFlCrewStats>& passedMap, string currentCrew, string teamOne, int currentWeek)
{
	bool statOne = false;
	bool statTwo = false;
	bool statThree = false;

	//if the value of the amountPlayed for teamOne is zero, then statOne is set to true
	//(this indicates that the team hasn't played yet)
	if (passedMap.at(currentCrew).crewScheduleSeason.returnAmountPlayed(teamOne) == 0)
	{
		statOne = true;
	}
	//otherwise, this statement is executed, if the value of the current week - the weekPlayed value of 
	//teamOne is greater than or equal to five, statOne is set to true
	else if (currentWeek - passedMap.at(currentCrew).crewScheduleSeason.returnWeekPlayed(teamOne) >= 5)
	{
		statOne = true;
	}

	//it the amountPlayed value of teamOne is less than two, statTwo is set to true
	if (passedMap.at(currentCrew).crewScheduleSeason.returnAmountPlayed(teamOne) < 2)
	{
		statTwo = true;
	}

	//if the value of teamOne's awayStatus is equal to one and the value of teamOne's homeStatus
	//is equal to zero, then statThree returns true (this indicates that the team can play two away games) 
	if (passedMap.at(currentCrew).crewScheduleSeason.returnAwayStatus(teamOne) == 1 &&
		passedMap.at(currentCrew).crewScheduleSeason.returnHomeStatus(teamOne) == 0)
	{
		statThree = true;
	}
	//otherwise this statement is executed, if the awayStatus of teamOne is less then one
	//statThree is set to true
	else if (passedMap.at(currentCrew).crewScheduleSeason.returnAwayStatus(teamOne) < 1)
	{
		statThree = true;
	}

	//if stateOne, statTwo, and statThree are all true
	//the function returns true (the team can play)
	if (statOne == true && statTwo == true && statThree == true)
	{
		return true;
	}

	//the function returns false if the if statement above fails (the team can not play)
	return false;
}

/*-------------------------------------------------------------------------------------------

Description:the canPlayTeamTwo function is used to determine if a certain team can play
for a crew's schedule, this will always check the second teams Home status, the function returns
true is the team can play, otherwise the function returns false

-Within the parameter list, a map is being passed by reference (passedMap)
-Within the parameter list, two strings are passed (currentCrew, and teamTwo)
-Within the parameter list, an integer is passed (currentWeek)

--------------------------------------------------------------------------------------------*/
bool canPlayTeamTwo(map<string, class NFlCrewStats>& passedMap, string currentCrew, string teamTwo, int currentWeek)
{
	bool statOne = false;
	bool statTwo = false;
	bool statThree = false;

	//if the value of the amountPlayed for teamTwo is zero, then statOne is set to true
	//(this indicates that the team hasn't played yet)
	if (passedMap.at(currentCrew).crewScheduleSeason.returnAmountPlayed(teamTwo) == 0)
	{
		statOne = true;
	}
	//otherwise, this statement is executed, if the value of the current week - the weekPlayed value of 
	//teamTwo is greater than or equal to five, statOne is set to true
	else if (currentWeek - passedMap.at(currentCrew).crewScheduleSeason.returnWeekPlayed(teamTwo) >= 5)
	{
		statOne = true;
	}

	//it the amountPlayed value of teamTwo is less than two, statTwo is set to true
	if (passedMap.at(currentCrew).crewScheduleSeason.returnAmountPlayed(teamTwo) < 2)
	{
		statTwo = true;
	}

	//if the value of teamTwo's homeStatus is less than one, statThree is set to true
	if (passedMap.at(currentCrew).crewScheduleSeason.returnHomeStatus(teamTwo) < 1)
	{
		statThree = true;
	}

	//if stateOne, statTwo, and statThree are all true
	//the function returns true (the team can play)
	if (statOne == true && statTwo == true && statThree == true)
	{
		return true;
	}

	//the function returns false if the if statement above fails (the team can not play)
	return false;
}

/*-------------------------------------------------------------------------------------------

Description: the matchSwap function is used to swap the matches of two crews
(this is used to prevent the program from looping and create schedules that will not conflict 
with each other) if the function returns true, then the matches were swapped, otherwise the function
returns false and the matches are not swapped

-Within the parameter list, a map is being passed by reference (passedMap)
-Within the parameter list, three strings are passed (currentCrew, teamOne, and teamTwo)
-Within the parameter list, an integer is passed (currentWeek)

--------------------------------------------------------------------------------------------*/
bool matchSwap(map<string, class NFlCrewStats>& passedMap, string crewArray[], string currentCrew, string teamOne, string teamTwo, int currentWeek)
{
	string assignCrew;
	
	int ranCrewNum = RandomCrewNumber(CrewRandomizer);

	//a crew is randomly called from the crewArray is called 
	//and assigCrew is set to the value within the crewArray
	assignCrew = crewArray[ranCrewNum];

	//if the schedule of the crew called (using the map) is not equal to "Empty" or "OFF"
	//the following statement is executed 
	if (passedMap.at(assignCrew).getSeasonSchedule(currentWeek - 1) != "Empty"
		&& passedMap.at(assignCrew).getSeasonSchedule(currentWeek - 1) != "OFF")
	{
		bool teamFlagOne = false;
		bool teamFlagTwo = false;
		bool teamFlagThree = false;
		
		bool tempFlagOne = false;
		bool tempFlagTwo = false;
		bool tempFlagThree = false;

		bool canPlayOne = false;
		bool canPlayTwo = false;

		string passedTeamOne;
		string passedTeamTwo;

		//the passedCrewGame is assigned the value of the assignCrew schedule 
		string passedCrewGame = passedMap.at(assignCrew).getSeasonSchedule(currentWeek - 1);

		bool difference = false;

		//this for loop is used to seperate the passedCrewGame string to retrieve the 
		//two teams that will be playing for that week
		for (int index = 0; index < passedCrewGame.length(); index++)
		{
			//if the current character of the passedCrewGame is a punctation character "@"
			//then difference is set to true
			if (ispunct(passedCrewGame[index]))
			{
				difference = true;
			}
			//otherwise, while difference is false, passedTeamOne will equal the first 
			//team being played (in the passedCrewGame string) plus itself 
			else if (difference == false)
			{
				passedTeamOne += passedCrewGame[index];
			}
			//otherwise, once difference is true, passedTeamTwo will equal the second 
			//team being played (in the passedCrewGame string) plus itself 
			else
			{
				passedTeamTwo += passedCrewGame[index];
			}
		}

		//the canPlayTeamOne function is called, passing the passedMap, currentCrew, passedTeamOne, and currentWeek as arguements
		//the canPlayTeamTwo function is called, passing the passedMap, currentCrew, passedTeamTwo, and currentWeek as arguements
		//the repeatMatch function is called, passing the passedMap, currentCrew, passedTeamOne, and passedTeamTwo as arguements
		teamFlagOne = canPlayTeamOne(passedMap, currentCrew, passedTeamOne, currentWeek);
		teamFlagTwo = canPlayTeamTwo(passedMap, currentCrew, passedTeamTwo, currentWeek);
		teamFlagThree = repeatMatch(passedMap, currentCrew, passedTeamOne, passedTeamTwo);

		//the canPlayTeamOne function is called, passing the passedMap, assignCrew, teamOne, and currentWeek as arguements
		//the canPlayTeamTwo function is called, passing the passedMap, assignCrew, teamTwo, and currentWeek as arguements
		//the repeatMatch function is called, passing the passedMap, assignCrew, teamOne, and teamTwo as arguements
		tempFlagOne = canPlayTeamOne(passedMap, assignCrew, teamOne, currentWeek);
		tempFlagTwo = canPlayTeamTwo(passedMap, assignCrew, teamTwo, currentWeek);
		tempFlagThree = repeatMatch(passedMap, assignCrew, teamOne, teamTwo);

		//if teamFlagOne, teamFlagTwo, and teamFlagThree are true
		//then canPlayOne is set to true
		if (teamFlagOne == true && teamFlagTwo == true && teamFlagThree == true)
		{
			canPlayOne = true;
		}

		//if tempFlagOne, tempFlagTwo, and tempFlagThree are true
		//then canPlayTwo is set to true
		if (tempFlagOne == true && tempFlagTwo == true && tempFlagThree == true)
		{
			canPlayTwo = true;
		}

		//if canPlayOne and canPlayTwo are true, the the following statement is executed 
		//(the teams swap their matches)
		if (canPlayOne == true && canPlayTwo == true)
		{
			//the values of passedTeamOne and passedTeamTwo are removed (update for the matches being swapped)
			passedMap.at(assignCrew).crewScheduleSeason.removeValues(passedTeamOne, passedTeamTwo);

			//the currentCrew is given the match that was played by assignCrew
			//and the values of passedTeamOne and passedTeamTwo are updated
			passedMap.at(currentCrew).setSeasonSchedule(passedCrewGame, currentWeek);
			passedMap.at(currentCrew).crewScheduleSeason.insertValues(passedTeamOne, passedTeamTwo, currentWeek);

			string tempMatch = teamOne + '@' + teamTwo;

			//the assignCrew is given the match that was played by currentCrew
			//and the values of teamOne and teamTwo are updated
			passedMap.at(assignCrew).setSeasonSchedule(tempMatch, currentWeek);
			passedMap.at(assignCrew).crewScheduleSeason.insertValues(teamOne, teamTwo, currentWeek);

			//the function returns true (a swap has occured)
			return true;
		}
	}

	//the function returns false if a swap does not occur
	return false;
}