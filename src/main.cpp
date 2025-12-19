#include <iostream>
#include <vector>
#include <cmath>
#include <memory>

// 1. HAFIZA AJANI
struct AllocationMetrics {
    uint32_t TotalAllocated = 0;
    uint32_t TotalFreed = 0;
    uint32_t CurrentUsage() { return TotalAllocated - TotalFreed; }
};

static AllocationMetrics s_AllocationMetrics;

void* operator new(size_t size) {
    s_AllocationMetrics.TotalAllocated += size;
    return malloc(size);
}

void operator delete(void* memory, size_t size) noexcept {
    s_AllocationMetrics.TotalFreed += size;
    free(memory);
}

void operator delete(void* memory) noexcept {
    free(memory);
}

static void PrintMemoryUsage() {
    std::cout << ">> Guncel Bellek: " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
}

// 2. MATEMATİK VE FİZİK SINIFLARI
struct Vec2 {
    float x, y;

    Vec2() : x(0.0f), y(0.0f) {}
    Vec2(float x, float y) : x(x), y(y) {}

    Vec2 operator+(const Vec2& other) const {
        return Vec2(x + other.x, y + other.y);
    }

    Vec2 operator*(float scalar) const {
        return Vec2(x * scalar, y * scalar);
    }
};

struct Particle {
    Vec2 position;
    Vec2 velocity;
    float mass;

    Particle(float x, float y, float vx, float vy, float m)
        : position(x, y), velocity(vx, vy), mass(m) {}

    void Update(float deltaTime) {
        position = position + (velocity * deltaTime);
    }
};

// 3. TEST SAHASI
int main() {
    std::cout << "--- BASLANGIC ---\n";
    PrintMemoryUsage();

    std::vector<Particle*> world;

    std::cout << "\n--- 1000 PARCACIK YARATILIYOR ---\n";
    
    for (int i = 0; i < 1000; i++) {
        world.push_back(new Particle(0, 0, 1.0f, 1.5f, 10.0f));
    }
    PrintMemoryUsage();

    std::cout << "\n--- FIZIK DONGUSU BASLIYOR (5 Kare) ---\n";
    
    for (int i = 0; i < 5; i++) {
        for (Particle* p : world) {
            p->Update(0.016f); // Her karede fizik hesaplanıyor
        }
 
        PrintMemoryUsage(); 
    }

    std::cout << "\n--- TEMIZLIK ---\n";
    for (Particle* p : world) {
        delete p;
    }
    world.clear();
    PrintMemoryUsage();

    return 0;
}