############################################################################
# File:		makefile
#
# Purpose:	Makefile for the UNIXem project, for the Intel C/C++ Compiler v10.0
#           compiler, on Win32
#
# Created:	15th Feburary 2005
# Updated:	12th August 2010
#
############################################################################


############################################################################
# Environment check
#


############################################################################
# Symbols

########################################
# Project & compiler version

COMP_TAG            =   icl10
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

CC						=	icl
CPPC                    =   icl
AR						=	xilib
LD						=	xilink
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

TARGET_LIB_MT_D	= 
TARGET_LIB_DLL_D	= 
TARGET_LIB_DLL_R	= 
TARGET_LIB_MT_R	= 

# #defines

COMMON_DEFS			=	-DWIN32

CUSTOM_DEFS			=

CC_CUSTOM_DEFS		=	$(CUSTOM_DEFS)

CPPC_CUSTOM_DEFS	=	$(CUSTOM_DEFS)

CC_DEFS 			=	$(COMMON_DEFS) $(CC_CUSTOM_DEFS)

CPPC_DEFS			=	$(COMMON_DEFS) $(CPPC_CUSTOM_DEFS)

# CC flags

CC_F_NOLOGO				=	-nologo
CC_F_COMPILE_ONLY		=	-c
CC_F_WARNING_MAX		=	-W4
CC_F_WARNING_ERR		=	-W3  -Qwd193 -Qwd279
CC_F_WARNINGS_LIMIT		=	
CC_F_MINIMUM_SIZE		=	
#CC_F_MAXIMUM_SPEED		=	
CC_APP_F_WARNING_MAX	=	$(CC_F_WARNING_MAX)
CC_APP_F_WARNING_ERR	=	$(CC_F_WARNING_ERR)

# CPPC flags

CPPC_F_NOLOGO			=	-nologo
CPPC_F_COMPILE_ONLY 	=	-c
CPPC_F_WARNING_MAX		=	-W3 -Qwd171 -Qwd193 -Qwd279 -Qwd383
CPPC_F_WARNING_ERR		=	-WX
CPPC_F_WARNINGS_LIMIT	=	
CPPC_F_MINIMUM_SIZE 	=	
#CPPC_F_MAXIMUM_SPEED	=	
CPPC_F_EXCEPTIONS		=	-GX
CPPC_F_NO_EXCEPTIONS	=	
CPPC_F_WITH_EXCEPTIONS	=	
CPPC_F_RTTI 			=	-GR
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

CC_ARGS_MT_D				=	-MTd -D_DEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_DLL_D				=	-MDd -D_DEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_DLL_R				=	-MD -DNDEBUG -O1 $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_MT_R				=	-MT -DNDEBUG -O1 $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)

AR_ARGS				=	-nologo

LD_ARGS				=	-nologo $(COMMON_LIB)

############################################################################
# Targets

TARGET_LIB_MT_D			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG)$(OS_TAG)$(ARCH_TAG).mt.debug.lib
TARGET_LIB_UN_MT_D		=	$(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG)$(OS_TAG)$(ARCH_TAG).mt.debug.lib
TARGET_LIB_DLL_D			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG)$(OS_TAG)$(ARCH_TAG).dll.debug.lib
TARGET_LIB_UN_DLL_D		=	$(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG)$(OS_TAG)$(ARCH_TAG).dll.debug.lib
TARGET_LIB_DLL_R			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG)$(OS_TAG)$(ARCH_TAG).dll.lib
TARGET_LIB_UN_DLL_R		=	$(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG)$(OS_TAG)$(ARCH_TAG).dll.lib
TARGET_LIB_MT_R			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG)$(OS_TAG)$(ARCH_TAG).mt.lib
TARGET_LIB_UN_MT_R		=	$(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG)$(OS_TAG)$(ARCH_TAG).mt.lib



TARGETS = \
 $(TARGET_LIB_MT_D)\
 $(TARGET_LIB_UN_MT_D)\
 $(TARGET_LIB_DLL_D)\
 $(TARGET_LIB_UN_DLL_D)\
 $(TARGET_LIB_DLL_R)\
 $(TARGET_LIB_UN_DLL_R)\
 $(TARGET_LIB_MT_R)\
 $(TARGET_LIB_UN_MT_R)\
 \

OBJ_PROJ_atomic__MT_D = $(PROJ_OBJ_DIR)\atomic.mt.debug.obj
OBJ_PROJ_dirent__MT_D = $(PROJ_OBJ_DIR)\dirent.mt.debug.obj
OBJ_PROJ_dlfcn__MT_D = $(PROJ_OBJ_DIR)\dlfcn.mt.debug.obj
OBJ_PROJ_glob__MT_D = $(PROJ_OBJ_DIR)\glob.mt.debug.obj
OBJ_PROJ_hostname__MT_D = $(PROJ_OBJ_DIR)\hostname.mt.debug.obj
OBJ_PROJ_mmap__MT_D = $(PROJ_OBJ_DIR)\mmap.mt.debug.obj
OBJ_PROJ_resource__MT_D = $(PROJ_OBJ_DIR)\resource.mt.debug.obj
OBJ_PROJ_setenv__MT_D = $(PROJ_OBJ_DIR)\setenv.mt.debug.obj
OBJ_PROJ_time__MT_D = $(PROJ_OBJ_DIR)\time.mt.debug.obj
OBJ_PROJ_uio__MT_D = $(PROJ_OBJ_DIR)\uio.mt.debug.obj
OBJ_PROJ_unistd__MT_D = $(PROJ_OBJ_DIR)\unistd.mt.debug.obj
OBJ_PROJ_internal_util__MT_D = $(PROJ_OBJ_DIR)\internal.util.mt.debug.obj

OBJ_PROJ_MT_D = \
 $(OBJ_PROJ_atomic__MT_D)\
 $(OBJ_PROJ_dirent__MT_D)\
 $(OBJ_PROJ_dlfcn__MT_D)\
 $(OBJ_PROJ_glob__MT_D)\
 $(OBJ_PROJ_hostname__MT_D)\
 $(OBJ_PROJ_mmap__MT_D)\
 $(OBJ_PROJ_resource__MT_D)\
 $(OBJ_PROJ_setenv__MT_D)\
 $(OBJ_PROJ_time__MT_D)\
 $(OBJ_PROJ_uio__MT_D)\
 $(OBJ_PROJ_unistd__MT_D)\
 $(OBJ_PROJ_internal_util__MT_D)\
 \

OBJ_PROJ_atomic__DLL_D = $(PROJ_OBJ_DIR)\atomic.dll.debug.obj
OBJ_PROJ_dirent__DLL_D = $(PROJ_OBJ_DIR)\dirent.dll.debug.obj
OBJ_PROJ_dlfcn__DLL_D = $(PROJ_OBJ_DIR)\dlfcn.dll.debug.obj
OBJ_PROJ_glob__DLL_D = $(PROJ_OBJ_DIR)\glob.dll.debug.obj
OBJ_PROJ_hostname__DLL_D = $(PROJ_OBJ_DIR)\hostname.dll.debug.obj
OBJ_PROJ_mmap__DLL_D = $(PROJ_OBJ_DIR)\mmap.dll.debug.obj
OBJ_PROJ_resource__DLL_D = $(PROJ_OBJ_DIR)\resource.dll.debug.obj
OBJ_PROJ_setenv__DLL_D = $(PROJ_OBJ_DIR)\setenv.dll.debug.obj
OBJ_PROJ_time__DLL_D = $(PROJ_OBJ_DIR)\time.dll.debug.obj
OBJ_PROJ_uio__DLL_D = $(PROJ_OBJ_DIR)\uio.dll.debug.obj
OBJ_PROJ_unistd__DLL_D = $(PROJ_OBJ_DIR)\unistd.dll.debug.obj
OBJ_PROJ_internal_util__DLL_D = $(PROJ_OBJ_DIR)\internal.util.dll.debug.obj

OBJ_PROJ_DLL_D = \
 $(OBJ_PROJ_atomic__DLL_D)\
 $(OBJ_PROJ_dirent__DLL_D)\
 $(OBJ_PROJ_dlfcn__DLL_D)\
 $(OBJ_PROJ_glob__DLL_D)\
 $(OBJ_PROJ_hostname__DLL_D)\
 $(OBJ_PROJ_mmap__DLL_D)\
 $(OBJ_PROJ_resource__DLL_D)\
 $(OBJ_PROJ_setenv__DLL_D)\
 $(OBJ_PROJ_time__DLL_D)\
 $(OBJ_PROJ_uio__DLL_D)\
 $(OBJ_PROJ_unistd__DLL_D)\
 $(OBJ_PROJ_internal_util__DLL_D)\
 \

OBJ_PROJ_atomic__DLL_R = $(PROJ_OBJ_DIR)\atomic.dll.obj
OBJ_PROJ_dirent__DLL_R = $(PROJ_OBJ_DIR)\dirent.dll.obj
OBJ_PROJ_dlfcn__DLL_R = $(PROJ_OBJ_DIR)\dlfcn.dll.obj
OBJ_PROJ_glob__DLL_R = $(PROJ_OBJ_DIR)\glob.dll.obj
OBJ_PROJ_hostname__DLL_R = $(PROJ_OBJ_DIR)\hostname.dll.obj
OBJ_PROJ_mmap__DLL_R = $(PROJ_OBJ_DIR)\mmap.dll.obj
OBJ_PROJ_resource__DLL_R = $(PROJ_OBJ_DIR)\resource.dll.obj
OBJ_PROJ_setenv__DLL_R = $(PROJ_OBJ_DIR)\setenv.dll.obj
OBJ_PROJ_time__DLL_R = $(PROJ_OBJ_DIR)\time.dll.obj
OBJ_PROJ_uio__DLL_R = $(PROJ_OBJ_DIR)\uio.dll.obj
OBJ_PROJ_unistd__DLL_R = $(PROJ_OBJ_DIR)\unistd.dll.obj
OBJ_PROJ_internal_util__DLL_R = $(PROJ_OBJ_DIR)\internal.util.dll.obj

OBJ_PROJ_DLL_R = \
 $(OBJ_PROJ_atomic__DLL_R)\
 $(OBJ_PROJ_dirent__DLL_R)\
 $(OBJ_PROJ_dlfcn__DLL_R)\
 $(OBJ_PROJ_glob__DLL_R)\
 $(OBJ_PROJ_hostname__DLL_R)\
 $(OBJ_PROJ_mmap__DLL_R)\
 $(OBJ_PROJ_resource__DLL_R)\
 $(OBJ_PROJ_setenv__DLL_R)\
 $(OBJ_PROJ_time__DLL_R)\
 $(OBJ_PROJ_uio__DLL_R)\
 $(OBJ_PROJ_unistd__DLL_R)\
 $(OBJ_PROJ_internal_util__DLL_R)\
 \

OBJ_PROJ_atomic__MT_R = $(PROJ_OBJ_DIR)\atomic.mt.obj
OBJ_PROJ_dirent__MT_R = $(PROJ_OBJ_DIR)\dirent.mt.obj
OBJ_PROJ_dlfcn__MT_R = $(PROJ_OBJ_DIR)\dlfcn.mt.obj
OBJ_PROJ_glob__MT_R = $(PROJ_OBJ_DIR)\glob.mt.obj
OBJ_PROJ_hostname__MT_R = $(PROJ_OBJ_DIR)\hostname.mt.obj
OBJ_PROJ_mmap__MT_R = $(PROJ_OBJ_DIR)\mmap.mt.obj
OBJ_PROJ_resource__MT_R = $(PROJ_OBJ_DIR)\resource.mt.obj
OBJ_PROJ_setenv__MT_R = $(PROJ_OBJ_DIR)\setenv.mt.obj
OBJ_PROJ_time__MT_R = $(PROJ_OBJ_DIR)\time.mt.obj
OBJ_PROJ_uio__MT_R = $(PROJ_OBJ_DIR)\uio.mt.obj
OBJ_PROJ_unistd__MT_R = $(PROJ_OBJ_DIR)\unistd.mt.obj
OBJ_PROJ_internal_util__MT_R = $(PROJ_OBJ_DIR)\internal.util.mt.obj

OBJ_PROJ_MT_R = \
 $(OBJ_PROJ_atomic__MT_R)\
 $(OBJ_PROJ_dirent__MT_R)\
 $(OBJ_PROJ_dlfcn__MT_R)\
 $(OBJ_PROJ_glob__MT_R)\
 $(OBJ_PROJ_hostname__MT_R)\
 $(OBJ_PROJ_mmap__MT_R)\
 $(OBJ_PROJ_resource__MT_R)\
 $(OBJ_PROJ_setenv__MT_R)\
 $(OBJ_PROJ_time__MT_R)\
 $(OBJ_PROJ_uio__MT_R)\
 $(OBJ_PROJ_unistd__MT_R)\
 $(OBJ_PROJ_internal_util__MT_R)\
 \

OBJS = \
 $(OBJ_PROJ_MT_D)\
 $(OBJ_PROJ_DLL_D)\
 $(OBJ_PROJ_DLL_R)\
 $(OBJ_PROJ_MT_R)\
 \

all:	target

usage:
	@echo "make [usage | clean | all | test | target] - default is 'all'"

clean:
	@-$(RM) $(TARGET_LIB_MT_D)
	@-$(RM) $(TARGET_LIB_UN_MT_D)
	@-$(RM) $(TARGET_LIB_DLL_D)
	@-$(RM) $(TARGET_LIB_UN_DLL_D)
	@-$(RM) $(TARGET_LIB_DLL_R)
	@-$(RM) $(TARGET_LIB_UN_DLL_R)
	@-$(RM) $(TARGET_LIB_MT_R)
	@-$(RM) $(TARGET_LIB_UN_MT_R)
	@-$(RM) $(OBJ_PROJ_MT_D)
	@-$(RM) $(OBJ_PROJ_DLL_D)
	@-$(RM) $(OBJ_PROJ_DLL_R)
	@-$(RM) $(OBJ_PROJ_MT_R)


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
#	$(TARGET_TEST_C_MT_D) --unittest
#	$(TARGET_TEST_C_DLL_D) --unittest
#	$(TARGET_TEST_C_DLL_R) --unittest
#	$(TARGET_TEST_C_MT_R) --unittest

test:	target test_


# build targets

# library


$(TARGET_LIB_UN_MT_D): $(TARGET_LIB_MT_D)
	@$(CP) $(TARGET_LIB_MT_D) $@

$(TARGET_LIB_MT_D): $(OBJ_PROJ_MT_D) makefile
	@-if not exist $(B64_LIB_DIR)\NUL mkdir $(B64_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_PROJ_MT_D)

$(OBJ_PROJ_atomic__MT_D):	$(PROJ_SRC_DIR)\atomic.c $(PROJ_INCLUDE_DIR)\asm\atomic.h makefile
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\atomic.c
$(OBJ_PROJ_dirent__MT_D):	$(PROJ_SRC_DIR)\dirent.c $(PROJ_INCLUDE_DIR)\dirent.h makefile
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\dirent.c
$(OBJ_PROJ_dlfcn__MT_D):	$(PROJ_SRC_DIR)\dlfcn.c $(PROJ_INCLUDE_DIR)\dlfcn.h makefile
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\dlfcn.c
$(OBJ_PROJ_glob__MT_D):	$(PROJ_SRC_DIR)\glob.c $(PROJ_INCLUDE_DIR)\glob.h makefile
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\glob.c
$(OBJ_PROJ_hostname__MT_D):	$(PROJ_SRC_DIR)\hostname.c $(PROJ_INCLUDE_DIR)\unistd.h makefile
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\hostname.c
$(OBJ_PROJ_mmap__MT_D):	$(PROJ_SRC_DIR)\mmap.c $(PROJ_INCLUDE_DIR)\sys\mman.h makefile
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\mmap.c
$(OBJ_PROJ_resource__MT_D):	$(PROJ_SRC_DIR)\resource.c $(PROJ_INCLUDE_DIR)\sys\resource.h makefile
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\resource.c
$(OBJ_PROJ_setenv__MT_D):	$(PROJ_SRC_DIR)\setenv.c $(PROJ_INCLUDE_DIR)\unixem\setenv.h makefile
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\setenv.c
$(OBJ_PROJ_time__MT_D):	$(PROJ_SRC_DIR)\time.c $(PROJ_INCLUDE_DIR)\sys\time.h makefile
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\time.c
$(OBJ_PROJ_uio__MT_D):	$(PROJ_SRC_DIR)\uio.c $(PROJ_INCLUDE_DIR)\sys\uio.h makefile
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\uio.c
$(OBJ_PROJ_unistd__MT_D):	$(PROJ_SRC_DIR)\unistd.c $(PROJ_INCLUDE_DIR)\unistd.h makefile
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\unistd.c
$(OBJ_PROJ_internal_util__MT_D): $(PROJ_SRC_DIR)\internal\util.c $(PROJ_INCLUDE_DIR)\unixem\internal\util.h makefile
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\internal\util.c



$(TARGET_LIB_UN_DLL_D): $(TARGET_LIB_DLL_D)
	@$(CP) $(TARGET_LIB_DLL_D) $@

$(TARGET_LIB_DLL_D): $(OBJ_PROJ_DLL_D) makefile
	@-if not exist $(B64_LIB_DIR)\NUL mkdir $(B64_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_PROJ_DLL_D)

$(OBJ_PROJ_atomic__DLL_D):	$(PROJ_SRC_DIR)\atomic.c $(PROJ_INCLUDE_DIR)\asm\atomic.h makefile
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\atomic.c
$(OBJ_PROJ_dirent__DLL_D):	$(PROJ_SRC_DIR)\dirent.c $(PROJ_INCLUDE_DIR)\dirent.h makefile
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\dirent.c
$(OBJ_PROJ_dlfcn__DLL_D):	$(PROJ_SRC_DIR)\dlfcn.c $(PROJ_INCLUDE_DIR)\dlfcn.h makefile
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\dlfcn.c
$(OBJ_PROJ_glob__DLL_D):	$(PROJ_SRC_DIR)\glob.c $(PROJ_INCLUDE_DIR)\glob.h makefile
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\glob.c
$(OBJ_PROJ_hostname__DLL_D):	$(PROJ_SRC_DIR)\hostname.c $(PROJ_INCLUDE_DIR)\unistd.h makefile
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\hostname.c
$(OBJ_PROJ_mmap__DLL_D):	$(PROJ_SRC_DIR)\mmap.c $(PROJ_INCLUDE_DIR)\sys\mman.h makefile
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\mmap.c
$(OBJ_PROJ_resource__DLL_D):	$(PROJ_SRC_DIR)\resource.c $(PROJ_INCLUDE_DIR)\sys\resource.h makefile
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\resource.c
$(OBJ_PROJ_setenv__DLL_D):	$(PROJ_SRC_DIR)\setenv.c $(PROJ_INCLUDE_DIR)\unixem\setenv.h makefile
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\setenv.c
$(OBJ_PROJ_time__DLL_D):	$(PROJ_SRC_DIR)\time.c $(PROJ_INCLUDE_DIR)\sys\time.h makefile
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\time.c
$(OBJ_PROJ_uio__DLL_D):	$(PROJ_SRC_DIR)\uio.c $(PROJ_INCLUDE_DIR)\sys\uio.h makefile
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\uio.c
$(OBJ_PROJ_unistd__DLL_D):	$(PROJ_SRC_DIR)\unistd.c $(PROJ_INCLUDE_DIR)\unistd.h makefile
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\unistd.c
$(OBJ_PROJ_internal_util__DLL_D): $(PROJ_SRC_DIR)\internal\util.c $(PROJ_INCLUDE_DIR)\unixem\internal\util.h makefile
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\internal\util.c



$(TARGET_LIB_UN_DLL_R): $(TARGET_LIB_DLL_R)
	@$(CP) $(TARGET_LIB_DLL_R) $@

$(TARGET_LIB_DLL_R): $(OBJ_PROJ_DLL_R) makefile
	@-if not exist $(B64_LIB_DIR)\NUL mkdir $(B64_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_PROJ_DLL_R)

$(OBJ_PROJ_atomic__DLL_R):	$(PROJ_SRC_DIR)\atomic.c $(PROJ_INCLUDE_DIR)\asm\atomic.h makefile
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\atomic.c
$(OBJ_PROJ_dirent__DLL_R):	$(PROJ_SRC_DIR)\dirent.c $(PROJ_INCLUDE_DIR)\dirent.h makefile
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\dirent.c
$(OBJ_PROJ_dlfcn__DLL_R):	$(PROJ_SRC_DIR)\dlfcn.c $(PROJ_INCLUDE_DIR)\dlfcn.h makefile
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\dlfcn.c
$(OBJ_PROJ_glob__DLL_R):	$(PROJ_SRC_DIR)\glob.c $(PROJ_INCLUDE_DIR)\glob.h makefile
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\glob.c
$(OBJ_PROJ_hostname__DLL_R):	$(PROJ_SRC_DIR)\hostname.c $(PROJ_INCLUDE_DIR)\unistd.h makefile
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\hostname.c
$(OBJ_PROJ_mmap__DLL_R):	$(PROJ_SRC_DIR)\mmap.c $(PROJ_INCLUDE_DIR)\sys\mman.h makefile
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\mmap.c
$(OBJ_PROJ_resource__DLL_R):	$(PROJ_SRC_DIR)\resource.c $(PROJ_INCLUDE_DIR)\sys\resource.h makefile
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\resource.c
$(OBJ_PROJ_setenv__DLL_R):	$(PROJ_SRC_DIR)\setenv.c $(PROJ_INCLUDE_DIR)\unixem\setenv.h makefile
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\setenv.c
$(OBJ_PROJ_time__DLL_R):	$(PROJ_SRC_DIR)\time.c $(PROJ_INCLUDE_DIR)\sys\time.h makefile
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\time.c
$(OBJ_PROJ_uio__DLL_R):	$(PROJ_SRC_DIR)\uio.c $(PROJ_INCLUDE_DIR)\sys\uio.h makefile
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\uio.c
$(OBJ_PROJ_unistd__DLL_R):	$(PROJ_SRC_DIR)\unistd.c $(PROJ_INCLUDE_DIR)\unistd.h makefile
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\unistd.c
$(OBJ_PROJ_internal_util__DLL_R): $(PROJ_SRC_DIR)\internal\util.c $(PROJ_INCLUDE_DIR)\unixem\internal\util.h makefile
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\internal\util.c



$(TARGET_LIB_UN_MT_R): $(TARGET_LIB_MT_R)
	@$(CP) $(TARGET_LIB_MT_R) $@

$(TARGET_LIB_MT_R): $(OBJ_PROJ_MT_R) makefile
	@-if not exist $(B64_LIB_DIR)\NUL mkdir $(B64_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_PROJ_MT_R)

$(OBJ_PROJ_atomic__MT_R):	$(PROJ_SRC_DIR)\atomic.c $(PROJ_INCLUDE_DIR)\asm\atomic.h makefile
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\atomic.c
$(OBJ_PROJ_dirent__MT_R):	$(PROJ_SRC_DIR)\dirent.c $(PROJ_INCLUDE_DIR)\dirent.h makefile
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\dirent.c
$(OBJ_PROJ_dlfcn__MT_R):	$(PROJ_SRC_DIR)\dlfcn.c $(PROJ_INCLUDE_DIR)\dlfcn.h makefile
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\dlfcn.c
$(OBJ_PROJ_glob__MT_R):	$(PROJ_SRC_DIR)\glob.c $(PROJ_INCLUDE_DIR)\glob.h makefile
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\glob.c
$(OBJ_PROJ_hostname__MT_R):	$(PROJ_SRC_DIR)\hostname.c $(PROJ_INCLUDE_DIR)\unistd.h makefile
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\hostname.c
$(OBJ_PROJ_mmap__MT_R):	$(PROJ_SRC_DIR)\mmap.c $(PROJ_INCLUDE_DIR)\sys\mman.h makefile
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\mmap.c
$(OBJ_PROJ_resource__MT_R):	$(PROJ_SRC_DIR)\resource.c $(PROJ_INCLUDE_DIR)\sys\resource.h makefile
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\resource.c
$(OBJ_PROJ_setenv__MT_R):	$(PROJ_SRC_DIR)\setenv.c $(PROJ_INCLUDE_DIR)\unixem\setenv.h makefile
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\setenv.c
$(OBJ_PROJ_time__MT_R):	$(PROJ_SRC_DIR)\time.c $(PROJ_INCLUDE_DIR)\sys\time.h makefile
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\time.c
$(OBJ_PROJ_uio__MT_R):	$(PROJ_SRC_DIR)\uio.c $(PROJ_INCLUDE_DIR)\sys\uio.h makefile
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\uio.c
$(OBJ_PROJ_unistd__MT_R):	$(PROJ_SRC_DIR)\unistd.c $(PROJ_INCLUDE_DIR)\unistd.h makefile
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\unistd.c
$(OBJ_PROJ_internal_util__MT_R): $(PROJ_SRC_DIR)\internal\util.c $(PROJ_INCLUDE_DIR)\unixem\internal\util.h makefile
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\internal\util.c



############################################################################
