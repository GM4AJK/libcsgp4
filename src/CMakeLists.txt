

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
    DecayedException.cpp
    Observer.cpp
    TleException.cpp
    Tle.cpp
    OrbitalElements.cpp
    SatelliteException.cpp
    SolarPosition.cpp
    SGP4.cpp
)

ADD_LIBRARY(libcsgp4
    ${libcsgp4_SRCS}
)

TARGET_LINK_LIBRARIES(libcsgp4
    rt
)

