#include <iostream>
#include <string>

/*
* =================================================================
* ----------------------------Variables----------------------------
* =================================================================
*/
enum CinCondition
{
	e_buffErazer = 32750,
	e_cinOkey = 1,
	e_cinFail = 0
};

enum EducationMatters
{
	e_yearsOfStudy = 4
};

/*
* =================================================================
* ----------------------Functions prototypes-----------------------
* =================================================================
*/
std::string getName(); //user input for name
int getAge(); //user input for age
int getWeight(); //user input for weight
int getYearOfStudy(); //user input for student starting year of education

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
		std::cout << "This student's numbet is " << m_studentNumber << std::endl;
		std::cout << "His info:" << std::endl;
		std::cout << " - name: " << m_name << std::endl;
		std::cout << " - age: " << m_age << std::endl;
		std::cout << " - weight: " << m_weight << std::endl;
		std::cout << " - year of study: " << m_yearOfStudy << std::endl;
		std::cout << " - student number: " << m_studentNumber << std::endl;
	}
protected:
	int m_studentIndex{};
	int m_yearOfStudy{};
	int m_studentNumber{};
	int m_graduationCounting{};
};

/*
* =================================================================
* ---------------------------!!!Main!!!----------------------------
* =================================================================
*/
int main()
{
	Student studentOne;
	studentOne.setName();
	studentOne.setAge();
	studentOne.setWeight();
	studentOne.setYearOfStudy();
	studentOne.printStudentInfo();
	studentOne.incrYearOfStudy();
	studentOne.printStudentInfo();
	return 0;
}

/*
* =================================================================
* ----------------------------Functions----------------------------
* =================================================================
*/
std::string getName()
{
	std::string personName{};
	bool cinFlag{};
	while (!cinFlag)
	{
		cinFlag = e_cinOkey;
		std::cout << "Pls enter Person's name: ";
		std::getline(std::cin, personName);
		if (std::cin.fail())
		{
			cinFlag = e_cinFail;
			std::cin.clear();
			std::cin.ignore(e_buffErazer, '\n');
			std::cout << "Error! Pls try again." << std::endl;
		}
	}
	return personName;
}

int getAge()
{
	int personAge{};
	bool cinFlag{};
	while (!cinFlag)
	{
		cinFlag = e_cinOkey;
		std::cout << "Pls enter Person's age: ";
		std::cin >> personAge;
		std::cin.ignore(e_buffErazer, '\n');
		if (std::cin.fail())
		{
			cinFlag = e_cinFail;
			std::cin.clear();
			std::cin.ignore(e_buffErazer, '\n');
			std::cout << "Error! Pls try again." << std::endl;
		}
	}
	return personAge;
}

int getWeight()
{
	int personWeight{};
	bool cinFlag{};
	while (!cinFlag)
	{
		cinFlag = e_cinOkey;
		std::cout << "Pls enter Person's weight: ";
		std::cin >> personWeight;
		std::cin.ignore(e_buffErazer, '\n');
		if (std::cin.fail())
		{
			cinFlag = e_cinFail;
			std::cin.clear();
			std::cin.ignore(e_buffErazer, '\n');
			std::cout << "Error! Pls try again." << std::endl;
		}
	}
	return personWeight;
}

int getYearOfStudy()
{
	int studentStartingYear{};
	bool cinFlag{};
	while (!cinFlag)
	{
		cinFlag = e_cinOkey;
		std::cout << "Pls enter Student's starting year of education: ";
		std::cin >> studentStartingYear;
		std::cin.ignore(e_buffErazer, '\n');
		if (std::cin.fail())
		{
			cinFlag = e_cinFail;
			std::cin.clear();
			std::cin.ignore(e_buffErazer, '\n');
			std::cout << "Error! Pls try again." << std::endl;
		}
	}
	return studentStartingYear;
}