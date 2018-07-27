#include "Arcade.hpp"
#include "Background.hpp"
#include "time.h"
#include <unistd.h>

int main(int ac, char **av)
{
	Arcade *arcade = new Arcade();
	arcade->start(ac, av);
	return 0;
}
