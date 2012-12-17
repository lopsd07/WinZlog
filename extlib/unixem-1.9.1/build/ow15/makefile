############################################################################
# File:		makefile
#
# Purpose:	Makefile for the UNIXem project, for the Open Watcom C/C++ 1.5
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

COMP_TAG            =   ow15
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

CC						=	wcc386
CPPC                    =   wpp386
AR						=	wlib
LD						=	wcl386
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

TARGET_LIB_ST_D	= 
TARGET_LIB_ST_R	= 

# #defines

COMMON_DEFS			=	-DWIN32

CUSTOM_DEFS			=

CC_CUSTOM_DEFS		=	$(CUSTOM_DEFS)

CPPC_CUSTOM_DEFS	=	$(CUSTOM_DEFS)

CC_DEFS 			=	$(COMMON_DEFS) $(CC_CUSTOM_DEFS)

CPPC_DEFS			=	$(COMMON_DEFS) $(CPPC_CUSTOM_DEFS)

# CC flags

CC_F_NOLOGO				=	-zq
CC_F_COMPILE_ONLY		=	
CC_F_WARNING_MAX		=	-w=9
CC_F_WARNING_ERR		=	-we
CC_F_WARNINGS_LIMIT		=	
CC_F_MINIMUM_SIZE		=	
#CC_F_MAXIMUM_SPEED		=	
CC_APP_F_WARNING_MAX	=	$(CC_F_WARNING_MAX)
CC_APP_F_WARNING_ERR	=	$(CC_F_WARNING_ERR)

# CPPC flags

CPPC_F_NOLOGO			=	-zq
CPPC_F_COMPILE_ONLY 	=	
CPPC_F_WARNING_MAX		=	-w=9
CPPC_F_WARNING_ERR		=	-we
CPPC_F_WARNINGS_LIMIT	=	
CPPC_F_MINIMUM_SIZE 	=	
#CPPC_F_MAXIMUM_SPEED	=	
CPPC_F_EXCEPTIONS		=	-xs
CPPC_F_NO_EXCEPTIONS	=	
CPPC_F_WITH_EXCEPTIONS	=	
CPPC_F_RTTI 			=	-xr
CPPC_APP_F_WARNING_MAX	=	$(CPPC_F_WARNING_MAX)
CPPC_APP_F_WARNING_ERR	=	$(CPPC_F_WARNING_ERR)



CC_TOOL_FLAGS		=	

CPPC_TOOL_FLAGS 	=



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

CC_ARGS_ST_D				=	 $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_ST_R				=	 $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)

AR_ARGS				=	-q -c

LD_ARGS				=	-zq $(COMMON_LIB)

############################################################################
# Targets

TARGET_LIB_ST_D			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG)$(OS_TAG)$(ARCH_TAG).debug.lib
TARGET_LIB_UN_ST_D		=	$(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG)$(OS_TAG)$(ARCH_TAG).debug.lib
TARGET_LIB_ST_R			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG)$(OS_TAG)$(ARCH_TAG).lib
TARGET_LIB_UN_ST_R		=	$(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG)$(OS_TAG)$(ARCH_TAG).lib



TARGETS = \
 $(TARGET_LIB_ST_D)\
 $(TARGET_LIB_UN_ST_D)\
 $(TARGET_LIB_ST_R)\
 $(TARGET_LIB_UN_ST_R)\
 \

OBJ_PROJ_atomic__ST_D = $(PROJ_OBJ_DIR)\atomic.debug.obj
OBJ_PROJ_dirent__ST_D = $(PROJ_OBJ_DIR)\dirent.debug.obj
OBJ_PROJ_dlfcn__ST_D = $(PROJ_OBJ_DIR)\dlfcn.debug.obj
OBJ_PROJ_glob__ST_D = $(PROJ_OBJ_DIR)\glob.debug.obj
OBJ_PROJ_hostname__ST_D = $(PROJ_OBJ_DIR)\hostname.debug.obj
OBJ_PROJ_mmap__ST_D = $(PROJ_OBJ_DIR)\mmap.debug.obj
OBJ_PROJ_resource__ST_D = $(PROJ_OBJ_DIR)\resource.debug.obj
OBJ_PROJ_setenv__ST_D = $(PROJ_OBJ_DIR)\setenv.debug.obj
OBJ_PROJ_time__ST_D = $(PROJ_OBJ_DIR)\time.debug.obj
OBJ_PROJ_uio__ST_D = $(PROJ_OBJ_DIR)\uio.debug.obj
OBJ_PROJ_unistd__ST_D = $(PROJ_OBJ_DIR)\unistd.debug.obj
OBJ_PROJ_internal_util__ST_D = $(PROJ_OBJ_DIR)\internal.util.debug.obj

OBJ_PROJ_ST_D = \
 $(OBJ_PROJ_atomic__ST_D)\
 $(OBJ_PROJ_dirent__ST_D)\
 $(OBJ_PROJ_dlfcn__ST_D)\
 $(OBJ_PROJ_glob__ST_D)\
 $(OBJ_PROJ_hostname__ST_D)\
 $(OBJ_PROJ_mmap__ST_D)\
 $(OBJ_PROJ_resource__ST_D)\
 $(OBJ_PROJ_setenv__ST_D)\
 $(OBJ_PROJ_time__ST_D)\
 $(OBJ_PROJ_uio__ST_D)\
 $(OBJ_PROJ_unistd__ST_D)\
 $(OBJ_PROJ_internal_util__ST_D)\
 \

OBJ_PROJ_ST_D_P = \
 +$(OBJ_PROJ_atomic__ST_D)\
 +$(OBJ_PROJ_dirent__ST_D)\
 +$(OBJ_PROJ_dlfcn__ST_D)\
 +$(OBJ_PROJ_glob__ST_D)\
 +$(OBJ_PROJ_hostname__ST_D)\
 +$(OBJ_PROJ_mmap__ST_D)\
 +$(OBJ_PROJ_resource__ST_D)\
 +$(OBJ_PROJ_setenv__ST_D)\
 +$(OBJ_PROJ_time__ST_D)\
 +$(OBJ_PROJ_uio__ST_D)\
 +$(OBJ_PROJ_unistd__ST_D)\
 +$(OBJ_PROJ_internal_util__ST_D)\
 \


OBJ_PROJ_atomic__ST_R = $(PROJ_OBJ_DIR)\atomic.obj
OBJ_PROJ_dirent__ST_R = $(PROJ_OBJ_DIR)\dirent.obj
OBJ_PROJ_dlfcn__ST_R = $(PROJ_OBJ_DIR)\dlfcn.obj
OBJ_PROJ_glob__ST_R = $(PROJ_OBJ_DIR)\glob.obj
OBJ_PROJ_hostname__ST_R = $(PROJ_OBJ_DIR)\hostname.obj
OBJ_PROJ_mmap__ST_R = $(PROJ_OBJ_DIR)\mmap.obj
OBJ_PROJ_resource__ST_R = $(PROJ_OBJ_DIR)\resource.obj
OBJ_PROJ_setenv__ST_R = $(PROJ_OBJ_DIR)\setenv.obj
OBJ_PROJ_time__ST_R = $(PROJ_OBJ_DIR)\time.obj
OBJ_PROJ_uio__ST_R = $(PROJ_OBJ_DIR)\uio.obj
OBJ_PROJ_unistd__ST_R = $(PROJ_OBJ_DIR)\unistd.obj
OBJ_PROJ_internal_util__ST_R = $(PROJ_OBJ_DIR)\internal.util.obj

OBJ_PROJ_ST_R = \
 $(OBJ_PROJ_atomic__ST_R)\
 $(OBJ_PROJ_dirent__ST_R)\
 $(OBJ_PROJ_dlfcn__ST_R)\
 $(OBJ_PROJ_glob__ST_R)\
 $(OBJ_PROJ_hostname__ST_R)\
 $(OBJ_PROJ_mmap__ST_R)\
 $(OBJ_PROJ_resource__ST_R)\
 $(OBJ_PROJ_setenv__ST_R)\
 $(OBJ_PROJ_time__ST_R)\
 $(OBJ_PROJ_uio__ST_R)\
 $(OBJ_PROJ_unistd__ST_R)\
 $(OBJ_PROJ_internal_util__ST_R)\
 \

OBJ_PROJ_ST_R_P = \
 +$(OBJ_PROJ_atomic__ST_R)\
 +$(OBJ_PROJ_dirent__ST_R)\
 +$(OBJ_PROJ_dlfcn__ST_R)\
 +$(OBJ_PROJ_glob__ST_R)\
 +$(OBJ_PROJ_hostname__ST_R)\
 +$(OBJ_PROJ_mmap__ST_R)\
 +$(OBJ_PROJ_resource__ST_R)\
 +$(OBJ_PROJ_setenv__ST_R)\
 +$(OBJ_PROJ_time__ST_R)\
 +$(OBJ_PROJ_uio__ST_R)\
 +$(OBJ_PROJ_unistd__ST_R)\
 +$(OBJ_PROJ_internal_util__ST_R)\
 \


OBJS = \
 $(OBJ_PROJ_ST_D)\
 $(OBJ_PROJ_ST_R)\
 \

all:	target

usage:
	@echo "make [usage | clean | all | test | target] - default is 'all'"

clean:
	@-$(RM) $(TARGET_LIB_ST_D)
	@-$(RM) $(TARGET_LIB_UN_ST_D)
	@-$(RM) $(TARGET_LIB_ST_R)
	@-$(RM) $(TARGET_LIB_UN_ST_R)
	@-$(RM) $(OBJ_PROJ_ST_D)
	@-$(RM) $(OBJ_PROJ_ST_R)


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
#	$(TARGET_TEST_C_ST_D) --unittest
#	$(TARGET_TEST_C_ST_R) --unittest

test:	target test_


# build targets

# library


$(TARGET_LIB_UN_ST_D): $(TARGET_LIB_ST_D)
	@$(CP) $(TARGET_LIB_ST_D) $@

$(TARGET_LIB_ST_D): $(OBJ_PROJ_ST_D) makefile
	@-if not exist $(B64_LIB_DIR)\NUL mkdir $(B64_LIB_DIR)
	@-$(RM) $(TARGET_LIB_ST_D)
	$(AR) $(AR_ARGS) $@ $(OBJ_PROJ_ST_D_P)

$(OBJ_PROJ_atomic__ST_D):	$(PROJ_SRC_DIR)\atomic.c $(PROJ_INCLUDE_DIR)\asm\atomic.h makefile
	$(CC) $(CC_ARGS_ST_D) -fo=$@ $(PROJ_SRC_DIR)\atomic.c
$(OBJ_PROJ_dirent__ST_D):	$(PROJ_SRC_DIR)\dirent.c $(PROJ_INCLUDE_DIR)\dirent.h makefile
	$(CC) $(CC_ARGS_ST_D) -fo=$@ $(PROJ_SRC_DIR)\dirent.c
$(OBJ_PROJ_dlfcn__ST_D):	$(PROJ_SRC_DIR)\dlfcn.c $(PROJ_INCLUDE_DIR)\dlfcn.h makefile
	$(CC) $(CC_ARGS_ST_D) -fo=$@ $(PROJ_SRC_DIR)\dlfcn.c
$(OBJ_PROJ_glob__ST_D):	$(PROJ_SRC_DIR)\glob.c $(PROJ_INCLUDE_DIR)\glob.h makefile
	$(CC) $(CC_ARGS_ST_D) -fo=$@ $(PROJ_SRC_DIR)\glob.c
$(OBJ_PROJ_hostname__ST_D):	$(PROJ_SRC_DIR)\hostname.c $(PROJ_INCLUDE_DIR)\unistd.h makefile
	$(CC) $(CC_ARGS_ST_D) -fo=$@ $(PROJ_SRC_DIR)\hostname.c
$(OBJ_PROJ_mmap__ST_D):	$(PROJ_SRC_DIR)\mmap.c $(PROJ_INCLUDE_DIR)\sys\mman.h makefile
	$(CC) $(CC_ARGS_ST_D) -fo=$@ $(PROJ_SRC_DIR)\mmap.c
$(OBJ_PROJ_resource__ST_D):	$(PROJ_SRC_DIR)\resource.c $(PROJ_INCLUDE_DIR)\sys\resource.h makefile
	$(CC) $(CC_ARGS_ST_D) -fo=$@ $(PROJ_SRC_DIR)\resource.c
$(OBJ_PROJ_setenv__ST_D):	$(PROJ_SRC_DIR)\setenv.c $(PROJ_INCLUDE_DIR)\unixem\setenv.h makefile
	$(CC) $(CC_ARGS_ST_D) -fo=$@ $(PROJ_SRC_DIR)\setenv.c
$(OBJ_PROJ_time__ST_D):	$(PROJ_SRC_DIR)\time.c $(PROJ_INCLUDE_DIR)\sys\time.h makefile
	$(CC) $(CC_ARGS_ST_D) -fo=$@ $(PROJ_SRC_DIR)\time.c
$(OBJ_PROJ_uio__ST_D):	$(PROJ_SRC_DIR)\uio.c $(PROJ_INCLUDE_DIR)\sys\uio.h makefile
	$(CC) $(CC_ARGS_ST_D) -fo=$@ $(PROJ_SRC_DIR)\uio.c
$(OBJ_PROJ_unistd__ST_D):	$(PROJ_SRC_DIR)\unistd.c $(PROJ_INCLUDE_DIR)\unistd.h makefile
	$(CC) $(CC_ARGS_ST_D) -fo=$@ $(PROJ_SRC_DIR)\unistd.c
$(OBJ_PROJ_internal_util__ST_D): $(PROJ_SRC_DIR)\internal\util.c $(PROJ_INCLUDE_DIR)\unixem\internal\util.h makefile
	$(CC) $(CC_ARGS_ST_D) -fo=$@ $(PROJ_SRC_DIR)\internal\util.c



$(TARGET_LIB_UN_ST_R): $(TARGET_LIB_ST_R)
	@$(CP) $(TARGET_LIB_ST_R) $@

$(TARGET_LIB_ST_R): $(OBJ_PROJ_ST_R) makefile
	@-if not exist $(B64_LIB_DIR)\NUL mkdir $(B64_LIB_DIR)
	@-$(RM) $(TARGET_LIB_ST_R)
	$(AR) $(AR_ARGS) $@ $(OBJ_PROJ_ST_R_P)

$(OBJ_PROJ_atomic__ST_R):	$(PROJ_SRC_DIR)\atomic.c $(PROJ_INCLUDE_DIR)\asm\atomic.h makefile
	$(CC) $(CC_ARGS_ST_R) -fo=$@ $(PROJ_SRC_DIR)\atomic.c
$(OBJ_PROJ_dirent__ST_R):	$(PROJ_SRC_DIR)\dirent.c $(PROJ_INCLUDE_DIR)\dirent.h makefile
	$(CC) $(CC_ARGS_ST_R) -fo=$@ $(PROJ_SRC_DIR)\dirent.c
$(OBJ_PROJ_dlfcn__ST_R):	$(PROJ_SRC_DIR)\dlfcn.c $(PROJ_INCLUDE_DIR)\dlfcn.h makefile
	$(CC) $(CC_ARGS_ST_R) -fo=$@ $(PROJ_SRC_DIR)\dlfcn.c
$(OBJ_PROJ_glob__ST_R):	$(PROJ_SRC_DIR)\glob.c $(PROJ_INCLUDE_DIR)\glob.h makefile
	$(CC) $(CC_ARGS_ST_R) -fo=$@ $(PROJ_SRC_DIR)\glob.c
$(OBJ_PROJ_hostname__ST_R):	$(PROJ_SRC_DIR)\hostname.c $(PROJ_INCLUDE_DIR)\unistd.h makefile
	$(CC) $(CC_ARGS_ST_R) -fo=$@ $(PROJ_SRC_DIR)\hostname.c
$(OBJ_PROJ_mmap__ST_R):	$(PROJ_SRC_DIR)\mmap.c $(PROJ_INCLUDE_DIR)\sys\mman.h makefile
	$(CC) $(CC_ARGS_ST_R) -fo=$@ $(PROJ_SRC_DIR)\mmap.c
$(OBJ_PROJ_resource__ST_R):	$(PROJ_SRC_DIR)\resource.c $(PROJ_INCLUDE_DIR)\sys\resource.h makefile
	$(CC) $(CC_ARGS_ST_R) -fo=$@ $(PROJ_SRC_DIR)\resource.c
$(OBJ_PROJ_setenv__ST_R):	$(PROJ_SRC_DIR)\setenv.c $(PROJ_INCLUDE_DIR)\unixem\setenv.h makefile
	$(CC) $(CC_ARGS_ST_R) -fo=$@ $(PROJ_SRC_DIR)\setenv.c
$(OBJ_PROJ_time__ST_R):	$(PROJ_SRC_DIR)\time.c $(PROJ_INCLUDE_DIR)\sys\time.h makefile
	$(CC) $(CC_ARGS_ST_R) -fo=$@ $(PROJ_SRC_DIR)\time.c
$(OBJ_PROJ_uio__ST_R):	$(PROJ_SRC_DIR)\uio.c $(PROJ_INCLUDE_DIR)\sys\uio.h makefile
	$(CC) $(CC_ARGS_ST_R) -fo=$@ $(PROJ_SRC_DIR)\uio.c
$(OBJ_PROJ_unistd__ST_R):	$(PROJ_SRC_DIR)\unistd.c $(PROJ_INCLUDE_DIR)\unistd.h makefile
	$(CC) $(CC_ARGS_ST_R) -fo=$@ $(PROJ_SRC_DIR)\unistd.c
$(OBJ_PROJ_internal_util__ST_R): $(PROJ_SRC_DIR)\internal\util.c $(PROJ_INCLUDE_DIR)\unixem\internal\util.h makefile
	$(CC) $(CC_ARGS_ST_R) -fo=$@ $(PROJ_SRC_DIR)\internal\util.c



############################################################################
