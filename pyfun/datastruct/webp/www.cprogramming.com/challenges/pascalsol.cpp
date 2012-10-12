#include <iostream>

using namespace std;

int compute_pascal(int row, int position)
{
	if(position == 1)
	{
		return 1;
	}
	else if(position == row)
	{
		return 1;
	}
	else
	{
		return compute_pascal(row-1, position) + compute_pascal(row-1, position-1);
	}
}
int main()
{
	int row, position;
	cout<<"Please input a row and a position along the row: ";
	cin>>row>>position;
	if(row<position)
	{
		cout<<"Invalid entry.  Position must be less than or equal to row.";
		return 1;
	}
        cout<<"Value at row "<<row<<" and position "<<position<<" is "<<compute_pascal(row, position);
}
