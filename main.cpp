#include <iostream>

using namespace std;
class Course {
    friend istream &operator >>(ostream &out,Course &obj);
    friend ostream &operator <<(ostream &out,Course &obj);
private:
    static const int maxsiz = 60;
    string Name;
    int Size;
    string StudentNames[maxsiz];
    float ExamGrades[maxsiz];
    float HomeWorkGrades[maxsiz];
    float HomeWorkWeight;
public:
    Course()
    {
    }
    Course(string _Name, float hww, int _Size)
    {
        Name = _Name;
        setHomeWorkweight(hww);
        setSize(_Size);
    }

    int getsize()
    {
        return Size;
    }

    string getname()
    {
        return Name;
    }

    void setStudentName(/*string StudentName*/)
    {
        string StudentName;
        for (int i = 0; i < Size; i++)
        {
            cin >> StudentName;
            StudentNames[i] = StudentName;
        }
    }

    void setExamgrades(/*float Examgrades*/)
    {
        float Examgrades;
        for (int i = 0; i < Size; i++)
        {
            cin >> Examgrades;
            if (Examgrades >= 0 && Examgrades < 21) {
                ExamGrades[i] = Examgrades;
            } else {
                ExamGrades[i] = 0;
            }
        }
    }

    void setHomeWorkgrades(/*float HomeWorkgrades*/)
    {
        float HomeWorkgrades;
        for (int i = 0; i < Size; i++) {
            cin >> HomeWorkgrades;
            if (HomeWorkgrades >= 0 && HomeWorkgrades < 21) {
                HomeWorkGrades[i] = HomeWorkgrades;
            } else {
                HomeWorkGrades[i] = 0;
            }
        }
    }

    void setHomeWorkweight(float HomeWorkweight)
    {
        //cin >> HomeWorkweight;
        if (HomeWorkweight >= 0 && HomeWorkweight <= 1) {
            HomeWorkWeight = HomeWorkweight;
        } else {
            HomeWorkWeight = 0;
        }
    }

    float getHomeWorkweight()
    {
        return HomeWorkWeight;
    }

    void Insert(string StudentName, float HomeWorkgrades, float Examgrades)
    {
        StudentNames[Size] = StudentName;
        HomeWorkGrades[Size] = HomeWorkgrades;
        ExamGrades[Size] = Examgrades;
        Size += 1;
    }

    float getfinalgrades(string _Name)
    {
        float final = 0;
        for(int i=0;i<Size;i++)
        {
            if(_Name == StudentNames[i])
            {
                final = (ExamGrades[i] * (1 - HomeWorkWeight));
                final += (HomeWorkGrades[i] * HomeWorkWeight);
                //return ExamGrades[i];
            }
        }
        final /= 2;
        return final;
    }
    void setSize(int _Size)
    {
        if(_Size > 0 && _Size < 61)
        {
            Size = _Size;
        }else{
            Size = 0;
        }
    }
    Course operator ++(int)
    {
        Course temp = *this;
        for(int i=0;i<Size;i++)
        {
            if(ExamGrades[i] != 20)
            {
                ExamGrades[i] += 1;
            }
        }
        return temp;
    }
    int getmaxSize()
    {
        return maxsiz;
    }
};
istream &operator >>(istream &in,Course &obj)
{
    cout << "\nYou can enter "<<obj.getsize()<<" information from your student.";
    cout <<"\nEnter name of your student class: ";
    obj.setStudentName();
    cout << "\nEnter home work grades: ";
    obj.setHomeWorkgrades();
    cout << "\nEnter exam grades: ";
    obj.setExamgrades();
    return in;
}

ostream &operator <<(ostream &out,Course &obj)
{
    out <<"\nThe name of lesson: "<<obj.getname()<<endl;
    out <<"Number of your student: "<<obj.getsize()<<endl;
    for(int i=0;i<obj.Size;i++)
    {
        out << "\nName: "<<obj.StudentNames[i]<<'\t'<<"Exam Grades: "<<obj.ExamGrades[i] <<'\t'<<"Home work grades: "<<obj.HomeWorkGrades[i];
        out <<'\t'<<"Final grades:"<<obj.getfinalgrades(obj.StudentNames[i])<<endl;
    }
    return out;
}
int main()
{
    for(;;)
    {
        int size;
        cout<<"\nEnter number of your student: ";
        cin >> size;
        Course Student("C++ programming", 0.4, size);
        cin >> Student;
        cout << Student;

        int out;

        for(;;)
        {
            cout <<"\nIf you want enter new student information enter number ZERO: ";
            cin >> out;
            if(out == 0)
            {
                string name;
                cout <<"\nEnter a new name: ";
                cin >> name;
                float home;
                cout <<"\nEnter a home work grade: ";
                cin >> home;
                float exam;
                cout <<"\nEnter a exam grade: ";
                cin >> exam;

                Student.Insert(name,home,exam);
            }

            cout << Student;

            cout << "\n\"If you want exit from first loop enter ONE\"\n";
            cin >> out;
            if(out == 1) break;
        }

        cout << "\n\"If you want exit from second loop enter TWO\"\n";
        cin >> out;
        if(out == 2) break;
    }
    return 0;
}
