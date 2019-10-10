#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include <iomanip>

void heading();
int getLabData();
int getAssignmentData();
int getQuizData();
int getTestData();
char computeLabGrade(int);
char computeAssignmentGrade(int);
char computeQuizGrade(int);
char computeTestGrade(int);
float gradeToFloat(char);
char computeTotalGrade(float, float, float, float);
ifstream myFile;
int main()
{
  heading();
  myFile.open("infile.txt");
    for (int studentNum = 1; studentNum <=6; studentNum++)
    {
    int labSum = getLabData();
    int assignmentSum = getAssignmentData();
    int quizSum = getQuizData();
    int testSum = getTestData();
    
    char labGrade = computeLabGrade(labSum);
    char assignmentGrade = computeAssignmentGrade(assignmentSum);
    char quizGrade = computeQuizGrade(quizSum);
    char testGrade = computeTestGrade(testSum);

    float labFloat = gradeToFloat(labGrade);
    float assignmentFloat = gradeToFloat(assignmentGrade);
    float quizFloat = gradeToFloat(quizGrade);
    float testFloat = gradeToFloat(testGrade);

    char finalGrade = computeTotalGrade(labFloat, assignmentFloat, quizFloat, testFloat);

        cout << "Student " << studentNum << endl;
        cout << "Student's lab grade is: " << labGrade << endl;
    cout << "Student's assignment grade is: " << assignmentGrade << endl;
        cout << "Student's quiz grade is: " << quizGrade << endl;
        cout << "Student's test grade is: " << testGrade << endl;
        cout << "Student's final grade is: " << finalGrade << endl;
        cout << endl;
    }
    myFile.close();
    return 0;
}

int getLabData()
{
  int labSum = 0;
  int labGrade = 0;
  for (int i = 1; i<=5; i++)
  {
    myFile >> labGrade;
    labSum = labSum + labGrade;
  }
  return labSum;
}

char computeLabGrade(int labSum)
{
  char letter;
  if (labSum > 60)
      letter = 'A';
  if ((labSum >= 50) && (labSum <= 60))
      letter = 'B';
  if ((labSum >= 40) && (labSum <= 49))
      letter = 'C';
  if ((labSum >= 30) && (labSum <= 39))
      letter = 'D';
  if (labSum < 30)
      letter = 'F';
  return letter;
}

int getAssignmentData()
{
  int assignmentSum = 0;
  int assignmentGrade;
    for (int i = 1; i<=7; i++)
    {
      myFile >> assignmentGrade;
      assignmentSum = assignmentSum + assignmentGrade;
    }
  return assignmentSum;
}

char computeAssignmentGrade(int assignmentSum)
{
  char letter;
    if (assignmentSum > 130)
        letter = 'A';
    if ((assignmentSum >= 112) && (assignmentSum <= 130))
        letter = 'B';
    if ((assignmentSum >= 100) && (assignmentSum <= 111))
        letter = 'C';
    if ((assignmentSum >= 80) && (assignmentSum <= 99))
        letter = 'D';
    if (assignmentSum < 80)
        letter = 'F';
  return letter;
}

int getQuizData()
{
  int quizSum = 0;
  int quizGrade;
  for (int i=1; i<=12; i++){
    myFile >> quizGrade;
    quizSum = quizSum + quizGrade;
  }
    return quizSum;
}

char computeQuizGrade(int quizSum)
{
  char letter;
    if (quizSum > 100)
        letter = 'A';
    if ((quizSum >= 85) && (quizSum <= 100))
        letter = 'B';
    if ((quizSum >= 70) && (quizSum <= 84))
        letter = 'C';
    if ((quizSum >= 60) && (quizSum <= 69))
        letter = 'D';
    if (quizSum < 60)
        letter = 'F';
  return letter;
}

int getTestData()
{
  int gradeSum = 0;
  int testGrade;
  for (int i=1; i<=3; i++){
    myFile >> testGrade;
    gradeSum = gradeSum + testGrade;
  }
    return gradeSum;
}

char computeTestGrade(int testScore)
{
  char letter;
    if (testScore > 360)
        letter = 'A';
    if ((testScore >= 210) && (testScore <= 360))
        letter = 'B';
    if ((testScore >= 180) && (testScore <= 209))
        letter = 'C';
    if ((testScore >= 150) && (testScore <= 179))
        letter = 'D';
    if (testScore < 150)
        letter = 'F';
  return letter;
}


float gradeToFloat(char letterGrade)
{
  int grade;
    if (letterGrade == 'A')
        grade = 4.0;
    if (letterGrade == 'B')
        grade = 3.0;
    if (letterGrade == 'C')
        grade = 2.0;
    if (letterGrade == 'D')
        grade = 1.0;
    if (letterGrade == 'F')
        grade = 0.0;
    return grade;
}

char computeTotalGrade(float quizFloat, float assignmentFloat, float labFloat, float testFloat)
{
    float final = ((10.0 * quizFloat) + (25.0 * assignmentFloat) + (30.0 * labFloat) + (35.0 * testFloat))/ 100.0;
  char letter;
  if (final > 3.49)
        letter = 'A';
    if (final >= 2.7 && final <= 3.48)
        letter = 'B';
    if (final >= 1.7 && final <= 2.69)
        letter = 'C';
    if (final >= 0.7 && final <= 1.69)
        letter = 'D';
    if (final < 0.7)
        letter = 'F';
  return letter;
}

void heading()
{
    string star;
    star = "**********************************";
    cout << star << endl << "Asha Johnson" << endl << "@02919852" << endl << "September 20, 2019" << endl;
    cout << "This lab computes the final grades of students in a class" << endl << star << endl;
}
//
//**********************************
//Asha Johnson
//@02919852
//September 20, 2019
//This lab computes the final grades of students in a class
//**********************************
//Student 1
//Student's lab grade is: F
//Student's assignment grade is: D
//Student's quiz grade is: F
//Student's test grade is: B
//Student's final grade is: D
//
//Student 2
//Student's lab grade is: B
//Student's assignment grade is: C
//Student's quiz grade is: B
//Student's test grade is: B
//Student's final grade is: B
//
//Student 3
//Student's lab grade is: C
//Student's assignment grade is: B
//Student's quiz grade is: F
//Student's test grade is: B
//Student's final grade is: C
//
//Student 4
//Student's lab grade is: C
//Student's assignment grade is: D
//Student's quiz grade is: F
//Student's test grade is: B
//Student's final grade is: D
//
//Student 5
//Student's lab grade is: C
//Student's assignment grade is: F
//Student's quiz grade is: D
//Student's test grade is: B
//Student's final grade is: D
//
//Student 6
//Student's lab grade is: B
//Student's assignment grade is: B
//Student's quiz grade is: C
//Student's test grade is: B
//Student's final grade is: B
//
