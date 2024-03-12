//Name: Jose Villanueva Vigil
//Course: COSC 2436
//Program set 2, problem 1 (PostInfix)
//References: I used the PDF covering program set 2
//=================================================================================

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//this is a Dyanic Stack Class that will be utilized throughout the duration of the program  
//it will hold the variables and symbols used for a given expression 
class DynStrStack
{
private:

	//this is a ListNode structure named StackNode
	//letter holds a given expressions variables and the next pointer is used
	//to create a series of nodes (to create a list of nodes)
	struct StackNode
	{
		string letter;
		StackNode* next = nullptr;
	};

	//this is a stackNode pointer named top that will point to the top of the stack
	StackNode* top;

public:

	//these are out-of-line member functions that will be used for the DynStrStack class
	//futher elaboration of these functions can be found below this class

	//when an instance of the DynStrStack class is created, its default constructor is called and
	//sets the top pointer to nullptr
	DynStrStack() 
	{
		top = nullptr;
	}
	~DynStrStack();
	void push(string);
	void pop(string&);
	bool isEmpty();
};

//the out-of-line DynStrStack deconstructor is used to delete and free the dynamically allocated
//memory used to create the stack 
DynStrStack::~DynStrStack()
{
	//two pointers with the DataType of StackNode are created and are set to nullptr
	StackNode* nodePtr = nullptr;
	StackNode* nextNode = nullptr;

	//nodePtr is set to the top of the stack
	nodePtr = top;

	//while noePtr is not nullptr it will traverse the stack and delete the nodes
	while (nodePtr != nullptr)
	{
		//nextNode points to the address of the next node pointed to by nodePtr
		//the current node within nodePtr is deleted, and then nodePtr is set to the nextNode
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

//the out-of-line DynStrStack push member function is used to insert a new node into the stack 
//within the parameter list, a string is being passed (let)
void DynStrStack::push(string let)
{
	//a new pointer with the data type of StackNode is created and is set to nullptr
	StackNode* newNode = nullptr;

	//memory is dynamically allocated to create a new instance of the StackNode structure using the 
	//newNode, and its letter variable holds the letter(let) that was passed in the parameter list
	newNode = new StackNode;
	newNode->letter = let;

	//if the top pointer is nullptr, the following statement is executed 
	if (!top)
	{
		//top equals the address of the newNode
		//and the next pointer within the newNode is set to nullptr
		top = newNode;
		newNode->next = nullptr;
	}
	//else if, this statement is executed 
	else
	{
		//the address of the newNode points to the top of the stack
		//and top points to the address of the newNode
		newNode->next = top;
		top = newNode;
	}
}

//the out-of-line DynStrStack pop member function is used to remove a node from the stack
//within the parameter list, a string is being passed by reference (let)
void DynStrStack::pop(string &let)
{
	//a new pointer with the data type of StackNode is created and is set to nullptr
	StackNode* temp = nullptr;

	//if the isEmpty function returns true, then the following statement is executed 
	if (isEmpty())
	{
		//a message is printed, stating that the stack is empty
		cout << "The stack is empty.\n";
	}
	//otherwise, the following statement is executed 
	else
	{
		//let will hold the current string within the top node
		//temp will be set to equal the address being pointed to by the next pointer
		//top is deleted and then top is set to equal temp
		let = top->letter;
		temp = top->next;
		delete top;
		top = temp;
	}
}

//the out-of-line DynStrStack isEmpty member function is used to check if a stack is empty
//and returns a bool expression
bool DynStrStack::isEmpty()
{
	//a bool value is created 
	bool status;

	//if the top of the stack equals nullptr, then the following statement is executed 
	if (!top)
	{
		//status is set to true
		status = true;
	}
	//otherwise, the following statement is executed 
	else
	{
		//status is set to false
		status = false;
	}

	//status is returned.
	return status;
}

//these are the functions that will be utilized throughout the duration of the program
//their descriptions can be found towards the bottom of the program 
void FormatEq(DynStrStack&);
void AssignValue(string &, int &);

int main()
{
	//a new instance of the DynStrStack class is created
	DynStrStack InFixList;

	string UserInput;
	string ExpressionString;
	char CaseChecker = 'Y';
	
	//while the CaseChecker character is not 'N', the while loop will continue to iterate 
	while (CaseChecker != 'N')
	{
		int counter = 0;

		//the getline function is used to gather the UserInput
		cout << "Enter postfix expression: ";
		getline(cin, UserInput);
		cout << " " << endl;

		//the for loop is used to push character into the stack (InFixList)
		//and format the expression within the stack
		for (int index = 0; index < UserInput.length(); index++)
		{
			//if the current position of the UserInput is not a space, the following
			//statement is executed 
			if (!isspace(UserInput[index]))
			{
				//the current position of the UserInput string is converted into a string using
				//the string function and is pushed into the stack
				InFixList.push((string(1,toupper(UserInput[index]))));
			}

			//if the current position of the UserInput is a punctuation character
			//the following statement is executed 
			if (ispunct(UserInput[index]))
			{
				//the FormatEq function is called and the InFixList object is passed as 
				//an arguement 
				FormatEq(InFixList);
			}
		}

		cout << "Infix: ";

		//the pop function is called, passing DummyCharacter as an arguement 
		InFixList.pop(ExpressionString);

		//the for loop is used to print the new expression held within the ExpressionString
		for (int index = 0; index < ExpressionString.length(); index++)
		{
			//the first characetr of the ExpressionString is printed
			//and counter is set to equal the (index + 1)
			cout << ExpressionString[index];
			counter = index + 1;

			//if the current position of the ExpressionString hold the ( " ( " ) character 
			//the following statement is executed 
			if (ExpressionString[index] == '(')
			{
				//the space is skipped 
			}
			//else if the current position of the ExpressionString hold the ( " ) " ) character 
			//the following statement is executed 
			else if (ExpressionString[counter] == ')')
			{
				//the index is incremented by (1)
				//the new position of the string (using index) is printed
				//along with a space 
				index++;
				cout << ExpressionString[index] << " ";
			}
			//otherwise, the following statement is executed 
			else
			{
				//a space is printed
				cout << " ";
			}
		}
		cout << " " << endl << endl;

		//the CaseChecker input is collected here and is converted into an uppercase character
		cout << "Run Again (Y/N): ";
		cin >> CaseChecker;
		CaseChecker = toupper(CaseChecker);

		//if an invalid input was made, the while loop will continue to iterate until a correct
		//input is made
		while (CaseChecker != 'Y' && CaseChecker != 'N')
		{
			cout << "An invalid input was made, please try again." << endl;
			cout << "Run Again (Y/N): ";
			cin >> CaseChecker;
			CaseChecker = toupper(CaseChecker);
		}	
		cout << " " << endl;
		
		//the cin.ignore function is used to ingore the previous input (made by the CaseChecker)
		//so the user can enter a new expression 
		cin.ignore(1, '\n');
	}
	return 0;
}

/*-------------------------------------------------------------------------------------------

Description:The FormatEq function is used to turn a given expression from its PostFix version to 
its Infixed version.

-Within the parameter list, a class object with the data type of DynStrStack
is being passed by reference(stack)

--------------------------------------------------------------------------------------------*/

void FormatEq(DynStrStack& stack)
{
	//the frist and second string variables are used to hold the 
	//alphabetical characters within the expression while the firstSymbol
	//and mainSymbol will hold the arithmetic characters found within the expression

	string first;
	string second;
	string firstSymbol;
	string mainSymbol;

	//SymValue and FirstValue will hold the value of the arithmetic characters 
	//and location will hold the location of where the firstSymbol was found 
	int SymValue = 0;
	int FirstValue = 0;
	int location = 0;

	//the full string is used to hold a fully formatted expression (the end result)
	string full;

	//the top three values from the stack are popped off
	stack.pop(mainSymbol);
	stack.pop(second);
	stack.pop(first);

	//if the length of the first string is greater than or equal to three, then the if statement is executed
	if (first.length() >= 3)
	{

		//the for loop is used to search for an arithmetic character within the first string 
		for (int index = 0; index < first.length(); index++)
		{
			//if an arithmetic character is found then the if statement is executed 
			if (ispunct(first[index]))
			{
				//firstSymbol holds the current arithmetic character within the current
				//position of the first string and location saves the location the arithmetic
				//character was found in 
				firstSymbol = first[index];
				location = index;
			}
		}

		//the AssignValue function is called 
		//firstSymbol, FirstValue, mainSymbol, and SymValue 
		//are passed as arguements 
		AssignValue(firstSymbol, FirstValue);
		AssignValue(mainSymbol, SymValue);

		//if the value of FirstValue is less than SymValue
		//then the if statment is executed 
		if (FirstValue < SymValue)
		{
			//a(n) ( " ) " ) character is added to the end of the first string
			//location is decremenetd by (-1) and a ( " ( " ) is inserted at the 
			//new location within the first string 
			first = first + ")";
			location--;
			first = first.insert(location, "(");
		}
	}

	//full is the combined strings of first, mainSymbol, and second (the new expression)
	full = first + mainSymbol + second;

	//the full string is pushed into the stack
	stack.push(full);
}

/*-------------------------------------------------------------------------------------------

Description:The AssignValue function is used to assign the value of an arithmetic character within
an expression, this will be used to determine if an arithmetic character has a higher or lower 
priority within an expression (P.E.M.D.A.S)

-Within the parameter list, a string is being passed by reference (opp)
-Within the parameter list, an integer is being passed by reference (value)

--------------------------------------------------------------------------------------------*/

void AssignValue(string& opp, int& value)
{

	//if opp == ( or opp == ) then the value variable is set to 5
	if (opp == "(" || opp == ")")
	{
		value = 5;
	}
	//else if opp == ^ then the value variable is set to 4
	else if (opp == "^")
	{
		value = 4;
	}
	//else if opp == * then the value variable is set to 3
	else if (opp == "*")
	{
		value = 3;
	}
	//else if opp == / then the value variable is set to 2
	else if (opp == "/")
	{
		value = 2;
	}
	//else if opp == + then the value variable is set to 1
	else if (opp == "+")
	{
		value = 1;
	}
	//else if opp == - then the value variable is set to 0
	else if (opp == "-")
	{
		value = 0;
	}
}