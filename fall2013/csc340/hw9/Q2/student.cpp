//File name--student.cpp: implementation file for the Student class
#include "student.h"
//#include "dayOfYear.h"

//destructor
Student::~Student()
{
   if (grades != NULL ){
      delete [] grades;
   }
   if (list_classes != NULL){
      delete [] list_classes;
   }
}

//default constructor
Student::Student():Person()
{
   //call the constructor of the base class to initialize the inherited members
   level = 1; //freshmen
   num_grades = 0;
   num_classes = 0;
   grades = NULL;
   list_classes = NULL;
}

//a second constructor
Student::Student(int new_id, string new_name, DayOfYear date, int lvl):Person(new_id, new_name, date),level(lvl),num_grades(0),grades(NULL),list_classes(NULL)
{
 //call the corresponding constructor in the 
 //base class to initialize the inherited members
 /*  level = lvl;
   num_grades = 0;
   grades = NULL;   
 */
}

//copy constructor
Student::Student(const Student & std):Person(std) //call the copy constructor of the base class
{
   
    level = std.level;
    num_grades = std.num_grades;
    if (num_grades <= 0)
       grades = NULL;
    else{ //allocate space to *grades and copy the grades from std
       (*this).grades = new double [ num_grades ];
       if (grades == NULL ){
           cerr<< "Student:Student(const Student &): Memory allocation error\n";
           exit( -1 );
       }
       for (int i=0; i<num_grades; i++)
           grades[ i ] = std.grades[ i ];
    }

    num_classes = std.num_classes;
    if (num_classes <= 0)
	list_classes = NULL;

    else{
	this->list_classes = new string[ num_classes ];
        if (list_classes == NULL ){
            cerr<< "Student:Student(const Student &): Memory allocation error\n";
            exit( -1 );
        }
	for (int i=0; i<num_classes; i++)
		list_classes[i] = std.list_classes[i];

    }
}

void Student::operator=( const Student & rhs)
{
     (*this).Person::operator=(rhs);
     level = rhs.level;
     if (num_grades != rhs.num_grades){
        delete [] grades;
        num_grades = rhs.num_grades;
        grades = new double[ num_grades ];
        if (grades == NULL){
           cerr<< "Student:operator=(const Student &): Memory allocation error\n";
           exit( -1 );
        }
        for (int i=0; i<num_grades; i++)
           grades[ i ] = rhs.grades[ i ];
     }  

     if (num_classes != rhs.num_classes) {
	delete [] list_classes;
	num_classes = rhs.num_classes;
	list_classes = new string[ num_classes ];
        if (list_classes == NULL){
           cerr<< "Student:operator=(const Student &): Memory allocation error\n";
           exit( -1 );
        }
	for (int i=0; i<num_classes; i++)
		list_classes[i] = rhs.list_classes[i];
     }
}

int Student::get_level() const
{
    return level;
}

int Student::get_num_grades() const
{
    return num_grades;
}

int Student::get_num_classes() const
{
	return num_classes;
}

double Student::get_grade( int i) const
{
    if (i<1 || i>num_grades) 
       return -1.0; //non-existent grade
    else
        return grades[ i-1 ];
}

string Student::get_class(int i) const
{
	if(i<1 || i>num_classes)
		return NULL;
	else
		return list_classes[i-1];
}

void Student::set_level(int lvl)
{
   level = lvl;
}

void Student::set_num_grades(int num)
{
   num_grades = num;
   if (num > 0){
      grades = new double [ num ];
      if (grades == NULL ){
         cerr<< "Student:set_num_grades(int ): Memory allocation error\n";
         exit( -1 );
      }
      for (int i=0; i<num; i++)
         grades[ i ] = 0;
   }
}

void Student::set_num_classes(int num)
{
	num_classes = num;
	if( num > 0) {
		list_classes = new string[ num ];
		if (grades == NULL ){
			cerr<< "Student:set_num_grades(int ): Memory allocation error\n";
			exit( -1 );
		}
		for(int i=0; i<num; i++)
			grades[i] = 0;

	}
}

void Student::set_grade(int i, double grd)
{
    if (i>=1 && i<=num_grades) 
       grades[ i-1 ] = grd;
}

void Student::set_class(int i, string cls)
{
	if(i>=1 && i<=num_classes)
		list_classes[i-1] = cls;
}

ostream& operator<<(ostream& out, const Student& std)
{
   DayOfYear bday;
   bday = std.get_birthday();
   
   out << "------------------------------\n";
   out << "id=" << std.get_id() <<endl;
   out   << "name=" << std.get_name() << endl;
   out << "birthday=" << bday.get_day(); 
   out << "-" << bday.get_month();
   out << "-" << bday.get_year() << endl;
   out << "#emails=" <<std.get_num_emails()<<endl;
   out << " 1st email=" << std.getEmail(0)<<endl;
   out << "level="<<std.level<<endl;
   out << "#grades=" << std.num_grades << endl; 
   for (int i=1; i<=std.num_grades; i++)
        out << "grade[" << i <<"]=" << std.grades[i-1] <<" ";
   out <<endl;
   out << "#class=" << std.num_classes << endl;
   for (int i=1; i<=std.num_classes; i++)
	out << "class[" << i <<"]=" << std.list_classes[i-1] <<" ";
   out << endl;
   out << "------------------------------\n";  
   
   return out;    
}


void Student::output() const
{
     DayOfYear bday;
   bday = get_birthday();
   
   cout << "------------------------------\n";
   cout << "id=" << get_id() <<endl;
   cout   << "name=" <<  get_name() << endl;//private-is-private rule 
   cout << "birthday=" << bday.get_day(); 
   cout << "-" << bday.get_month();
   cout << "-" << bday.get_year() << endl;
   cout << "#emails=" <<get_num_emails()<<endl;
   cout << " 1st email=" << getEmail(0)<<endl;
   cout << "level="<<level<<endl;
   cout << "#grades="<< num_grades <<endl; 
   for (int i=1; i<=num_grades; i++)
        cout << "grade[" << i <<"]=" << grades[i-1] <<" ";
   cout <<endl;
   cout << "#class=" << num_classes << endl;
   for (int i=1; i<=num_classes; i++)
	cout << "class[" << i <<"]=" << list_classes[i-1] <<" ";
   cout << endl;
   cout << "------------------------------\n";  
   
}

