#------------------------ Tool Specifications & Options ----------------------

COMPILER  =  lcc

CC        =  "C:\Program Files\MATLAB\R2023b\sys\lcc64\lcc64\bin\lcc64.exe"
LD        =  "C:\Program Files\MATLAB\R2023b\sys\lcc64\lcc64\bin\lcclnk64.exe"
LIBCMD    =  "C:\Program Files\MATLAB\R2023b\sys\lcc64\lcc64\bin\lcclib64.exe"
CFLAGS    =  -dll -noregistrylookup  -c -Zp8 -DLCC_WIN64 -DMATLAB_MEX_FILE -nodeclspec
LDFLAGS   =  -s -dll -entry LibMain hTz0WIxwkE7MuOPybPder_cclib.def -L"C:\Program Files\MATLAB\R2023b\sys\lcc64\lcc64\lib64"

OBJECTS = \
	   simplex.obj \
	   slcc_interface_hTz0WIxwkE7MuOPybPder.obj \
	   lccstub.obj \

STATICLIBS = \

#------------------------------ Include/Lib Path ------------------------------

INCLUDE_PATH = \
     -I"c:\program files\matlab\r2023b\extern\include" \
     -I"c:\program files\matlab\r2023b\simulink\include" \
     -I"c:\users\inver\onedrive\documents\github\simscapemodel\slprj\_slcc\htz0wixwke7muopybpder" \
     -I"c:\users\inver\onedrive\documents\github\simscapemodel\code_generation_project" \
     -I"c:\users\inver\onedrive\documents\github\simscapemodel" \
     -I"c:\users\inver\onedrive\documents\github\simscapemodel\vehicle subsystems" \
     -I"c:\program files\matlab\r2023b\sys\lcc64\lcc64\include64" \
     -I"c:\program files\matlab\r2023b\sys\lcc64\lcc64\mex" \

#--------------------------------- Rules --------------------------------------

hTz0WIxwkE7MuOPybPder_cclib.dll : $(MAKEFILE) $(OBJECTS)
	$(LD) $(LDFLAGS) /OUT:hTz0WIxwkE7MuOPybPder_cclib.dll $(OBJECTS)  $(STATICLIBS) "C:\Program Files\MATLAB\R2023b\extern\lib\win64\microsoft\libmex.lib" "C:\Program Files\MATLAB\R2023b\extern\lib\win64\microsoft\libmx.lib"
simplex.obj :	c:\users\inver\onedrive\DOCUME~1\github\SIMSCA~1\CODE_G~1\simplex.c
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "c:\users\inver\onedrive\documents\github\simscapemodel\Code_Generation_Project\simplex.c"
slcc_interface_hTz0WIxwkE7MuOPybPder.obj :	C:\Users\Inver\OneDrive\DOCUME~1\GitHub\SIMSCA~1\slprj\_slcc\HTZ0WI~1\SLCC_I~1.C
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "C:\Users\Inver\OneDrive\Documents\GitHub\SimscapeModel\slprj\_slcc\hTz0WIxwkE7MuOPybPder\slcc_interface_hTz0WIxwkE7MuOPybPder.c"
lccstub.obj :	C:\PROGRA~1\MATLAB\R2023b\sys\lcc64\lcc64\mex\lccstub.c
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "C:\Program Files\MATLAB\R2023b\sys\lcc64\lcc64\mex\lccstub.c"
