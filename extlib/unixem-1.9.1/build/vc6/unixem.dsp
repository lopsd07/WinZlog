# Microsoft Developer Studio Project File - Name="unixem" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=unixem - Win32 Debug Multithreaded pseudoUNIX
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "unixem.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "unixem.mak" CFG="unixem - Win32 Debug Multithreaded pseudoUNIX"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "unixem - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "unixem - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "unixem - Win32 Debug pseudoUNIX" (based on "Win32 (x86) Static Library")
!MESSAGE "unixem - Win32 Release pseudoUNIX" (based on "Win32 (x86) Static Library")
!MESSAGE "unixem - Win32 Debug Multithreaded pseudoUNIX" (based on "Win32 (x86) Static Library")
!MESSAGE "unixem - Win32 Release Multithreaded pseudoUNIX" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "unixem - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O1 /I "..\..\include" /D "NDEBUG" /D "UNIX" /D "unix" /D "_WIN32" /D "_WINDOWS" /YX /FD /c
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\..\lib\unixem.1.vc6.lib"

!ELSEIF  "$(CFG)" == "unixem - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /I "..\..\include" /D "_DEBUG" /D "UNIX" /D "unix" /D "_WIN32" /D "_WINDOWS" /FR /YX /FD /GZ /c
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\..\lib\unixem.1.vc6.debug.lib"

!ELSEIF  "$(CFG)" == "unixem - Win32 Debug pseudoUNIX"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugUNIX"
# PROP BASE Intermediate_Dir "DebugUNIX"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugUNIX"
# PROP Intermediate_Dir "DebugUNIX"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /I "..\..\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /I "..\..\include" /D "_DEBUG" /D "UNIX" /D "unix" /D "_WIN32" /D "_WINDOWS" /YX /FD /GZ /c
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\unixem.vc6.debug.lib"
# ADD LIB32 /nologo /out:"..\..\lib\unixem.1.vc6.unix.debug.lib"

!ELSEIF  "$(CFG)" == "unixem - Win32 Release pseudoUNIX"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseUNIX"
# PROP BASE Intermediate_Dir "ReleaseUNIX"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseUNIX"
# PROP Intermediate_Dir "ReleaseUNIX"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O1 /I "..\..\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O1 /I "..\..\include" /D "NDEBUG" /D "UNIX" /D "unix" /D "_WIN32" /D "_WINDOWS" /YX /FD /c
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\unixem.vc6.lib"
# ADD LIB32 /nologo /out:"..\..\lib\unixem.1.vc6.unix.lib"

!ELSEIF  "$(CFG)" == "unixem - Win32 Debug Multithreaded pseudoUNIX"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugMTUNIX"
# PROP BASE Intermediate_Dir "DebugMTUNIX"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugMTUNIX"
# PROP Intermediate_Dir "DebugMTUNIX"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /I "..\..\include" /D "_DEBUG" /D "UNIX" /D "unix" /D "_WIN32" /D "_WINDOWS" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /I "..\..\include" /D "_DEBUG" /D "UNIX" /D "unix" /D "_WIN32" /D "_WINDOWS" /FR /YX /FD /GZ /c
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\unixem.1.vc6.debug.lib"
# ADD LIB32 /nologo /out:"..\..\lib\unixem.1.vc6.unix.mt.debug.lib"

!ELSEIF  "$(CFG)" == "unixem - Win32 Release Multithreaded pseudoUNIX"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseMTUNIX"
# PROP BASE Intermediate_Dir "ReleaseMTUNIX"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMTUNIX"
# PROP Intermediate_Dir "ReleaseMTUNIX"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O1 /I "..\..\include" /D "NDEBUG" /D "UNIX" /D "unix" /D "_WIN32" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O1 /I "..\..\include" /D "NDEBUG" /D "UNIX" /D "unix" /D "_WIN32" /D "_WINDOWS" /FR /YX /FD /c
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\unixem.1.vc6.lib"
# ADD LIB32 /nologo /out:"..\..\lib\unixem.1.vc6.unix.mt.lib"

!ENDIF 

# Begin Target

# Name "unixem - Win32 Release"
# Name "unixem - Win32 Debug"
# Name "unixem - Win32 Debug pseudoUNIX"
# Name "unixem - Win32 Release pseudoUNIX"
# Name "unixem - Win32 Debug Multithreaded pseudoUNIX"
# Name "unixem - Win32 Release Multithreaded pseudoUNIX"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "Supporting / Additional Source"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\ex\mmap_ex.c
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\src\atomic.c
# End Source File
# Begin Source File

SOURCE=..\..\src\dirent.c
# End Source File
# Begin Source File

SOURCE=..\..\src\dlfcn.c
# End Source File
# Begin Source File

SOURCE=..\..\src\glob.c
# End Source File
# Begin Source File

SOURCE=..\..\src\hostname.c
# End Source File
# Begin Source File

SOURCE=..\..\src\mmap.c
# End Source File
# Begin Source File

SOURCE=..\..\src\resource.c
# End Source File
# Begin Source File

SOURCE=..\..\src\setenv.c
# End Source File
# Begin Source File

SOURCE=..\..\src\time.c
# End Source File
# Begin Source File

SOURCE=..\..\src\uio.c
# End Source File
# Begin Source File

SOURCE=..\..\src\unistd.c
# End Source File
# Begin Source File

SOURCE=..\..\src\internal\util.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "UNIXem API Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\include\unixem\asm\atomic.h
# End Source File
# Begin Source File

SOURCE=..\..\include\unixem\dirent.h
# End Source File
# Begin Source File

SOURCE=..\..\include\unixem\dlfcn.h
# End Source File
# Begin Source File

SOURCE=..\..\include\unixem\glob.h
# End Source File
# Begin Source File

SOURCE=..\..\include\unixem\sys\mman.h
# End Source File
# Begin Source File

SOURCE=..\..\include\unixem\sys\resource.h
# End Source File
# Begin Source File

SOURCE=..\..\include\unixem\internal\safestr.h
# End Source File
# Begin Source File

SOURCE=..\..\include\unixem\setenv.h
# End Source File
# Begin Source File

SOURCE=..\..\include\unixem\sys\uio.h
# End Source File
# Begin Source File

SOURCE=..\..\include\unixem\unistd.h
# End Source File
# Begin Source File

SOURCE=..\..\include\unixem\unixem.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\include\sys\mman.h
# End Source File
# Begin Source File

SOURCE=..\..\include\unistd.h
# End Source File
# End Group
# Begin Group "Distribution Files"

# PROP Default_Filter "txt"
# Begin Source File

SOURCE="..\..\_internal\dist-src\AUTHORS.txt"
# End Source File
# Begin Source File

SOURCE="..\..\_internal\dist-src\CHANGES.txt"
# End Source File
# Begin Source File

SOURCE="..\..\_internal\dist-src\FAQ.txt"
# End Source File
# Begin Source File

SOURCE="..\..\_internal\dist-src\HISTORY.txt"
# End Source File
# Begin Source File

SOURCE="..\..\_internal\dist-src\INSTALL.txt"
# End Source File
# Begin Source File

SOURCE="..\..\_internal\dist-src\KNOWN_ISSUES.txt"
# End Source File
# Begin Source File

SOURCE="..\..\_internal\dist-src\LICENSE.txt"
# End Source File
# Begin Source File

SOURCE="..\..\_internal\dist-src\NEWS.txt"
# End Source File
# Begin Source File

SOURCE="..\..\_internal\dist-src\README.txt"
# End Source File
# Begin Source File

SOURCE="..\..\_internal\dist-src\TODO.txt"
# End Source File
# End Group
# End Target
# End Project
