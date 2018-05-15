:: directories
set binDIR=%~dp0..\bin
set objDIR=%~dp0..\bin\obj
set libDIR=%~dp0..\lib

if not exist %binDIR% mkdir %binDIR%
if not exist %objDIR% mkdir %objDIR%

cd %~dp0
make

cd %binDIR%
:: dependencies
if not exist SDL2.dll xcopy /y %libDIR%\SDL2-2.0.8\bin\SDL2.dll .
if not exist SDL2_image.dll xcopy /y %libDIR%\SDL2_image-2.0.3\bin\SDL2_image.dll .
if not exist SDL2_ttf.dll xcopy /y %libDIR%\SDL2_ttf-2.0.14\bin\SDL2_ttf.dll .
if not exist SDL2_mixer.dll xcopy /y %libDIR%\SDL2_mixer-2.0.2\bin\SDL2_mixer.dll .

if not exist libpng16-16.dll xcopy /y %libDIR%\SDL2_image-2.0.3\bin\libpng16-16.dll .
if not exist zlib1.dll xcopy /y %libDIR%\SDL2_image-2.0.3\bin\zlib1.dll .
if not exist libfreetype-6.dll xcopy /y %libDIR%\SDL2_ttf-2.0.14\bin\libfreetype-6.dll .
if not exist libmpg123-0.dll xcopy /y %libDIR%\SDL2_mixer-2.0.2\bin\libmpg123-0.dll .