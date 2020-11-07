#include <iostream>
#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;

int main()
{
	try
	{
		connection C;
		cout << "Connected to " << C.dbname() << endl;
		work W(C);

		cout << "Found " << R.size() << "employees:" << endl;
		for (result::const_iterator r = R.begin();
		     r != R.end();
		     ++r)
		{
			cout << r[0].c_str() << endl;
		}

		cout << "Doubling all employees' salaries..." << endl;
		W.exec("UPDATE employee SET salary=salary*2");

		cout << "Making changes definite: ";
		W.commit();
		cout << "ok." << endl;
	}
	catch (const exception &e)
	{
		cerr << e.what() << endl;
		return 1;
	}
	return 0;
}
