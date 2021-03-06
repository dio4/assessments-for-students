#include <algorithm>//для max()
#include <vector>
#include <string>
#include "grade.h"
#include "Student_info.h"

#ifdef _MSC_VER
#include "../minmax.h"
#else
using std::max;
#endif
using std::istream;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

//прототип ф-ции extract_fails() ее определение в fails_iters.cc
vector<Student_info> extract_fails(vector<Student_info>& v);

#ifdef _MSC_VER
bool operator<(const Student_info& x, const Student_info& y)
{
	return compare(x, y);
}
#endif

int main()
{
        vector<Student_info> vs;
        Student_info s;
        string::size_type maxlen = 0;
//в цикле заполняем структуру Student_info для каждого вводимого объекта s-name, midterm, final и vector<double> homework и заталкиваем каждую заполненную структуру в вектор vs
        while (read(cin, s)) { //вызов ф-ции istream& read(istream& is, Student_info& s) Student_info.cc
                maxlen = max(maxlen, s.name.size());//расчет самого длинного имени из введенных
                vs.push_back(s);// каждый заполненный объект загоняем в vs -вектор хран. всю инф. по всем студентам.
        }
//включить сюда версию sort() для векторов или для списков, если контейнер list
//сортирует элем. контейнера vs по возрастанию длины имени (те если нужна сортировка по ИМЕНИ в алф. порядке)
#ifdef _MSC_VER
	sort(vs.begin(), vs.end(), compare);//ф-я compare() в Student_info.cc
#else
    sort(vs.begin(), vs.end(), compare);
#endif

//передает отсортир. контейнер в ф-ю extract_fails(vs) в fails_iters.cc. Она сортир. по оценкам и удаляет из исх. вектора vs те объекты s (студенты), у кот. оценка < 60)
	vector<Student_info> fails = extract_fails(vs);

#ifdef _MSC_VER
	std::vector<Student_info>::iterator i;
#else
	vector<Student_info>::iterator i;
#endif

	/*for (i = fails.begin(); i != fails.end(); ++i)
		cout << i->name << " " << grade(*i) << endl;*/
    cout << "список студентов с суммарной оценкой ниже 80 баллов: " << endl;
//печать в цикле всех имен студентов и их сумм. оценок из вектора, сформир. для тех, у кого оценка ниже указанной в fgrade(const Student_info& s) - см. grade.cc
	for (i = fails.begin(); i != fails.end(); ++i)
		cout << i->name << " " << grade(*i) << endl;//разыменованный итератор i* указывает на ntreobq объект в векторе fails и передается в функ. grade() как "const Student_info& s" как ссылка на объект s - те на студента.
		//cout << (*i).name << " " << grade(*i) << endl;

	if (vs.size() != 0)//vs.size() уменьшилось на величину студентов, оценки которых < 60
	{
	    cout << "список остальных студентов : " << endl;
	    for (i = vs.begin(); i != vs.end(); ++i)
		cout << i->name << " " << grade(*i) << endl;
	}
	cout << "программа завершена" << "\n";
	return 0;
}
