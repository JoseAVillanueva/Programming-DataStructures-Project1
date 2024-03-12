//Name: Jose Villanueva Vigil
//Course: COSC 2436
//Program set 2, problem 2 (PrintQueue)
//References: I used the PDF covering program set 2
//=================================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//this is a Dyanic Queue Class that will be utilized throughout the duration of the program  
//it will hold the position of a number within the queue and its priority 
class PrinterQueue
{
private:

	//This is a List Node named QueueNode that will be used to store and retrieve 
	//the values within the queue
	struct QueueNode
	{
		int PriorityLevel;
		int QueuePosition;
		QueueNode* next;
	};

	//two pointers with the data type of QueueNode are defined here, front points to the 
	//front of the queue while the rear points to the end of the queue 
	//numItmes tracks the number of items within the queue
	QueueNode* front;
	QueueNode* rear;
	int numItems;

public:
	//these are out-of-line member functions that will be used for the PrinterQueue class
	//futher elaboration of these functions can be found below this class
	PrinterQueue();
	~PrinterQueue();
	void enqueue(int, int);
	void dequeue(int&, int&);
	bool isEmpty() const;
	void clear();
	bool queueScan(int&, int&);
};

//the out-of-line PrinterQueue constructor is used to initalize the variables that will
//be used to form the queue
PrinterQueue::PrinterQueue()
{
	//front and rear are set to nullptr (there is nothing to point to in the queue)
	//numitems is set to 0 (no items are in the queue)
	front = nullptr;
	rear = nullptr;
	numItems = 0;
}

//the out-of-line PrinterQueue deconstructor is used to delete and free the dynamically allocated
//memory used to create the queue 
PrinterQueue::~PrinterQueue()
{
	//the clear function is called
	clear();
}

//the out-of-line PrinterQueue enqueue member function is used to add a new element into the queue 
//within the parameter list, two integers are being passed (level and position)
void PrinterQueue::enqueue(int level, int position)
{
	//a new pointer with the Data type of QueueNode is created here
	//and is initalied to nullptr
	QueueNode* newNode = nullptr;

	//memory is allocated to create a new instance of the QueueNode structure 
	//and the values of newNode are initalized using the arguments passed through the 
	//parameter list.
	newNode = new QueueNode;
	newNode->PriorityLevel = level;
	newNode->QueuePosition = position;
	newNode->next = nullptr;

	//The queue calls the "isEmpty()" function, if the statement is true,
	//the following statement is executed 
	if (isEmpty())
	{
		//the newNode is inserted at the beginning of the list
		front = newNode;
		rear = newNode;
	}

	//otherwise this statement is excuted
	else
	{
		//the newNode is inserted at the end of the queue
		rear->next = newNode;
		rear = newNode;
	}

	//numItems is incremented by (1)
	numItems++;
}

//the out-of-line PrinterQueue dequeue member function is used to remove an element from the queue 
//within the parameter list, two integers are being passed by reference (level and position)
void PrinterQueue::dequeue(int& level, int& position)
{
	//a pointer with the Data type of QueueNode is created here 
	//and initalized to nullptr
	QueueNode* temp = nullptr;

	//The queue calls the "isEmpty()" function, if the statement is true,
	//the following statement is executed (indicates that the queue is empty)
	if (isEmpty())
	{
		cout << "The queue is empty.\n";
	}

	//otherwise this statement is excuted
	else
	{
		//level and position take the values of the node in the front of the queue
		//temp is set to equal front
		//front is set do the next node in the queue
		//temp is then deleted 
		//numItems is then incremented by (-1)
		level = front->PriorityLevel;
		position = front->QueuePosition;
		temp = front;
		front = front->next;
		delete temp;
		numItems--;
	}
}

//the out-of-line PrinterQueue isEmpty member function is used to determine if a queue is empty
//and returns a bool
bool PrinterQueue::isEmpty() const
{
	//a new bool variable is created here
	bool status;

	//if the numItems variable is greater than zero, this statement is executed 
	if (numItems > 0)
	{
		//status is set to false (stack is not empty)
		status = false;
	}

	//otherwise this statement is executed 
	else
	{
		//status is set to true (stack is empty)
		status = true;
	}

	//status is returned 
	return status;
}

//the out-of-line PrinterQueue clear member function is used to dequeue all of the elements witin the queue
void PrinterQueue::clear()
{
	//two integers are defined here
	int level;
	int pos;

	//the while loop will continue to iterate while 
	//the isEmpty returns true (while the queue is not empty)
	while (!isEmpty())
	{
		//the dequeue function is called and passes level and pos 
		//as arguements 
		dequeue(level, pos);
	}
}

//the out-of-line PrinterQueue queueScan member function is used to look for any elements 
//that have a greater priority than first element in the queue and reposition the elements within the 
//queue is an element with a greater priority is found 
//within the parameter list, two integers are being passed by reference (lvl and pos)
bool PrinterQueue::queueScan(int& lvl, int& pos)
{
	//a pointer with the data type of QueueNode is created and 
	//is initalized with nullptr
	QueueNode* nodePtr = nullptr;

	int valueOne = 0, valueTwo = 0;

	//nodePtr points to the front of the queue
	nodePtr = front;

	//a do-while loop is used to move nodePtr through the queue
	do
	{
		//nodePtr is set to the next element in the Queue
		nodePtr = nodePtr->next;
	} while (nodePtr != nullptr && front->PriorityLevel >= nodePtr->PriorityLevel);
	//the loop will continue to iterate while nodePtr is not nullptr and priority level of the first
	//element in the queue is greater than or equal to the current element being pointed to by nodePtr

	//if the value of nodePtr is nullptr, this statement is executed 
	if (nodePtr == nullptr)
	{
		//the dequeue function is called, passing lvl and pos as arguements 
		//and the queueScan function returns true (prints the element in the queue)
		dequeue(lvl, pos);
		return true;
	}

	//otherwise this statement is executed
	else
	{
		//the dequeue function is called, passing valueOne and valueTwo as arguements
		//the enqueue function is called, passing valueOne and valueTwo as arguements 
		//This is used to move the first element of the queue to the end of the queue
		dequeue(valueOne, valueTwo);
		enqueue(valueOne, valueTwo);

		//this is here to offset pos since the original value is (0 in the main body of the program)
		//which causes any queues that request for a value of (0) to automatically complete without
		//checking the remaining elements in the queue for elements that have a higher priority.
		pos = -1;
		
		//scanQueue returns false (nothing was printed)
		return false;
	}
	return false;
}

int main()
{
	char CaseChecker = 'Y';

	//a new instance of the PrinterQueue class is created here
	PrinterQueue printerStatus;

	string FileName;
	ifstream InputFile;

	//a pointer with the data type of an integer is created here and is set to nullptr
	int* printerQueue = nullptr;

	//while the value of CaseChecker is not 'N', the loop will continue to iterate 
	while (CaseChecker != 'N')
	{
		cout << "Enter file name: ";
		cin >> FileName;
		cout << " " << endl;

		//the file entered by the user is opened here
		InputFile.open(FileName);

		//if the file is failed to open, the statement is executed
		//displaying an error
		if (InputFile.fail())
		{
			cout << "An error has Occured while opening the file\n";
		}
		//otherwise this statement is executed 
		else
		{
			//a list of integers is created to hold the data within the file
			int NumOfCases = 0;
			int NumOfJobs = 0;
			int JobPosition = 0;
			int jobs = 0;

			//the number of cases is retrieved 
			InputFile >> NumOfCases;

			//the for loop will continue to iterate while i is less than the NumOfCases
			//this will run through all of the printer queues
			for (int i = 0; i < NumOfCases; i++)
			{
				//a list of integers is created to keep track of a jobs position within the queue
				//and the amount of time that will be spent to print an element (minutes)
				int minutes = 0;
				int JobPos = 0;
				int JobLevel = 0, JobQueuePos = 0;

				bool queueFlag = false;

				//the NumOfJobs within the queue is retrieved and 
				//the desired element (with the desired position) is retrieved (JobPosition)
				InputFile >> NumOfJobs;
				InputFile >> JobPosition;
				
				printerQueue = new int[NumOfJobs];

				//this for loop gathers the information for the PrinterQueue
				for (int index = 0; index < NumOfJobs; index++)
				{
					//the element from the queue is retreived here
					InputFile >> printerQueue[index];
					
					//the enqueue function is called, passing PrinterQueue[index] and JobPos as arguemnts
					printerStatus.enqueue(printerQueue[index], JobPos);
					JobPos++;
					//JobPos is incremneted by (1)
				}

				//the do-while loop will continue to iterate while JobQueuePos is not equal to JobPosition
				//this indicates that the desired element within the queue has been found
				do
				{
					//queueFlag is set to equal the return value of thr queueScan function
					//the queueScan function is called and JobLevel and JobQueuePos are passed
					//as arguements
					queueFlag = printerStatus.queueScan(JobLevel, JobQueuePos);
					
					//if the value of queueFlag is true, the following statement is executed 
					if (queueFlag == true)
					{
						//minutes is incremented by(1)
						minutes++;
					}

				} while (JobQueuePos != JobPosition);

				//jobs is incremeted by (1)
				jobs++;

				//the following if statements are used to format the minute(s) output
				cout << "Job " << jobs << ": ";

				//if minutes is greater than one, the following statment is executed
				if (minutes > 1)
				{
					//prints minutes
					cout << minutes << " minutes" << endl;
				}
				//otherwise the following statement is executed 
				else
				{
					//prints minute
					cout << minutes << " minute" << endl;
				}

				//miutes is set to 0 
				//and the memory used to create the printerQueue array is deallocated 
				//printerQueue is also set to nullptr 
				//the clear function is called to empty the queue
				minutes = 0;
				delete[] printerQueue;
				printerQueue = nullptr;
				printerStatus.clear();
			}
		}

		cout << endl;
		cout << "Run again (Y/N): ";
		cin >> CaseChecker;
		CaseChecker = toupper(CaseChecker);
		cout << endl;

		//the while loop will continue to iterate while an invalid option is being made
		while (CaseChecker != 'Y' && CaseChecker != 'N')
		{
			cout << "An invalid input was made, please try again\n";
			cout << "Run again (Y/N): ";
			cin >> CaseChecker;
			CaseChecker = toupper(CaseChecker);
			cout << endl;
		}

		//the file is closed
		InputFile.close();
	}
	return 0;
}