FILE(GLOB SOURCE_FILES "*.cpp" "*.h")

ADD_LIBRARY(tea ${SOURCE_FILES})

INCLUDE_DIRECTORIES(tea "/include")
INCLUDE_DIRECTORIES(tea "/glm" "/glm/gtc" "/glm/gtc" "/glm/detail")

#INCLUDE(FindPkgConfig)
#PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)


#OpenGL
find_package("OpenGL" REQUIRED)
if(${OPENGL_FOUND})
	include_directories(tea ${OPENGL_INCLUDE_DIR})
	target_link_libraries(tea ${OPENGL_LIBRARIES})
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
	INCLUDE_DIRECTORIES(tea ".WindowsBS/")

	MESSAGE(${CMAKE_SOURCE_DIR})

	FILE(GLOB LIBRARIES "${CMAKE_SOURCE_DIR}/tea/.WindowsBS/include/*.lib")

	target_link_libraries(tea ${LIBRARIES})

else()
	INCLUDE(FindPkgConfig)

	PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
	PKG_SEARCH_MODULE(GLEW REQUIRED glew)

	INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})
	TARGET_LINK_LIBRARIES(tea ${SDL2_LIBRARIES} ${GLEW_LIBRARIES})
endif()

#
# #OpenGL
# find_package("OpenGL" REQUIRED)
# if(${OPENGL_FOUND})
# 	include_directories(tea ${OPENGL_INCLUDE_DIR})
# 	target_link_libraries(tea ${OPENGL_LIBRARIES})
# endif()
#
# #SDL2
# if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
# 	file(GLOB SDL_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SDL2/*.lib)
# elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
# 	find_package("SDL2" REQUIRED)
# 	if(${SDL_FOUND})
# 		include_directories(tea ${SDL2_INCLUDE_DIR})
# 		target_link_libraries(tea ${SDL2_LIBRARIES})
# 	endif()
# else()
# 	message(FATAL_ERROR "A ${CMAKE_SYSTEM_NAME} build is not available, yet!")
# endif()
# target_link_libraries(tea ${SDL_LIB_DIR})
#
# #GLEW
# if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
# 	file(GLOB GLEW_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/GLEW/*.lib)
# elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
# 	find_package("GLEW" REQUIRED)
# 	if(${GLEW_FOUND})
# 		include_directories(tea ${GLEW_INCLUDE_DIR})
# 		target_link_libraries(tea ${GLEW_LIBRARIES})
# 	endif()
# else()
# 	message(FATAL_ERROR "A ${CMAKE_SYSTEM_NAME} build is not available, yet!")
# endif()
#
# target_link_libraries(tea ${GLEW_LIB_DIR})
