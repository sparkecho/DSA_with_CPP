#include <iostream>
#include "list.h"

using namespace std;

int main()
{
	List<string> lst;
	lst.InsertAfterHead("ab");
	lst.InsertBeforeRear("cd");
	lst.PrettyPrint();

//	cout << "Position(3): " << lst.Position(3) << endl;
//	cout << "GetValue(1): " << lst.GetValue(1) << endl;

//	cout << "GetCurrentValue(FindPosition(3)): " << lst.GetCurrentValue(lst.FindPosition(3)) << endl;
	
	cout << lst.Length() << endl;

	return 0;
}
