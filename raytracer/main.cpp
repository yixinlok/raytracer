//
//  main.cpp
//  raytracer
//
//  Created by Yixin on 08/08/2022.
//

#include <iostream>
#include <fstream>
#include "vec3.h"
#include "ray.h"
using namespace std;

vec3 color(const ray& r){
    vec3 unit_direction = unit_vector(r.direction());
    float t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*vec3(1,1,1) + t*vec3(0.5,0.7,1);
}

int main(int argc, const char * argv[]) {
    ofstream fout;
    fout.open("output.ppm");
    
    int nx = 200;
    int ny = 100;
    fout << "P3\n" << nx << " " << ny <<"\n255\n";
    
    vec3 origin(0,0,0);
    vec3 lower_left_corner(-2,-1,-1);
    vec3 horizontal(4,0,0);
    vec3 vertical(0,2,-1);

    for(int j = ny-1; j >= 0; j--){
        for(int i = 0; i < nx; i++){
            
            float u = float(i)/float(nx);
            float v = float(j)/float(ny);
            ray r(origin, lower_left_corner + u*horizontal + v*vertical);
            vec3 col = color(r);
            
            int ir = int(255*col[0]);
            int ig = int(255*col[1]);
            int ib = int(255*col[2]);
            
            fout << ir << " " << ig << " " << ib << "\n";
        }
    }
    
    return 0;
}
