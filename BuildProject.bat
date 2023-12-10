@echo off

if not "%1"=="" (
  if not exist TheZoomies.sln (
    echo The required .sln file does not exist. Run GenerateProject.bat first.
    exit /b 1
  )

  if /i "%1"=="Debug" (
    msbuild .\TheZoomies.sln /p:Configuration=Debug /p:Platform=x64
  ) else if /i "%1"=="Release" (
    msbuild .\TheZoomies.sln /p:Configuration=Release /p:Platform=x64
  ) else if /i "%1"=="Dist" (
    msbuild .\TheZoomies.sln /p:Configuration=Dist /p:Platform=x64
  ) else (
    echo Invalid build configuration. Use Debug, Release, or Dist.
    exit /b 1
  )

  echo Build process complete.
  pause
) else (
  echo Invalid arguments. Example: .\BuildProject.bat Debug
  exit /b 1
)


