

SET(libcsgp4_SRCS
    version.cpp
    Vector.cpp
    TimeSpan.cpp
    Util.cpp
    Globals.cpp
    CoordGeodetic.cpp
    DateTime.cpp
    Eci.cpp
    CoordTopocentric.cpp
    CoordEquatorial.cpp
    DecayedException.cpp
    Observer.cpp
    TleException.cpp
    Tle.cpp
    OrbitalElements.cpp
    SatelliteException.cpp
    SolarPosition.cpp
    SGP4.cpp
    SunModel.cpp
    LunarModel.cpp
    CoordEcliptic.cpp
)

ADD_LIBRARY(csgp4
    ${libcsgp4_SRCS}
)

SET(libcsgp4_INCS
    csgp4/Vector.h
    csgp4/TimeSpan.h
    csgp4/Util.h
    csgp4/Globals.h
    csgp4/CoordGeodetic.h
    csgp4/DateTime.h
    csgp4/Eci.h
    csgp4/CoordTopocentric.h
    csgp4/CoordEquatorial.h
    csgp4/DecayedException.h
    csgp4/Observer.h
    csgp4/TleException.h
    csgp4/Tle.h
    csgp4/OrbitalElements.h
    csgp4/SatelliteException.h
    csgp4/SolarPosition.h
    csgp4/SGP4.h
    csgp4/SunModel.h
    csgp4/LunarModel.h
    csgp4/CoordEcliptic.h
)

TARGET_LINK_LIBRARIES(csgp4
    rt
)

INSTALL(FILES ${libcsgp4_INCS} DESTINATION include/csgp4)
INSTALL(TARGETS csgp4 LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

SET(libcsgp4_SRC_EXCLUDE
    build
    .git
    .github
)
SET(CPACK_SOURCE_IGNORE_FILES "${libcsgp4_SRC_EXCLUDE}")

SET(PACK_RESOURCE_FILE_LICENSE, "${PROJECT_SOURCE_DIR}/LICENSE.txt")
INCLUDE(CPack)



