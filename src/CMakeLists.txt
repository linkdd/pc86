include_directories(
	${CMAKE_CURRENT_SOURCE_DIR} 
	"${CMAKE_CURRENT_SOURCE_DIR}/emu/"
	"${CMAKE_CURRENT_SOURCE_DIR}/utils/"
)

file(GLOB C_FILES "*.c")
file(GLOB C_EMU_FILES "emu/*.c")
file(GLOB C_HANDLERS_FILES "emu/handlers/*.c")
file(GLOB C_UTILS_FILES "utils/*.c")

set(C_FILES 
  ${C_FILES}
  ${C_EMU_FILES}
  ${C_HANDLERS_FILES}
  ${C_UTILS_FILES}
)

add_executable( ${PROJECT_NAME} ${C_FILES} )
target_link_libraries( ${PROJECT_NAME}  )
                                                                                                                                                                                                                  
