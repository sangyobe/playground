cmake_minimum_required(VERSION 3.8)

function(GetCurrentDirectoryName dir_name)
    string(LENGTH "${CMAKE_SOURCE_DIR}/" cm_src_dir_len)
    string(SUBSTRING ${CMAKE_CURRENT_SOURCE_DIR} ${cm_src_dir_len}, -1 curr_dir_name)
    set("${dir_name}" "${curr_dir_name}" PARENT_SCOPE)
endfunction()