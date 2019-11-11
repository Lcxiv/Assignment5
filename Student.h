using namespace std;
class Student
{
  int studentID, advisorField;
  double studentGPA;
  string nameField, levelField, majorField;

public:
  Student();
  Student(int studID,string nameF, string levelF = "Freshman", string majorF = "Undecided", double GPAtotal, int advisorF);
  ~Student;

  int getStudentID();
  int getAdvisorField();
  double getGPA();
  string getNameField();
  string getLevelField();
  string getMajorField();
}
