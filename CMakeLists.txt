cmake_minimum_required (VERSION 2.6)

#Project variables
set(OXYGEN_SRC_LOCATION "/home/chris/dev/source/oxygine-framework")

project (Particle_Prototype)

add_subdirectory(${OXYGEN_SRC_LOCATION} oxygine-framework)
add_definitions(${OXYGINE_DEFINITIONS})
include_directories(${OXYGINE_INCLUDE_DIRS} src/headers)
link_directories(${OXYGINE_LIBRARY_DIRS})

set(SRC_HEADERS "")
set(SRC_FILES "")

function(addHeader name)

	set(SRC_HEADERS ${SRC_HEADERS} src/headers/${name} PARENT_SCOPE)
endfunction()

function(addFile name)

	set(SRC_FILES ${SRC_FILES} src/${name} PARENT_SCOPE)
	
endfunction()

function(addSrcFile name)

	set(SRC_HEADERS ${SRC_HEADERS} src/headers/${name}.h PARENT_SCOPE)
	set(SRC_FILES ${SRC_FILES} src/${name}.cpp PARENT_SCOPE)

endfunction()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

addSrcFile(Particle_Prototype)
addSrcFile(Particle)
addFile(entry_point.cpp)

add_executable(Particle_Prototype ${SRC_FILES} ${SRC_HEADERS})

target_link_libraries(Particle_Prototype ${OXYGINE_CORE_LIBS})