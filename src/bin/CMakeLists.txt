set(THEME_INSTALL_PATH "${CMAKE_INSTALL_PREFIX}/share/jesus/")
set(PACKAGE_DATA_DIR "${CMAKE_INSTALL_PREFIX}/share/jesus/")
set(PACKAGE_LIB_DIR "${CMAKE_INSTALL_PREFIX}/lib/")
set(PACKAGE_BIN_DIR "${CMAKE_INSTALL_PREFIX}/bin/")

add_custom_command(
     OUTPUT efm.edc.edj
     COMMAND edje_cc -id ${CMAKE_SOURCE_DIR}/data/img ${CMAKE_SOURCE_DIR}/data/theme/efm/efm.edc ${CMAKE_BINARY_DIR}/data/theme/efm.edc.edj
     DEPENDS ${CMAKE_SOURCE_DIR}/data/theme/efm/efm.edc
)

add_executable(efm jesus.c titlebar.c ui.c config.c exec_ui.c exec.c hooks.c history.c clipboard.c fs_operation.c efm.edc.edj)

include_directories(
  ${EINA_INCLUDE_DIRS}
  ${EVAS_INCLUDE_DIRS}
  ${EFL_INCLUDE_DIRS}
  ${EIO_INCLUDE_DIRS}
  ${EET_INCLUDE_DIRS}
  ${EFREET_INCLUDE_DIRS}
  ${ECORE_INCLUDE_DIRS}
  ${ELEMENTARY_INCLUDE_DIRS}
  ../lib/efm
  ../widgets/
  )

target_link_libraries (efm
   ${EINA_LIBRARIES}
   ${EVAS_LIBRARIES}
   ${EFL_LIBRARIES}
   ${EIO_LIBRARIES}
   ${EO_LIBRARIES}
   ${EFREET_LIBRARIES}
   ${EFREET_TRASH_LIBRARIES}
   ${ECORE_LIBRARIES}
   ${EET_LIBRARIES}
   ${ELEMENTARY_LIBRARIES}
   widgets
   efm_lib)

set_property(TARGET efm PROPERTY COMPILE_DEFINITIONS THEME_PATH="${THEME_INSTALL_PATH}"
PACKAGE_DATA_DIR="${PACKAGE_DATA_DIR}"
PACKAGE_LIB_DIR="${PACKAGE_LIB_DIR}"
PACKAGE_BIN_DIR="${PACKAGE_BIN_DIR}"
)

INSTALL(FILES ${CMAKE_BINARY_DIR}/data/theme/efm.edc.edj
  DESTINATION share/jesus/)

INSTALL(TARGETS efm DESTINATION bin)