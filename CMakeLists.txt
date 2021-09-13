# 요구 CMake 최소 버전
CMAKE_MINIMUM_REQUIRED ( VERSION 3.1.1 )

# 프로젝트 이름 및 버전
PROJECT ( "gserver" )
SET ( PROJECT_VERSION_MAJOR 1 )
SET ( PROJECT_VERSION_MINOR 1 )

# 빌드 형상(Configuration) 및 주절주절 Makefile 생성 여부
SET ( CMAKE_BUILD_TYPE DEBUG )
SET ( CMAKE_VERBOSE_MAKEFILE true )

# 빌드 대상 바이너리 파일명 및 소스파일 목록
SET ( gserver
	"${CMAKE_PROJECT_NAME}-${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.out"
)
SET ( SRC_FILES
	Server.cpp
	User.cpp
	Process.cpp
	PacketHandler.cpp
	PacketProcessThread.cpp
	TetrisProcess.cpp
	LoginProcess.cpp
	LobbyProcess.cpp
	msg.pb.cc
	CompletionQue.cpp
	main.cpp
	)

# 공통 컴파일러
SET ( CMAKE_C_COMPILER "g++" )

# 공통 헤더 파일 Include 디렉토리 (-I)

# 공통 컴파일 옵션, 링크 옵션
ADD_COMPILE_OPTIONS ( -std=c++17 )
SET ( CMAKE_EXE_LINKER_FLAGS "" )

#FIND_PACKAGE(PkgConfig REQUIRED)
#PKG_CHECK_MODULES(PROTOBUF protobuf)

#INCLUDE_DIRECTORIES ( /home/ubuntu/work/libnp/libnp/Common  ${PROTOBUF_INCLUDE_DIRS} )
INCLUDE_DIRECTORIES ( /home/ubuntu/work/libnp/libnp/Common )

# 공통 링크 라이브러리 (-l)
#LINK_LIBRARIES( pthread np protoc  ${PROTOBUF_LIBRARIES} )
LINK_LIBRARIES( pthread np protoc )

# 공통 링크 라이브러리 디렉토리 (-L)
LINK_DIRECTORIES ( /home/ubuntu/work/libnp/libnp/Common )

# "Debug" 형상 한정 컴파일 옵션, 링크 옵션
SET ( CMAKE_C_FLAGS_DEBUG "-g" )
SET ( CMAKE_EXE_LINKER_FLAGS_DEBUG "" )

# "Release" 형상 한정 컴파일 옵션, 링크 옵션
SET ( CMAKE_C_FLAGS_RELEASE "" )
SET ( CMAKE_EXE_LINKER_FLAGS_RELEASE "" )

# 출력 디렉토리
SET ( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BUILD_TYPE} )
SET ( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BUILD_TYPE}/lib )
SET ( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BUILD_TYPE}/lib )

# 빌드 대상 바이너리 추가
ADD_EXECUTABLE( ${gserver} ${SRC_FILES} )

include(FindProtobuf)
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(PROTOBUF protobuf)
TARGET_LINK_LIBRARIES( ${gserver} ${PROTOBUF_LIBRARY} )

target_include_directories( ${gserver} PUBLIC ${PROTOBUF_INCLUDE_DIRS} )
target_compile_options( ${gserver} PUBLIC ${PROTOBUF_CFLAGS_OTHER})
#ADD_DEFINITIONS( ${PROTOBUF_CFLAGS} ${PROTOBUF_CFLAGS_OTHER} )
