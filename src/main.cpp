#include <iostream>
#include "../include/Vec2.h"

int main() {
    // Başlangıç değerleri
    Vec2 position(0.0f, 0.0f); // Konum: (0,0)
    Vec2 velocity(1.0f, 0.5f); // Hız: Sağa 1, yukarı 0.5 birim
    
    // Delta Time (Zaman adımı) - Simülasyon hızı
    float dt = 1.0f; 

    std::cout << "--- 2D Physics Engine Started ---" << std::endl;

    for (int i = 0; i < 10; i++) {
        // FİZİK FORMÜLÜ: Yeni Konum = Eski Konum + (Hız * Zaman)
        position = position + (velocity * dt);

        std::cout << "Frame " << i 
                  << ": Position (" << position.x << ", " << position.y << ")" 
                  << " | Magnitude: " << position.Magnitude() 
                  << std::endl;
    }

    std::cout << "--- Simulation Finished ---" << std::endl;
    return 0;
}