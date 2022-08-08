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

int main(int argc, const char * argv[]) {
    ofstream fout;
    fout.open("output.ppm");
    
    int nx = 200;
    int ny = 100;
    
    fout << "P3\n" << nx << " " << ny <<"\n255\n";
    for(int j = ny-1; j >= 0; j--){
        for(int i = 0; i < nx; i++){
            
            vec3 col(float(i)/float(nx),float(j)/float(ny),0.2);
            
            int ir = int(256*col[0]);
            int ig = int(256*col[1]);
            int ib = int(256*col[2]);
            
            fout << ir << " " << ig << " " << ib << "\n";
        }
    }
    
    return 0;
}
