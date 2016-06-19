#pragma once

#ifdef _WIN64

#include "include/glew.h"
#include "include/SDL.h"
#include <GL/gl.h>

#elif _WIN32

#include "include/glew.h"
#include "include/SDL.h"
#include <GL/gl.h>

#else
//Assumes it's Linux
#include "SDL2/SDL.h"
#include "GL/glew.h"
#include "GL/gl.h"

#endif

#undef main