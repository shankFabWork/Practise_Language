# Download Flutter SDK

# Import it in environment variables

# Install VSCode Extension Following Extension ->
# 1) Flutter 
# 2) Dart
# 3) Awesome Flutter Snippets [Autocomplete]

# Ctrl+Shift+P -> Flutter:New Project
# Check If Everthing is OK by writing command -> "flutter doctor"
# Now Run command in cmd -> "flutter doctor --android-licenses"
# Use Ctrl+F5 to run the project
# Install Android Studios
# Default Android SDK Location ->
#     C:\Users\shank\AppData\Local\Android

# No very Important
# Android Studios -> Configure -> Plugins -> Flutter
# Android Studios -> Configure -> AVD Manager -> Create Virtual Device -> Pixel 2 -> Oreo 26 -> Download -> Finish

# Open Android Studio then File -> Settings -> Appearance & Behavior -> Notifications
# Then uncheck "Display baloon notifications"

# If Error
# Exception: Unable to find suitable Visual Studio toolchain. Please run `flutter doctor` for more details.
# Android Studios -> SDK Manager -> Edit -> Next -> Install -> Done

# Download and Install Visual Studio Community Version
# https://visualstudio.microsoft.com/downloads/
# Workloads -> Desktop Version with C++

# 1) Go to control panel. Open programs and features.
# 2) Find android studio and uninstall it.
# 3) Go to your android sdk folder and delete it. It can be found at this location C:\Users\User_Name\AppData\Local\Android
# 4) Find the .config .android .AndroidStudio 1.2.3 or your version .gradle files and delete it. Location C:\Users\User_Name\

# Unable to delete android sdk , go to msconfig.exe 
# and disable microsoft services and do clean restart

# Open Android Studios -> Click on 3-dots -> Click on Virtual Device Manager
# Nexus 6 [5.96 Inch] -> Orea

# There are following steps to clean flutter
# 1) Check the import package line it should be like packages: your file not file:///
# 2) use command flutter clean then flutter pub get in your terminal / command promp

# For Normal run -> click on F5 
# For Hot Reload -> Ctrl+Shift+F5

# Emulator always on TOP
# Go to three dots in emulator 
# Go to settings -> "Emulator always on TOP"