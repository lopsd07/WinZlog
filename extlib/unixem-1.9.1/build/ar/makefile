############################################################################
# File:		makefile
#
# Purpose:	Makefile for the UNIXem project, for the Arturius C/C++ Compiler Multiplexer
#           compiler, on Win32
#
# Created:	15th Feburary 2005
# Updated:	12th August 2010
#
############################################################################


############################################################################
# Symbols

########################################
# Project & compiler version

COMP_TAG            =   ar
ARCH_TAG            =   
OS_TAG				=   
PROJ_TAG			=	unixem
PROJ_VER_MAJOR		=	1
PROJ_TAG_VER		=	$(PROJ_TAG).$(PROJ_VER_MAJOR)

PROJ_MAKEFILE_NAME  =   makefile

########################################
# Testing verbosity

TEST_VERBOSITY		=	2

########################################
# Directories

PROJ_BASE_DIR			=	..\..
PROJ_BIN_DIR			=	$(PROJ_BASE_DIR)\bin
PROJ_INCLUDE_DIR		=	$(PROJ_BASE_DIR)\include
PROJ_LIB_DIR			=	$(PROJ_BASE_DIR)\lib
PROJ_OBJ_DIR			=	.
PROJ_SRC_DIR			=	$(PROJ_BASE_DIR)\src
PROJ_EXAMPLES_DIR		=	$(PROJ_BASE_DIR)\examples
PROJ_SAMPLES_DIR        =   $(PROJ_BASE_DIR)\samples
PROJ_TEST_ROOT_DIR		=	$(PROJ_BASE_DIR)\test
PROJ_TEST_COMPONENT_DIR	=	$(PROJ_TEST_ROOT_DIR)\component
PROJ_TEST_SCRATCH_DIR	=	$(PROJ_TEST_ROOT_DIR)\scratch
PROJ_TEST_UNIT_DIR		=	$(PROJ_TEST_ROOT_DIR)\unit

########################################
# tools

CC						=	arcc.debug
CPPC                    =   arcc.debug
AR						=	arar
LD						=	arld
RM						=	del /f
CP						=	copy
RC                      =   rc

# Includes

INCLUDES_LEADER			=	

PROJ_INCLUDE			=	-I$(PROJ_INCLUDE_DIR)

ENV_INCLUDES 	=

COMMON_INCLUDES		=

CC_INCLUDES_BASE=\
$(INCLUDES_LEADER)\
$(PROJ_INCLUDE)\
-I"$(STLSOFT)\include"\
$(COMMON_INCLUDES)\
$(ENV_INCLUDES)\
 \

CC_INCLUDES =\
$(CC_INCLUDES_BASE)\
 \

CPPC_INCLUDES_BASE=\
$(INCLUDES_LEADER)\
$(PROJ_INCLUDE)\
-I"$(STLSOFT)\include"\
$(COMMON_INCLUDES)\
$(ENV_INCLUDES)\
 \

CPPC_INCLUDES=\
$(CPPC_INCLUDES_BASE)\
 \


# Lib

LIBS_LEADER			=	

# lib paths

ENV_LIBPATHS		=
COMMON_LIBPATHS			=



LIBPATHS=\
 $(LIBS_LEADER)\
 $(COMMON_LIBPATHS)\
 $(ENV_LIBPATHS)\
\


# lib names

TARGET_LIB_DEBUG	= 
TARGET_LIB_RELEASE	= 

# #defines

COMMON_DEFS			=	-DWIN32

CUSTOM_DEFS			=

CC_CUSTOM_DEFS		=	$(CUSTOM_DEFS)

CPPC_CUSTOM_DEFS	=	$(CUSTOM_DEFS)

CC_DEFS 			=	$(COMMON_DEFS) $(CC_CUSTOM_DEFS)

CPPC_DEFS			=	$(COMMON_DEFS) $(CPPC_CUSTOM_DEFS)

# CC flags

CC_F_NOLOGO				=	
CC_F_COMPILE_ONLY		=	-c
CC_F_WARNING_MAX		=	--warning-level=maximum
CC_F_WARNING_ERR		=	--warnings-as-errors=on
CC_F_WARNINGS_LIMIT		=	
CC_F_MINIMUM_SIZE		=	--minimum-size
#CC_F_MAXIMUM_SPEED		=	--maximum-speed
CC_APP_F_WARNING_MAX	=	$(CC_F_WARNING_MAX)
CC_APP_F_WARNING_ERR	=	$(CC_F_WARNING_ERR)

# CPPC flags

CPPC_F_NOLOGO			=	
CPPC_F_COMPILE_ONLY 	=	-c
CPPC_F_WARNING_MAX		=	--warning-level=maximum
CPPC_F_WARNING_ERR		=	--warnings-as-errors=on
CPPC_F_WARNINGS_LIMIT	=	
CPPC_F_MINIMUM_SIZE 	=	--minimum-size
#CPPC_F_MAXIMUM_SPEED	=	--maximum-speed
CPPC_F_EXCEPTIONS		=	--exception-handling=on
CPPC_F_NO_EXCEPTIONS	=	
CPPC_F_WITH_EXCEPTIONS	=	
CPPC_F_RTTI 			=	
CPPC_APP_F_WARNING_MAX	=	$(CPPC_F_WARNING_MAX)
CPPC_APP_F_WARNING_ERR	=	$(CPPC_F_WARNING_ERR)



CC_TOOL_FLAGS		=	--compilers=bc56,dmb-stlport,gcc34,icl8,vc6,vc71,ow12 --announce-tools --active-compiler=vc/6 --announce-tool-commands

CPPC_TOOL_FLAGS 	=	--compilers=bc56,dmb-stlport,gcc34,icl8,vc6,vc71 --announce-tools --active-compiler=vc/6 --announce-tool-commands



CC_FLAGS =\
 $(CC_TOOL_FLAGS)\
 $(CC_F_NOLOGO)\
 $(CC_F_COMPILE_ONLY)\
 $(CC_F_WARNING_MAX)\
 $(CC_F_WARNING_ERR)\
 $(CC_F_WARNINGS_LIMIT)\
 $(CC_F_MINIMUM_SIZE)\
 \

CPPC_FLAGS=\
 $(CPPC_TOOL_FLAGS)\
 $(CPPC_F_NOLOGO)\
 $(CPPC_F_COMPILE_ONLY)\
 $(CPPC_F_WARNING_MAX)\
 $(CPPC_F_WARNING_ERR)\
 $(CPPC_F_WARNINGS_LIMIT)\
 $(CPPC_F_MINIMUM_SIZE)\
 $(CPPC_F_EXCEPTIONS)\
 $(CPPC_F_RTTI)\
 \



# Arguments (= flags + defines + includes)

CC_ARGS_DEBUG				=	-D_DEBUG -UNDEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_RELEASE				=	-DNDEBUG -U_DEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)

AR_ARGS				=	

LD_ARGS				=	 $(COMMON_LIB)

############################################################################
# Targets

TARGET_LIB_DEBUG			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG)$(OS_TAG)$(ARCH_TAG).debug.lib
TARGET_LIB_UN_DEBUG		=	$(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG)$(OS_TAG)$(ARCH_TAG).debug.lib
TARGET_LIB_RELEASE			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG)$(OS_TAG)$(ARCH_TAG).release.lib
TARGET_LIB_UN_RELEASE		=	$(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG)$(OS_TAG)$(ARCH_TAG).release.lib



TARGETS = \
 $(TARGET_LIB_DEBUG)\
 $(TARGET_LIB_UN_DEBUG)\
 $(TARGET_LIB_RELEASE)\
 $(TARGET_LIB_UN_RELEASE)\
 \

OBJ_PROJ_atomic__DEBUG = $(PROJ_OBJ_DIR)\atomic.debug.obj
OBJ_PROJ_dirent__DEBUG = $(PROJ_OBJ_DIR)\dirent.debug.obj
OBJ_PROJ_dlfcn__DEBUG = $(PROJ_OBJ_DIR)\dlfcn.debug.obj
OBJ_PROJ_glob__DEBUG = $(PROJ_OBJ_DIR)\glob.debug.obj
OBJ_PROJ_hostname__DEBUG = $(PROJ_OBJ_DIR)\hostname.debug.obj
OBJ_PROJ_mmap__DEBUG = $(PROJ_OBJ_DIR)\mmap.debug.obj
OBJ_PROJ_resource__DEBUG = $(PROJ_OBJ_DIR)\resource.debug.obj
OBJ_PROJ_setenv__DEBUG = $(PROJ_OBJ_DIR)\setenv.debug.obj
OBJ_PROJ_time__DEBUG = $(PROJ_OBJ_DIR)\time.debug.obj
OBJ_PROJ_uio__DEBUG = $(PROJ_OBJ_DIR)\uio.debug.obj
OBJ_PROJ_unistd__DEBUG = $(PROJ_OBJ_DIR)\unistd.debug.obj
OBJ_PROJ_internal_util__DEBUG = $(PROJ_OBJ_DIR)\internal.util.debug.obj

OBJ_PROJ_DEBUG = \
 $(OBJ_PROJ_atomic__DEBUG)\
 $(OBJ_PROJ_dirent__DEBUG)\
 $(OBJ_PROJ_dlfcn__DEBUG)\
 $(OBJ_PROJ_glob__DEBUG)\
 $(OBJ_PROJ_hostname__DEBUG)\
 $(OBJ_PROJ_mmap__DEBUG)\
 $(OBJ_PROJ_resource__DEBUG)\
 $(OBJ_PROJ_setenv__DEBUG)\
 $(OBJ_PROJ_time__DEBUG)\
 $(OBJ_PROJ_uio__DEBUG)\
 $(OBJ_PROJ_unistd__DEBUG)\
 $(OBJ_PROJ_internal_util__DEBUG)\
 \

OBJ_PROJ_atomic__RELEASE = $(PROJ_OBJ_DIR)\atomic.release.obj
OBJ_PROJ_dirent__RELEASE = $(PROJ_OBJ_DIR)\dirent.release.obj
OBJ_PROJ_dlfcn__RELEASE = $(PROJ_OBJ_DIR)\dlfcn.release.obj
OBJ_PROJ_glob__RELEASE = $(PROJ_OBJ_DIR)\glob.release.obj
OBJ_PROJ_hostname__RELEASE = $(PROJ_OBJ_DIR)\hostname.release.obj
OBJ_PROJ_mmap__RELEASE = $(PROJ_OBJ_DIR)\mmap.release.obj
OBJ_PROJ_resource__RELEASE = $(PROJ_OBJ_DIR)\resource.release.obj
OBJ_PROJ_setenv__RELEASE = $(PROJ_OBJ_DIR)\setenv.release.obj
OBJ_PROJ_time__RELEASE = $(PROJ_OBJ_DIR)\time.release.obj
OBJ_PROJ_uio__RELEASE = $(PROJ_OBJ_DIR)\uio.release.obj
OBJ_PROJ_unistd__RELEASE = $(PROJ_OBJ_DIR)\unistd.release.obj
OBJ_PROJ_internal_util__RELEASE = $(PROJ_OBJ_DIR)\internal.util.release.obj

OBJ_PROJ_RELEASE = \
 $(OBJ_PROJ_atomic__RELEASE)\
 $(OBJ_PROJ_dirent__RELEASE)\
 $(OBJ_PROJ_dlfcn__RELEASE)\
 $(OBJ_PROJ_glob__RELEASE)\
 $(OBJ_PROJ_hostname__RELEASE)\
 $(OBJ_PROJ_mmap__RELEASE)\
 $(OBJ_PROJ_resource__RELEASE)\
 $(OBJ_PROJ_setenv__RELEASE)\
 $(OBJ_PROJ_time__RELEASE)\
 $(OBJ_PROJ_uio__RELEASE)\
 $(OBJ_PROJ_unistd__RELEASE)\
 $(OBJ_PROJ_internal_util__RELEASE)\
 \

OBJS = \
 $(OBJ_PROJ_DEBUG)\
 $(OBJ_PROJ_RELEASE)\
 \

all:	target

usage:
	@echo "make [usage | clean | all | test | target] - default is 'all'"

clean:
	@-$(RM) $(TARGET_LIB_DEBUG)
	@-$(RM) $(TARGET_LIB_UN_DEBUG)
	@-$(RM) $(TARGET_LIB_RELEASE)
	@-$(RM) $(TARGET_LIB_UN_RELEASE)
	@-$(RM) $(OBJ_PROJ_DEBUG)
	@-$(RM) $(OBJ_PROJ_RELEASE)


# targets

target:		check.lib.dir $(TARGETS)

compile.libs.core:	$(OBJS)

compile.libs:		compile.libs.core

compile:			compile.libs

build.libs.core:	$(TARGETS)

build.libs:			build.libs.core

build:				build.libs

check.lib.dir:
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)

check.bin.dir:
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)


test_:
#	$(TARGET_TEST_C_DEBUG) --unittest
#	$(TARGET_TEST_C_RELEASE) --unittest

test:	target test_


# build targets

# library


$(TARGET_LIB_UN_DEBUG): $(TARGET_LIB_DEBUG)
	@$(CP) $(TARGET_LIB_DEBUG) $@

$(TARGET_LIB_DEBUG): $(OBJ_PROJ_DEBUG) makefile
	@-if not exist $(B64_LIB_DIR)\NUL mkdir $(B64_LIB_DIR)
	$(AR) $(AR_ARGS) $@ $(OBJ_PROJ_DEBUG)

$(OBJ_PROJ_atomic__DEBUG):	$(PROJ_SRC_DIR)\atomic.c $(PROJ_INCLUDE_DIR)\asm\atomic.h makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(PROJ_SRC_DIR)\atomic.c
$(OBJ_PROJ_dirent__DEBUG):	$(PROJ_SRC_DIR)\dirent.c $(PROJ_INCLUDE_DIR)\dirent.h makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(PROJ_SRC_DIR)\dirent.c
$(OBJ_PROJ_dlfcn__DEBUG):	$(PROJ_SRC_DIR)\dlfcn.c $(PROJ_INCLUDE_DIR)\dlfcn.h makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(PROJ_SRC_DIR)\dlfcn.c
$(OBJ_PROJ_glob__DEBUG):	$(PROJ_SRC_DIR)\glob.c $(PROJ_INCLUDE_DIR)\glob.h makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(PROJ_SRC_DIR)\glob.c
$(OBJ_PROJ_hostname__DEBUG):	$(PROJ_SRC_DIR)\hostname.c $(PROJ_INCLUDE_DIR)\unistd.h makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(PROJ_SRC_DIR)\hostname.c
$(OBJ_PROJ_mmap__DEBUG):	$(PROJ_SRC_DIR)\mmap.c $(PROJ_INCLUDE_DIR)\sys\mman.h makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(PROJ_SRC_DIR)\mmap.c
$(OBJ_PROJ_resource__DEBUG):	$(PROJ_SRC_DIR)\resource.c $(PROJ_INCLUDE_DIR)\sys\resource.h makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(PROJ_SRC_DIR)\resource.c
$(OBJ_PROJ_setenv__DEBUG):	$(PROJ_SRC_DIR)\setenv.c $(PROJ_INCLUDE_DIR)\unixem\setenv.h makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(PROJ_SRC_DIR)\setenv.c
$(OBJ_PROJ_time__DEBUG):	$(PROJ_SRC_DIR)\time.c $(PROJ_INCLUDE_DIR)\sys\time.h makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(PROJ_SRC_DIR)\time.c
$(OBJ_PROJ_uio__DEBUG):	$(PROJ_SRC_DIR)\uio.c $(PROJ_INCLUDE_DIR)\sys\uio.h makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(PROJ_SRC_DIR)\uio.c
$(OBJ_PROJ_unistd__DEBUG):	$(PROJ_SRC_DIR)\unistd.c $(PROJ_INCLUDE_DIR)\unistd.h makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(PROJ_SRC_DIR)\unistd.c
$(OBJ_PROJ_internal_util__DEBUG): $(PROJ_SRC_DIR)\internal\util.c $(PROJ_INCLUDE_DIR)\unixem\internal\util.h makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(PROJ_SRC_DIR)\internal\util.c



$(TARGET_LIB_UN_RELEASE): $(TARGET_LIB_RELEASE)
	@$(CP) $(TARGET_LIB_RELEASE) $@

$(TARGET_LIB_RELEASE): $(OBJ_PROJ_RELEASE) makefile
	@-if not exist $(B64_LIB_DIR)\NUL mkdir $(B64_LIB_DIR)
	$(AR) $(AR_ARGS) $@ $(OBJ_PROJ_RELEASE)

$(OBJ_PROJ_atomic__RELEASE):	$(PROJ_SRC_DIR)\atomic.c $(PROJ_INCLUDE_DIR)\asm\atomic.h makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(PROJ_SRC_DIR)\atomic.c
$(OBJ_PROJ_dirent__RELEASE):	$(PROJ_SRC_DIR)\dirent.c $(PROJ_INCLUDE_DIR)\dirent.h makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(PROJ_SRC_DIR)\dirent.c
$(OBJ_PROJ_dlfcn__RELEASE):	$(PROJ_SRC_DIR)\dlfcn.c $(PROJ_INCLUDE_DIR)\dlfcn.h makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(PROJ_SRC_DIR)\dlfcn.c
$(OBJ_PROJ_glob__RELEASE):	$(PROJ_SRC_DIR)\glob.c $(PROJ_INCLUDE_DIR)\glob.h makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(PROJ_SRC_DIR)\glob.c
$(OBJ_PROJ_hostname__RELEASE):	$(PROJ_SRC_DIR)\hostname.c $(PROJ_INCLUDE_DIR)\unistd.h makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(PROJ_SRC_DIR)\hostname.c
$(OBJ_PROJ_mmap__RELEASE):	$(PROJ_SRC_DIR)\mmap.c $(PROJ_INCLUDE_DIR)\sys\mman.h makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(PROJ_SRC_DIR)\mmap.c
$(OBJ_PROJ_resource__RELEASE):	$(PROJ_SRC_DIR)\resource.c $(PROJ_INCLUDE_DIR)\sys\resource.h makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(PROJ_SRC_DIR)\resource.c
$(OBJ_PROJ_setenv__RELEASE):	$(PROJ_SRC_DIR)\setenv.c $(PROJ_INCLUDE_DIR)\unixem\setenv.h makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(PROJ_SRC_DIR)\setenv.c
$(OBJ_PROJ_time__RELEASE):	$(PROJ_SRC_DIR)\time.c $(PROJ_INCLUDE_DIR)\sys\time.h makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(PROJ_SRC_DIR)\time.c
$(OBJ_PROJ_uio__RELEASE):	$(PROJ_SRC_DIR)\uio.c $(PROJ_INCLUDE_DIR)\sys\uio.h makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(PROJ_SRC_DIR)\uio.c
$(OBJ_PROJ_unistd__RELEASE):	$(PROJ_SRC_DIR)\unistd.c $(PROJ_INCLUDE_DIR)\unistd.h makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(PROJ_SRC_DIR)\unistd.c
$(OBJ_PROJ_internal_util__RELEASE): $(PROJ_SRC_DIR)\internal\util.c $(PROJ_INCLUDE_DIR)\unixem\internal\util.h makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(PROJ_SRC_DIR)\internal\util.c



############################################################################
