#include "CDinausor.h"

CDinausor::CDinausor(int x, int y) : CAnimal(x, y)
{

}

// For Impact function
bool CDinausor::isDxAndDyInRange(int Dx, int Dy)
{
	if (Dy == 1)
		return (Dx >= 3 && Dx <= 9);
	if (Dy == 2)
		return (Dx >= 3 && Dx <= 9);
	if (Dy == 3)
		return (Dx >= 2 && Dx <= 8);
	if (Dy == 4)
		return (Dx >= 4 && Dx <= 8);
	return 0;
}