#pragma once

/*
  This handles includes, cause I saw this as a
  good solution at the time.
*/

#if defined(_WIN64) || defined(_WIN32)

#include "include/SDL.h"
#include "include/glew.h"
#include <GL/gl.h>

#else
//Assumes it's Linux
#include "SDL2/SDL.h"
#include "GL/glew.h"
#include "GL/gl.h"

#endif

#undef main
