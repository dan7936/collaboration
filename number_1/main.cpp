#include <iostream>
#include <string>

void Task1();
int setSizeOfDatabase();
char userChoosing();
int getUserInput();

/*
* =================================================================
* -----------------------------Classes-----------------------------
* =================================================================
*/
class Person // Parent class for TASK 1
{
public:
	void setName()
	{
		m_name = getName();
	}
	void setAge()
	{
		m_age = getAge();
	}
	void setWeight()
	{
		m_weight = getWeight();
	}
protected:
	std::string m_name{};
	int m_age{};
	int m_weight{};
private:
	std::string getName() //user input for name
	{
		std::cout << "Pls enter Person's name: ";
		std::string personName{};
		int i_buffErazer{ 32750 };
		bool cinFlag{};
		while (!cinFlag)
		{
			cinFlag = true;
			std::getline(std::cin, personName);
			if (std::cin.fail())
			{
				cinFlag = false;
				std::cin.clear();
				std::cin.ignore(i_buffErazer, '\n');
				std::cout << "Error! Pls try again." << std::endl;
			}
		}
		return personName;
	}

	int getAge() //user input for age
	{
		std::cout << "Pls enter Person's age: ";
		int personAge = getUserInput();
		return personAge;
	}

	int getWeight() //user input for weight
	{
		std::cout << "Pls enter Person's weight: ";
		int personWeight = getUserInput();
		return personWeight;
	}
};

class Student : public Person // Heritage class for TASK 1
{
public:
	void setYearOfStudy()
	{
		m_yearOfStudy = getYearOfStudy();
		m_studentIndex++;
		m_studentNumber = m_studentIndex;
		m_graduationCounting++;
	}
	void incrYearOfStudy()
	{
		m_graduationCounting++;
		if (m_graduationCounting > e_yearsOfStudy)
		{
			std::cout << "Congratulations this student graduated our university at last!" << std::endl;
		}
		else
		{
			m_yearOfStudy++;
			m_age++;
		}
	}
	void printStudentInfo()
	{
		std::cout << "This student's number is " << m_studentNumber << std::endl;
		std::cout << "His info:" << std::endl;
		std::cout << " - name: " << m_name << std::endl;
		std::cout << " - age: " << m_age << std::endl;
		std::cout << " - weight: " << m_weight << std::endl;
		std::cout << " - year of study: " << m_yearOfStudy << std::endl;
		std::cout << " - student number: " << m_studentNumber << std::endl;
	}
	void getInfo()
	{
		setName();
		setAge();
		setWeight();
		setYearOfStudy();
	}
protected:
	int m_studentIndex{};
	int m_yearOfStudy{};
	int m_studentNumber{};
	int m_graduationCounting{};
	enum EducationMatters // mark of education's length
	{
		e_yearsOfStudy = 4
	};

private:
	int getYearOfStudy() //user input for student starting year of education
	{
		std::cout << "Pls enter Student's starting year of education: ";
		int studentStartingYear = getUserInput();
		return studentStartingYear;
	}
};

/*
* =================================================================
* ---------------------------!!!Main!!!----------------------------
* =================================================================
*/
int main()
{
	Task1();
	return 0;
}

/*
* =================================================================
* ----------------------------Functions----------------------------
* =================================================================
*/

void Task1() // primal function for TASK 1
{
	int sizeOfDatabase = setSizeOfDatabase();
	Student* p_studentDatabase = new Student[sizeOfDatabase];
	char c_userChoise{};
	int databaseIndex{};
	bool databaseClosing{};
	while (!databaseClosing)
	{
		std::cout << "Do you want to input a new student in database? y/n: ";
		c_userChoise = userChoosing();
		if (databaseIndex > sizeOfDatabase)
		{
			std::cout << "Sorry the database is full!" << std::endl;
		}
		else if (c_userChoise == 'y')
		{
			p_studentDatabase[databaseIndex].getInfo();
			databaseIndex++;
		}
		else
		{
			std::cout << "Do you want to increment existing student's year of study? y/n: ";
			c_userChoise = userChoosing();
			if (c_userChoise == 'y')
			{
				std::cout << "Pls choose a student's number who's year of study you want to increment: ";
				int databaseNavig = getUserInput();
				if (databaseNavig > databaseIndex)
				{
					std::cout << "Sorry, we don't have so much students in our database!" << std::endl;
				}
				else
				{
					databaseNavig--;
					p_studentDatabase[databaseNavig].incrYearOfStudy();
				}
			}
			else
			{
				std::cout << "Right now we have a " << databaseIndex << " students in our database!" << std::endl;
				std::cout << "Do you want to see info about your students? y/n: ";
				c_userChoise = userChoosing();
				if (c_userChoise == 'y')
				{
					std::cout << "Pls choose a student's number who's info you want to read: ";
					int databaseNavig = getUserInput();
					if (databaseNavig > databaseIndex)
					{
						std::cout << "Sorry, we don't have so much students in our database!" << std::endl;
					}
					else
					{
						databaseNavig--;
						p_studentDatabase[databaseNavig].printStudentInfo();
					}
				}
				else
				{
					std::cout << "Do you want to stop working with database? y/n: ";
					c_userChoise = userChoosing();
					if (c_userChoise == 'y')
					{
						databaseClosing = true;
					}
					else
					{
						databaseClosing = false;
					}
				}
			}
		}
	}
	delete[] p_studentDatabase;
}

int setSizeOfDatabase() // function for seting size of database in TASK 1
{
	std::cout << "Let's create our student database." << std::endl;
	std::cout << "Pls, enter the size of our database: ";
	int sizeOfDatabase = getUserInput();
	return sizeOfDatabase;
}

int getUserInput() // function for geting user input
{
	int i_buffErazer{ 32750 };
	int RealityCheck{ 1 };
	int userInput{};
	bool cinFlag{};
	while (!cinFlag)
	{
		cinFlag = true;
		std::cin >> userInput;
		std::cin.ignore(i_buffErazer, '\n');
		if (std::cin.fail() || userInput < RealityCheck)
		{
			cinFlag = false;
			std::cin.clear();
			std::cout << "Error! Pls try again." << std::endl;
		}
	}
	return userInput;
}

char userChoosing() // function for geting user input on continue or not
{
	char c_choise{};
	bool cinFlag{};
	int i_buffErazer{ 32750 };
	while (!cinFlag)
	{
		cinFlag = true;
		std::cin >> c_choise;
		if (std::cin.fail() || c_choise != 'y' && c_choise != 'n')
		{
			cinFlag = false;
			std::cin.clear();
			std::cin.ignore(i_buffErazer, '\n');
			std::cout << "Error! Pls try again." << std::endl;
		}
	}
	std::cin.ignore(i_buffErazer, '\n');
	return c_choise;
}