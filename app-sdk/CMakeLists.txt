cmake_minimum_required(VERSION 3.1)

project(hoscomm)

set(DEPENDS_FOLDER "D:/External" CACHE PATH "Dependency Path")

# zeromq
set(ZEROMQ_INCLUDE ${DEPENDS_FOLDER}/zeromq_secure/x64/include)
set(ZEROMQ_LIBS ${DEPENDS_FOLDER}/zeromq_secure/x64/lib)
set(ZEROMQ_BINS ${DEPENDS_FOLDER}/zeromq_secure/x64/bin)
set(ZEROMQ_LINK libzmq)
set(ZEROMQ_DLL "${ZEROMQ_BINS}/libzmq.dll" "${ZEROMQ_BINS}/libsodium.dll")

# tbb
set(TBB_INCLUDE ${DEPENDS_FOLDER}/tbb/include)
set(TBB_LIBS ${DEPENDS_FOLDER}/tbb/lib/intel64/vc12)
set(TBB_BINS ${DEPENDS_FOLDER}/tbb/bin/intel64/vc12)
set(TBB_LINK optimized "tbb" debug "tbb_debug")

#spdlog
set(SPDLOG_INCLUDE ${DEPENDS_FOLDER}/spdlog/include)

add_subdirectory(sender)