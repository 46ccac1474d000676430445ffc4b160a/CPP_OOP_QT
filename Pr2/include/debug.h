#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>

#define DEBUG(exp) printf("\n  >>> DEBUG_BEFORE: in file %s, on line %d\n", __FILE__, __LINE__); exp; printf("\n  >>> DEBUG_AFTER:  in file %s, on line %d\n", __FILE__, __LINE__);

#endif	//DEBUG_H

