set(SOURCES
    main.cpp
    options.cpp
    ../find_object.cpp
    ../plugin.cpp
)

add_executable(kno-evaluate
    ${SOURCES}
)
target_link_options(kno-evaluate PUBLIC
    "-Wl,--export-dynamic-symbol=kno_plugin_make"
)
