#ifndef COURSESCHEDULE_H
#define COURSESCHEDULE_H
using namespace std;
#include "Course.h"

class CourseSchedule{
	//overloaded operators
	friend ostream& operator<<(ostream&, const CourseSchedule&);

	private:
		
	public:
		CourseSchedule();
};
#endif
