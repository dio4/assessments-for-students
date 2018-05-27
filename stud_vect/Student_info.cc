// исходник связанных функций для `Student_info'
#include "Student_info.h"

using std::istream;  using std::vector; using std::cout; using std::endl;

//сортировка по имени в алф. порядке
bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

istream& read(istream& is, Student_info& s) //принимает ссылку на вх. поток и объект структуры Student_info
{
	/*cout << "Введите имя студента, срединную и финальную оценки за семестр" << endl;
	cout << "окончание ввода Ctrl+D" << endl;*/
	is >> s.name >> s.midterm >> s.final;
//вызов ф-ции read_hw()
	read_hw(is, s.homework);  // чтение и сохранение всех оценок студентов за ДЗ
	return is; //возврат в main()
//имеем на каждого студента заполнен. структуру с его именем, и оценками
}

// чтение оценок из вх. потока в  `vector<double>' hw
istream& read_hw(istream& in, vector<double>& hw)
{
	if (in) {
		// очищение вектора std::vector<double> homework от мусора
		hw.clear();
		// read homework grades
		/*cout << "введите оценки студентов за ДЗ" << endl;
		cout << "окончание ввода Ctrl+D" << endl;*/
		double x;
		while (in >> x)
			hw.push_back(x);//заполнение вектора std::vector<double> homework вводимыми оценками
		// очищение потока перед вводом след. данных
		in.clear();
		/*cout << "вывод вектора оценок считанных в hw" << endl;
		vector<double>::iterator i;
		for (i = hw.begin(); i != hw.end(); ++i)
		cout << *i << endl;*/
	}
	return in;
}

