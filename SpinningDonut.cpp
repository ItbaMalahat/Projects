#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

#define pi 3.142

class Donut {
public:
    Donut() {
        // Define buffer length
        int bufferLength = 1760;
        // Initialize rotation angles
        float A = 0, B = 0;
        // Define variables for spherical coordinates
        float theta, phi, z[1760];
        // Define buffer to hold ASCII art
        char buffer[1760];

        // Loop indefinitely to animate the donut
        while (true) {
            // Clear buffer and depth buffer
            memset(buffer, ' ', bufferLength);
            memset(z, 0, bufferLength * sizeof(float));

            // Calculate points on the surface of the donut
            for (phi = 0; phi < 2 * pi; phi += 0.07) {
                for (theta = 0; theta < 2 * pi; theta += 0.07) {
                    // Compute trigonometric functions
                    float c = sin(theta);
                    float d = cos(phi);
                    float e = sin(A);
                    float f = sin(phi);
                    float g = cos(A);
                    float h = d + 2;
                    // Compute various components of the equation
                    float D = 1 / (c * h * e + f * g + 5.1);
                    float l = cos(theta);
                    float m = cos(B);
                    float n = sin(B);
                    float t = c * h * g - f * e;
                    // Compute coordinates in screen space
                    int x = 40 + 30 * D * (l * h * m - t * n);
                    int y = 12 + 15 * D * (l * h * n + t * m);
                    int o = x + 80 * y;
                    int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);

                    // Check if point is within screen boundaries and closer to viewer
                    if (y < 22 && y > 0 && x > 0 && x < 80 && D > z[o]) {
                        // Store depth value and ASCII character for point
                        z[o] = D;
                        buffer[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                    }
                }
            }

            // Move cursor to top-left corner of terminal window
            cout << "\x1b[H";

            // Print the ASCII art buffer
            for (int q = 0; q < bufferLength; q++) {
                if (q % 80 != 0) {
                    cout << buffer[q];
                } else {
                    cout << endl;
                }
            }

            // Update rotation angles
            A += 0.04;
            B += 0.02;
        }
    }
};

int main() {
    // Create instance of Donut class to start animation
    Donut d;
    return 0;
}
