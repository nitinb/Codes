#include <iostream>

using namespace std;

#define min(a, b) a > b ? b : a

float get_volume(float *height, int num_of_buildings){
    float height_difference = 0.0;

    for(int i = 0; i < num_of_buildings; i++){
        // std::cout << "Processing building: " << i << std::endl;

        int j, index = -1, max_height = -1;
        for(j = i + 1; j < num_of_buildings; j++){
            if(height[j] > max_height){
                index = j;
                max_height = height[j];
            }

            if(height[j] > height[i]){
                break;
            }
        }

        if(index == -1){
            continue;
        }

        max_height = min(max_height, height[i]);
        for(j = i + 1; j < index; j++){
            height_difference += max_height - height[j];
            // std::cout << "height diff: " << height_difference << std::endl;
        }
        i = index - 1;
    }

    return height_difference;
}

int main(){
    int num_of_buildings;

    std::cout << "Number of buildings: ";
    std::cin >> num_of_buildings;

    float height[num_of_buildings];
    for(int i = 0; i < num_of_buildings; i++){
        std::cin >> height[i];
    }

    float height_difference = get_volume(height, num_of_buildings);
    std::cout << "Height diff: " << height_difference << std::endl;
}
