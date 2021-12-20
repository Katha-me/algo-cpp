#include "InterpolationSearch.h"
#include <iostream>
#include <cmath>

int interpolationSearch(string item, vector<string> list, int listLength)
{
	//TODO: Hier vervollständigen
	/*string unten = list[0];
	string oben = list[listLength-1];*/
	
	int unten = 0;
	int oben = listLength-1;
	int run = 0;
	cout << "looking for " << item << "\n";
	while (oben > unten)
	{
		
		cout << "=================================== \n";
		cout << "Durchlauf Nr: " << run << "\n";
		
		run++;
		int mitte = floor((oben-unten) / 2); 
		//string mitte = list[floor ((oben - unten) / 2)];
		int next = floor(stringQuotient(list[unten], item ,list[oben]) * (oben-unten)) + unten;
		
		cout << "Intial oben: " << oben << "\n";
		cout << "Intial unten: " << unten << "\n";
		cout << "Initial next: " << next << "\n";
		
		if ((item).compare(list[next]) == 0)
		{
			return next;
		}
		else{
			
			int n = oben - unten + 1;
			int sqrt_n = floor(sqrt(n));
			cout << "Intial Sqrt_n: " << sqrt_n << "\n";
			if (item.compare(list[next]) < 0)
			{
				cout << "item is SMALLER then NEXT \n";

				int i = 0;
				while (true)
				{
					if (list[(next - ((i+1) * sqrt_n + 1))].compare(item) <= 0 && list[(next - (i * sqrt_n))].compare(item) >= 0)
					{
						break;
					}else{
						i=i+1;
					}
				}
				
				oben = next - (i * sqrt_n);
				int temp = (next - ((i+1)*sqrt_n) +1);
				unten =  max(unten, temp);
				
				cout << "New oben: " << oben <<"\n";
				cout << "New unten: " << unten << "\n";
				
			}else{

				cout << "item is BIGGER then NEXT \n";
				int i = 0;
	
				while(true){
					if(list[next + (i*sqrt_n)].compare(item) <= 0 && list[next + ((i+1)*sqrt_n) - 1].compare(item) >= 0){	
						break;
					}else{
						i = i+1;
					}
				}

				int temp = (i+1) * floor(sqrt(n))-1 + next;
				oben = min(oben, temp);
				unten =  i * floor(sqrt(n)) + next;
				
				cout << "New oben: " << oben <<"\n";
				cout << "New unten: " << unten << "\n";
				
			}
			
		}
		
	}
	if(oben == unten && list[oben].compare(item) == 0){
		return oben;
	}

	return -1;
}


double stringQuotient(string a, string b, string c)
{
	// Ensure that a < b < c
	if (a.compare(b) > 0 || b.compare(c) > 0)
	{
		return -1;
	}
	int i = 0;
	// Figure out maximum search length
	int maxLength = a.length();
	if (b.length() < maxLength)
	{
		maxLength = b.length();
	}
	if (c.length() < maxLength)
	{
		maxLength = c.length();
	}
	// While i smaller than shortest of a,b,c
	while (i < maxLength)
	{
		// if the strings begin to be different at i
		if (a.at(i) != c.at(i))
		{
			// if b is still the same as a return 0
			if (a.at(i)==b.at(i))
			{
				return 0;
			}
			else
			{
				// if b is still the same as c return 1
				if (b.at(i) == c.at(i))
				{
					return 1;
				}
				else
				{
					// otherwise return (b[i]-a[i])/(c[i]-a[i])
					double zaehler = b.at(i) - a.at(i);
					double nenner = c.at(i) - a.at(i);
					return zaehler/nenner;
				}
			}
		}
		i++;
	}
	// at least one string finished
	// figure out next character (if a string ended, give it value 31 which is one less than space)
	int aChar;
	int bChar;
	int cChar;
	if (maxLength == a.length())
	{
		aChar = 31;
	}
	else
	{
		aChar = a.at(maxLength);
	}
	if (maxLength == b.length())
	{
		bChar = 31;
	}
	else
	{
		bChar = b.at(maxLength);
	}
	if (maxLength == c.length())
	{
		cChar = 31;
	}
	else
	{
		cChar = c.at(maxLength);
	}
	// a[i] = b[i] -> return 0
	if (aChar==bChar)
	{
		return 0;
	}
	else
	{
		// b[i] = c[i] -> return 1
		if (bChar == cChar)
		{
			return 1;
		}
		else
		{
			// otherwise return (b[i]-a[i])/(c[i]-a[i])
			double zaehler = bChar - aChar;
			double nenner = cChar - aChar;
			return zaehler/nenner;
		}
	}
}
