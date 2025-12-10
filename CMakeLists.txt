cmake_minimum_required(VERSION 3.10)

# Projenin adı
project(PhysicsEngine)

# Modern C++17 standartını kullan (Eski C++ ile vakit kaybetme)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Başlık dosyaları nerede? (include klasörü)
include_directories(include)

# Kaynak kodları bul (src içindeki her şey)
file(GLOB SOURCES "src/*.cpp")

# Çalıştırılabilir dosyayı oluştur (Adı: PhysicsEngine)
add_executable(PhysicsEngine ${SOURCES})