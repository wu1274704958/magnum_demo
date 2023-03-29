aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} CUR_SRC_FILES)
set(CUR_TARGET_NAME triangle)
add_executable(${CUR_TARGET_NAME} ${CUR_SRC_FILES})
set_directory_properties(PROPERTIES CORRADE_USE_PEDANTIC_FLAGS ON)
target_link_libraries(${CUR_TARGET_NAME} PRIVATE
        Corrade::Main
        Magnum::Application
        Magnum::GL
        Magnum::Shaders
        Magnum::Magnum
)
