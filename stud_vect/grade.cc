#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error;  using std::vector;


// расчет общей оценки из промежуточных экзаменов, конечных и общей за ДЗ
double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;//здесь homework это значение double, высчитанное функ. median()
}

// расчет промежуточной и финальной оценки с добавлением ее в вектор hw 
double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("студент не делал ДЗ!");
	return grade(midterm, final, median(hw));//вызов ф-ции median()
}

double grade(const Student_info& s)
{
//вызывает ф-ю double grade(double midterm, double final, const vector<double>& hw) которая внутри себя вызывает другую double grade(double midterm, double final, double homework)
	return grade(s.midterm, s.final, s.homework);//s.homework - это ВЕКТОР значений оценок объекта s
}

// предикат, определяющий прошел ли студент пороговое значение
bool fgrade(const Student_info& s)
{
	return grade(s) < 80;
	//return grade(s) < 4;
}

