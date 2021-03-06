#include <vector>
#include "Student_info.h"
#include "grade.h"

using std::vector;

// версия на итераторах

/*ф-я принимает ссылку на вектор students и с пом-ю итераторов передает кажд. элемент (структуру, сод. инф. о студенте) ф-ции fgrade(*iter) см. grade.cc внизу, котор. возвр. True, если оценка студента < 60 и False наоборот.*/
vector<Student_info> extract_fails(vector<Student_info>& students)
{
	vector<Student_info> fail;
#ifdef _MSC_VER
	std::vector<Student_info>::iterator iter = students.begin();
#else
	vector<Student_info>::iterator iter = students.begin();
#endif

	while (iter != students.end()) {
		if (fgrade(*iter)) { //ф-ции fgrade() передаем через итератор 1-й и послед. элементы vector, пред. собой заполненные объекты структуры Student_info. она возвр. True или False
			fail.push_back(*iter); //добавл. в вектор fail студента, у кот. оценка < 60
			iter = students.erase(iter); //удаляет текущий объект после его добавления в vector fail и переуст. итератор на след. элемент. Этот итератор возвращ. ф-я erase(iter). 
		} else//если удаления нет - просто перемещает итератор на след элемент списка
			++iter;
	}
	return fail;//возвращ. контейнер со. студ. у котор. оценка < чем в fgrade(const Student_info& s) - см. grade.cc
}

