set(SOURCES
    main.cpp
    options.cpp
    ../find_object.cpp
    ../plugin.cpp
)

add_executable(kno-evaluate
    ${SOURCES}
)
