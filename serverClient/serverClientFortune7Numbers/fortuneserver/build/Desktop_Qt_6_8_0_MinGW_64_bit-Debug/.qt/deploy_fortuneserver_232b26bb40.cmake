include(C:/Qt/Examples/Qt-6.8.0/network/fortuneserver/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/.qt/QtDeploySupport.cmake)
include("${CMAKE_CURRENT_LIST_DIR}/fortuneserver-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE C:/Qt/Examples/Qt-6.8.0/network/fortuneserver/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/fortuneserver.exe
    GENERATE_QT_CONF
)
