#include "grade_school.h"

using namespace std;


namespace grade_school
{
	void students::add(const string student_name)
	{
		_students.insert(
			lower_bound(_students.cbegin(), _students.cend(), student_name),
			student_name
		);
	}

	vector<string> students::list_students() const
	{
		return vector<string> { cbegin(_students), cend(_students) };
	}
	
	void school::add(const string student_name, const int grade)
	{
		_roster[grade].add(student_name);
	}
	
	map<int, vector<string>> school::roster() const
	{
		map<int, vector<string>> new_map;

		for (const auto& grade_level_data : _roster)
		{
			const auto& grade = grade_level_data.first;
			const auto& students = grade_level_data.second;

			new_map[grade] = students.list_students();
		}

		return new_map;
	}
	
	vector<string> school::grade(const int level) const
	{
		const auto roster_itr = _roster.find(level);

		return
			(roster_itr != _roster.cend()) ?
				roster_itr->second.list_students()
				: vector<string>();
	}
}
