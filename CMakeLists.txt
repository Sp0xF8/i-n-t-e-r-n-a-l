cmake_minimum_required(VERSION 3.15)
project(csgowin64)

set(CMAKE_CXX_STANDARD 20)


file(GLOB_RECURSE SOURCES 
            "src/*.cpp"
)

file(GLOB_RECURSE HEADERS 
            "src/inc/*.h"
            "src/inc/*.hpp"
)

file(GLOB_RECURSE FEATURES
            "src/features/*.cpp"         "src/features/inc/*.h"

)


file (GLOB_RECURSE RESOURCES
            "res/*.cpp"             "res/*.h"
			"res/cs/*.cpp"         "res/cs/*.h"
            "res/imgui/*.cpp"       "res/imgui/*.h"
            "res/MinHook/*.c"       "res/MinHook/*.h" 
)

include_directories("src/inc"
                    "src/features/inc"
                    "res/imgui"
                    "res/MinHook"
					"res/cs")

add_library(csgowin64 SHARED ${SOURCES} ${HEADERS} ${RESOURCES} ${FEATURES} ) 

target_link_libraries(csgowin64 dwmapi.lib d3d11.lib)

if(MSVC)
    target_compile_options(csgowin64 PUBLIC)
else()
    target_compile_options(csgowin64 PUBLIC -fpic -mtune=native)
    target_link_options(csgowin64 PUBLIC -static-libgcc -static-libstdc++ -static -lpthread)
endif()



