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
#             "src/features/misc/*.cpp"           "src/features/misc/*.h"
#            "src/features/visuals/*.cpp"        "src/features/visuals/*.h"
#             # "src/features/ragebot/*.cpp"        "src/features/ragebot/*.h"
#             # "src/features/legitbot/*.cpp"       "src/features/legitbot/*.h"
#             # "src/features/antiaim/*.cpp"        "src/features/antiaim/*.h"
)


file (GLOB_RECURSE RESOURCES
            "res/*.cpp"             "res/*.h"
            "res/imgui/*.cpp"       "res/imgui/*.h"
            "res/MinHook/*.c"       "res/MinHook/*.h" 
)

include_directories("src/inc"
                    # "src/features/misc"
                    "src/features/visuals"
                    "res/imgui"
                    "res/MinHook"
                    "res/fnv1a")

add_library(csgowin64 SHARED ${SOURCES} ${HEADERS} ${RESOURCES} ${FEATURES} ) 

target_link_libraries(csgowin64 dwmapi.lib d3d11.lib)

if(MSVC)
    target_compile_options(csgowin64 PUBLIC)
else()
    target_compile_options(csgowin64 PUBLIC -fpic -mtune=native)
    target_link_options(csgowin64 PUBLIC -static-libgcc -static-libstdc++ -static -lpthread)
endif()



