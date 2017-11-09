#pragma once

#include <algorithm>
#include <list>
#include <map>
#include <string>
#include <vector>


namespace grade_school
{
	struct students
	{
		void add(const std::string student_name);
		std::vector<std::string> list_students() const;
	private:
		std::list<std::string> _students;
	};

	class school
	{
	public:
		void add(const std::string student_name, const int grade);
		std::map<int, std::vector<std::string>> roster() const;
		std::vector<std::string> grade(const int level) const;
	private:
		std::map<int, students> _roster;
	};
}
