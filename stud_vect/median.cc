// расчет медианы значений оценок каждого учащегося
#include <algorithm>    // to get the declaration of `sort'
#include <stdexcept>    // to get the declaration of `domain_error'
#include <vector>       // to get the declaration of `vector'

using std::domain_error;   using std::sort;   using std::vector;

#include "median.h"

// расчет медианы из данных `vector<double>'
double median(vector<double> vec) //vec - вектор оценок за ДЗ
{
#ifdef _MSC_VER
	typedef std::vector<double>::size_type vec_sz;
#else
	typedef vector<double>::size_type vec_sz;
#endif

	vec_sz size = vec.size();
	if (size == 0)
		throw domain_error("медиана пустого вектора");

	sort(vec.begin(), vec.end());

	vec_sz mid = size/2;

	return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

